#!/bin/bash
programs=("-i" "-m" "-h" "-q" "-c" "-r" "-b")
for flag in ${programs[@]}
do
	echo $flag
	for num in {1..1000}
	do
		./bin/sort $flag --size 100
	done
done
