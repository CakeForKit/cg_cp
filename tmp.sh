#!/bin/bash

g++ tmp.cpp -o ./tmp.exe # -lGL -lglut -lGLEW
./tmp.exe
# g++ --std=c++20 -c tmp.cpp -lglut -lGL -lGLEW -lGLU -lglfw -lglm 
# g++ --std=c++20 tmp.o -o ./tmp.exe