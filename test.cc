#include "sma.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    sma_init(100);

    for (size_t i = 0; i < 10000; ++i) {
        sma_push(rand() % 1024);
        cout << sma_avg() << endl;
    }
}
