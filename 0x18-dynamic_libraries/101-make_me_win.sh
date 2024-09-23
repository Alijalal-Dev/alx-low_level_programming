#!/bin/bash
wget -q -O /tmp/libwin.so https://github.com/Alijalal-Dev/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libwin.so
export LD_PRELOAD=/tmp/libwin.so
