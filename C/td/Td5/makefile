CC =gcc
CFLAG = -Wall

prog: main.o tp_struct_alloc.o
	$(CC) $(CLFAG) main.o tp_struct_alloc.o -o prog

main.o: main.c bibli.h tp_struct.h
	$(CC) $(CLFAG) -c main.c

tp_struct_alloc.o: tp_struct_alloc.c bibli.h tp_struct.h
	$(CC) $(CLFAG) -c tp_struct_alloc.c

clean:
	rm -rf *.o
