mkdir build
cd build

cmake .. -G "Ninja" ^
    -DCMAKE_BUILD_TYPE="Release" ^
    -DENABLE_SMESH=OFF ^
    -DENABLE_NETGEN=OFF ^
    -DENABLE_FORCE=ON ^
    -TBB_INCLUDE_DIR="%LIBRARY_PREFIX%"/include

if errorlevel 1 exit 1
ninja install
if errorlevel 1 exit 1

cd ..
python setup.py install
