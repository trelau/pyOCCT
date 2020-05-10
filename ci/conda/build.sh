#!/usr/bin/env bash

# Fail on error
set -e

rm -Rf build
mkdir build
cd build

cmake .. -G "Ninja" \
    -DCMAKE_BUILD_TYPE="Release" \
    -DPTHREAD_INCLUDE_DIRS="$PREFIX"

ninja install

cd ..
python setup.py install --prefix="$PREFIX"
