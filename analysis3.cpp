#include "algo3.hpp"

int main()
{
    int64 median = one_pass_median("testdata.txt");
    cout << "The median is:" << median << endl;
}