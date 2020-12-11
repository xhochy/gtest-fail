#!/bin/bash

set -exuo pipefail

rm -rf build
mkdir build
pushd build
cmake -GNinja ..
ninja
./test
