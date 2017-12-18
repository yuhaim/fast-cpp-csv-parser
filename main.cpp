#define _CRT_SECURE_NO_WARNINGS
//#define CSV_IO_NO_THREAD
#include "csv.h"
#include <cstdio>
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

//cl /Wall /wd4514 /wd4820 /wd4365 /wd4244 /EHsc main.cpp

int main(){
	double start_time = clock()*1000.0/CLOCKS_PER_SEC;
	io::CSVReader<5> in("D:\\csvData.csv");
	in.read_header(io::ignore_extra_column, "time", "sin_t_pi_14", "cos_t_pi_14", "sin_t_pi_16", "cos_t_pi_16");
	int time;
	double sin_t_pi_14, cos_t_pi_14, sin_t_pi_16, cos_t_pi_16;

	fprintf(stdout, "time\t\tsin_t_pi_14\t\tcos_t_pi_14\t\tsin_t_pi_16\t\tcos_t_pi_16\n");
	while(in.read_row(time, sin_t_pi_14,cos_t_pi_14,sin_t_pi_16,cos_t_pi_16)){
    // do stuff with the data
	double current_time = clock()*1000.0/CLOCKS_PER_SEC;
    //fprintf(stdout, "%d\t\t%lf\t\t%lf\t\t%lf\t\t%lf\n", time, sin_t_pi_14, cos_t_pi_14, sin_t_pi_16, cos_t_pi_16);
	fprintf(stdout, "data time:%d\t\t run time:%lf\t\tchecking data sum:%lf\t\tchecking data sum:%lf\n", 
					time, 
					(current_time - start_time)*1.0e-3,
					pow(sin_t_pi_14,2)+pow(cos_t_pi_14,2), 
					pow(sin_t_pi_16,2)+pow(cos_t_pi_16,2));
  }
}