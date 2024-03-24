#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <time.h>
using namespace std;

typedef long long int64;
int generate_data(int64 n, int mode, string filename);
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