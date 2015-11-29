#include "my_io.h"
#include "globals.h"
#include <stdlib.h>
#include <stdio.h>
my_io::my_io()
{
}

int my_io::load_bin_vector(char* name, int n)
{


    int i,j,k,l,i1;


    FILE* file;

    float f1,f2,f3,f4,f5,f6,f7,f8,f9;

    FILE* pFile;

    char mystring [251];






    //добавить поиск соответствий по именам


    file=fopen(name,"rb");

    i=NX;j=NY;k=NZ;l=9;
    fread(&i,sizeof(int),1,file);
    fread(&j,sizeof(int),1,file);
    fread(&k,sizeof(int),1,file);
    fread(&l,sizeof(int),1,file);


    char names[MAX_VAR_COUNT][MAX_NAME_LEN];

    for (i=0;i<l;i++)
    {

        for (j=0;j<MAX_NAME_LEN;j++)
        {

            char ch=names[i][j];
            fread(&ch,sizeof(char),1,file);

        }


    }

    for (k=0;k<NZ;k++)
    {



        for (j=0;j<NY;j++)
        {

            for (i=0;i<NX;i++)
            {

                fread(&f1,sizeof(float),1,file);
                fread(&f2,sizeof(float),1,file);
                fread(&f3,sizeof(float),1,file);


                fread(&f4,sizeof(float),1,file);
                fread(&f5,sizeof(float),1,file);
                fread(&f6,sizeof(float),1,file);


                fread(&f7,sizeof(float),1,file);
                fread(&f8,sizeof(float),1,file);
                fread(&f9,sizeof(float),1,file);

                u_[n][i][j][k]=f1;
                v_[n][i][j][k]=f2;
                w_[n][i][j][k]=f3;

                te_[n][i][j][k]=f4;
                vis_[n][i][j][k]=f5;
                vart_[n][i][j][k]=f6;

                temp_[n][i][j][k]=f7;
                wtt_[n][i][j][k]=f8;
                humid_[n][i][j][k]=f9;

            }
        }

    }
    fclose(file);



}
