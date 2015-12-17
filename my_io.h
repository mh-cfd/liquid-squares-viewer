#ifndef MY_IO_H
#define MY_IO_H



void load_xyz_text(char * name);
void convert_uvw_text(char * name,int n);
void convert_sat_text(char * name);
void load_sat_bin(char * name);
void load_uvw_bin(char * name,int n);
void load_xyz_bin(char * name);
void load_uvw_time_bin(char * name);

class my_io
{
public:
    my_io();

int load_bin_vector(char* name, int n);//loads bin vector file
};

#endif // MY_IO_H
