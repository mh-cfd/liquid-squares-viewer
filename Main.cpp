
#include <stdio.h>
#include <stdlib.h>

#include  <GL/gl.h>
#include  <GL/glu.h>
#include  <GL/glut.h>/* glut.h includes gl.h and glu.h*/
#include  <math.h>
#include <time.h>
#include "globals.h"
#include "myrender.h"
#include "myscreenshot.h"
#include "vsofont.h"
#include "my_io.h"
#include "mytracers.h"
//#include <sys/time.h>

#define VIEW_U 1
#define VIEW_V 2
#define VIEW_W 3
#define VIEW_U1 4
#define VIEW_V1 5
#define VIEW_W1 6
#define VIEW_DIV0 7
#define VIEW_DIV  8
#define VIEW_PHI  9

void save_fields();
void load_fields();

void draw_cross();
void draw_cross_hum();
void build_cross();
void display(void);
void sweep_init();
void init();

void animate_tracers();
void rearrange_tracers();

void sweep();



void draw_prof(int i,int j);
void draw_tracers();

void filter_kplane(float var_[NX][NY][NZ],int k);





void display(void)
{

    int i,j,k,l;


    double l_2,tx,ty,tx0,ty0,vx,vy,v0x,v0y;
    /* clear window */


    // if (clear_w==1)

    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    glLoadIdentity();



glPushMatrix();
    // glTranslatef(0,0.4,0);
    // glRotatef(-90,0,0,1);
    glRotatef(ry,1.0,0,0);
    glRotatef(rx,0.0,1.0,0);

    /*  glColor3f(1,1,1);

    glBegin(GL_TRIANGLE_STRIP);

    glVertex3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glEnd();

*/
    glColor3f(1,1,1);
    /*  glBegin(GL_POINTS);
    for (i=0;i<NX;i++)
     {

        for (j=0;j<NY;j++)
         {

            glVertex3f(ck*x_[i][j][0],ck*z_[i][j][0],ck*y_[i][j][0]);
        }
    }

    glEnd();

*/

    // render->draw_sat();
    //render->draw_k_plane(humid_[2],&(render->tbls[0]),k_curr,0.0f,0.5f);//12.8f,15.6f);

    /*    for(i=0;i<prof_num;i++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_prof(i_prof[i],j_prof[i]);
        glColor3f(1.0,0,0);
    }
*/

    draw_cross_hum();

     draw_tracers();

    /*    for (i=1;i<NX-1;i++)
    {

        glBegin(GL_TRIANGLE_STRIP);


        for (j=1;j<NY-1;j++)
        {

            //!	if (view)
            //  l_2=phi_it[0][i][j][(NZ-1)/2];
            //else
            if (view==VIEW_U)
                l_2=ck*(u0_[i][j][k_curr]+u_[i][j][k_curr]);

            if (view==VIEW_V)
                l_2=ck*(v0_[i][j][k_curr]+v_[i][j][k_curr]);

            if (view==VIEW_W)
                l_2=ck*(w0_[i][j][k_curr]+w_[i][j][k_curr]);


            if (view==VIEW_U1)
                l_2=ck*(u_[i][j][k_curr]);

            if (view==VIEW_V1)
                l_2=ck*(v_[i][j][k_curr]);

            if (view==VIEW_W1)
                l_2=ck*(w_[i][j][k_curr]);

            if (view==VIEW_DIV0)
                l_2=ck*(div0_[i][j][k_curr]);

            if (view==VIEW_DIV)
                l_2=ck*(div_[i][j][k_curr]);


            if (view==VIEW_PHI)
                l_2=ck*(phi_[i][j][k_curr]);





            glColor3f(l_2,l_2,-l_2);

            if (marker[i][j][k_curr]==2)
                glColor3f(1,0,0);
            glVertex2f(x_[i],y_[j]);



            if (view==VIEW_U)
                l_2=ck*(u0_[i+1][j][k_curr]+u_[i+1][j][k_curr]);

            if (view==VIEW_V)
                l_2=ck*(v0_[i+1][j][k_curr]+v_[i+1][j][k_curr]);

            if (view==VIEW_W)
                l_2=ck*(w0_[i+1][j][k_curr]+w_[i+1][j][k_curr]);


            if (view==VIEW_U1)
                l_2=ck*(u_[i+1][j][k_curr]);

            if (view==VIEW_V1)
                l_2=ck*(v_[i+1][j][k_curr]);

            if (view==VIEW_W1)
                l_2=ck*(w_[i+1][j][k_curr]);

            if (view==VIEW_DIV0)
                l_2=ck*(div0_[i+1][j][k_curr]);

            if (view==VIEW_DIV)
                l_2=ck*(div_[i+1][j][k_curr]);

            if (view==VIEW_PHI)
                l_2=ck*(phi_[i+1][j][k_curr]);



            if (marker[i+1][j][k_curr]==2)
                glColor3f(1,0,0);

            //  l_2=ck*(div_[i+1][j][k_curr]);

            glColor3f(l_2,l_2,-l_2);



            glVertex2f(x_[i+1],y_[j]);
        }


        glEnd();
    }

*/




    /*
 for (i=1;i<NX-1;i++)
  {

   glBegin(GL_LINES);


   for (j=1;j<NY-1;j++)
      {

    //!	if (view)
    //  l_2=phi_it[0][i][j][(NZ-1)/2];
    //else
      l_2=ck*div_[i][j][k_curr];


      glColor3f(1,1,1);

        glVertex2f(x_[i],y_[j]);


        glColor3f(0.0,0.0,0.0);



        glVertex2f(x_[i]+ck*(u0_[i][j][k_curr]+u_[i][j][k_curr]),y_[j]+ck*(v0_[i][j][k_curr]+v_[i][j][k_curr]));
      }
      

    glEnd();
  }

 */

    glPopMatrix();
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_FOG);
    //glDisable(GL_LINE_SMOOTH);
    glDisable(GL_LIGHTING);

    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    glBegin(GL_TRIANGLE_STRIP);
    for (i=0;i<=80;i++)
    {
       render->get_color(i/80.0,&(render->tbls[0]),0.0,1.0);

        glVertex2f(3*(-0.75+i*1.5/80),0.94*3);
        glVertex2f(3*(-0.75+i*1.5/80),0.98*3);
     }
    glEnd();


    glColor3f(0,0,0);
    glLineWidth(1);
    for (i=0;i<=4;i++)
    {

    glBegin(GL_LINES);
        glVertex2f(3*(-0.75+i*1.5/4),0.92*3);
        glVertex2f(3*(-0.75+i*1.5/4),0.94*3);
     glEnd();
    }






    /////////////


    glColor3f(0,0,0);

