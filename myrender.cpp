#include "myrender.h"

myRender *render;

myRender::myRender()
{
    sc_x=0.1;
    sc_y=0.1;
    sc_z=0.1;

    tr_x=0.0;
    tr_y=0.0;
    tr_z=0.0;
    tbls[0].num=5;

/*temp*/

 /*   tbls[0].r[0]=0.0; tbls[0].g[0]=35.0/255.0; tbls[0].b[0]=178.0/255.0; tbls[0].x[0]=0;

    tbls[0].r[1]=0.0; tbls[0].g[1]=85.0/255.0; tbls[0].b[1]=208.0/255.0; tbls[0].x[1]=10;
    tbls[0].r[2]=1.0; tbls[0].g[2]=1.0;         tbls[0].b[2]=1.0;         tbls[0].x[2]=80;
    tbls[0].r[3]=0.0; tbls[0].g[3]=189.0/255.0; tbls[0].b[3]=197.0/255.0; tbls[0].x[3]=160;

    tbls[0].r[4]=1.0; tbls[0].g[4]=1.0; tbls[0].b[4]=0.0; tbls[0].x[4]=280;
    tbls[0].r[5]=1.0; tbls[0].g[5]=0.0; tbls[0].b[5]=0.0; tbls[0].x[5]=400;
*/


    tbls[0].r[0]=0.0; tbls[0].g[0]=0.0; tbls[0].b[0]=0.0;  tbls[0].x[0]=0;
    tbls[0].r[1]=0.0; tbls[0].g[1]=0.0; tbls[0].b[1]=1.0;  tbls[0].x[1]=20;

    tbls[0].r[2]=1.0; tbls[0].g[2]=1; tbls[0].b[2]=1; tbls[0].x[2]=80;
    tbls[0].r[3]=1.0; tbls[0].g[3]=1.0; tbls[0].b[3]=0.0; tbls[0].x[3]=190;
    tbls[0].r[4]=1.0; tbls[0].g[4]=0.25; tbls[0].b[4]=0.25; tbls[0].x[4]=400;

    tbls[0].r[1]=0.0; tbls[0].g[1]=85.0/255.0; tbls[0].b[1]=208.0/255.0; tbls[0].x[1]=20;
    tbls[0].r[2]=0.0; tbls[0].g[2]=189.0/255.0; tbls[0].b[2]=197.0/255.0; tbls[0].x[2]=80;
    tbls[0].r[3]=1.0; tbls[0].g[3]=1.0; tbls[0].b[3]=0.0; tbls[0].x[3]=190;
    tbls[0].r[4]=1.0; tbls[0].g[4]=0.5; tbls[0].b[4]=0.5; tbls[0].x[4]=400;



    tbls[0].r[0]=1.0; tbls[0].g[0]=1.0; tbls[0].b[0]=1.0;  tbls[0].x[0]=0;
    tbls[0].r[1]=0.0; tbls[0].g[1]=85.0/255.0; tbls[0].b[1]=208.0/255.0; tbls[0].x[1]=20;
    tbls[0].r[2]=0.0; tbls[0].g[2]=189.0/255.0; tbls[0].b[2]=197.0/255.0; tbls[0].x[2]=80;
    tbls[0].r[3]=1.0; tbls[0].g[3]=1.0; tbls[0].b[3]=0.0; tbls[0].x[3]=150;
    tbls[0].r[4]=1.0; tbls[0].g[4]=0.0; tbls[0].b[4]=0.0; tbls[0].x[4]=400;

    tbls[0].dx=1.0/400;
    tbls[0].x_num=400;
    int nn=0;
    for (int i=0;i<=tbls[0].x_num+1;i++)
    {
        if (i>=tbls[0].x[nn])
        {
            tbls[0].xt[i]=nn;
            nn++;
        }else
        {
            tbls[0].xt[i]=nn-1;
        }

    }

}


