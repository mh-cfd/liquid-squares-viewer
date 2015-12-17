


#ifndef GLOBALS_H
#define GLOBALS_H

 //for multigrid
 #define NX 320
 #define NY 170
 #define NZ 100


#define NX_SAT 1464
#define NY_SAT 827




#define MAX_NAME_LEN 32
#define MAX_VAR_COUNT 32
 #define U_TAU 1.0


 #define W_WIDTH 800
 #define W_HEIGHT 800

 #define RES2_MIN 0.000001
#define TRACER_LEN 80


 //a,b-components of impulse, f-RHS from prev timestep

 //_____________________________________________________
 //used equations:

 //a_t + (u_grad)u =1/re*lapl_a
 //lapl_phi=-grad_a
 //u=a+grad_pfi
 //dphi/dn=0.0 on the boundary

 //_____________________________________________________

 //MAC grid is used
 //Gauss-seidel with SOR is used to iterate over the diffusion and poisson equations
 //boundary conditions for a_ are taken explicitly from prev. timestep


typedef struct
{
 float x,y,z;
 float r,g,b;
 float nx,ny,nz;
}XYZ;

typedef struct
{
 float x,y,z;
 int i,j,k;
}IJK;


typedef struct
{
 float x,y,z;
  float nx,ny,nz;
 XYZ index;
 float u[3],v[3],w[3],hum[3],temp[3],um,vm,wm;
}cross_elem;


typedef struct
{
 int num;

 float r[255],g[255],b[255];
 int x[255];

int x_num;
int xt[1024];
float dx;
}color_table;




 extern double Re;


extern float x_[NX][NY][NZ],y_[NX][NY][NZ],z_[NX][NY][NZ];

extern float x_sat[NX_SAT][NY_SAT],y_sat[NX_SAT][NY_SAT],z_sat[NX_SAT][NY_SAT];
extern float r_sat[NX_SAT][NY_SAT],g_sat[NX_SAT][NY_SAT],b_sat[NX_SAT][NY_SAT];


extern float u_[3][NX][NY][NZ],v_[3][NX][NY][NZ],w_[3][NX][NY][NZ];
extern float u_t[NX][NY][NZ],v_t[NX][NY][NZ],w_t[NX][NY][NZ];  //time averaged
extern float te_[3][NX][NY][NZ],vis_[3][NX][NY][NZ],vart_[3][NX][NY][NZ];
extern float temp_[3][NX][NY][NZ],wtt_[3][NX][NY][NZ],humid_[3][NX][NY][NZ];

extern IJK cross_map_ijk[100];
extern int cross_map_num;
extern float dxy_cross;//step in cross_section

extern cross_elem cross[1000][NZ];
extern  int cross_elem_num;

extern XYZ tracers[4000][TRACER_LEN];
extern int trace_num;

 extern double dt;




 extern int itn;
 extern int clear_w;

 extern float rx;
 extern float ry;
 extern int mx0,my0;
 extern int rotate;
 extern float rx0;
 extern float ry0;
 extern double d_temp;
 extern double mouse_x,mouse_y;


 extern double r_2g;


extern int view;

extern  int k_curr;
extern  double ck;


extern  int i_prof[10];
extern  int j_prof[10];

extern  int curr_prof;
extern  int prof_num;

extern  int screen_count;
extern  float alpha_u;

extern  float curr_coord;


 int i_min(int a,int b);
 int i_max(int a,int b);
 XYZ cross_prod(XYZ a,XYZ b);
 float vec_len(XYZ a);

 float dot_prod(XYZ a, XYZ b);
 XYZ scale_vec(XYZ a,float sc);
 XYZ add_vec(XYZ a,XYZ b);
 XYZ get_index(float x,float y, float z);
 float get_at_index(float arr_[NX][NY][NZ],XYZ indx);
 float get_mean(float var_[NX][NY][NZ],int i0,int j0,int k0,int ri,int rj);
 float get_2nd(float var_a[NX][NY][NZ],float var_b[NX][NY][NZ],float mean_a,float mean_b,int i0,int j0,int k0,int ri,int rj);

#endif
