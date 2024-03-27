#include "util.hpp"

/*
    This algorithm computes the median of n random integers in a single pass with high probability, the input should be a uniformly random permutation
    Algorithm:
    1. Read the first sqrt(n) integers from the stream and store them in a multiset.
    2. For the next n-sqrt(n) integers, if the integer is less than the smallest integer in the multiset, increment low.
    3. If the integer is greater than the largest integer in the multiset, increment high.
    4. If the integer is between the smallest and largest integer in the multiset, replace the smallest or largest integer in the multiset with the integer.
    5. The median is the (n/2 - low + 1)th element in the multiset.
*/
int64 algo3(string filename, int64 n){
    reader fr(filename);
    multiset<int64> curr_set;
    int64 low=0, high=0;
    int64 curr, curr_size, curr_set_size;
    curr_set_size =  sqrtl(n);
    while(curr_set.size()<curr_set_size){
        curr = fr.next();
        curr_set.insert(curr);
    }
    curr_size = curr_set_size;
    while(curr_size<n){
        curr = fr.next();
        auto it = curr_set.begin();
        auto itr = curr_set.end();
        --itr;
        if(curr <= *it){
            low++;
        }
        else if(curr >= *itr){
            high++;
        }
        else{
            if(low<high){
                curr_set.erase(it);
                curr_set.insert(curr);
                low++;
            }
            else{
                curr_set.erase(itr);
                curr_set.insert(curr);
                high++;
            }
        }
        curr_size++;
    }

    fr.close();
    int64 index_needed = (n/2) - low; 
    if(index_needed > curr_set.size()){
        cerr << "One-pass Algorithm Failed" << endl;
        return -1;
    }
    else{
        auto it = curr_set.begin();
        for(int64 i = 1;i<index_needed;i++){
            ++it;
        }
        ++it;
        int64 guessed_median = *it;
        return guessed_median;
    }
}


int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    clock_t t_start, t_end;
    srand(time(0));
    t_start = clock();
    int64 result = algo3("data.bin", n);
    t_end = clock();
    double time_taken = ((double)(t_end - t_start)) * 1000 / CLOCKS_PER_SEC;
    printf("%lld, %.3lf", result, time_taken);
    return 0;
}
