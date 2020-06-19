cd `dirname $0`
rm -rf build/*
cd build
cmake ..
make
cd -