#include "mytracers.h"
#include "myrender.h"


void gen_tracers_slice(XYZ r0,XYZ an,XYZ bn)
{


    for (int i=0;i<trace_num;i++)
    {

        float rand_a,rand_b;
        rand_a=(1.0*rand())/RAND_MAX;
        rand_b=(1.0*rand())/RAND_MAX;

        tracers[i][0].x=r0.x+an.x*rand_a+bn.x*rand_b;
        tracers[i][0].y=r0.y+an.y*rand_a+bn.y*rand_b;
        tracers[i][0].z=r0.z+an.z*rand_a+bn.z*rand_b;

    }


}



void animate_tracers_slice(XYZ r0,XYZ an,XYZ bn)
{
    int i,j;
    XYZ norm;

    norm=cross_prod(an,bn);
    float len=vec_len(norm);
    norm.x/=len;
    norm.y/=len;
    norm.z/=len;

    for (i=0;i<trace_num;i++)
    {

        //  if  (((rand()*1.0)/RAND_MAX)<0.04)//((tracers[i][0].x<curr_coord)||(tracers[i][0].x>curr_coord+1.0))
        {
            float rand_a,rand_b;
            rand_a=(1.0*rand())/RAND_MAX;
            rand_b=(1.0*rand())/RAND_MAX;

            tracers[i][0].x=r0.x+an.x*rand_a+bn.x*rand_b;
            tracers[i][0].y=r0.y+an.y*rand_a+bn.y*rand_b;
            tracers[i][0].z=r0.z+an.z*rand_a+bn.z*rand_b;
            tracers[i][0].nx=norm.x;
            tracers[i][0].ny=norm.y;
            tracers[i][0].nz=norm.z;

        }





/*
        for (j=0;j<TRACER_LEN/2;j++)
        {
            XYZ indx;
            XYZ u_vec;

            indx=get_index(tracers[i][j].x,tracers[i][j].y,tracers[i][j].z);

            float u,v,w,um,vm,wm,tmp;

            u=get_at_index(u_[1],indx);
            v=get_at_index(v_[1],indx);
            w=get_at_index(w_[1],indx);

            um=get_at_index(u_t,indx);
            vm=get_at_index(v_t,indx);
            wm=get_at_index(w_t,indx);

            //  tmp=get_at_index(temp_[0],indx);


            u=alpha_u*u-(1.0-alpha_u)*um;
            v=alpha_u*v-(1.0-alpha_u)*vm;
            w=alpha_u*w-(1.0-alpha_u)*wm;



            float dot=(u*norm.x+v*norm.y+w*norm.z);

            u-=dot*norm.x;
            v-=dot*norm.y;
            w-=dot*norm.z;


            tracers[i][0].x=tracers[i][0].x-1.5*0.3*u;
            tracers[i][0].y=tracers[i][0].y-1.5*0.3*v;
            tracers[i][0].z=tracers[i][0].z-1.5*0.3*w;



        }*/
        int ntry=0;

        for (j=0;j<TRACER_LEN-1;j++)
            // j=0;
        {
            XYZ indx;
            XYZ u_vec;

            indx=get_index(tracers[i][j].x,tracers[i][j].y,tracers[i][j].z);

            float u,v,w,um,vm,wm,tmp;

            u=get_at_index(u_[1],indx);
            v=get_at_index(v_[1],indx);
            w=get_at_index(w_[1],indx);

            um=get_at_index(u_t,indx);
            vm=get_at_index(v_t,indx);
            wm=get_at_index(w_t,indx);

            //  tmp=get_at_index(temp_[0],indx);


            u=alpha_u*u-(1.0-alpha_u)*um;//alpha_u*u-(1.0-alpha_u)*um;
            v=alpha_u*v-(1.0-alpha_u)*vm;//alpha_u*v-(1.0-alpha_u)*vm;
            w=alpha_u*w-(1.0-alpha_u)*wm;;//alpha_u*w-(1.0-alpha_u)*wm;

            // fprintf(stderr,"u=%f v=%f w=%f \n",u,v,w);
            if (j==0)
            {


                float dot=(u*norm.x+v*norm.y+w*norm.z);

                u-=dot*norm.x;
                v-=dot*norm.y;
                w-=dot*norm.z;


                tracers[i][j].x=tracers[i][j].x+1.5*0.3*u;
                tracers[i][j].y=tracers[i][j].y+1.5*0.3*v;
                tracers[i][j].z=tracers[i][j].z+1.5*0.3*w;

                tracers[i][j].nx=norm.x;
                tracers[i][j].ny=norm.y;
                tracers[i][j].nz=norm.z;

                XYZ col=render->get_color(u*u+v*v+w*w,&(render->tbls[0]),0.0,0.01);



                tracers[i][j].r=col.x;
                tracers[i][j].g=col.y;
                tracers[i][j].b=col.z;

                indx=get_index(tracers[i][j].x,tracers[i][j].y,tracers[i][j].z);

                u=get_at_index(u_[1],indx);
                v=get_at_index(v_[1],indx);
                w=get_at_index(w_[1],indx);
                tmp=get_at_index(temp_[0],indx);

                um=get_at_index(u_t,indx);
                vm=get_at_index(v_t,indx);
                wm=get_at_index(w_t,indx);

                u=alpha_u*u-(1.0-alpha_u)*um;//alpha_u*u-(1.0-alpha_u)*um;
                v=alpha_u*v-(1.0-alpha_u)*vm;//alpha_u*v-(1.0-alpha_u)*vm;
                w=alpha_u*w-(1.0-alpha_u)*wm;//alpha_u*w-(1.0-alpha_u)*wm;
            }

            float dot=(u*norm.x+v*norm.y+w*norm.z);

            u-=dot*norm.x;
            v-=dot*norm.y;
            w-=dot*norm.z;


            len= sqrt(u*u+v*v+w*w);

      /*      if (len<0.008)
            {

                u*=0.008/len;
                v*=0.008/len;
                w*=0.008/len;}
*/
            tracers[i][j+1].x=tracers[i][j].x+1.5*0.3*u;
            tracers[i][j+1].y=tracers[i][j].y+1.5*0.3*v;
            tracers[i][j+1].z=tracers[i][j].z+1.5*0.3*w;



            tracers[i][j+1].nx=norm.x;
            tracers[i][j+1].ny=norm.y;
            tracers[i][j+1].nz=norm.z;
            XYZ col=render->get_color(u*u+v*v+w*w,&(render->tbls[0]),0.0,0.01);


            tracers[i][j+1].r=col.x;
            tracers[i][j+1].g=col.y;
            tracers[i][j+1].b=col.z;




        }
    }

}

