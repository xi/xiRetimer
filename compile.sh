#!/bin/bash
aclocal
autoconf
./configure
make
make clean
rm -rf aclocal.m4 autom4te.cache config.log config.status
