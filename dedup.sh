#!/bin/sh
rm -f README.txt
for i in id*
do
	~/AFLplusplus/afl-tmin -i $i -o $i -t1000 $*
done
mkdir -p ../dedup
for i in id*
do
	if [ -r $i ]
	then
		mv $i ../dedup
		for j in id* 
		do
			if diff -aq ../dedup/$i $j
			then
				rm $j
			fi
		done
	fi
done
