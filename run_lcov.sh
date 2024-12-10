#!/bin/bash

cd ./build
./app.exe -test # Run the test at least once to generate the .gcda file
cd CMakeFiles/app.exe.dir
gcov main.cpp.gcno
lcov --capture --directory . --output-file gtest_coverage.info
lcov --remove gtest_coverage.info '/usr/include/*' 'cg_cp/build/*' -o gtest_coverage.info # !!
genhtml gtest_coverage.info --output-directory CODE_COVERAGE
cd CODE_COVERAGE\


# build/CMakeFiles/app.exe.dir/CODE_COVERAGE/index.html