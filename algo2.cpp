// Quick median algorithm O(n) space
#include "algo2.hpp"

int64 quick_median_algo(int64 * arr, int l, int r, int rank){
    if (l == r){
        return arr[l];
    }
    int pivot = l + rand() % (r - l + 1);
    swap(arr[r], arr[pivot]);
    int lst = arr[r], i = l, j = l;
    while (j < r) {
        if (arr[j] < lst) {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i], arr[r]);

    if (rank < i){
        return quick_median_algo(arr, l, i-1, rank);
    }
    if (rank > i){
        return quick_median_algo(arr, i+1, r, rank);
    }
    return arr[rank];
}
int64 quick_median(string filename, int64 n){
    reader fr(filename);
    int64 * arr = (int64 *)malloc(n * sizeof(int64));
    for (int64 i = 0; i < n; i++)
    {
        arr[i] = fr.next();
    }
    int64 median = quick_median_algo(arr, 0, n-1, n/2);
    fr.close();
    free(arr);
    return median;
}