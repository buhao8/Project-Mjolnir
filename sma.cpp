#include "sma.h"
#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <Arduino.h>

#define SMA_SIZE_MAX 500
static uint16_t SMA_BUF[SMA_SIZE_MAX];
static size_t SMA_SIZE = SMA_SIZE_MAX;

static int FILLED_ONCE = 0;

void (*bell_fn)(int) = NULL;

void sma_init(size_t size, void (*f)(int))
{
    // No dynamic memory plz
    assert(size <= SMA_SIZE_MAX);
    SMA_SIZE = size;
    bell_fn = f;
}

int get_size() { return SMA_SIZE; }

void sma_push(int val)
{
    static int idx = 0;
    if (idx == SMA_SIZE) {
        if (bell_fn)
            bell_fn(idx);

        idx = 0;
        FILLED_ONCE = 1;
    }
    SMA_BUF[idx++] = val;
}

uint32_t sma_avg(void)
{
    uint32_t sum = 0;

    if (!FILLED_ONCE)
        return -1;

    for (size_t i = 0; i < SMA_SIZE; ++i)
        sum += SMA_BUF[i];
    return sum / SMA_SIZE;
}
