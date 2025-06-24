#!/bin/bash

mkdir -p build
cd build
cmake -DBUILD_TESTS=ON ..
make test_wordle
./test_wordle


