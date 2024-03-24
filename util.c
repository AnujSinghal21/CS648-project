#include"util.h"
#define CHUNK_SIZE 1e6

int generate_data(int64 n, int mode, char * filename){
    FILE * fp = fopen(filename, "w");
    int64 * buffer = (int64 *)malloc(CHUNK_SIZE * sizeof(int64));
    int64 curr = 0;
    srand(time(NULL));
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

int64 reader_next(struct file_reader * fr){
    if (fr->index == CHUNK_SIZE)
    {
        int r = fread(fr->buffer, sizeof(int64), CHUNK_SIZE, fr->fp);
        if (r < 0){
            return -1;
        }
        fr->index = 0;
    }
    return fr->buffer[fr->index++];
}

void reader_reset(struct file_reader * fr){
    fr->index = 0;
    fseek(fr->fp, 0, SEEK_SET);
    return;
}

void reader_close(struct file_reader * fr){
    free(fr->buffer);
    fclose(fr->fp);
    return;
}

struct file_reader get_reader(char * filename){
    file_reader fr;
    fr.fp = fopen(filename, "rb");
    fr.buffer = (int64 *)malloc(CHUNK_SIZE * sizeof(int64));
    fr.index = CHUNK_SIZE;
    fr.next = &reader_next;
    fr.reset = &reader_reset;
    fr.close = &reader_close;
    return fr;
}