/*
    vsofont_write_string_billboard_centered(examplefont, "Examplefont", 0, 0, 0);
    vsofont_write_string_billboard(clone, "CLONE", 0, -0.2, 0);
    vsofont_write_string_billboard_centered(proportional, "PROPORTIONAL", 0, -0.4, 0);
    vsofont_write_string_2D_centered(proportional, "NIIIIIICE", 0, -0.8);

    glLineWidth(2);
    vsofont_write_string_2D(proportional, "Proportional", -0.1, -0.6);*/
    glLineWidth(1.5);
 /*   char tmp[100];
    sprintf(tmp, "INTERESTING:%c%c%c%c", 3, 1, 2, 0);
    vsofont_write_string_2D_centered(proportional, tmp, 0, 0.2);
*/
    /* antialiasing */
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 //    vsofont_write_string_2D_centered(proportional, "0.123456789e", 0, 0.4);

    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_BLEND);





    //////////


    glPointSize(3.0);

    glLineWidth(1.0);

    glutSwapBuffers();

}

void m_m(int x,int y)
{

    if (rotate==1)
    {
        rx=rx0+0.5*(x-mx0);
        ry=ry0+0.5*(y-my0);


        printf ("rx=%f ry=%f \n",rx,ry);
    }

    glutPostRedisplay();

    /*	x_[1]=(1.0*x)/250.0 -1.0;
    y_[1]=(1.0*(500-y))/250.0 -1.0;*/
    //redr=1;
    //	glutPostRedisplay();
}



void m_d(int button, int state,int x, int y)
{

    if (state==GLUT_UP)
    {
        rotate=0;
        rx0=rx;
        ry0=ry;

    }
    if (state==GLUT_DOWN)
    {


        rotate=1;

        mx0=x;
        my0=y;



    }



    mouse_x=(1.0*x)/W_WIDTH;

    mouse_y=(W_HEIGHT-(1.0*y))/W_HEIGHT;

    glutPostRedisplay();
}



void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        //do something here
    {
        /*  i_prof[curr_prof]++;
        if (i_prof[curr_prof]>NX-1)
            i_prof[curr_prof]=NX-1;*/

        cross_map_ijk[curr_prof].i++;
        if (cross_map_ijk[curr_prof].i>NX-1)
            cross_map_ijk[curr_prof].i=NX-1;
    }
        break;
    case GLUT_KEY_DOWN:
    {


        /*        i_prof[curr_prof]--;
        if (i_prof[curr_prof]<0)
            i_prof[curr_prof]=0;
            */
        cross_map_ijk[curr_prof].i--;
        if (cross_map_ijk[curr_prof].i<0)
            cross_map_ijk[curr_prof].i=0;

    }
        //do something here
        break;
    case GLUT_KEY_LEFT:
    {
        /* j_prof[curr_prof]--;
        if (j_prof[curr_prof]<0)
            j_prof[curr_prof]=0;*/
        cross_map_ijk[curr_prof].j--;
        if (cross_map_ijk[curr_prof].j<0)
            cross_map_ijk[curr_prof].j=0;

    }
        //do something here
        break;
    case GLUT_KEY_RIGHT:
    {
        /*
        j_prof[curr_prof]++;
        if (j_prof[curr_prof]>NY-1)
            j_prof[curr_prof]=NY-1;*/
        cross_map_ijk[curr_prof].j++;
        if (cross_map_ijk[curr_prof].j>NY-1)
            cross_map_ijk[curr_prof].j=NY-1;

    }
        //do something here
        break;




    case GLUT_KEY_PAGE_UP:
        //do something here
    {
        alpha_u+=0.05;
        if (alpha_u>1.0)
            alpha_u=1.0;
       // animate_tracers();
        printf("alpha_u=%f\n",alpha_u);
    }
        break;

    case GLUT_KEY_PAGE_DOWN:
        //do something here
    {
        alpha_u-=0.05;
        if (alpha_u<0.0)
            alpha_u=0.0;
       // animate_tracers();
        printf("alpha_u=%f\n",alpha_u);
    }
        break;


    case GLUT_KEY_F12:
    {
        char screen_name[1024];
        sprintf(screen_name,"out_%03d.bmp",screen_count);
        screen_count++;
        snapshot(W_WIDTH,W_HEIGHT,screen_name);
        printf("taking screenshot %d \n",screen_count-1);
    }
    break;
    case GLUT_KEY_F11:
    {
 //filter_kplane(temp_,0);
    }
        //do something here
        break;
     }

    glutPostRedisplay();
}

