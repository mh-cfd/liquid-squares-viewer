
#include "globals.h"
#include <math.h>

float x_[NX][NY][NZ],y_[NX][NY][NZ],z_[NX][NY][NZ];

float x_sat[NX_SAT][NY_SAT],y_sat[NX_SAT][NY_SAT],z_sat[NX_SAT][NY_SAT];
float r_sat[NX_SAT][NY_SAT],g_sat[NX_SAT][NY_SAT],b_sat[NX_SAT][NY_SAT];




float u_[3][NX][NY][NZ],v_[3][NX][NY][NZ],w_[3][NX][NY][NZ];
 float u_t[NX][NY][NZ],v_t[NX][NY][NZ],w_t[NX][NY][NZ];  //time averaged
 float te_[3][NX][NY][NZ],vis_[3][NX][NY][NZ],vart_[3][NX][NY][NZ];
float temp_[3][NX][NY][NZ],wtt_[3][NX][NY][NZ],humid_[3][NX][NY][NZ];



IJK cross_map_ijk[100];
int cross_map_num=8;
float dxy_cross=0.03;//step in cross_section

 cross_elem cross[1000][NZ];
  int cross_elem_num;

  double dt=0.0015;


XYZ tracers[4000][TRACER_LEN];
  int trace_num=3990;

  float rx=-77;
  float ry=-4;
  int mx0,my0;
  int rotate=0;
  float rx0=0;
  float ry0=0;
 double d_temp;
 double mouse_x,mouse_y;

double r_2g=0.0;//cg res


int view=0;

int k_curr=26;
double ck=1.0;


int i_prof[10]={50,60,70,80,90,100,100,100,100,100};
int j_prof[10]={50,50,50,50,50,40,30,20,10,60};

int curr_prof=0;
int prof_num=8;

int screen_count=1;
float alpha_u=0.5;

float curr_coord=10.5;



XYZ cross_prod(XYZ a,XYZ b)
{
XYZ res;

res.x=a.y*b.z-a.z*b.y;
res.y=-a.x*b.z+a.z*b.x;
res.z=a.x*b.y-a.y*b.x;
return res;
}

float vec_len(XYZ a)
{

    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

float dot_prod(XYZ a, XYZ b)
{

    return a.x*b.x+a.y*b.y+a.z*b.z;
}

XYZ scale_vec(XYZ a,float sc)
{
    XYZ res;

    res.x=a.x*sc;
    res.y=a.y*sc;
    res.z=a.z*sc;
    return res;
}
XYZ add_vec(XYZ a,XYZ b)
{
    XYZ res;

    res.x=a.x+b.x;
    res.y=a.y+b.y;
    res.z=a.z+b.z;
    return res;
}

XYZ get_index(float x,float y, float z)
{

    XYZ res;

    res.x=x/(x_[10][10][10]-x_[9][9][9]);
    res.y=y/(y_[10][10][10]-y_[9][9][9]);


    int k=NZ-2;


    int i=(int)(res.x);

    int j=(int)(res.y);

    while ((z_[i][j][k]>=z)&&(k>0))
    {

        k--;

    }

    float alpha=(z-z_[i][j][k])/(z_[i][j][k+1]-z_[i][j][k]);

    if (alpha>1.0) alpha=1.0;

    if (alpha<0) alpha=0.0;
    res.z=k+alpha;

    return res;
}

float get_at_index(float arr_[NX][NY][NZ],XYZ indx)
{
    int i,j,k;
    float ai,aj,ak;

    i=(int) (indx.x);
    j=(int) (indx.y);
    k=(int) (indx.z);

    ai=indx.x-i;
    aj=indx.y-j;
    ak=indx.z-k;


    float res=((arr_[i][j][k]*(1.0-ai)+ai*arr_[i+1][j][k])*(1.0-aj)+
            (arr_[i][j+1][k]*(1.0-ai)+ai*arr_[i+1][j+1][k])*(aj))*(1.0-ak)+
            ((arr_[i][j][k+1]*(1.0-ai)+ai*arr_[i+1][j][k+1])*(1.0-aj)+
            (arr_[i][j+1][k+1]*(1.0-ai)+ai*arr_[i+1][j+1][k+1])*(aj))*(ak);
    return res;
}




float get_mean(float var_[NX][NY][NZ],int i0,int j0,int k0,int ri,int rj)
{
    int i,j,k;


    int imin,imax,jmin,jmax;

    imin=i_max(i0-ri,0);
    jmin=i_max(j0-rj,0);

    imax=i_min(i0-ri,NX-1);
    jmax=i_min(j0-rj,NY-1);
    int num=0;
    float mean=0.0;
    for (i=i0-ri;i<=i0+ri;i++)
    {
        for(j=j0-rj;j<=j0+rj;j++)
        {


            mean+=var_[i][j][k0];
            num++;

        }
    }
    return mean/num;

}



float get_2nd(float var_a[NX][NY][NZ],float var_b[NX][NY][NZ],float mean_a,float mean_b,int i0,int j0,int k0,int ri,int rj)
{
    int i,j,k;


    int imin,imax,jmin,jmax;

    imin=i_max(i0-ri,0);
    jmin=i_max(j0-rj,0);

    imax=i_min(i0-ri,NX-1);
    jmax=i_min(j0-rj,NY-1);
    int num=0;
    float mean=0.0;
    for (i=i0-ri;i<=i0+ri;i++)
    {
        for(j=j0-rj;j<=j0+rj;j++)
        {


            mean+=(var_a[i][j][k0]-mean_a)*(var_b[i][j][k0]-mean_b);
            num++;

        }
    }
    return mean/num;

}



int i_min(int a,int b)
{
    if (a>b) return b;
    else return a;
}



int i_max(int a,int b)
{
    if (a>b) return a;
    else return b;
}
