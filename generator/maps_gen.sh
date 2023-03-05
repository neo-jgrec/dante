#!/bin/bash
# Generator tester Script by @jgreclevrai

# Test folder
folder=$(pwd | grep -q "generator" && echo "../maps" || echo "maps")
mkdir -p $folder && rm -f $folder/*

# Binary name can be generator or generator/generator or ../generator/generator
bin_name=$(pwd | grep -q "generator" && echo "./generator" || echo "generator/generator")
echo "Binary name: $bin_name"

# Makefile actions in silent mode if generator binary doesn't exist
if [ ! -f $bin_name ] ; then
    make re &> /dev/null
    make clean &> /dev/null
fi

array_test=(\
    "10 10 perfect" \
    "10 10" \
    "10000 10000" \
    "10000 10000 perfect" \
    "50 50 perfect" \
    "50 50" \
    "fail" \
    "10 10 perfect but its a fail" \
)

for test in "${array_test[@]}" ; do
    time_start=$(date +%s%N)
    file_name=$(echo $test | sed 's/ /_/g')
    $bin_name $test &> $folder/$file_name\
    && (echo -en "\e[32m[OK]\e[0m \`$test\`" && time_end=$(date +%s%N) && time_diff_sec=$(echo "scale=3; ($time_end - $time_start) / 1000000000" | bc) && echo -e " (\e[33m$time_diff_sec\e[0ms)")\
    || (echo -e "\e[31m[KO]\e[0m \`$test\` " && rm -f $folder/$file_name)
done