void kb(unsigned char key, int x, int y)
{
    int i,j,k,nn,n;
    double m,sum;
    double max_err=0.0;



    if (key=='a')
    {


        render->tr_x+=0.1;

    }


    if (key=='d')
    {


        render->tr_x-=0.1;

    }


    if (key=='w')
    {


        render->tr_y+=0.1;

    }


    if (key=='x')
    {


        render->tr_y-=0.1;

    }



    if (key=='.')
    {


        ck*=1.01;


    }


    if (key==',')
    {


        ck/=1.01;


    }


    if (key=='1')
    {

        view=VIEW_U;
        printf("viewing u \n");

    }


    if (key=='2')
    {

        view=VIEW_V;
        printf("viewing v \n");

    }


    if (key=='3')
    {

        view=VIEW_W;
        printf("viewing w \n");

    }



    if (key=='4')
    {

        view=VIEW_U1;
        printf("viewing u1 \n");

    }

    if (key=='5')
    {

        view=VIEW_V1;
        printf("viewing v1 \n");

    }


    if (key=='6')
    {

        view=VIEW_W1;
        printf("viewing w1 \n");

    }


    if (key=='7')
    {

        view=VIEW_DIV0;
        printf("viewing div0 \n");

    }


    if (key=='8')
    {

        view=VIEW_DIV;
        printf("viewing div \n");

    }


    if (key=='9')
    {

        view=VIEW_PHI;
        printf("viewing phi \n");

    }








    if (key==']')
    {


        k_curr++;
        if (k_curr>=NZ) k_curr=NZ-1;


        printf ("k_curr=%d \n",k_curr);
    }


    if (key=='[')
    {


        k_curr--;
        if (k_curr<0) k_curr=0;

        printf ("k_curr=%d \n",k_curr);



    }


    if (key==' ')
    {

        curr_prof++;
        if (curr_prof>=cross_map_num)
            curr_prof=0;

    }



    if (key=='s')
    {

        build_cross();
        //animate_tracers();
        //save_fields();
        // multigr_phi();
        //sweep();
    }








    if (key=='z')
    {

        FILE* file=fopen("coords.txt","r");

        for (int i=0;i<cross_map_num;i++)
            fscanf(file,"%d %d \n",&(cross_map_ijk[i].i),&(cross_map_ijk[i].j));

        fclose(file);

        //if (clear_w==1) clear_w=0; else clear_w=1;

    }


    if (key=='t')
    {

        XYZ r0,a,b;

    r0.x=x_[cross_map_ijk[0].i][cross_map_ijk[0].j][8];
    r0.y=y_[cross_map_ijk[0].i][cross_map_ijk[0].j][8];
    r0.z=z_[cross_map_ijk[0].i][cross_map_ijk[0].j][8];

    a.x=x_[cross_map_ijk[0].i][cross_map_ijk[0].j][0]-r0.x;
    a.y=y_[cross_map_ijk[0].i][cross_map_ijk[0].j][0]-r0.y;
    a.z=z_[cross_map_ijk[0].i][cross_map_ijk[0].j][NZ-25]-r0.z;

    b.x=x_[cross_map_ijk[1].i][cross_map_ijk[1].j][0]-r0.x;
    b.y=y_[cross_map_ijk[1].i][cross_map_ijk[1].j][0]-r0.y;
    b.z=z_[cross_map_ijk[1].i][cross_map_ijk[1].j][0]-r0.z;
    animate_tracers_slice(r0,a,b);

      }

    if (key=='/')
    {

        FILE* file=fopen("coords.txt","w");

        for (int i=0;i<cross_map_num;i++)
            fprintf(file,"%d %d \n",(cross_map_ijk[i].i),(cross_map_ijk[i].j));

        fclose(file);

        //if (clear_w==1) clear_w=0; else clear_w=1;

    }

    glutPostRedisplay();
}





void filter_kplane(float var_[NX][NY][NZ],int k)
{
    int i,j;

    float tmp[NX][NY];


    for(i=1;i<NX-1;i++)
    {
        for(j=1;j<NY-1;j++)
        {
            tmp[i][j]=(var_[i][j][k]+0.5*var_[i+1][j][k]+0.5*var_[i][j+1][k]+0.5*var_[i-1][j][k]
                    +0.5*var_[i][j-1][k]+0.35*var_[i+1][j+1][k]+0.35*var_[i+1][j-1][k]+0.35*var_[i-1][j+1][k]+0.35*var_[i-1][j-1][k])
                    /(1.0+2.0+0.35*4);


        }
    }

    for(i=1;i<NX-1;i++)
    {
        for(j=1;j<NY-1;j++)
        {


            var_[i][j][k]=tmp[i][j];

        }
    }



}








