#!/usr/bin/env bash

# Fail on error
set -e

python binder/generate/run.py

rm -Rf build
mkdir build
cd build

cmake .. -G "Ninja" \
    -DCMAKE_BUILD_TYPE="Release" \
    -DENABLE_SMESH=OFF \
    -DENABLE_NETGEN=OFF \
    -DENABLE_FORCE=OFF

ninja install

cd ..
python setup.py install --prefix="$PREFIX"
