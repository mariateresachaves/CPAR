#!/usr/bin/env bash

set -e

python -m compileall .

perf stat -e bus-cycles,cache-misses,cache-references,cpu-cycles,instructions,stalled-cycles-frontend -- python main.py 1 500 500 "$@"

perf stat -e bus-cycles,cache-misses,cache-references,cpu-cycles,instructions,stalled-cycles-frontend -- python main.py 1 500 500 "$@"
