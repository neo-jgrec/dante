#!/bin/bash
# Generator tester Script by @jgreclevrai

# Test folder
mkdir -p tests

# # Makefile actions in silent mode if generator binary doesn't exist
if [ ! -f generator ] ; then
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
    file_name=$(echo $test | sed 's/ /_/g')
    ./generator $test &> tests/$file_name\
    && echo -e "\e[32m[OK]\e[0m \`$test\`"\
    || (echo -e "\e[31m[KO]\e[0m \`$test\`" && rm -f tests/$file_name)
done
