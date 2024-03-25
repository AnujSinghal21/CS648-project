// Quick median algorithm O(n) space, provided by STL
#include "algo2.hpp"

int stl_median(string filename){
    reader fr(filename);
    int64* arr = (int64 *)malloc(N * sizeof(int64));
    for (int64 i = 0; i < N; i++)
    {
        arr[i] = fr.next();
    }
    nth_element(arr, arr + N/2, arr+N);
    int64 median = arr[N/2];
    fr.close();
    return median;
}