void build_cross()
{
    int i,j,k;

    cross_elem_num=0;
    for (i=0;i<cross_map_num-1;i++)
    {
        int n,num;
        float xloc=x_[cross_map_ijk[i+1].i][cross_map_ijk[i+1].j][0]-x_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
        float yloc=y_[cross_map_ijk[i+1].i][cross_map_ijk[i+1].j][0]-y_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];

        float len=sqrt(xloc*xloc+yloc*yloc);
        num=(int)(len/dxy_cross);


        for (n=0;n<num;n++)
        {
            for(k=0;k<NZ;k++)
            {
                XYZ indx;
                xloc=x_[cross_map_ijk[i+1].i][cross_map_ijk[i+1].j][0]*(n*1.0/num)+(1.0-n*1.0/num)*x_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
                yloc=y_[cross_map_ijk[i+1].i][cross_map_ijk[i+1].j][0]*(n*1.0/num)+(1.0-n*1.0/num)*y_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];

                float zloc=z_[cross_map_ijk[i+1].i][cross_map_ijk[i+1].j][k]*(n*1.0/num)+(1.0-n*1.0/num)*z_[cross_map_ijk[i].i][cross_map_ijk[i].j][k];

                indx=get_index(xloc,yloc,zloc);

                cross[cross_elem_num][k].index=indx;
                cross[cross_elem_num][k].x=xloc;
                cross[cross_elem_num][k].y=yloc;
                cross[cross_elem_num][k].z=zloc;

                float nx=x_[cross_map_ijk[i+1].i][cross_map_ijk[i+1].j][0]-x_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
                float ny=y_[cross_map_ijk[i+1].i][cross_map_ijk[i+1].j][0]-y_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];

                float nlen=sqrt(nx*nx+ny*ny);

                cross[cross_elem_num][k].nx=ny;
                cross[cross_elem_num][k].ny=-nx;
                cross[cross_elem_num][k].nz=0;


                cross[cross_elem_num][k].u[0]=get_at_index(u_[0],indx);
                cross[cross_elem_num][k].u[1]=get_at_index(u_[1],indx);
                cross[cross_elem_num][k].u[2]=get_at_index(u_[2],indx);

                cross[cross_elem_num][k].v[0]=get_at_index(v_[0],indx);
                cross[cross_elem_num][k].v[1]=get_at_index(v_[1],indx);
                cross[cross_elem_num][k].v[2]=get_at_index(v_[2],indx);


                cross[cross_elem_num][k].w[0]=get_at_index(w_[0],indx);
                cross[cross_elem_num][k].w[1]=get_at_index(w_[1],indx);
                cross[cross_elem_num][k].w[2]=get_at_index(w_[2],indx);


                cross[cross_elem_num][k].um=get_at_index(u_t,indx);
                cross[cross_elem_num][k].vm=get_at_index(v_t,indx);
                cross[cross_elem_num][k].wm=get_at_index(w_t,indx);


                cross[cross_elem_num][k].hum[0]=get_at_index(humid_[0],indx);
                cross[cross_elem_num][k].hum[1]=get_at_index(humid_[1],indx);
                cross[cross_elem_num][k].hum[2]=get_at_index(humid_[2],indx);

                cross[cross_elem_num][k].temp[0]=get_at_index(temp_[0],indx);
                cross[cross_elem_num][k].temp[1]=get_at_index(temp_[1],indx);
                cross[cross_elem_num][k].temp[2]=get_at_index(temp_[2],indx);





            }
            cross_elem_num++;
        }

    }


}





void draw_cross_hum()
{

    int i,j,k;


    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);

    for (i=0;i<cross_map_num;i++)
    {
        int n,num;
        float xloc=x_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
        float yloc=y_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
        float zloc=z_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];

        glColor3f(0,0,0);
        if (i==curr_prof)
            glColor3f(1,1,1);

     //   glVertex3f(render->sc_x*(xloc-render->tr_x),render->sc_z*(zloc-render->tr_z),render->sc_y*(yloc-render->tr_y));

        xloc=x_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
        yloc=y_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
        zloc=z_[cross_map_ijk[i].i][cross_map_ijk[i].j][NZ-1];



        glVertex3f(render->sc_x*(xloc-render->tr_x),render->sc_z*(zloc-render->tr_z),render->sc_y*(yloc-render->tr_y));

    }
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);




    for (i=0;i<cross_elem_num-1;i++)
    {

        glBegin(GL_TRIANGLE_STRIP);

        for (k=0;k<NZ;k++)
        {


            float xloc=cross[i][k].x;
            float yloc=cross[i][k].y;
            float zloc=cross[i][k].z;

            render->get_color(cross[i][k].hum[2],&(render->tbls[0]),0.0f,1.5f);
            glVertex3f(render->sc_x*(xloc-render->tr_x),render->sc_z*(zloc-render->tr_z),render->sc_y*(yloc-render->tr_y));

            xloc=cross[i+1][k].x;
            yloc=cross[i+1][k].y;
            zloc=cross[i+1][k].z;

            render->get_color(cross[i+1][k].hum[2],&(render->tbls[0]),0.0f,1.5f);
            glVertex3f(render->sc_x*(xloc-render->tr_x),render->sc_z*(zloc-render->tr_z),render->sc_y*(yloc-render->tr_y));


        }

        glEnd();
    }

    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(1.5);
    glDepthMask(false);
