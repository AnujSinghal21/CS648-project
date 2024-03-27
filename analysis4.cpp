#include "algo4.hpp"

int main()
{
    clock_t t_start, t_end;
    srand(time(0));
    t_start = clock();
    int64 median = another_2pass_algo("main_data.bin", 1e10);
    t_end = clock();
    double time_taken = ((double)(t_end - t_start)) * 1000 / CLOCKS_PER_SEC;
    printf("Time taken to read data: %.3lf ms\n", time_taken);
    if(median!=0) cout << "The median found by another_two_pass_algo is: " << median << endl;
    return 0;
       
}