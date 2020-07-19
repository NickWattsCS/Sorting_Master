graphs:
	python3 ./graphs.py

test:
	./bin/test.sh

clean:
	rm ./tmp/*.o ./bin/sort

sort.o: ./src/sort.cpp ./src/insertion_sort.h ./src/merge_sort.h ./src/heap_sort.h ./src/counting_sort.h ./src/quicksort.h ./src/radix_sort.h ./src/bucket_sort.h
	g++ -std=c++11 -c ./src/sort.cpp
	mv sort.o ./tmp

bucket_sort.o: ./src/bucket_sort.cpp ./src/bucket_sort.h
	g++ -std=c++11 -c ./src/bucket_sort.cpp
	mv bucket_sort.o ./tmp

radix_sort.o: ./src/radix_sort.cpp ./src/radix_sort.h
	g++ -std=c++11 -c ./src/radix_sort.cpp
	mv radix_sort.o ./tmp

quicksort.o: ./src/quicksort.cpp ./src/quicksort.h
	g++ -std=c++11 -c ./src/quicksort.cpp
	mv quicksort.o ./tmp

counting_sort.o: ./src/counting_sort.cpp ./src/counting_sort.h
	g++ -std=c++11 -c ./src/counting_sort.cpp
	mv counting_sort.o ./tmp

heap_sort.o: ./src/heap_sort.cpp ./src/heap_sort.h
	g++ -std=c++11 -c ./src/heap_sort.cpp
	mv heap_sort.o ./tmp

merge_sort.o: ./src/merge_sort.cpp ./src/merge_sort.h
	g++ -std=c++11 -c ./src/merge_sort.cpp
	mv merge_sort.o ./tmp

insertion_sort.o: ./src/insertion_sort.cpp ./src/insertion_sort.h
	g++ -std=c++11 -c ./src/insertion_sort.cpp
	mv insertion_sort.o ./tmp

sort: ./tmp/sort.o ./tmp/insertion_sort.o ./tmp/merge_sort.o ./tmp/heap_sort.o ./tmp/counting_sort.o ./tmp/quicksort.o ./tmp/radix_sort.o ./tmp/bucket_sort.o
	g++ -std=c++11 -o sort ./tmp/sort.o ./tmp/insertion_sort.o ./tmp/merge_sort.o ./tmp/heap_sort.o ./tmp/counting_sort.o ./tmp/quicksort.o ./tmp/radix_sort.o ./tmp/bucket_sort.o
	mv ./sort ./bin

