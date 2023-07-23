#!/bin/bash

/bin/bash CleanServiceFrameworkBuild.sh ${1}

echo "Building ServiceFramework for: ${1}"

BLD_PATH=${PWD}/../$1/bld

if [ -d ${BLD_PATH} ]
then 
  cd ${BLD_PATH}

  cmake .. && make
  echo "Build directory contents after build:"
  ls
  
else
  echo "Invalid build directory: ${BLD_PATH}"
fi

exit