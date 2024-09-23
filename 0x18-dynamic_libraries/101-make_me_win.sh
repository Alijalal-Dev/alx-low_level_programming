#!/bin/bash
wget -q -O /tmp/libgiga.so https://github.com/Alijalal-Dev/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libgiga.so
export LD_PRELOAD=/tmp/libgiga.so
