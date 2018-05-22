mkdir build
cd build

# export CC=gcc-4.9
# export CXX=g++-4.9

cmake .. -G "Ninja" \
    -DCMAKE_BUILD_TYPE="Release" \
    -DPTHREAD_INCLUDE_DIRS=${PREFIX} \
    -DENABLE_SMESH=ON \
    -DENABLE_NETGEN=ON \
    -DENABLE_BLSURF=OFF \
    -DENABLE_FORCE=OFF \
    -DENABLE_WARNINGS=OFF \
    -DTEST_BUILD=OFF

ninja install

cd ..
${PYTHON} setup.py install
