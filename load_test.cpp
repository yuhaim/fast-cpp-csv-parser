#define _CRT_SECURE_NO_WARNINGS
//#define CSV_IO_NO_THREAD
#include "csv.h"
#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

//cl /Wall /wd4514 /wd4820 /wd4365 /wd4244 /EHsc main.cpp

int main(){
	double start_time = clock()*1000.0/CLOCKS_PER_SEC;
	io::CSVReader<5> in("D:\\csvData.csv");
	io::CSVReader<5> in_1("D:\\csvData_1.csv");
	io::CSVReader<5> in_2("D:\\csvData_2.csv");
	io::CSVReader<5> in_3("D:\\csvData_3.csv");
	io::CSVReader<5> in_4("D:\\csvData_4.csv");

	in.read_header(io::ignore_extra_column, "time", "sin_t_pi_14", "cos_t_pi_14", "sin_t_pi_16", "cos_t_pi_16");
	in_1.read_header(io::ignore_extra_column, "time", "sin_t_pi_18", "cos_t_pi_18", "sin_t_pi_20", "cos_t_pi_20");
	in_2.read_header(io::ignore_extra_column, "time", "sin_t_pi_22", "cos_t_pi_22", "sin_t_pi_24", "cos_t_pi_24");
	in_3.read_header(io::ignore_extra_column, "time", "sin_t_pi_26", "cos_t_pi_26", "sin_t_pi_28", "cos_t_pi_28");
	in_4.read_header(io::ignore_extra_column, "time", "sin_t_pi_30", "cos_t_pi_30", "sin_t_pi_32", "cos_t_pi_32");

	int time;
	double sin_t_pi_14, cos_t_pi_14, sin_t_pi_16, cos_t_pi_16;
	double sin_t_pi_18, cos_t_pi_18, sin_t_pi_20, cos_t_pi_20;
	double sin_t_pi_22, cos_t_pi_22, sin_t_pi_24, cos_t_pi_24;
	double sin_t_pi_26, cos_t_pi_26, sin_t_pi_28, cos_t_pi_28;
	double sin_t_pi_30, cos_t_pi_30, sin_t_pi_32, cos_t_pi_32;

	fprintf(stdout, "time\t\tsin_t_pi_14\t\tcos_t_pi_14\t\tsin_t_pi_16\t\tcos_t_pi_16\n");
	while(in.read_row(time, sin_t_pi_14,cos_t_pi_14,sin_t_pi_16,cos_t_pi_16) && 
			in_1.read_row(time, sin_t_pi_18, cos_t_pi_18, sin_t_pi_20, cos_t_pi_20) && 	
			in_2.read_row(time, sin_t_pi_22, cos_t_pi_22, sin_t_pi_24, cos_t_pi_24) && 
			in_3.read_row(time, sin_t_pi_26, cos_t_pi_26, sin_t_pi_28, cos_t_pi_28) && 
			in_4.read_row(time, sin_t_pi_30, cos_t_pi_30, sin_t_pi_32, cos_t_pi_32)){
    // do stuff with the data
	double current_time = clock()*1000.0/CLOCKS_PER_SEC;

	fprintf(stdout, "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	fprintf(stdout, "data time:%d\t\t run time:%lf\t\tchecking data sum:%lf\t\tchecking data sum:%lf\n", 
					time, 
					(current_time - start_time)*1.0e-3,
					pow(sin_t_pi_14,2)+pow(cos_t_pi_14,2), 
					pow(sin_t_pi_16,2)+pow(cos_t_pi_16,2));
	fprintf(stdout, "data time:%d\t\t run time:%lf\t\tchecking data sum:%lf\t\tchecking data sum:%lf\n", 
					time, 
					(current_time - start_time)*1.0e-3,
					pow(sin_t_pi_18,2)+pow(cos_t_pi_18,2), 
					pow(sin_t_pi_20,2)+pow(cos_t_pi_20,2));
	fprintf(stdout, "data time:%d\t\t run time:%lf\t\tchecking data sum:%lf\t\tchecking data sum:%lf\n", 
					time, 
					(current_time - start_time)*1.0e-3,
					pow(sin_t_pi_22,2)+pow(cos_t_pi_22,2), 
					pow(sin_t_pi_24,2)+pow(cos_t_pi_24,2));
	fprintf(stdout, "data time:%d\t\t run time:%lf\t\tchecking data sum:%lf\t\tchecking data sum:%lf\n", 
					time, 
					(current_time - start_time)*1.0e-3,
					pow(sin_t_pi_26,2)+pow(cos_t_pi_26,2), 
					pow(sin_t_pi_28,2)+pow(cos_t_pi_28,2));
	fprintf(stdout, "data time:%d\t\t run time:%lf\t\tchecking data sum:%lf\t\tchecking data sum:%lf\n", 
					time, 
					(current_time - start_time)*1.0e-3,
					pow(sin_t_pi_30,2)+pow(cos_t_pi_30,2), 
					pow(sin_t_pi_32,2)+pow(cos_t_pi_32,2));				
	fprintf(stdout, "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  }
}