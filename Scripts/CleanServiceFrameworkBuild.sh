#!/bin/bash

BLD_PATH=$PWD/../$1/bld

echo "Cleaning ServiceFramework build for: ${1}"

if [ -d ${BLD_PATH} ]
then 
  cd ${BLD_PATH}
  
  rm -rf *
  echo "Build directory contents after clean:"
  ls
  
else
  echo "Invalid build directory: ${BLD_PATH}"
fi

exit