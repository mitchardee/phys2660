#!/bin/bash

# File: make.sh used to build sample phys 2660 library and a test program

if [ "$1" == "clean" ]
then
    rm -vf *.a test1 test2 test3 *.pdf *.exe *.dat
    exit
fi

# The -g flag used below generates information for the debugger

# build code for libraries
g++ -Wall -c -g hist.cpp
g++ -Wall -c -g random.cpp

g++ -Wall -c -g hist2.cpp
g++ -Wall -c -g random2.cpp

#create the library
ar -csr libp2660.a hist.o random.o
ar -csr libp2660_2.a hist2.o random.o
ar -csr libp2660_3.a hist.o random2.o

#clean up, we no longer need the object files
rm -f hist*.o random*.o

#build the test program
# -L. defines a new directory to look for library files
#     in this case "." or the current directory
#     normally the compiler looks in /usr/lib, etc...
#     to find the libraries it needs
# -lp2660 means we must link w/ the library called libp2660.a
#     to get the code for our custom functions
g++ -Wall -g test.cpp -o test1 -L. -lp2660
g++ -Wall -g test.cpp -o test2 -L. -lp2660_2
g++ -Wall -g test.cpp -o test3 -L. -lp2660_3



