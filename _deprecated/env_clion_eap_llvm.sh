#!/bin/bash

cd /

# export LDFLAGS="-L/usr/local/opt/llvm/lib"

# -L /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib

export PATH=/usr/local/opt/llvm/bin:$PATH
export PATH=/usr/local/Cellar/cmake/3.27.7/bin:$PATH
export PATH=/usr/local/Cellar/llvm/17.0.3/lib/c++/:$PATH
#export PATH=/Users/felixberge/Downloads/SDL2.framework:$PATH
  #export PATH=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib:$PATH


# Read by compilers, linkers?
# https://llvm.org/docs/CommandGuide/llvm-config.html
#export LDFLAGS="-L /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib"
export LDFLAGS="-L/usr/opt/llvm/lib/c++ -Wl,-rpath,/usr/opt/llvm/lib/c++"
export ARCHFLAGS="x86_64"
export CPPFLAGS="-I/usr/local/opt/llvm/include"
export PKG_CONFIG_PATH="/usr/local/opt/llvm/lib/pkgconfig"

#-L /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib

# cmake -DCMAKE_CXX_COMPILER=/usr/local/opt/llvm/bin/clang++ ..
# make

# echo $PATH
# echo $(pwd)
cd /