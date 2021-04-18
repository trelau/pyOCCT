#!/usr/bin/env bash

declare -a CMAKE_PLATFORM_FLAGS
CMAKE_PLATFORM_FLAGS+=(-DCMAKE_TOOLCHAIN_FILE="${RECIPE_DIR}/cross-linux.cmake")

# Fail on error
set -e

rm -Rf build
mkdir build
cd build

cmake -G "Ninja" \
      -DCMAKE_BUILD_TYPE="Release" \
      -DPYBIND11_FINDPYTHON=ON \
      ${CMAKE_PLATFORM_FLAGS[@]} \
      ..

ninja -j1 install

cd ..
python setup.py install --prefix="$PREFIX"
