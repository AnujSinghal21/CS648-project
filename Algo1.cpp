#include <bits/stdc++.h>
#include <random>
#include <ctime>
#include "algo1.h"
#include "util.h"
using namespace std;
typedef long long ll;

int64 get_rand_num(){
   static mt19937_64 gen(static_cast<unsigned int>(time(0)));
   uniform_int_distribution<int64> dist(1, N);
   return dist(gen);
}
int main(){
     ll set_size = pow(N, 2.0/3.0) * log(N);
     generate_data(N, 0, "testdata.txt"); // for datset
     file_reader fr = get_reader("testdata.txt");
     ll num;
     vector<ll> set_nums;
     unordered_set<ll> random_indices;
     
     while(random_indices.size()<set_size){
          ll curr = get_rand_num();
          random_indices.insert(curr);
     }
     
     ll curr_file_ind = 1;

     for(;curr_file_ind<=N;curr_file_ind++)
     {
          num = fr.next(&fr);
          if(random_indices.find(curr_file_ind)!=random_indices.end())
          {
               set_nums.push_back(num);
          }
     }

     fr.reset(&fr);
     

}