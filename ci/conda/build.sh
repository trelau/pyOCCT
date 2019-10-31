#!/usr/bin/env bash
mkdir -f build
cd build

# export CC=gcc-4.9
# export CXX=g++-4.9

cmake .. -G "Ninja" \
    -DCMAKE_BUILD_TYPE="Release" \
    -DENABLE_SMESH=OFF \
    -DENABLE_NETGEN=OFF \
    -DENABLE_FORCE=OFF \
    -DTBB_INCLUDE_DIR=$PREFIX/include

ninja install

cd ..
python setup.py install
