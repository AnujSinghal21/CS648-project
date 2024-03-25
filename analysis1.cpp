//#include "util.hpp"
#include "algo1.hpp"

// int sample_read(){
//     reader fr("data.bin");
//     int64 z;
//     for (int64 i = 0; i < 1e7; i++)
//     {
//         z = fr.next();
//         if (z % 1000000000 == 0){
//             printf("z\n");
//         }
//     }
//     return 0;
// }
int main(){
    clock_t t_start, t_end;
    srand(time(0));
    t_start = clock();
    //generate_data(1e7, 0, "data.bin");
    // sample_read();
    generate_data(N, 0, "testdata.txt"); // for datset, if want sortd dataset set flag to be 1 or -1, otherwise 0 for random dataset
    int64 result = two_pass_algo("testdata.txt");
    t_end = clock();
    double time_taken = ((double)(t_end - t_start)) * 1000 / CLOCKS_PER_SEC;
    printf("Time taken to read data: %.3lf ms\n", time_taken);
    cout << "The median is :" << result << endl;
    return 0;
}
