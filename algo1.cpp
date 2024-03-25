#include <bits/stdc++.h>
#include <random>
#include <ctime>
#include "algo1.hpp"
#include "algo2.hpp"
#include "util.hpp"
using namespace std;
typedef long long ll;

int64 get_rand_num(){
   static mt19937_64 gen(static_cast<unsigned int>(time(0)));
   uniform_int_distribution<int64> dist(1, N);
   return dist(gen);
}
int main(){
     ll set_size = pow(N, 2.0/3.0) * log(N);
     ll range_size = pow(N, 2.0/3.0);
     ll med_pos = N/2;
     generate_data(N, 0, "testdata.txt"); // for datset
     reader fr("testdata.txt");
     ll num;
     ll found = 0;
     while(found!=1)
     {
        vector<ll> set_nums;
        unordered_set<ll> random_indices;
        
        while(random_indices.size()<set_size){
            ll curr = get_rand_num();
            random_indices.insert(curr);
        }
        
        ll curr_file_ind = 1;

        for(;curr_file_ind<=N;curr_file_ind++)
        {
            num = fr.next();
            if(random_indices.find(curr_file_ind)!=random_indices.end())
            {
                set_nums.push_back(num);
            }
        }

        fr.reset();
        
        nth_element(set_nums.begin(),set_nums.begin()+(set_size/2),set_nums.end());
        ll med_num = set_nums[set_size/2];
        multiset<ll> small_nums,large_nums;
        ll rank = 1;
        ll same_as = 1;
        curr_file_ind = 1;
        for(;curr_file_ind<=N;curr_file_ind++)
        {
            num = fr.next();
            if(num<med_num)
            {
                rank++;
                if(small_nums.size()<range_size)
                {
                    small_nums.insert(num); 
                }
                else
                {
                    auto it = small_nums.begin();
                    if(*it<num)
                    {
                        small_nums.erase(it);
                        small_nums.insert(num);
                    }
                }
            }
            else if(num>med_num)
            {
                if(large_nums.size()<range_size)
                {
                    large_nums.insert(num); 
                }
                else
                {
                    auto it = large_nums.end();
                    --it;
                    if(*it>num)
                    {
                        small_nums.erase(it);
                        small_nums.insert(num);
                    }
                }
            }
            else{
                same_as++;
            }
        }
        
        fr.reset();

        for(ll i = 1;i<same_as;i++){
            small_nums.insert(med_num);
            rank++;
        }

        ll low_range = rank - range_size;
        ll up_range = rank + range_size;

        if(low_range>med_pos || up_range<med_pos)
        {
            // The algorithm continues
        }
        else
        {
            found = 1;
            if(med_pos==rank)
            {
                cout << "The Median is : " << med_num;
            }
            else if(med_pos>rank)
            {
                ll offset = med_pos-rank;
                auto it = large_nums.begin();
                for(ll i = 1;i<offset;i++){
                    ++it;
                }
                ll found_med = *it;
                cout << "The Median is : " << found_med;
            }
            else{
                ll offset = rank-med_pos;
                auto it = small_nums.end();
                for(ll i = 0;i<offset;i++){
                    --it;
                }
                ll found_med = *it;
                cout << "The Median is : " << found_med;
            }
            //break;
        }
     }
}