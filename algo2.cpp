#include "util.hpp"

int64 algo2(string filename, int n){
     int64 set_size = pow(n, 2.0/3.0) * log(n);
     int64 range_size = pow(n, 2.0/3.0);
     int64 med_pos = n/2 + 1;
     
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
            int64 curr = get_rand_num(n);
            random_indices.insert(curr);
        }
        
        int64 curr_file_ind = 1;

        for(;curr_file_ind<=n;curr_file_ind++)
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
        for(;curr_file_ind<=n;curr_file_ind++)
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
            cerr << "Another Iteration required" << endl;
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
    return found_med; 
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    clock_t t_start, t_end;
    srand(time(0));
    t_start = clock();
    int64 result = algo2("data.bin", n);
    t_end = clock();
    double time_taken = ((double)(t_end - t_start)) * 1000 / CLOCKS_PER_SEC;
    printf("%lld, %.3lf", result, time_taken);
    return 0;
}