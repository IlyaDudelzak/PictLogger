#include <stdio.h> 
#include <stdlib.h> 
#include <dlfcn.h>
 
 
int main() { 
  typedef void (*t_1)();
  typedef void (*t_2)(char*); 
  typedef void (*t_3)(int); 
 
  //We open the shared object 
  void* dlh = dlopen("./logger.so", RTLD_LAZY); 
  if (dlh == NULL) { 
    fprintf(stderr, "%s", dlerror()); 
    exit(1); 
  } 
 
  //We resolve the function symbol to use 
  t_1 start = (t_1)dlsym(dlh, "start"); 
  t_2 log = (t_2)dlsym(dlh, "log"); 
  t_3 close = (t_3)dlsym(dlh, "closec"); 
 
  start();
  log("Test logging");
  close(0);
  return 0;
}
