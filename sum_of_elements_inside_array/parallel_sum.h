#ifndef PARALLEL_SUM_H
#define PARALLEL_SUM_H

#include <pthread.h>
#include "array_utils.h"

extern int global_sum;
extern pthread_mutex_t lock;
extern pthread_barrier_t barrier;
typedef struct {
    int tid;
    int nproc;
    int size;
} thread_data_t;

void* parallel_sum(void* arg);
void compute_parallel_sum(int nproc, int size);
#endif