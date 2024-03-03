gcc -c merge_sort.c -o merge_sort.o
gcc -c insertion_sort.c -o insertion_sort.o
gcc -c selection_sort.c -o selection_sort.o
gcc -c quick_sort.c -o quick_sort.o
gcc -c utils.c -o utils.o
gcc hw4.c merge_sort.o insertion_sort.o quick_sort.o selection_sort.o utils.o -o main -lm 
rm *.o
