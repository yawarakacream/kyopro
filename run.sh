#!/bin/sh
if [ $1 = "cpp" ]; then
  g++ source.cpp -o cpp_run.out -DDBG=1
  ./cpp_run.out
elif [ $1 = "python" ]; then
  python3 source.py
else
  echo "Unknown or empty argument"
fi
