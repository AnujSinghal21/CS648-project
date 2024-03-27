#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <random>
using namespace std;
typedef long long int64;
#define N 10000000  
// HERE YOU SET THE SIZE OF THE INPUT FOR WHICH YOU WANT TO FIND MEDIAN
// DON'T DECLARE LIKE 1e8,1e7 etc. BECAUSE WE HAVE A FUNCTION (nth_element) THAT DOESN'T SUPPORT THESE TYPE OF DECLARATION
int64 get_rand_num(int64 Range);
int generate_data(int64 n, int mode, string filename);
class reader {
    public:
        int64 * buffer;
        int64 index;
        FILE * fp;
        reader(string filename);
        int64 next();
        void reset();
        void close();
};

int64 * get_sample(int64 sample_size, int64 n, reader & fr);