#!/bin/bash
rm file1.csv
for i in {1..20000}
do
    shuf -i0-99 | xargs ./push_swap | wc -l >> file1.csv
done
