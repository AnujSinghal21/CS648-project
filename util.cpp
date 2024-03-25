#include "util.hpp"
#define CHUNK_SIZE 1e6

int64 rand_num(){
   static mt19937_64 gen(static_cast<unsigned int>(time(0)));
   uniform_int_distribution<int64> dist(1, 100000000000LL);
   return dist(gen);
}

int generate_data(int64 n, int mode, string filename){
    FILE * fp = fopen(filename.c_str(), "w");
    int64 * buffer = (int64 *)malloc(CHUNK_SIZE * sizeof(int64));
    int64 curr = 0;
    //srand(time(NULL));
    switch (mode)
    {
    case 0:
        /* random dataset */
        while (n > 0)
        {
            int64 chunk = n > CHUNK_SIZE ? CHUNK_SIZE : n;
            for (int64 i = 0; i < chunk; i++)
            {
                buffer[i] = rand_num();
            }
            fwrite(buffer, sizeof(int64), chunk, fp);
            printf("Remaining: %lld\n", n);
            n -= chunk;
        }
        break;
    case 1: 
        /* sorted dataset */
        curr = 0;
        while (n > 0)
        {
            int64 chunk = n > CHUNK_SIZE ? CHUNK_SIZE : n;
            for (int64 i = 0; i < chunk; i++)
            {
                buffer[i] = ++curr;
            }
            fwrite(buffer, sizeof(int64), chunk, fp);
            printf("Remaining: %lld\n", n);
            n -= chunk;
        }
        break;
    case -1: 
        /* reverse sorted dataset */
        curr = n;
        while (n > 0)
        {
            int64 chunk = n > CHUNK_SIZE ? CHUNK_SIZE : n;
            for (int64 i = 0; i < chunk; i++)
            {
                buffer[i] = curr--;
            }
            fwrite(buffer, sizeof(int64), chunk, fp);
            printf("Remaining: %lld\n", n);
            n -= chunk;
        }
        break;    
    default:
        break;
    }
    free(buffer);
    return 0;
}

int64 reader::next(){
    if (index == CHUNK_SIZE)
    {
        int r = fread(buffer, sizeof(int64), CHUNK_SIZE, fp);
        if (r < 0){
            return -1;
        }
        index = 0;
    }
    return buffer[index++];
}
void reader::reset(){
    index = 0;
    fseek(fp, 0, SEEK_SET);
    return;
}
void reader::close(){
    free(buffer);
    fclose(fp);
    return;
}

reader::reader(string filename){
    fp = fopen(filename.c_str(), "rb");
    buffer = (int64 *)malloc(CHUNK_SIZE * sizeof(int64));
    index = CHUNK_SIZE;
}