//glDisable(GL_DEPTH_TEST);
    for ( i=0;i<cross_elem_num-1;i++)
    {


        glBegin(GL_LINES);

        for ( k=0;k<NZ-1;k++)
        {



            XYZ r_t[5];
            r_t[0].x=cross[i][k].x;     r_t[0].y=cross[i][k].y;     r_t[0].z=cross[i][k].z;
            r_t[1].x=cross[i+1][k].x;   r_t[1].y=cross[i+1][k].y;   r_t[1].z=cross[i+1][k].z;
            r_t[2].x=cross[i+1][k+1].x; r_t[2].y=cross[i+1][k+1].y; r_t[2].z=cross[i+1][k+1].z;
            r_t[3].x=cross[i][k+1].x;   r_t[3].y=cross[i][k+1].y;   r_t[3].z=cross[i][k+1].z;
            r_t[4].x=cross[i][k].x;     r_t[4].y=cross[i][k].y;     r_t[4].z=cross[i][k].z;

            int ii,kk;

            ii=i; kk=k;
            r_t[0].r=cross[ii][kk].hum[2];

            ii=i+1; kk=k;
            r_t[1].r=cross[ii][kk].hum[2];

            ii=i+1; kk=k+1;
            r_t[2].r=cross[ii][kk].hum[2];

            ii=i; kk=k+1;
            r_t[3].r=cross[ii][kk].hum[2];
            ii=i; kk=k;
            r_t[4].r=cross[ii][kk].hum[2];

float ddt=0.08;

float iso=ck;///2;
            for (int nnn=0;nnn<40;nnn++)
            {

           iso-=ddt;
            ddt*=0.97;

            XYZ pp[2];
            int pp_num=0;
            ii=0;

            while ( (ii<4)&&(pp_num<2))
            {
                if ((r_t[ii].r>iso)&&(r_t[ii+1].r<iso))
                {
                    float alpha=(r_t[ii].r-iso)/(r_t[ii].r-r_t[ii+1].r);
                    pp[pp_num].x=r_t[ii].x*(1.0-alpha)+alpha*r_t[ii+1].x;
                    pp[pp_num].y=r_t[ii].y*(1.0-alpha)+alpha*r_t[ii+1].y;
                    pp[pp_num].z=r_t[ii].z*(1.0-alpha)+alpha*r_t[ii+1].z;

                    pp_num++;
                }


                if ((r_t[ii].r<iso)&&(r_t[ii+1].r>iso))
                {
                    float alpha=(r_t[ii+1].r-iso)/(r_t[ii+1].r-r_t[ii].r);
                    pp[pp_num].x=r_t[ii].x*(alpha)+(1.0-alpha)*r_t[ii+1].x;
                    pp[pp_num].y=r_t[ii].y*(alpha)+(1.0-alpha)*r_t[ii+1].y;
                    pp[pp_num].z=r_t[ii].z*(alpha)+(1.0-alpha)*r_t[ii+1].z;
                    pp_num++;
                }
                ii++;
            }




            if (pp_num>1)
            {
                glColor3f(0,0,0);
                glVertex3f(render->sc_x*(pp[0].x-render->tr_x),render->sc_z*(pp[0].z-render->tr_z),render->sc_y*(pp[0].y-render->tr_y));


                glColor3f(0,0,0);
                glVertex3f(render->sc_x*(pp[1].x-render->tr_x),render->sc_z*(pp[1].z-render->tr_z),render->sc_y*(pp[1].y-render->tr_y));

            }
            }





        }

        glEnd();
    }

 glEnable(GL_DEPTH_TEST);

    glDisable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(1.5);
    glDepthMask(false);
    glDisable(GL_DEPTH_TEST);
    for (int ii=0;ii<cross_elem_num/20;ii++)
    {

        i=ii*20;

k=0;
        for (int kk=0;kk<NZ/2;kk++)
        {

            int kp=k;
            while ((((cross[i][kp].z-cross[i][k].z)<0.01))&&(kp<NZ))
{
                kp++;
            }
            k=kp;
            XYZ rloc;
            rloc.x=cross[i][k].x;
            rloc.y=cross[i][k].y;
            rloc.z=cross[i][k].z;


            XYZ nn;
            nn.x=cross[i][k].nx;
            nn.y=cross[i][k].ny;
            nn.z=cross[i][k].nz;

            XYZ uu;

            uu.x=2.0*cross[i][k].u[2];
            uu.y=2.0*cross[i][k].v[2];
            uu.z=0.0;//2.0*cross[i][k].w[1];


            float dot=(uu.x*nn.x+uu.y*nn.y+uu.z*nn.z)/(nn.x*nn.x+nn.y*nn.y+nn.z*nn.z);

            uu.x-=dot*nn.x;
            uu.y-=dot*nn.y;
            uu.z-=dot*nn.z;







            XYZ arrow1,arrow2;

            XYZ tangent,ut;

            nn=scale_vec(nn,1.0/vec_len(nn));
            tangent=cross_prod(uu,nn);

            float arrow_len=0.22;
                   tangent=scale_vec(tangent,arrow_len*0.25);

            XYZ uu_s=scale_vec(uu,1.0-arrow_len);
            arrow1=add_vec(uu_s,tangent);
            arrow2=add_vec(uu_s,scale_vec(tangent,-1.0));

/*
                glBegin(GL_LINES);
            glColor3f(0,0,0);
            glVertex3f(render->sc_x*(rloc.x-render->tr_x),render->sc_z*(rloc.z-render->tr_z),render->sc_y*(rloc.y-render->tr_y));
            glColor3f(0,0,0);
            glVertex3f(render->sc_x*(rloc.x+uu_s.x-render->tr_x),render->sc_z*(rloc.z+uu_s.z-render->tr_z),render->sc_y*(rloc.y+uu_s.y-render->tr_y));
            glEnd();

            glBegin(GL_TRIANGLES);
             glColor3f(0,0,0);
            glVertex3f(render->sc_x*(rloc.x+uu.x-render->tr_x),render->sc_z*(rloc.z+uu.z-render->tr_z),render->sc_y*(rloc.y+uu.y-render->tr_y));
            glVertex3f(render->sc_x*(rloc.x+arrow1.x-render->tr_x),render->sc_z*(rloc.z+arrow1.z-render->tr_z),render->sc_y*(rloc.y+arrow1.y-render->tr_y));
            glVertex3f(render->sc_x*(rloc.x+arrow2.x-render->tr_x),render->sc_z*(rloc.z+arrow2.z-render->tr_z),render->sc_y*(rloc.y+arrow2.y-render->tr_y));


            glEnd();
*/

        }

        glEnd();
    }
    glEnable(GL_DEPTH_TEST);
 glDisable(GL_LINE_SMOOTH);
 glDepthMask(true);
}

