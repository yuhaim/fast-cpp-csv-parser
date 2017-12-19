#define _CRT_SECURE_NO_WARNINGS
//#define CSV_IO_NO_THREAD
#include "csv.h"
#include <cstdio>
#include <ctime>

#define CSV_QUERY_FILE_PATH "D:\\csvData_short.csv"
#define CSV_QUERY_NUM_COLS 3
#define CSV_QUERY_TITLE_LIST "time", "sin_t_pi_14", "cos_t_pi_14"
#define CSV_QUERY_VAR_LIST values[0], values[1]

static double time_init;
static double time_now;
static double values[CSV_QUERY_NUM_COLS];
io::CSVReader<CSV_QUERY_NUM_COLS> csv(CSV_QUERY_FILE_PATH);

void csv_init(void)
{
	csv.read_header(io::ignore_extra_column, CSV_QUERY_TITLE_LIST);

	if(!csv.read_row(time_now, CSV_QUERY_VAR_LIST))
	{
		fprintf(stderr, "ERROR: Empty data block csv %s\n", CSV_QUERY_FILE_PATH);
		exit(EXIT_FAILURE);
	}

	time_init = time_now;
}

const double *csv_query(double sim_time)
{
	static double time_pre = -1.0;
	static double values_pre[CSV_QUERY_NUM_COLS];
	static double results[CSV_QUERY_NUM_COLS];

	while(sim_time - time_now>FLT_EPSILON && time_now - time_pre>FLT_EPSILON)
	{
		time_pre = time_now;
		for(int j=0; j<CSV_QUERY_NUM_COLS-1; j++)
		{
			values_pre[j] = values[j];
		}

		csv.read_row(time_now, CSV_QUERY_VAR_LIST);

		if(!(time_now - time_pre>FLT_EPSILON))
		{
			fprintf(stdout, "WARNING: Duplicated/desending/end of data lines csv %s, holding last valid values\n", CSV_QUERY_FILE_PATH);
		}
	}

	if(time_now - time_pre>FLT_EPSILON && sim_time - time_init>FLT_EPSILON)
	{
		double ratio = (sim_time - time_pre)/(time_now - time_pre);
		for(int j=0; j<CSV_QUERY_NUM_COLS-1; j++)
		{
			results[j] = values_pre[j] + (values[j] - values_pre[j])*ratio;
		}
	}
	else
	{
		for(int j=0; j<CSV_QUERY_NUM_COLS-1; j++)
		{
			results[j] = values[j];
		}
	}

	return results;
}


int main()
{
	double start_time = clock()*1000.0/CLOCKS_PER_SEC;
	
	csv_init();

	for (int i = 0; i<221; i++)
	{	
		double sim_time = i*0.5;
		
		const double *results = csv_query(sim_time);

		double current_time = clock()*1000.0/CLOCKS_PER_SEC;
		fprintf(stdout, "simulation time_now:%lf\t\t run time_now:%lf\t\tsine value:%lf\t\tcosine value:%lf\n", 
						sim_time, 
						(current_time - start_time)*1.0e-3,
						results[0], 
						results[1]);
	}
}