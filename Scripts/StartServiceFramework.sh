#!/bin/bash

BLD_PATH=$PWD/../${1}/bld

echo "Starting ServiceFramework for: ${1}"

if [ -d ${BLD_PATH} ]
then 
  cd ${BLD_PATH}
  
  xfce4-terminal -e 'bash -c "./ServiceFramework; bash"' -T "ServiceFramework" 
  
else
  echo "Invalid build directory: ${BLD_PATH}"
fi

exit