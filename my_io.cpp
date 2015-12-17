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



void load_xyz_text(char * name)
{



    int i,j,k,i1;


    FILE* file;

    float f1,f2,f3,f4,f5,f6;
    int n;
    FILE* pFile;

    char mystring [251];



    file = fopen( name, "r" );


    n=0;


    for (i=0;i<9;i++){
        fgets (mystring , 250 , file);
        printf ("%s \n",mystring    );   }


    for (k=0;k<NZ;k++)
    {



        for (j=0;j<NY;j++)
        {

            for (i=0;i<NX;i++)
            {

                // n++;
                //printf("line_num=%d \n", n);

                f4=0.0; f5=0.0; f6=0.0;

                fgets (mystring , 250 , file);

                sscanf (mystring, "%f %f %f ", &f1,&f2,&f3);

                x_[i][j][k]=f1;
                y_[i][j][k]=f2;
                z_[i][j][k]=f3;


            }
        }

    }



    fclose(file);



    char name2[2048];

    sprintf(name2,"%s.bin",name);



    file=fopen(name2,"wb");

    i=NX;j=NY;k=NZ;
    fwrite(&i,sizeof(int),1,file);
    fwrite(&j,sizeof(int),1,file);
    fwrite(&k,sizeof(int),1,file);

    for (k=0;k<NZ;k++)
    {



        for (j=0;j<NY;j++)
        {

            for (i=0;i<NX;i++)
            {


                f1=x_[i][j][k];
                f2=y_[i][j][k];
                f3=z_[i][j][k];

                fwrite(&f1,sizeof(float),1,file);
                fwrite(&f2,sizeof(float),1,file);
                fwrite(&f3,sizeof(float),1,file);
            }
        }

    }
    fclose(file);




}






