#!/bin/bash

mkdir -p build
cd build
cmake -DBUILD_TESTS=OFF ..
make wordle



