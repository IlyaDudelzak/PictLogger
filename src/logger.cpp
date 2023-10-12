#include "logger.h"

using namespace std;

logger::logger(){
    string path = "./logs/log_" + getTime() + ".log";
    f.open(path.c_str());
    ff.open("./logs/latest.log");
    log(startStr);
    log(string("Version: ") + version);
    if(!f.is_open()) log(("Error opening file " + path).c_str()); 
    if(!ff.is_open()) log("Error opening file ./logs/latest.log"); 
}
logger::logger(char* path){
    f.open(path);
    ff.open("./logs/latest.log");
    log(startStr);
    log(string("Version: ") + version);
}
string logger::getTime(){
    time_t t;
    struct tm* tt;
    time(&t);
    tt = localtime(&t);
    string ti = asctime(tt);
    ti.pop_back();
    return ti;
}
void logger::log(string text){
    string t = getTime() + ": " + text + "\n";
    f << t;
    ff << t;
    if(print) cout << t;
}
void logger::log(char* text){
    string t = getTime() + ": " + text + "\n";
    f << t;
    ff << t;
    if(print) cout << t;
}
void logger::close(){
    log("Exit");
    f.close();
    ff.close();

    delete this;
}
void logger::close(int code){
	  string text = "Exit with exit code: ";
	  if(code == 0) text += "0 (Success)";
	  else if(code == 1) text += "1 (Error)";
    else text += "Unknown";

    log(text.c_str());
    f.close();
    ff.close();

    delete this;
}

logger* logg;

void start(){
  logg = new logger();
}
void startp(char* path){
  logg = new logger(path);
}
void logt(char* text){
  logg->log(text);
}
void closel(){
  logg->close();
}
void closec(int code){
  logg->close(code);
}