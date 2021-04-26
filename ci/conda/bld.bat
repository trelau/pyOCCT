mkdir build
cd build

cmake -G "Ninja" ^
  -DCMAKE_BUILD_TYPE="Release" ^
  -DPython_FIND_VIRTUALENV=ONLY ^
  ..

if errorlevel 1 exit 1

ninja -j1
if errorlevel 1 exit 1

ninja install
if errorlevel 1 exit 1

cd ..
python setup.py install --prefix=%PREFIX%
