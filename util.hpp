#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <time.h>
using namespace std;

typedef long long int64;
int generate_data(int64 n, int mode, char * filename);
class reader {
    public:
        int64 * buffer;
        int64 index;
        FILE * fp;
        reader(string filename);
        int64 next();
        void reset();
        void close();
};
typedef struct file_reader {
    int64 * buffer;
    int64 index;
    FILE * fp;
    int64 (*next)(struct file_reader * fr);
    void (*reset)(struct file_reader * fr);
    void (*close)(struct file_reader * fr);
} file_reader;
struct file_reader get_reader(string filename);