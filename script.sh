#!/bin/bash


if [[ -z "${OTT_ROOT}" ]]; then
    echo "OTT_ROOT is undefined"
    exit 1
fi


echo "OTT_ROOT is defined"

if [ -e "build" ]; then
    echo "build dir is exist"
else
    mkdir -p build
fi


pushd build

cmake ..
make -j4




