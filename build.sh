#! /bin/bash

g++ -fPIC -shared -s -w -Werror -o bin/logger.so src/logger.cpp
g++ -fPIC -shared -s -w -Werror -I/usr/include/python3.10 -lpython3.10 -o python_library/pictlogger/pictlogger.so src/python.cpp
g++ -s -w -Werror -o examples/exampleCpp examples/exampleCpp.cpp 