#include <bits/stdc++.h>
#include <random>
#include <ctime>
#include "util.hpp"
using namespace std;
typedef long long int64;

int64 get_curr_num(){
   static mt19937_64 gen(static_cast<unsigned int>(time(0)));
   uniform_int_distribution<int64> dist(1, 100000000000LL);
   return dist(gen);
}

int main(){
    multiset<int64> curr_set;
    int64 low=0, high=0;
    int64 n, curr, curr_size, curr_set_size;
    cin >> n;
    curr_set_size =  sqrtl(n);
    //vector<int64> v; //for testing
    while(curr_set.size()<curr_set_size){
        curr = get_curr_num();
        curr_set.insert(curr);
        //v.push_back(curr);
    }
    curr_size = curr_set_size;
    while(curr_size<n){
        curr = get_curr_num();
        //v.push_back(curr);
        auto it = curr_set.begin();
        auto itr = curr_set.end();
        --itr;
        if(curr <= *it){
            low++;
        }
        else if(curr >= *itr){
            high++;
        }
        else{
            if(low<high){
                curr_set.erase(it);
                curr_set.insert(curr);
                low++;
            }
            else{
                curr_set.erase(itr);
                curr_set.insert(curr);
                high++;
            }
        }
        curr_size++;
    }
    int64 index_needed = (n/2) - low; 
    if(index_needed > curr_set.size()){
        cout << "OOPS!! Algorithm Failed";
    }
    else{
    auto it = curr_set.begin();
    for(int64 i = 1;i<index_needed;i++){
        ++it;
    }
    int64 guessed_median = *it;
    cout << "The median of the stream of n random integers is: " << guessed_median << '\n';
    // for(auto p : v){
    //     cout << p << ' ';
    // } // for testing purpose
    }
    return 0;
}