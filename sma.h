#pragma once
#include <stddef.h>
#include <stdint.h>


extern void sma_init(size_t, void (*)(int));
extern void sma_push(int);
extern uint32_t sma_avg(void);
extern int get_size();
