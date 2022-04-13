#!/bin/sh

# build the test program for the phys 2660 library
# -L defines a new directory to look for library files
#     in this case $P2660LIB
#     normally the compiler looks in /usr/lib, etc...
#     to find the libraries it needs
#
# -I defines a new directory to look for include files
#    in this case $P2660LIB
#    normally the compiler looks in /usr/include, the current directory, etc...
#    to find the header files it needs
#
# -lp2660 means we must link w/ the library called libp2660.a
#     to get the code for our custom functions
#      Note the syntax. The "lib" prefix is assumed to be part 
#            of the library's name
#
echo "Making test programs for C interface"
echo "building test_p2660"
g++ -O -Wall test_p2660.cpp -o test_p2660 -L$P2660LIB -I$P2660LIB -lp2660

echo "building test_h1"
g++ -g -Wall test_h1.cpp -o test_h1 -L$P2660LIB -I$P2660LIB -lp2660

echo "building test_h2"
g++ -O -Wall test_h2.cpp -o test_h2 -L$P2660LIB -I$P2660LIB -lp2660

echo "building test_s2"
# now using more compact variable to set all compiler flags
g++ -O -Wall test_s2.cpp -o test_s2 $P2660FLAGS
