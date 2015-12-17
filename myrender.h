#ifndef MYRENDER_H
#define MYRENDER_H



#include <stdio.h>
#include <stdlib.h>

#include  <GL/gl.h>
#include  <GL/glu.h>
#include  <GL/glut.h>/* glut.h includes gl.h and glu.h*/
#include  <math.h>

#include "globals.h"
class myRender
{
public:
    myRender();
    void draw_k_plane(float arr_[NX][NY][NZ], color_table* tbl,int k_curr,float min_,float max_);


    void draw_k_prof(float arr_[NX][NY][NZ],float scale,float val0, int i,int j,int k_min,int k_max);

    void draw_sat();
    XYZ get_color(float gval, color_table* tbl,float min, float max);

    float sc_x,sc_y,sc_z,tr_x,tr_y,tr_z;

    color_table tbls[20];

};
extern myRender *render;
#endif // MYRENDER_H
