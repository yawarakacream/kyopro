#!/bin/sh
if [ $1 = "cpp" ]; then
  g++ source.cpp -o cpp_run.out -std=gnu++17 -Wall -Wextra -DLOCAL_DBG=1
  ./cpp_run.out
elif [ $1 = "python" ]; then
  python3 source.py
else
  echo "Unknown or empty argument"
fi
