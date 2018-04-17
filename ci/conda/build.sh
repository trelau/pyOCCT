mkdir build
cd build

#    -DPTHREAD_INCLUDE_DIRS:FILEPATH="%LIBRARY_PREFIX%/include" \

cmake .. -G "Ninja" \
    -DCMAKE_BUILD_TYPE="Release" \
    -DENABLE_SMESH=OFF \
    -DENABLE_NETGEN=OFF \
    -DENABLE_BLSURF=OFF \
    -DENABLE_FORCE=OFF \
    -DENABLE_WARNINGS=OFF \
    -DTEST_BUILD=ON

export NINJA_STATUS="[%f/%t(%r)] "

ninja install

cd ..
$PYTHON setup.py install


