#include "util.hpp"
#define N 1e8

int64 get_rand_num(){
   static mt19937_64 gen(static_cast<unsigned int>(time(0)));
   uniform_int_distribution<int64> dist(1, N);
   return dist(gen);
}