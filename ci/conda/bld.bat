mkdir build
cd build

cmake .. -G "Ninja" ^
    -DCMAKE_BUILD_TYPE="Release" ^
    -DENABLE_SMESH=OFF ^
    -DENABLE_NETGEN=OFF

if errorlevel 1 exit 1
ninja install
if errorlevel 1 exit 1

cd ..
python setup.py install
