all:myplay wstd rwstd

clean: 
	rm -vf myplay wstd rwstd

CCFLAGS=-O -Wall


myplay: myplay.c sample.h
	g++ ${CCFLAGS} -o myplay myplay.c

write: wstd.cpp
	g++ ${CCFLAGS} -o wstd wstd.cpp

rwrite: rwstd.cpp
	g++ ${CCFLAGS} -o rwstd rwstd.cpp