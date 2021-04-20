#include "sma.h"
#include <assert.h>
#include <stdint.h>
#include <stddef.h>

#define SMA_SIZE_MAX 400
static uint16_t SMA_BUF[SMA_SIZE_MAX];
static size_t SMA_SIZE = SMA_SIZE_MAX;

static int FILLED_ONCE = 0;

void sma_init(size_t size)
{
    // No dynamic memory plz
    assert(size <= SMA_SIZE_MAX);
    SMA_SIZE = size;
}

void sma_push(int val)
{
    static int idx = 0;
    if (idx == SMA_SIZE) {
        idx = 0;
        FILLED_ONCE = 1;
    }
    SMA_BUF[idx++] = val;
}

int sma_avg(void)
{
    int sum = 0;

    if (!FILLED_ONCE)
        return -1;

    for (size_t i = 0; i < SMA_SIZE; ++i)
        sum += SMA_BUF[i];
    return sum / SMA_SIZE;
}
