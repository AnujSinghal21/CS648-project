#include "algo1.hpp"

int64 two_pass_algo(string filename){
     int64 set_size = pow(N, 2.0/3.0) * log(N);
     int64 range_size = pow(N, 2.0/3.0);
     int64 med_pos = N/2 + 1;
     
     int64 found_med;
     
     reader fr(filename);
     int64 num;
     int64 found = 0;
     int64 num_iter = 1;
     while(found!=1)
     {
        vector<int64> set_nums;
        unordered_set<int64> random_indices;
        
        while(random_indices.size()<set_size){
            int64 curr = get_rand_num(N);
            random_indices.insert(curr);
        }
        
        int64 curr_file_ind = 1;

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
        int64 med_num = set_nums[set_size/2];
        multiset<int64> small_nums,large_nums;
        int64 rank = 1;
        int64 same_as = 1;
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
                        large_nums.erase(it);
                        large_nums.insert(num);
                    }
                }
            }
            else{
                same_as++;
                rank++;
            }
        }
        
        fr.close();
        
        rank--;
        for(int64 i = 1;i<same_as;i++){
            auto it = small_nums.begin();
            small_nums.erase(it);
            small_nums.insert(med_num);
        }

        int64 low_range = rank - range_size;
        int64 up_range = rank + range_size;

        if(low_range>med_pos || up_range<med_pos)
        {
            // The algorithm continues
            num_iter++;
            cout << "Another Iteration" << endl;
        }
        else
        {
            found = 1;
            if(med_pos==rank)
            {
                found_med = med_num;
            }
            else if(med_pos>rank)
            {
                int64 offset = med_pos-rank;
                auto it = large_nums.begin();
                for(int64 i = 1;i<offset;i++){
                    ++it;
                }
                found_med = *it;
            }
            else{
                int64 offset = rank-med_pos;
                auto it = small_nums.end();
                it--;
                for(int64 i = 0;i<offset;i++){
                    --it;
                }
                found_med = *it;
            }
            //break;
        }
     }
    cout << "Number of Iteration taken : " << num_iter << endl;
    return found_med; 
}