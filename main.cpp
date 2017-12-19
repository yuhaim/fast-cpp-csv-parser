#define _CRT_SECURE_NO_WARNINGS
//#define CSV_IO_NO_THREAD
#include "csv.h"
#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

//cl /Wall /wd4514 /wd4820 /wd4365 /wd4244 /EHsc main.cpp

void csv_interp_query(const char *csvFileName, double current_time, double const *pValueArray[], unsigned int sizeArray)
{

}

int main(){
	double start_time = clock()*1000.0/CLOCKS_PER_SEC;
	io::CSVReader<5> in("D:\\csvData_short.csv");
	
	in.read_header(io::ignore_extra_column, "time", "sin_t_pi_14", "cos_t_pi_14");
	
	double time;
	double sin_t_pi_14, cos_t_pi_14;

	double time_pre = -1;
	double sin_t_pi_14_pre = 0, cos_t_pi_14_pre = 0;

	double sim_time;	

	double sin_value_pi_14 = 0.0;
	double cos_value_pi_14 = 0.0;

	if(!in.read_row(time, sin_t_pi_14, cos_t_pi_14))
	{
		time_pre = time;
	}

	for (int i = 0; i<221; i++)
	{	
		sim_time = i*0.5;
		
		while(sim_time - time>FLT_EPSILON && time - time_pre>FLT_EPSILON){
			time_pre = time;
			sin_t_pi_14_pre = sin_t_pi_14;
			cos_t_pi_14_pre = cos_t_pi_14;

			if(!in.read_row(time, sin_t_pi_14, cos_t_pi_14))
			{
				time_pre = time;
			}
		}

		if(fabs(time - time_pre)>FLT_EPSILON)
		{
			sin_value_pi_14 = sin_t_pi_14_pre + (sin_t_pi_14 - sin_t_pi_14_pre)/(time - time_pre)*(sim_time - time_pre);
			cos_value_pi_14 = cos_t_pi_14_pre + (cos_t_pi_14 - cos_t_pi_14_pre)/(time - time_pre)*(sim_time - time_pre);
		}
		else
		{
			sin_value_pi_14 = sin_t_pi_14;
			cos_value_pi_14 = cos_t_pi_14;
		}

		double current_time = clock()*1000.0/CLOCKS_PER_SEC;
		fprintf(stdout, "simulation time:%lf\t\t run time:%lf\t\tsine value:%lf\t\tcosine value:%lf\n", 
						sim_time, 
						(current_time - start_time)*1.0e-3,
						sin_value_pi_14, 
						cos_value_pi_14);
	}
}