void draw_cross()
{

    int i,j,k;


    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLE_STRIP);

    for (i=0;i<cross_map_num;i++)
    {
        int n,num;
        float xloc=x_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
        float yloc=y_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
        float zloc=z_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];

        glColor3f(0,0,0);
        if (i==curr_prof)
            glColor3f(1,1,1);

        glVertex3f(render->sc_x*(xloc-render->tr_x),render->sc_z*(zloc-render->tr_z),render->sc_y*(yloc-render->tr_y));

        xloc=x_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
        yloc=y_[cross_map_ijk[i].i][cross_map_ijk[i].j][0];
        zloc=z_[cross_map_ijk[i].i][cross_map_ijk[i].j][NZ-1];



        glVertex3f(render->sc_x*(xloc-render->tr_x),render->sc_z*(zloc-render->tr_z),render->sc_y*(yloc-render->tr_y));

    }
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);




    for (i=0;i<cross_elem_num-1;i++)
    {

        glBegin(GL_TRIANGLE_STRIP);

        for (k=0;k<NZ;k++)
        {


            float xloc=cross[i][k].x;
            float yloc=cross[i][k].y;
            float zloc=cross[i][k].z;

            render->get_color(cross[i][k].temp[1],&(render->tbls[0]),12.25f,14.5f);
            glVertex3f(render->sc_x*(xloc-render->tr_x),render->sc_z*(zloc-render->tr_z),render->sc_y*(yloc-render->tr_y));

            xloc=cross[i+1][k].x;
            yloc=cross[i+1][k].y;
            zloc=cross[i+1][k].z;

            render->get_color(cross[i+1][k].temp[1],&(render->tbls[0]),12.25f,14.5f);
            glVertex3f(render->sc_x*(xloc-render->tr_x),render->sc_z*(zloc-render->tr_z),render->sc_y*(yloc-render->tr_y));


        }

        glEnd();
    }

    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(0.5);
    glDepthMask(false);
//glDisable(GL_DEPTH_TEST);
    for ( i=0;i<cross_elem_num-1;i++)
    {


        glBegin(GL_LINES);

        for ( k=0;k<NZ-1;k++)
        {



            XYZ r_t[5];
            r_t[0].x=cross[i][k].x;     r_t[0].y=cross[i][k].y;     r_t[0].z=cross[i][k].z;
            r_t[1].x=cross[i+1][k].x;   r_t[1].y=cross[i+1][k].y;   r_t[1].z=cross[i+1][k].z;
            r_t[2].x=cross[i+1][k+1].x; r_t[2].y=cross[i+1][k+1].y; r_t[2].z=cross[i+1][k+1].z;
            r_t[3].x=cross[i][k+1].x;   r_t[3].y=cross[i][k+1].y;   r_t[3].z=cross[i][k+1].z;
            r_t[4].x=cross[i][k].x;     r_t[4].y=cross[i][k].y;     r_t[4].z=cross[i][k].z;

            int ii,kk;

            ii=i; kk=k;
            r_t[0].r=cross[ii][kk].temp[1];

            ii=i+1; kk=k;
            r_t[1].r=cross[ii][kk].temp[1];

            ii=i+1; kk=k+1;
            r_t[2].r=cross[ii][kk].temp[1];

            ii=i; kk=k+1;
            r_t[3].r=cross[ii][kk].temp[1];
            ii=i; kk=k;
            r_t[4].r=cross[ii][kk].temp[1];

float ddt=0.035;

float iso=ck;
            for (int nnn=0;nnn<40;nnn++)
            {

           iso-=ddt;
            ddt*=0.98;

            XYZ pp[2];
            int pp_num=0;
            ii=0;

            while ( (ii<4)&&(pp_num<2))
            {
                if ((r_t[ii].r>iso)&&(r_t[ii+1].r<iso))
                {
                    float alpha=(r_t[ii].r-iso)/(r_t[ii].r-r_t[ii+1].r);
                    pp[pp_num].x=r_t[ii].x*(1.0-alpha)+alpha*r_t[ii+1].x;
                    pp[pp_num].y=r_t[ii].y*(1.0-alpha)+alpha*r_t[ii+1].y;
                    pp[pp_num].z=r_t[ii].z*(1.0-alpha)+alpha*r_t[ii+1].z;

                    pp_num++;
                }


                if ((r_t[ii].r<iso)&&(r_t[ii+1].r>iso))
                {
                    float alpha=(r_t[ii+1].r-iso)/(r_t[ii+1].r-r_t[ii].r);
                    pp[pp_num].x=r_t[ii].x*(alpha)+(1.0-alpha)*r_t[ii+1].x;
                    pp[pp_num].y=r_t[ii].y*(alpha)+(1.0-alpha)*r_t[ii+1].y;
                    pp[pp_num].z=r_t[ii].z*(alpha)+(1.0-alpha)*r_t[ii+1].z;
                    pp_num++;
                }
                ii++;
            }




            if (pp_num>1)
            {
                glColor3f(0.7,0.7,0.7);
                glVertex3f(render->sc_x*(pp[0].x-render->tr_x),render->sc_z*(pp[0].z-render->tr_z),render->sc_y*(pp[0].y-render->tr_y));


                glColor3f(0.7,0.7,0.7);
                glVertex3f(render->sc_x*(pp[1].x-render->tr_x),render->sc_z*(pp[1].z-render->tr_z),render->sc_y*(pp[1].y-render->tr_y));

            }
            }





        }

        glEnd();
    }

