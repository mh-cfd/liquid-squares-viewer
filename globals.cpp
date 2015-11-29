
#include "globals.h"


float x_[NX][NY][NZ],y_[NX][NY][NZ],z_[NX][NY][NZ];

float x_sat[NX_SAT][NY_SAT],y_sat[NX_SAT][NY_SAT],z_sat[NX_SAT][NY_SAT];
float r_sat[NX_SAT][NY_SAT],g_sat[NX_SAT][NY_SAT],b_sat[NX_SAT][NY_SAT];




float u_[3][NX][NY][NZ],v_[3][NX][NY][NZ],w_[3][NX][NY][NZ];
 float u_t[NX][NY][NZ],v_t[NX][NY][NZ],w_t[NX][NY][NZ];  //time averaged
 float te_[3][NX][NY][NZ],vis_[3][NX][NY][NZ],vart_[3][NX][NY][NZ];
float temp_[3][NX][NY][NZ],wtt_[3][NX][NY][NZ],humid_[3][NX][NY][NZ];



IJK cross_map_ijk[100];
int cross_map_num=2;
float dxy_cross=0.03;//step in cross_section

 cross_elem cross[1000][NZ];
  int cross_elem_num;

  double dt=0.0015;


XYZ tracers[2000][TRACER_LEN];
  int trace_num=1000;

  float rx=-70;
  float ry=10.5;
  int mx0,my0;
  int rotate=0;
  float rx0=0;
  float ry0=0;
 double d_temp;
 double mouse_x,mouse_y;

double r_2g=0.0;//cg res
