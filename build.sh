#! /bin/bash

g++ -fPIC -shared -s -w -Werror -o bin/logger.so src/logger.cpp
g++ -fPIC -shared -s -w -Werror -I/usr/include/python3.10 -lpython3.10 -o bin/pictlogger_py.so src/python.cpp