// glEnable(GL_DEPTH_TEST);

    glDisable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(1.5);
    glDepthMask(false);
    glDisable(GL_DEPTH_TEST);
    for (int ii=0;ii<cross_elem_num/20;ii++)
    {

        i=ii*20;

k=0;
        for (int kk=0;kk<NZ/2;kk++)
        {

            int kp=k;
            while ((((cross[i][kp].z-cross[i][k].z)<0.01))&&(kp<NZ))
{
                kp++;
            }
            k=kp;
            XYZ rloc;
            rloc.x=cross[i][k].x;
            rloc.y=cross[i][k].y;
            rloc.z=cross[i][k].z;


            XYZ nn;
            nn.x=cross[i][k].nx;
            nn.y=cross[i][k].ny;
            nn.z=cross[i][k].nz;

            XYZ uu;

            uu.x=2.0*cross[i][k].u[1];
            uu.y=2.0*cross[i][k].v[1];
            uu.z=0.0;//2.0*cross[i][k].w[1];


            float dot=(uu.x*nn.x+uu.y*nn.y+uu.z*nn.z)/(nn.x*nn.x+nn.y*nn.y+nn.z*nn.z);

            uu.x-=dot*nn.x;
            uu.y-=dot*nn.y;
            uu.z-=dot*nn.z;







            XYZ arrow1,arrow2;

            XYZ tangent,ut;

            nn=scale_vec(nn,1.0/vec_len(nn));
            tangent=cross_prod(uu,nn);

            float arrow_len=0.22;
                   tangent=scale_vec(tangent,arrow_len*0.25);

            XYZ uu_s=scale_vec(uu,1.0-arrow_len);
            arrow1=add_vec(uu_s,tangent);
            arrow2=add_vec(uu_s,scale_vec(tangent,-1.0));


                glBegin(GL_LINES);
            glColor3f(0.0,0.0,0.0);
            glVertex3f(render->sc_x*(rloc.x-render->tr_x),render->sc_z*(rloc.z-render->tr_z),render->sc_y*(rloc.y-render->tr_y));
            glColor3f(0,0,0);
            glVertex3f(render->sc_x*(rloc.x+uu_s.x-render->tr_x),render->sc_z*(rloc.z+uu_s.z-render->tr_z),render->sc_y*(rloc.y+uu_s.y-render->tr_y));
            glEnd();

            glBegin(GL_TRIANGLES);
             glColor3f(0,0,0);
            glVertex3f(render->sc_x*(rloc.x+uu.x-render->tr_x),render->sc_z*(rloc.z+uu.z-render->tr_z),render->sc_y*(rloc.y+uu.y-render->tr_y));
            glVertex3f(render->sc_x*(rloc.x+arrow1.x-render->tr_x),render->sc_z*(rloc.z+arrow1.z-render->tr_z),render->sc_y*(rloc.y+arrow1.y-render->tr_y));
            glVertex3f(render->sc_x*(rloc.x+arrow2.x-render->tr_x),render->sc_z*(rloc.z+arrow2.z-render->tr_z),render->sc_y*(rloc.y+arrow2.y-render->tr_y));


            glEnd();


        }

        glEnd();
    }
    glEnable(GL_DEPTH_TEST);
 glDisable(GL_LINE_SMOOTH);
 glDepthMask(true);
}



void draw_prof(int i,int j)
{






    glBegin(GL_LINE_LOOP);




    glVertex3f(render->sc_x*(x_[i-5][j-5][0]-render->tr_x),render->sc_z*(z_[i-5][j-5][0]-render->tr_z),render->sc_y*(y_[i-5][j-5][0]-render->tr_y));
    glVertex3f(render->sc_x*(x_[i-5][j+5][0]-render->tr_x),render->sc_z*(z_[i-5][j+5][0]-render->tr_z),render->sc_y*(y_[i-5][j+5][0]-render->tr_y));
    glVertex3f(render->sc_x*(x_[i+5][j+5][0]-render->tr_x),render->sc_z*(z_[i+5][j+5][0]-render->tr_z),render->sc_y*(y_[i+5][j+5][0]-render->tr_y));
    glVertex3f(render->sc_x*(x_[i+5][j-5][0]-render->tr_x),render->sc_z*(z_[i+5][j-5][0]-render->tr_z),render->sc_y*(y_[i+5][j-5][0]-render->tr_y));




    glEnd();

    //glColor3f(0.65,0.65,0.65);
    glColor3f(1,1,1);
    glBegin(GL_LINES);




    glVertex3f(render->sc_x*(x_[i][j][0]-render->tr_x),render->sc_z*(z_[i][j][0]-render->tr_z),render->sc_y*(y_[i][j][0]-render->tr_y));
    glVertex3f(render->sc_x*(x_[i][j][NZ-1]-render->tr_x),render->sc_z*(z_[i][j][NZ-1]-render->tr_z),render->sc_y*(y_[i][j][NZ-1]-render->tr_y));




    glEnd();



    float prf[10][NZ];

    for (int k=0;k<NZ;k++)
    {

        float tmean;
        float wmean;
        float wttres;
        float wttmod;
        float wttfull;
        float ff;//=tmean-13.0;//get_mean(temp_,i,j,NZ-2,5,5);


        int ii=2;
        //    for( ii=0;ii<3;ii++)
        {
            tmean=get_mean(temp_[ii],i,j,k,5,5);
            wmean=get_mean(w_[ii],i,j,k,5,5);
            wttres=get_2nd(temp_[ii],w_[0],tmean,wmean,i,j,k,5,5);
            wttmod=get_mean(wtt_[ii],i,j,k,5,5);
            wttfull=wttres+wttmod;
            ff=tmean-get_mean(temp_[ii],i,j,2,5,5);
            //glVertex3f(sc_x*(x_[i][j][k]-tr_x),sc_z*(z_[i][j][k]-tr_z),sc_y*(y_[i][j][k]-tr_y));

            //prf[ii][k]=ff*0.4;//-150*wttfull;
            prf[0][k]=-950*wttfull;
            prf[1][k]=-950*wttres;
            prf[2][k]=-950*wttmod;

        }
    }


    //  glEnable(GL_LINE_SMOOTH);

    glLineWidth(2);
    glBegin(GL_LINE_STRIP);

    for (int k=4;k<NZ;k++)
    {

        glColor3f(1,1,1);
        glVertex3f(render->sc_x*(x_[i][j][k]-render->tr_x),render->sc_z*(z_[i][j][k]-render->tr_z),render->sc_y*(y_[i][j][k]-render->tr_y)+(prf[0][k]));
    }
    glEnd();

    glLineWidth(3);


    glLineStipple(3, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINE_STRIP);

    for (int k=4;k<NZ;k++)
    {

        glColor3f(0.9,0.9,1);
        glVertex3f(render->sc_x*(x_[i][j][k]-render->tr_x),render->sc_z*(z_[i][j][k]-render->tr_z),render->sc_y*(y_[i][j][k]-render->tr_y)+(prf[1][k]));
    }
    glEnd();

    glLineWidth(2);
    glDisable(GL_LINE_STIPPLE);
    glDisable(GL_LINE_SMOOTH);
    glBegin(GL_LINE_STRIP);

    for (int k=4;k<NZ;k++)
    {

        glColor3f(1,1,0);
        glVertex3f(render->sc_x*(x_[i][j][k]-render->tr_x),render->sc_z*(z_[i][j][k]-render->tr_z),render->sc_y*(y_[i][j][k]-render->tr_y)+(prf[2][k]));
    }
    glEnd();
    glLineWidth(1);
    glDisable(GL_LINE_STIPPLE);
    glDisable(GL_LINE_SMOOTH);

}

