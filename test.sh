#!/bin/bash

# Build executables if needed
make

# Define the number of times to repeat the task
k=25

# Loop k times
for ((i=1; i<=$k; i++))
do
    # Run the executables
    ./data
    ./analysis1
    ./analysis2
    ./analysis3
     
    echo 
    # Delete the file "testdata.txt"
    rm -f testdata.txt
done