void animate_tracers()
{
    int i,j;
    for (i=0;i<trace_num;i++)
    {

        if  (((rand()*1.0)/RAND_MAX)<0.5)//((tracers[i][0].x<curr_coord)||(tracers[i][0].x>curr_coord+1.0))
        {
            tracers[i][0].x=(x_[NX-1][0][0]*rand())/RAND_MAX;//curr_coord+(1.0*rand())/RAND_MAX;//
            tracers[i][0].y=(y_[0][NY-1][0]*rand())/RAND_MAX;
            tracers[i][0].z=0.1;//0.1+0.75*(z_[0][0][NZ-1]*rand())/RAND_MAX;
        }
        for (j=0;j<TRACER_LEN-1;j++)
            // j=0;
        {
            XYZ indx;
            indx=get_index(tracers[i][j].x,tracers[i][j].y,tracers[i][j].z);

            float u,v,w,um,vm,wm,tmp;

            u=get_at_index(u_[0],indx);
            v=get_at_index(v_[0],indx);
            w=get_at_index(w_[0],indx);

            um=get_at_index(u_t,indx);
            vm=get_at_index(v_t,indx);
            wm=get_at_index(w_t,indx);

            tmp=get_at_index(temp_[0],indx);

            u=um;//(1.0-alpha_u)*um;
            v=vm;///(1.0-alpha_u)*vm;
            w=wm;//(1.0-alpha_u)*wm;
            // fprintf(stderr,"u=%f v=%f w=%f \n",u,v,w);
            if (j==0)
            {
                tracers[i][j].x=tracers[i][j].x+1.5*0.5*u;
                tracers[i][j].y=tracers[i][j].y+1.5*0.5*v;
                tracers[i][j].z=tracers[i][j].z+1.5*0.5*w;


                XYZ col=render->get_color(tmp,&(render->tbls[0]),12.0,12.5);


                tracers[i][j].r=col.x;
                tracers[i][j].g=col.y;
                tracers[i][j].b=col.z;

                indx=get_index(tracers[i][j].x,tracers[i][j].y,tracers[i][j].z);

                u=get_at_index(u_[0],indx);
                v=get_at_index(v_[0],indx);
                w=get_at_index(w_[0],indx);
                tmp=get_at_index(temp_[0],indx);

                um=get_at_index(u_t,indx);
                vm=get_at_index(v_t,indx);
                wm=get_at_index(w_t,indx);

                u=um;//+(1.0-alpha_u)*um;
                v=vm;//+(1.0-alpha_u)*vm;
                w=wm;//+(1.0-alpha_u)*wm;
            }
            tracers[i][j+1].x=tracers[i][j].x+1.5*0.5*u;
            tracers[i][j+1].y=tracers[i][j].y+1.5*0.5*v;
            tracers[i][j+1].z=tracers[i][j].z+1.5*0.5*w;

            XYZ col=render->get_color(tmp,&(render->tbls[0]),12.0,12.5);


            tracers[i][j].r=col.x;
            tracers[i][j].g=col.y;
            tracers[i][j].b=col.z;

        }
    }

}


