#include <windows.h>
#include "myscreenshot.h"

#include <stdio.h>
#include <stdlib.h>

#include  <GL/gl.h>
#include  <GL/glu.h>
#include  <GL/glut.h>/* glut.h includes gl.h and glu.h*/
#include  <math.h>
//  include windows header for the BITMAPFILEHEADER and
// BITMAPINFOHEADER  structures.
// should work in other platforms with correct structures.

void snapshot(int windowWidth, int windowHeight, char* filename)
{

byte* bmpBuffer = (byte*)malloc(windowWidth*windowHeight*3);
if (!bmpBuffer)
return;

glReadPixels((GLint)0, (GLint)0,
(GLint)windowWidth-1, (GLint)windowHeight-1,
GL_RGB, GL_UNSIGNED_BYTE, bmpBuffer);


int i;
byte* ch=bmpBuffer;
for (i=0;i<windowWidth*windowHeight;i++)
{
  byte tch=ch[i*3+2];
  ch[i*3+2]=ch[i*3];
  ch[i*3]=tch;


}

FILE *filePtr = fopen(filename, "wb");
if (!filePtr)
return;

BITMAPFILEHEADER bitmapFileHeader;
BITMAPINFOHEADER bitmapInfoHeader;

bitmapFileHeader.bfType = 0x4D42; //"BM"
bitmapFileHeader.bfSize = windowWidth*windowHeight*3;
bitmapFileHeader.bfReserved1 = 0;
bitmapFileHeader.bfReserved2 = 0;
bitmapFileHeader.bfOffBits =
sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

bitmapInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
bitmapInfoHeader.biWidth = windowWidth-1;
bitmapInfoHeader.biHeight = windowHeight-1;
bitmapInfoHeader.biPlanes = 1;
bitmapInfoHeader.biBitCount = 24;
bitmapInfoHeader.biCompression = BI_RGB;
bitmapInfoHeader.biSizeImage = 0;
bitmapInfoHeader.biXPelsPerMeter = 0; // ?
bitmapInfoHeader.biYPelsPerMeter = 0; // ?
bitmapInfoHeader.biClrUsed = 0;
bitmapInfoHeader.biClrImportant = 0;

fwrite(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);
fwrite(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);
fwrite(bmpBuffer, windowWidth*windowHeight*3, 1, filePtr);
fclose(filePtr);

free(bmpBuffer);
}
