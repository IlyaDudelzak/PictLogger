#include "logger.hpp"

using namespace std;

logger::logger(bool print = true){
    string path = "./logs/log_" + getTime() + ".log";
    f.open(path.c_str());
    ff.open("./logs/latest.log");
    if(print) log(logstr("Pictlogger", "Started"));
    if(print) log(logstr("PictLogger", (char*)((string("Version: ") + version).c_str())));
    if(!f.is_open()) log(("Error opening file " + path).c_str()); 
    if(!ff.is_open()) log("Error opening file ./logs/latest.log"); 
    this->print = print;
    started = true;
}
string logger::getTime(){
    time_t t;
    struct tm* tt;
    time(&t);
    tt = localtime(&t);
    string ti;
    ti = asctime(tt);
    ti.pop_back();
    return ti;
}
void logger::log(logstr text){
    string t = text.tostring();
    f << t;
    ff << t;
    if(print) cout << t;
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
    log(logstr("PictLogger", "Exit"));
    f.close();
    ff.close();

    delete this;
}
void logger::close(int code){
	  string text = "Exit with exit code: ";
	  if(code == 0) text += "0 (Success)";
	  else if(code == 1) text += "1 (Error)";
    else text += "Unknown";

    log(logstr("PictLogger", (char*)text.c_str()));
    f.close();
    ff.close();

    delete this;
}

logger* logg;

void startarg(bool a = false){
  logg = new logger(a);
}
//void start(){
  // logg = new logger();
// }
void logt(char* text){
  logg->log(text);
}
void logl(logstr text){
  logg->log(text);
}
void closel(){
  logg->close();
}
void closec(int code){
  logg->close(code);
}