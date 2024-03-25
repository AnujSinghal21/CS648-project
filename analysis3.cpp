#include "algo3.hpp"

int main()
{
    int64 median = one_pass_median("testdata.txt",1e7);
    cout << "The median is:" << median << endl;
}