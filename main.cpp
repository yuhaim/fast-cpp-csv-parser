#define _CRT_SECURE_NO_WARNINGS
#define CSV_IO_NO_THREAD
#include "csv.h"
#include <iostream>
using namespace std;

//cl /Wall /wd4514 /wd4820 /wd4365 /wd4244 /EHsc main.cpp

int main(){
  io::CSVReader<4> in("ram.csv");
  in.read_header(io::ignore_extra_column, "time", "y1", "y2", "y3");
  double time, y1, y2, y3;
  while(in.read_row(time, y1, y2, y3)){
    // do stuff with the data
    cout<<time<<'\t'<<y1<<'\t'<<y2<<'\t'<<y3<<'\n';
  }
}