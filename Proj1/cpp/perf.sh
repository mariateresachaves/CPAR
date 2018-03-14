#!/usr/bin/env bash

set -e

perf stat -e bus-cycles,cache-misses,cache-references,cpu-cycles,instructions,stalled-cycles-frontend ./bin/matrixmult 1 500 500 "$@"

perf stat -e bus-cycles,cache-misses,cache-references,cpu-cycles,instructions,stalled-cycles-frontend ./bin/matrixmult 2 500 500 "$@"