void convert_uvw_text(char * name,int n)
{



    int i,j,k,l,i1;


    FILE* file;

    float f1,f2,f3,f4,f5,f6,f7,f8,f9;

    FILE* pFile;

    char mystring [251];



    file = fopen( name, "r" );





    for (i=0;i<15;i++){
        fgets (mystring , 250 , file);
        printf ("%s \n",mystring    );   }




    for (k=0;k<NZ;k++)
    {



        for (j=0;j<NY;j++)
        {

            for (i=0;i<NX;i++)
            {

                // n++;
                //printf("line_num=%d \n", n);

                f4=0.0; f5=0.0; f6=0.0;

                fgets (mystring , 250 , file);

                sscanf (mystring, "%f %f %f %f %f %f %f %f %f ", &f1,&f2,&f3,&f4,&f5,&f6,&f7,&f8,&f9);

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



    char name2[2048];

    sprintf(name2,"%s.bin",name);



    file=fopen(name2,"wb");

    i=NX;j=NY;k=NZ;l=9;
    fwrite(&i,sizeof(int),1,file);
    fwrite(&j,sizeof(int),1,file);
    fwrite(&k,sizeof(int),1,file);
    fwrite(&l,sizeof(int),1,file);


    char names[MAX_VAR_COUNT][MAX_NAME_LEN];

    for (i=0;i<l;i++)
    {

        for (j=0;j<MAX_NAME_LEN;j++)
        {

            char ch=names[i][j];
            fwrite(&ch,sizeof(char),1,file);

        }


    }

    for (k=0;k<NZ;k++)
    {



        for (j=0;j<NY;j++)
        {

            for (i=0;i<NX;i++)
            {




                f1=u_[n][i][j][k];
                f2=v_[n][i][j][k];
                f3=w_[n][i][j][k];

                f4=te_[n][i][j][k];
                f5=vis_[n][i][j][k];
                f6=vart_[n][i][j][k];

                f7=temp_[n][i][j][k];
                f8=wtt_[n][i][j][k];
                f9=humid_[n][i][j][k];



                fwrite(&f1,sizeof(float),1,file);
                fwrite(&f2,sizeof(float),1,file);
                fwrite(&f3,sizeof(float),1,file);


                fwrite(&f4,sizeof(float),1,file);
                fwrite(&f5,sizeof(float),1,file);
                fwrite(&f6,sizeof(float),1,file);


                fwrite(&f7,sizeof(float),1,file);
                fwrite(&f8,sizeof(float),1,file);
                fwrite(&f9,sizeof(float),1,file);

            }
        }

    }
    fclose(file);




}





void convert_sat_text(char * name)
{



    int i,j,k,l,i1;


    FILE* file;

    float f1,f2,f3,f4,f5,f6,f7,f8,f9;
    int n;
    FILE* pFile;

    char mystring [251];



    file = fopen( name, "r" );


    n=0;


    for (i=0;i<12;i++){
        fgets (mystring , 250 , file);
        printf ("%s \n",mystring    );   }



    for (j=0;j<NY_SAT;j++)
    {

        for (i=0;i<NX_SAT;i++)
        {

            // n++;
            //printf("line_num=%d \n", n);

            f4=0.0; f5=0.0; f6=0.0;

            fgets (mystring , 250 , file);

            sscanf (mystring, "%f %f %f %f %f %f", &f1,&f2,&f3,&f4,&f5,&f6);

            x_sat[i][j]=f1;
            y_sat[i][j]=f2;
            z_sat[i][j]=f3;

            r_sat[i][j]=f4;
            g_sat[i][j]=f5;
            b_sat[i][j]=f6;




        }
    }





    fclose(file);



    char name2[2048];

    sprintf(name2,"%s.bin",name);



    file=fopen(name2,"wb");

    i=NX_SAT;j=NY_SAT;k=1;l=6;
    fwrite(&i,sizeof(int),1,file);
    fwrite(&j,sizeof(int),1,file);
    fwrite(&k,sizeof(int),1,file);
    fwrite(&l,sizeof(int),1,file);


    char names[MAX_VAR_COUNT][MAX_NAME_LEN];

    for (i=0;i<l;i++)
    {

        for (j=0;j<MAX_NAME_LEN;j++)
        {

            char ch=names[i][j];
            fwrite(&ch,sizeof(char),1,file);

        }


    }




    for (j=0;j<NY_SAT;j++)
    {

        for (i=0;i<NX_SAT;i++)
        {




            f1=x_sat[i][j];
            f2=y_sat[i][j];
            f3=z_sat[i][j];

            f4=r_sat[i][j];
            f5=g_sat[i][j];
            f6=b_sat[i][j];


            fwrite(&f1,sizeof(float),1,file);
            fwrite(&f2,sizeof(float),1,file);
            fwrite(&f3,sizeof(float),1,file);


            fwrite(&f4,sizeof(float),1,file);
            fwrite(&f5,sizeof(float),1,file);
            fwrite(&f6,sizeof(float),1,file);




        }
    }


    fclose(file);




}





void load_sat_bin(char * name)
{



    int i,j,k,l,i1;


    FILE* file;

    float f1,f2,f3,f4,f5,f6,f7,f8,f9;
    int n;
    FILE* pFile;

    char mystring [251];






    file=fopen(name,"rb");

    i=NX_SAT;j=NY_SAT;k=1;l=6;
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




    for (j=0;j<NY_SAT;j++)
    {

        for (i=0;i<NX_SAT;i++)
        {







            fread(&f1,sizeof(float),1,file);
            fread(&f2,sizeof(float),1,file);
            fread(&f3,sizeof(float),1,file);


            fread(&f4,sizeof(float),1,file);
            fread(&f5,sizeof(float),1,file);
            fread(&f6,sizeof(float),1,file);


            x_sat[i][j]=f1;
            y_sat[i][j]=f2;
            z_sat[i][j]=f3;

            r_sat[i][j]=f4;
            g_sat[i][j]=f5;
            b_sat[i][j]=f6;

        }
    }


    fclose(file);




}



void load_uvw_bin(char * name,int n)
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

void load_xyz_bin(char * name)
{



    int i,j,k,i1;


    FILE* file;

    float f1,f2,f3,f4,f5,f6;







    file=fopen(name,"rb");

    //i=NX;j=NY;k=NZ;
    fread(&i,sizeof(int),1,file);
    fread(&j,sizeof(int),1,file);
    fread(&k,sizeof(int),1,file);

    for (k=0;k<NZ;k++)
    {



        for (j=0;j<NY;j++)
        {

            for (i=0;i<NX;i++)
            {


                fread(&f1,sizeof(float),1,file);
                fread(&f2,sizeof(float),1,file);
                fread(&f3,sizeof(float),1,file);



                x_[i][j][k]=f1;
                y_[i][j][k]=f2;
                z_[i][j][k]=f3;


            }
        }

    }
    fclose(file);




}





void load_uvw_time_bin(char * name)
{



    int i,j,k,i1;


    FILE* file;

    float f1,f2,f3,f4,f5,f6;







    file=fopen(name,"rb");

    //i=NX;j=NY;k=NZ;
    fread(&i,sizeof(int),1,file);
    fread(&j,sizeof(int),1,file);
    fread(&k,sizeof(int),1,file);

    for (k=0;k<NZ;k++)
    {



        for (j=0;j<NY;j++)
        {

            for (i=0;i<NX;i++)
            {


                fread(&f1,sizeof(float),1,file);
                fread(&f2,sizeof(float),1,file);
                fread(&f3,sizeof(float),1,file);



                u_t[i][j][k]=f1;
                v_t[i][j][k]=f2;
                w_t[i][j][k]=f3;


            }
        }

    }
    fclose(file);




}

