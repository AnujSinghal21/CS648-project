#!/bin/bash

# Define the array of different values of N
# N_values=(10 100 1000 10000 100000 1000000 10000000 100000000 10000000000)
N_values=(100000000)
# Define the number of repetitions for each N
# repetitions=(10000 1000 1000 1000 1000 1000 100 100 10)
repetitions=(1)

make all

# Run the algo for each N and write the output to observations.csv
printf "data, N, iteration ,algo1_answer, algo1_time, algo2_answer, algo2_time, algo3_answer, algo3_time, algo4_answer, algo4_time\n" > observations.csv

# on random datasets
# echo "Running on random datasets"
# for ((i=0; i<${#N_values[@]}; i++)); do
#     N=${N_values[i]}
#     echo "N = $N"
#     repetition=${repetitions[i]}
#     for ((j=0; j<repetition; j++)); do
#         echo "Iteration $j"
#         ./data $N 0
#         printf "random, $N, $j, " 
#         ./algo1 $N  
#         printf ", " 
#         ./algo2 $N 
#         printf ", " 
#         ./algo3 $N 
#         printf ", " 
#         if [ $N -le 100000000 ]; then
#             ./algo4 $N 
#         else
#             printf "-, -" 
#         fi
#         printf "\n" 
#     done
# done

# on sorted datasets
echo "Running on sorted datasets"
for ((i=0; i<${#N_values[@]}; i++)); do
    N=${N_values[i]}
    echo "N = $N"
    repetition=${repetitions[i]}
    for ((j=0; j<repetition; j++)); do
        ./data $N 0
        echo "Iteration $j"
        printf "sorted, $N, $j, " 
        ./algo1 $N  
        # printf ", " 
        # ./algo2 $N 
        # printf ", " 
        # printf "NA, NA" 
        # printf ", " 
        if [ $N -le 100000000 ]; then
            ./algo4 $N 
        else
            printf "NA, NA" 
        fi
        printf "\n" 
    done
done

# on reverse sorted datasets
# echo "Running on reverse sorted datasets"
# for ((i=0; i<${#N_values[@]}; i++)); do
#     N=${N_values[i]}
#     echo "N = $N"
#     repetition=${repetitions[i]}
#     ./data $N -1
#     for ((j=0; j<repetition; j++)); do
#         echo "Iteration $j"
#         printf "reverse_sorted, $N, $j, " 
#         ./algo1 $N  
#         printf ", " 
#         ./algo2 $N 
#         printf ", " 
#         printf "NA, NA" 
#         printf ", " 
#         if [ $N -le 100000000 ]; then
#             ./algo4 $N 
#         else
#             printf "NA, NA" 
#         fi
#         printf "\n" 
#     done
# done
