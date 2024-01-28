#!/usr/bin/env bash
# Factorize as many numbers as possible into a product of two smaller numbers.

while IFS= read -r LINE
do
	for ((DIV = 2; DIV <= LINE; DIV++))
	do
		if ((LINE % DIV == 0)); then
			COUNT=$((LINE / DIV))
			echo "$LINE=$COUNT*$DIV"
			break
		fi
	done
done < "$1"
