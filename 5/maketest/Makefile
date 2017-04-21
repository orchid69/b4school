CC = gcc
OBJS = mat_cal.o q1.o

.SUFFIXES: .c .o

main: $(OBJS)
	$(CC) -o $@ $^

%o: %c
	$(CC) -c $<

mat_cal.o: mat_cal.h

clean:
	rm main
	rm *.o
	rm -f *~