XYZ myRender::get_color(float gval, color_table* tbl,float min, float max)
{

    int i;
    float val;
    val=gval;
    if (val>max) val=max-0.00001;
    if (val<min) val=min+0.00001;


    XYZ res;





    double alpha;


    if ((max-min)>0.00001)
    {
        alpha=(val-min)/(max-min)*(tbl->x_num);
        i=tbl->xt[(int)(alpha)];
       // alpha=alpha-i;
    }else
    {
        alpha=0.0;
        i=2;
    }

    alpha=(alpha-tbl->x[i])*1.0/(tbl->x[i+1]-tbl->x[i]);

    res.x=tbl->r[i]*(1.0-alpha)+alpha*tbl->r[i+1];
    res.y=tbl->g[i]*(1.0-alpha)+alpha*tbl->g[i+1];
    res.z=tbl->b[i]*(1.0-alpha)+alpha*tbl->b[i+1];


    glColor3f(res.x,res.y,res.z);
    //glColor3f(alpha,alpha,-alpha);
    return res;

}

void myRender::draw_k_plane(float arr_[NX][NY][NZ], color_table* tbl, int k_curr,float min_,float max_)
{
    int i,j;
   // glColorModel(GL_FRONT_AND_BACK,GL_FILL);
    for (i=0;i<NX-1;i++)
    {
         glBegin(GL_TRIANGLE_STRIP);
        for(j=0;j<NY;j++)
        {
            get_color(arr_[i][j][k_curr],tbl,min_,max_);
            glVertex3f(sc_x*(x_[i][j][k_curr]-tr_x),sc_z*(z_[i][j][k_curr]-tr_z),sc_y*(y_[i][j][k_curr]-tr_y));
            get_color(arr_[i+1][j][k_curr],tbl,min_,max_);
            glVertex3f(sc_x*(x_[i+1][j][k_curr]-tr_x),sc_z*(z_[i+1][j][k_curr]-tr_z),sc_y*(y_[i+1][j][k_curr]-tr_y));

        }

        glEnd();
    }




}


void myRender::draw_sat()
{
    int i,j;
   // glColorModel(GL_FRONT_AND_BACK,GL_FILL);
    for (i=0;i<NX_SAT-1;i++)
    {
         glBegin(GL_TRIANGLE_STRIP);
        for(j=0;j<NY_SAT;j++)
        {
            glColor3f(r_sat[i][j],g_sat[i][j],b_sat[i][j]);
            glVertex3f(sc_x*(x_sat[i][j]-tr_x),sc_z*(z_sat[i][j]-tr_z),sc_y*(y_sat[i][j]-tr_y));

            glColor3f(r_sat[i+1][j],g_sat[i+1][j],b_sat[i+1][j]);
            glVertex3f(sc_x*(x_sat[i+1][j]-tr_x),sc_z*(z_sat[i+1][j]-tr_z),sc_y*(y_sat[i+1][j]-tr_y));



        }

        glEnd();
    }




}


void myRender::draw_k_prof(float arr_[NX][NY][NZ],float scale,float val0, int i, int j, int k_min, int k_max)
{
    int k;

    glBegin(GL_LINES);




        glVertex3f(sc_x*(x_[i][j][k_min]-tr_x),sc_z*(z_[i][j][k_min]-tr_z),sc_y*(y_[i][j][k_min]-tr_y));
        glVertex3f(sc_x*(x_[i][j][k_max]-tr_x),sc_z*(z_[i][j][k_max]-tr_z),sc_y*(y_[i][j][k_max]-tr_y));




    glEnd();


    glBegin(GL_LINE_STRIP);

    for (k=k_min;k<k_max;k++)
    {


        //glVertex3f(sc_x*(x_[i][j][k]-tr_x),sc_z*(z_[i][j][k]-tr_z),sc_y*(y_[i][j][k]-tr_y));
        glVertex3f(sc_x*(x_[i][j][k]-tr_x),sc_z*(z_[i][j][k]-tr_z),sc_y*(y_[i][j][k]-tr_y)+scale*(arr_[i][j][k]-val0));

        fprintf(stderr,"%d %f \n",k,arr_[i][j][k]);
    }

    glEnd();
}
