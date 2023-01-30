#!/bin/bash
for i in {1..200}
do
    shuf -i1-5 | xargs ./push_swap | wc -l
done
