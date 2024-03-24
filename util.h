#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef long long int64;
int generate_data(int64 n, int mode, char * filename);
typedef struct file_reader {
    int64 * buffer;
    int64 index;
    FILE * fp;
    int64 (*next)(struct file_reader * fr);
    void (*reset)(struct file_reader * fr);
    void (*close)(struct file_reader * fr);
} file_reader;
struct file_reader get_reader(char * filename);