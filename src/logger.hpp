#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <ctime>

#define version "0.1"

using namespace std;

size_t until(char* bytes, char t){
    for(int i = 0;; i++) {
        if(bytes[i] == t) return i;
    }
}

bool comp(char* a, char* b){
    size_t len;
    len = strlen(a);
    if(len != strlen(b)) return false;
    for(int i = 0; i < len; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}
class logstr{
private:
    time_t t;
    char text[256];
    char sender[64];
public:
    logstr(char* send, char* txt){
        strcpy(text, txt);
        strcpy(sender, send);
        time(&this->t);
    }
    string tostring(){
        std::string out = "";
        struct tm* tt;
        tt = localtime(&t);
        string ti = asctime(tt);
        ti.pop_back();
        out += ti;
        out += " ";
        out += sender;
        out += ": ";
        out += text;
        out += '\n';
        return out;
    } 
};

using namespace std;
class logger{
private:
  ofstream f, ff;
  bool started  = false;
  bool print = true;
public:
  logger(bool);
  string getTime();
  void log(logstr);
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