void trace_tracers()
{
    int i,j;
    for (i=0;i<trace_num;i++)
    {

        for (j=0;j<TRACER_LEN-1;j++)
        {
            XYZ indx;
            indx=get_index(tracers[i][j].x,tracers[i][j].y,tracers[i][j].z);

            float u,v,w;

            u=get_at_index(u_t,indx);
            v=get_at_index(v_t,indx);
            w=get_at_index(w_t,indx);


            // fprintf(stderr,"u=%f v=%f w=%f \n",u,v,w);

            tracers[i][j+1].x=tracers[i][j].x+0.5*u;
            tracers[i][j+1].y=tracers[i][j].y+0.5*v;
            tracers[i][j+1].z=tracers[i][j].z+0.5*w;
        }
    }

}
void rearrange_tracers()
{
    for (int i=0;i<trace_num;i++)
    {
        tracers[i][0].x=(x_[NX-1][0][0]*rand())/RAND_MAX;//curr_coord+(1.0*rand())/RAND_MAX;//(x_[NX-1][0][0]*rand())/RAND_MAX;
        tracers[i][0].y=(y_[0][NY-1][0]*rand())/RAND_MAX;
        tracers[i][0].z=curr_coord*0.1;//0.1+0.75*(z_[0][0][NZ-1]*rand())/RAND_MAX;

    }
    animate_tracers();
}


void draw_tracers()
{
    int i,j;
    // glEnable(GL_POINT_SMOOTH);

    //  glEnable(GL_LINE_SMOOTH);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(0.5);
    for (i=0;i<trace_num;i++)
    {



        //    glLineWidth(1.5);
        glBegin(GL_LINE_STRIP);
        for(j=0;j<TRACER_LEN;j++)
        {

            glPointSize(TRACER_LEN-j);

            /*c=(1-j)*sqrt((tracers[i][1].x-tracers[i][2].x)*(tracers[i][1].x-tracers[i][2].x)+
                    (tracers[i][1].y-tracers[i][2].y)*(tracers[i][1].y-tracers[i][2].y)+
                    (tracers[i][1].z-tracers[i][2].z)*(tracers[i][1].z-tracers[i][2].z));*/

            //           glColor3f(tracers[i][j].z*1.8,tracers[i][j].z*1.6,tracers[i][j].z*1.6);
float c=1;
            if(i%2==0)
            {
                c=(1.0*(TRACER_LEN-j))/(TRACER_LEN)-0.5;

            }
            glColor3f(c,c,c);


            //       glColor3f(tracers[i][j].r,tracers[i][j].g,tracers[i][j].b);

            glVertex3f(render->sc_x*(tracers[i][j].x-render->tr_x),
                       render->sc_z*(tracers[i][j].z-render->tr_z),
                       render->sc_y*(tracers[i][j].y-render->tr_y));

        }
        glEnd();
    }


    for (i=0;i<trace_num;i++)
    {

        XYZ rloc,nn,uu;

        rloc=tracers[i][TRACER_LEN/2];


        float scl=15.0;
        uu.x=scl*(tracers[i][TRACER_LEN/2+1].x-tracers[i][TRACER_LEN/2].x);
        uu.y=scl*(tracers[i][TRACER_LEN/2+1].y-tracers[i][TRACER_LEN/2].y);
        uu.z=scl*(tracers[i][TRACER_LEN/2+1].z-tracers[i][TRACER_LEN/2].z);



        uu=scale_vec(uu,0.07/vec_len(uu));

        nn.x=tracers[i][0].nx;
        nn.y=tracers[i][0].ny;
        nn.z=tracers[i][0].nz;

        XYZ arrow1,arrow2;

        XYZ tangent,ut;

        //nn=scale_vec(nn,1.0/vec_len(nn));
        tangent=cross_prod(uu,nn);

        float arrow_len=.99;
        tangent=scale_vec(tangent,arrow_len*0.25);

        XYZ uu_s=scale_vec(uu,1.0-arrow_len);
        arrow1=add_vec(uu_s,tangent);
        arrow2=add_vec(uu_s,scale_vec(tangent,-1.0));



        if(i%48==0){

            glBegin(GL_TRIANGLES);
            glColor4f(0.0,0.0,0.0,0.8);


            //   glColor3f(tracers[i][TRACER_LEN/2].r,tracers[i][TRACER_LEN/2].g,tracers[i][TRACER_LEN/2].b);

            glVertex3f(render->sc_x*(rloc.x+uu.x-render->tr_x),render->sc_z*(rloc.z+uu.z-render->tr_z),render->sc_y*(rloc.y+uu.y-render->tr_y));
            glVertex3f(render->sc_x*(rloc.x+arrow1.x-render->tr_x),render->sc_z*(rloc.z+arrow1.z-render->tr_z),render->sc_y*(rloc.y+arrow1.y-render->tr_y));
            glVertex3f(render->sc_x*(rloc.x+arrow2.x-render->tr_x),render->sc_z*(rloc.z+arrow2.z-render->tr_z),render->sc_y*(rloc.y+arrow2.y-render->tr_y));


            glEnd();
        }

        /*    glPointSize(3.0);
          glColor3f(tracers[i][0].z,0,0);
          glBegin(GL_POINTS);
          glVertex3f(render->sc_x*(tracers[i][0].x-render->tr_x),
                     render->sc_z*(tracers[i][0].z-render->tr_z),
                     render->sc_y*(tracers[i][0].y-render->tr_y));
          glEnd();*/
    } glDisable(GL_LINE_SMOOTH);

//  glDisable(GL_POINT_SMOOTH);

}
