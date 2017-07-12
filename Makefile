.PHONY : all clean run new

MPIROOT = /usr

CFLAGS+= -Wall -g $(INCL)
CC=gcc
MPICC=  $(MPIROOT)/local/bin/mpic++
INCL= -I$(MPIROOT)/include
SRCS= consola.cpp main.cpp nodo.cpp HashMap.cpp base.cpp
BIN= dist_hashmap

all: dist_hashmap

$(BIN): $(SRCS)
	$(MPICC) $(CFLAGS) -o $(BIN) $(SRCS)
test-1-run: 
	awk -f corpus.awk corpus | sort >corpus-post
	cat test-1.txt | mpiexec -np 2 ./dist_hashmap | sort | diff -u - corpus-post
	rm -f corpus-post
test-2-run: 
	awk -f corpus.awk corpus | sort >corpus-post
	for i in 0 1 2 3 4; do sed -n "$$((i * 500 + 1)),$$(((i + 1) * 500))p" corpus >corpus-"$$i"; done
	for i in 1 2 3 4 5; do cat test-2.txt | mpiexec -np $$((i + 1)) ./dist_hashmap | sort | diff -u - corpus-post; done
	rm -f corpus-post corpus-[0-4]

test-3-run: 
	awk -f corpus.awk corpus | sort -nk 2 | tail -n 1 >corpus-max
	cat corpus-max
	for i in 0 1 2 3 4; do sed -n "$$((i * 500 + 1)),$$(((i + 1) * 500))p" corpus >corpus-"$$i"; done
	for i in 1 2 3 4 5; do cat test-3.txt | mpiexec -np $$((i + 1)) ./dist_hashmap | sort | diff -u - corpus-max; done
	rm -f corpus-max corpus-[0-4]
clean:
	rm -f $(BIN)
	rm -f *.log

new: clean all
