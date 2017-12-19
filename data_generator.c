#include <stdio.h>
#include <math.h>

int main(void)
{
    const char *dataFileName = "D:\\csvData_short.csv";
    const int dataLength = 101;
    //const int dataLength = 10000;
    double pi = 2.0*acos(0.0);
    double t;
    int i, j, k;

    FILE *dataFile = fopen(dataFileName, "w");

    fprintf(dataFile, "time,    "
                        "sin_t_pi_2,cos_t_pi_2,sin_t_pi_4,cos_t_pi_4,\t"
                        "sin_t_pi_6,cos_t_pi_6,sin_t_pi_8,cos_t_pi_8,\t"
                        "sin_t_pi_10,cos_t_pi_10,sin_t_pi_12,cos_t_pi_12,\t"
                        "sin_t_pi_14,cos_t_pi_14,sin_t_pi_16,cos_t_pi_16,\t"
                        "sin_t_pi_18,cos_t_pi_18,sin_t_pi_20,cos_t_pi_20,\t"
                        "sin_t_pi_22,cos_t_pi_22,sin_t_pi_24,cos_t_pi_24,\t"
                        "sin_t_pi_26,cos_t_pi_26,sin_t_pi_28,cos_t_pi_28,\t"
                        "sin_t_pi_30,cos_t_pi_30,sin_t_pi_32,cos_t_pi_32\n");

    for(i=0, j=0, k=0; i<dataLength; i++, j++)
    {
        t = (double)i;
        fprintf(dataFile, "%d,    "
                            "%lf,%lf,%lf,%lf,\t"
                            "%lf,%lf,%lf,%lf,\t"
                            "%lf,%lf,%lf,%lf,\t"
                            "%lf,%lf,%lf,%lf,\t"
                            "%lf,%lf,%lf,%lf,\t"
                            "%lf,%lf,%lf,%lf,\t"
                            "%lf,%lf,%lf,%lf,\t"
                            "%lf,%lf,%lf,%lf\n",
                            i,
                            sin(t*pi/2.0), cos(t*pi/2.0), sin(t*pi/4.0), cos(t*pi/4.0),
                            sin(t*pi/6.0), cos(t*pi/6.0), sin(t*pi/8.0), cos(t*pi/8.0),
                            sin(t*pi/10.0), cos(t*pi/10.0), sin(t*pi/12.0), cos(t*pi/12.0),
                            sin(t*pi/14.0), cos(t*pi/14.0), sin(t*pi/16.0), cos(t*pi/16.0),
                            sin(t*pi/18.0), cos(t*pi/18.0), sin(t*pi/20.0), cos(t*pi/20.0),
                            sin(t*pi/22.0), cos(t*pi/22.0), sin(t*pi/24.0), cos(t*pi/24.0),
                            sin(t*pi/26.0), cos(t*pi/26.0), sin(t*pi/28.0), cos(t*pi/28.0),
                            sin(t*pi/30.0), cos(t*pi/30.0), sin(t*pi/32.0), cos(t*pi/32.0));

        if(j == dataLength/100)
        {
            j = 0;
            k++;
            fprintf(stdout, "%d%% writen to %s \n", k, dataFileName);
        }
    }

    fclose(dataFile);
    return 0;
}