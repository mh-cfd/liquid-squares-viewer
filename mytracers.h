#ifndef MYTRACERS_H
#define MYTRACERS_H



#include <stdio.h>
#include <stdlib.h>

#include  <GL/gl.h>
#include  <GL/glu.h>
#include  <GL/glut.h>/* glut.h includes gl.h and glu.h*/
#include  <math.h>

#include "globals.h"

void animate_tracers();
void trace_tracers();
void rearrange_tracers();
void draw_tracers();

void animate_tracers_slice(XYZ r0,XYZ an,XYZ bn);
#endif
