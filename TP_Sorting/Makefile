CC=gcc -O3 -march=native -mtune=native -std=c99

DEPS = hw4.h
OBJS = insertion_sort.o selection_sort.o quick_sort.o merge_sort.o utils.o hw4.o

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@

main: $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm *.o main perf.txt
