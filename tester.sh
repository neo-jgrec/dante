#!/bin/bash
# Generator tester Script by @jgreclevrai

# Trace file if fail
name_file_fail=$(echo trace $(date +%s%N).txt | sed 's/ //g')

# Check if generator and solver binaries exist
if [ ! -f generator/generator ] ; then
    echo "Error: generator binary not found"
    exit 1
fi
if [ ! -f solver/solver ] ; then
    echo "Error: solver binary not found"
    exit 1
fi

# Execute map_gen script
echo -e "\e[34m[MAPS GENERATOR]\e[0m"
./generator/maps_gen.sh
echo -e "\e[34m[MAPS GENERATOR]\e[0m \e[32m[OK]\e[0m\n"

# False maps
no_map="maps/no_map"
touch $no_map

wrong_char="maps/wrong_char"
touch $wrong_char
echo "1 1" > $wrong_char

unsolvable="maps/unsolvable"
touch $unsolvable
echo -e "XXX\nX*X\nXXX" > $unsolvable

echo -e "\e[34m[MAPS SOLVER]\e[0m"

array_tests=$(find maps -type f -name "*" | sort -V)

for test in $array_tests ; do
    time_start=$(date +%s%N)
    ./solver/solver $test > $name_file_fail 2>&1
    if [ $(cat $name_file_fail | grep -q "no solution found" && echo "1" || echo "0") -eq 1 ] ; then
        echo -e "\e[31m[KO]\e[0m \`$test\`"
    else
        echo -e "\e[32m[OK]\e[0m \`$test\`"
    fi
    rm -f $name_file_fail
done

echo -e "\e[34m[MAPS SOLVER]\e[0m \e[32m[OK]\e[0m"