void init()
{
    /* set clear color to black */
    glClearColor (1.0, 1.0, 1.0, 1.0);

    /* set fill color to white */
    glColor3f(1.0, 1.0, 1.0);

    /* set up standard orthogonal view with clipping */
    /* box as cube of side 2 centered at origin */
    /* This is default view and these statement could be removed */
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(-3, 3, -3,3, -10.0, 10.0);
    glMatrixMode (GL_MODELVIEW);

    printf("loading .... \n");


    cross_map_num=2;


    for(int i=0;i<cross_map_num;i++)
    {
        cross_map_ijk[i].i=i*17+10; cross_map_ijk[i].j=i*7+10;
    }




   // convert_uvw_text("c:\\user\\devel\\tecio_loader\\tecload\\1762_step_hyb_humid.dat",0);


    // convert_sat_text("c:\\user\\devel\\tecio_loader\\tecload\\ground.dat");


    load_sat_bin("c:\\user\\devel\\tecio_loader\\tecload\\ground.dat.bin");

    load_uvw_bin("c:\\user\\devel\\tecio_loader\\tecload\\1761_rough_uvw.dat.bin",1);
    load_uvw_bin("c:\\user\\devel\\tecio_loader\\tecload\\1761_uvw.dat.bin",1);
    load_uvw_bin("c:\\user\\devel\\tecio_loader\\tecload\\1762_step_hyb_humid.dat.bin",2);

//    load_uvw_bin("c:\\user\\devel\\tecio_loader\\tecload\\44444.dat.bin",1);

    //  convert_uvw_text("c:\\user\\devel\\tecio_loader\\tecload\\1761_uvw.dat");
    //    load_xyz_text("c:\\user\\devel\\tecio_loader\\tecload\\uvw_tmean_hyb.dat");
    load_xyz_bin("c:\\user\\devel\\tecio_loader\\tecload\\xyz.dat.bin");
    load_uvw_time_bin("c:\\user\\devel\\tecio_loader\\tecload\\uvw_tmean_hyb.dat.bin");




    render=new myRender();
    render->tr_x=(x_[0][0][0]+x_[NX-1][0][0])*0.5;
    render->tr_y=(y_[0][0][0]+y_[0][NY-1][0])*0.5;
    render->tr_z=(z_[0][0][0]+z_[0][0][NZ-1])*0.5;

  /*  render->sc_x=1.50*0.75;
    render->sc_y=1.50*0.75;
    render->sc_z=3.6*0.75;
*/
    render->sc_x=1.5*0.75;
        render->sc_y=1.5*0.75;
     render->sc_z=3.0*0.75;


    int i,j,k;

    for (i=0;i<trace_num;i++)
    {
        tracers[i][0].x=10.5;//(x_[NX-1][0][0]*rand())/RAND_MAX;
        tracers[i][0].y=(y_[0][NY-1][0]*rand())/RAND_MAX;
        tracers[i][0].z=0.1+0.75*(z_[0][0][NZ-1]*rand())/RAND_MAX;

    }
    trace_tracers();


   // ck=12.5;

    /*
    for (i=0;i<NX;i++)
    {
        for(j=0;j<NY;j++)
        {
            for(k=0;k<NZ;k++)
            {
              //  t_mean[i][j][k]= get_mean(temp_,i,j,k,5,5);
           //     vart_mod[i][j][k]=get_mean(vart_,i,j,k,5,5);
              //  vart_res[i][j][k]=get_2nd(temp_,temp_,t_mean[i][j][k],t_mean[i][j][k],i,j,k,5,5);
            }
        }
    }*/



    font_init();
}

int main(int argc, char** argv)
{
    /* Initialize mode and open a window in upper left corner of screen */
    /* Window title is name of program (arg[0]) */


    srand(time(NULL));
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(W_WIDTH,W_HEIGHT);
    glutInitWindowPosition(0,0);
    glutCreateWindow("simple");
    glutDisplayFunc(display);
    glutMotionFunc(m_m);
    glutMouseFunc(m_d);
    glutKeyboardFunc(kb);
    glutSpecialFunc(SpecialInput);
    init();
    glutMainLoop();

    delete render;
}
