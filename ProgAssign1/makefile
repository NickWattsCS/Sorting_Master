sort: sort.o insertion_sort.o merge_sort.o heap_sort.o counting_sort.o quicksort.o radix_sort.o bucket_sort.o
	g++ -std=c++11 -o sort sort.o insertion_sort.o merge_sort.o heap_sort.o counting_sort.o quicksort.o radix_sort.o bucket_sort.o

sort.o: sort.cpp insertion_sort.h merge_sort.h heap_sort.h counting_sort.h quicksort.h radix_sort.h bucket_sort.h
	g++ -std=c++11 -c sort.cpp

bucket_sort.o: bucket_sort.cpp bucket_sort.h
	g++ -std=c++11 -c bucket_sort.cpp

radix_sort.o: radix_sort.cpp radix_sort.h
	g++ -std=c++11 -c radix_sort.cpp

quicksort.o: quicksort.cpp quicksort.h
	g++ -std=c++11 -c quicksort.cpp

counting_sort.o: counting_sort.cpp counting_sort.h
	g++ -std=c++11 -c counting_sort.cpp

heap_sort.o: heap_sort.cpp heap_sort.h
	g++ -std=c++11 -c heap_sort.cpp

merge_sort.o: merge_sort.cpp merge_sort.h
	g++ -std=c++11 -c merge_sort.cpp

insertion_sort.o: insertion_sort.cpp insertion_sort.h
	g++ -std=c++11 -c insertion_sort.cpp

clean:
	rm *.o sort
