#!/usr/bin/env bash

# Fail on error
set -e

rm -Rf build
mkdir build
cd build

cmake .. -G "Ninja" \
    -DCMAKE_BUILD_TYPE="Release"

ninja -j1 install

cd ..
python setup.py install --prefix="$PREFIX"
