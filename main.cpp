#define _CRT_SECURE_NO_WARNINGS
//#define CSV_IO_NO_THREAD
#include "csv.h"
#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

//cl /Wall /wd4514 /wd4820 /wd4365 /wd4244 /EHsc main.cpp

#define CSV_QUERY_FILE_PATH "D:\\csvData_short.csv"
#define CSV_QUERY_NUM_COLS 2
#define CSV_QUERY_TITLE_LIST "time", "sin_t_pi_14", "cos_t_pi_14"
#define CSV_QUERY_VAR_LIST values[0], values[1]

int main(){
	double start_time = clock()*1000.0/CLOCKS_PER_SEC;
	
	io::CSVReader<3> in(CSV_QUERY_FILE_PATH);
	in.read_header(io::ignore_extra_column, CSV_QUERY_TITLE_LIST);
	
	static double time;
	static double time_pre = -1.0;
	static double values[CSV_QUERY_NUM_COLS];
	static double values_pre[CSV_QUERY_NUM_COLS];
	static double results[CSV_QUERY_NUM_COLS];

	if(!in.read_row(time, CSV_QUERY_VAR_LIST))
	{
		fprintf(stderr, "ERROR: Empty data block in %s\n", CSV_QUERY_FILE_PATH);
		exit(EXIT_FAILURE);
	}

	static double time_init = time;

	for (int i = 0; i<221; i++)
	{	
		double sim_time = i*0.5;
		
		while(sim_time - time>FLT_EPSILON && time - time_pre>FLT_EPSILON)
		{
			time_pre = time;
			for(int j=0; j<CSV_QUERY_NUM_COLS; j++)
			{
				values_pre[j] = values[j];
			}

			in.read_row(time, CSV_QUERY_VAR_LIST);

			if(!(time - time_pre>FLT_EPSILON))
			{
				fprintf(stdout, "WARNING: Duplicated/desending/end of data lines in %s, holding last valid values\n", CSV_QUERY_FILE_PATH);
			}
		}

		if(time - time_pre>FLT_EPSILON && sim_time - time_init>FLT_EPSILON)
		{
			double ratio = (sim_time - time_pre)/(time - time_pre);
			for(int j=0; j<CSV_QUERY_NUM_COLS; j++)
			{
				results[j] = values_pre[j] + (values[j] - values_pre[j])*ratio;
			}
		}
		else
		{
			for(int j=0; j<CSV_QUERY_NUM_COLS; j++)
			{
				results[j] = values[j];
			}
		}

		double current_time = clock()*1000.0/CLOCKS_PER_SEC;
		fprintf(stdout, "simulation time:%lf\t\t run time:%lf\t\tsine value:%lf\t\tcosine value:%lf\n", 
						sim_time, 
						(current_time - start_time)*1.0e-3,
						results[0], 
						results[1]);
	}
}