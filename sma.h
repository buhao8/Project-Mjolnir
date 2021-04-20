#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
    extern void sma_init(size_t);
    extern void sma_push(int);
    extern int sma_avg(void);
#ifdef __cplusplus
}
#endif
