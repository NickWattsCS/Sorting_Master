programs=("-i" "-m" "-h" "-q" "-c" "-r" "-b")
for flag in ${programs[@]}
do
	echo $flag
	for num in {1..1000}
	do
		./sort $flag --size 1000
	done
done
