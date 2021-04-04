#!/usr/bin/env bash

declare -a CMAKE_PLATFORM_FLAGS
if [[ ${HOST} =~ .*linux.* ]]; then
    CMAKE_PLATFORM_FLAGS+=(-DCMAKE_TOOLCHAIN_FILE="${RECIPE_DIR}/cross-linux.cmake")
fi

# Fail on error
set -e

rm -Rf build
mkdir build
cd build

cmake .. -G "Ninja" \
    ${CMAKE_PLATFORM_FLAGS[@]} \
    -DCMAKE_BUILD_TYPE="Release"

ninja -j1 install

cd ..
python setup.py install --prefix="$PREFIX"
