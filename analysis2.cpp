#include "algo2.hpp"

int main(){
    clock_t t_start, t_end;
    //srand(time(0));
    t_start = clock();
    int64 median = stl_median("testdata.txt");
    t_end = clock();
    printf("Median: %lld\n", median);
    double time_taken = ((double)(t_end - t_start)) * 1000 / CLOCKS_PER_SEC;
    printf("Time taken to find median using quick median: %.3lf ms\n", time_taken);
    return 0;
}
