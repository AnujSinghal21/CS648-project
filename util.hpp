#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <random>
using namespace std;
typedef long long int64;

int64 get_rand_num(int64 Range){
   static mt19937_64 gen(static_cast<unsigned int>(time(0)));
   uniform_int_distribution<int64> dist(1, Range);
   return dist(gen);
}
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



