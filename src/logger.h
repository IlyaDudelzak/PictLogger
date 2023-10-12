#pragma once

#include <iostream>
#include <fstream>
#include <ctime>

#define startStr "Started Pict Logger"
#define version "0.0.1"

using namespace std;
class logger{
private:
  ofstream f, ff;
  bool opened;
  bool print = true;
public:
  logger();
  logger(char*);
  string getTime();
  void log(string);
  void log(char*);
  void close();
  void close(int);
};

extern "C"{
    void start();
    void startp(char*);
    void logt(char*);
    void closel();
    void closec(int);
}