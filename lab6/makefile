CC = gcc

range: lab6.o get_range_count.o
	cc -o range lab6.o get_range_count.o

lab6.o: lab6.c lab6.h
	cc -c -std=c99 lab6.c

get_range_count.o: get_range_count.c lab6.h
	cc -c -std=c99 get_range_count.c
