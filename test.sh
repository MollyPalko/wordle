#!/bin/bash

mkdir -p build
cd build
cmake -DBUILD_TESTS=ON ..
make wordle_tests
./wordle_tests



