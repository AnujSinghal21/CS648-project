#include"util.h"
#define X 1e6
#define CHUNK_SIZE 1000000

int64 timer(int func(int64), int64 arg, int n){
    return 0;
}
int generate_data(int64 n, int mode){
    FILE * fp = fopen("data.bin", "w");
    int64 * buffer = (int64 *)malloc(CHUNK_SIZE * sizeof(int64));
    int64 curr = 0;
    switch (mode)
    {
    case 0:
        /* random dataset */
        while (n > 0)
        {
            int64 chunk = n > CHUNK_SIZE ? CHUNK_SIZE : n;
            for (int64 i = 0; i < chunk; i++)
            {
                buffer[i] = rand();
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