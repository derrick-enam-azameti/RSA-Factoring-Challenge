#!/usr/bin/env bash
# Factorize as many numbers as possible into a product of two smaller numbers.

while IFS= read -r LINE
do
	FLAG=1
	DIV=2

	while ((FLAG == 1 && DIV * DIV <= LINE))
	do
		if ((LINE % DIV == 0)); then
			COUNT=$((LINE / DIV))
			echo "$LINE=$COUNT*$DIV"
			FLAG=0
		fi
		((DIV++))
	done
done < "$1"
