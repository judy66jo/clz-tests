CC = gcc
CFLAGS = -O0  -std=gnu99 -Wall 
EXECUTABLE = \
	clz
	
default: clz_function.o
	$(CC) $(CFLAGS) clz_function.o main.c -DBASELINE -o clz

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	
gencsv: default
	for i in `seq 1 10000 3000000`; do \
		printf "%d," $$i;\
		./clz $$i; \
	done > result.csv

plot: gencsv
	gnuplot plot.gp
	
clean:
	$(RM) $(EXEC) *.o result.csv clz_time.png clz
