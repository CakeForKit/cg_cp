#!/bin/bash

cmake -S .. && cmake --build .


# valgrind --leak-check=yes ./app.exe
