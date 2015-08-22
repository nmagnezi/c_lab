#!/bin/sh

# helper script to remake the whole program.
rm assembler
find . -name "*.ext" -type f -delete
find . -name "*.ent" -type f -delete
find . -name "*.obj" -type f -delete
find . -name "*.o" -type f -delete
make
