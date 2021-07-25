#!/bin/sh
if [ $1 = "cpp" ]; then
  g++ ./cpp/source.cpp -o ./cpp/run.out -std=gnu++17 -Wall -Wextra -DLOCAL_DEBUG=1 && ./cpp/run.out
elif [ $1 = "python" ]; then
  python3 ./python/source.py
else
  echo "Unknown or empty argument"
fi
