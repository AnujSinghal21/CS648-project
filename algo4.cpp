#include "algo4.hpp"
int64 another_2pass_algo(string filename, int64 n){
    reader fr(filename);
    int64 sample_size = pow(n, 2.0/3.0) * log(n); // n^(2/3) logn
    int64 * sample = get_sample(sample_size, n, fr);
    int64 offset = pow(n, 1.0/3.0) * log(n); // n^(1/3) logn
    int64 left_pivot = sample_size/2 - offset;
    int64 right_pivot = sample_size/2 + offset;
    nth_element(sample, sample + left_pivot, sample + sample_size);
    int64 left_median = sample[left_pivot];
    nth_element(sample, sample + right_pivot, sample + sample_size);
    int64 right_median = sample[right_pivot];
    fr.reset();
    int64 count = 0;
    int64 rank_lower = 0;
    for (int64 i = 0; i < n; i++){
        int64 num = fr.next();
        if (num >= left_median && num <= right_median){
            sample[count++] = num;
            if (count == sample_size){
                printf("Sample size reached\n");
                break;
            }
        }
        if (num < left_median){
            rank_lower++;
        }
    }
    if (n/2 - rank_lower < 0 || n/2 - rank_lower >= count){
        printf("Error: Rank out of bounds\n");
        return -1;
    }
    nth_element(sample, sample + n/2 - rank_lower, sample + count);
    int64 median = sample[n/2 - rank_lower];
    free(sample);
    fr.close();
    return median;
}
