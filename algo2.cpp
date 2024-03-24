// Quick median algorithm O(n) space, provided by STL
#include "algo2.hpp"

int stl_median(string filename, int64 n){
    reader fr(filename);
    int64* arr = (int64 *)malloc(n * sizeof(int64));
    for (int64 i = 0; i < n; i++)
    {
        arr[i] = fr.next();
    }
    nth_element(arr, arr + n/2, arr+n);
    int64 median = arr[n/2];
    fr.close();
    return median;
}
