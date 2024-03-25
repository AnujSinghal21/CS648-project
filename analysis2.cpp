#include "algo2.hpp"

int main(){
    clock_t t_start, t_end;
    //srand(time(0));
    t_start = clock();
    // int64 median = quick_median("data.bin", 1e7);
    int64 median = stl_median("testdata.txt");
    printf("Median: %lld\n", median);
    // generate_data(1e7, 1, "data.bin");
    // sample_read();
    t_end = clock();
    double time_taken = ((double)(t_end - t_start)) * 1000 / CLOCKS_PER_SEC;
    printf("Time taken to find median using quick median: %.3lf ms\n", time_taken);
    return 0;
}
