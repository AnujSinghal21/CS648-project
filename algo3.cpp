#include "algo3.hpp"

int64 one_pass_median(string filename, int64 n){
    reader fr(filename);
    multiset<int64> curr_set;
    int64 low=0, high=0;
    int64 curr, curr_size, curr_set_size;
    //cin >> n;
    curr_set_size =  sqrtl(n);
    //vector<int64> v; //for testing
    while(curr_set.size()<curr_set_size){
        curr = fr.next();
        curr_set.insert(curr);
        //v.push_back(curr);
    }
    curr_size = curr_set_size;
    while(curr_size<n){
        curr = fr.next();
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

    fr.reset();
    int64 index_needed = (n/2) - low; 
    if(index_needed > curr_set.size()){
        cout << "OOPS!! Algorithm Failed";
        return 0;
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
    return guessed_median;
    }
}