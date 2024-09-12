#include <pthread.h>
#include <stdio.h>
#include "parallel_sum.h"

int A[MAX];
int global_sum=0;
pthread_mutex_t lock;
pthread_barrier_t barrier;

void* parallel_sum(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    int tid = data->tid;
    int nproc = data->nproc;
    int size = data->size;

    int local_sum=0;
    int low = (tid * size)/ nproc;
    int high = ((tid + 1) * size)/ nproc;

    for(int i=low;i<high;i++) {
        printf("%d ", A[i]);
        local_sum+=A[i];
    }

    pthread_barrier_wait(&barrier);
    
    pthread_mutex_lock(&lock);
    global_sum += local_sum;
    pthread_mutex_unlock(&lock);
    printf("Thread %d: local_sum = %d\n", tid, local_sum); 
    return NULL;

}

void compute_parallel_sum(int nproc, int size) {
    pthread_t threads[nproc];
    thread_data_t thread_data[nproc];

    pthread_mutex_init(&lock, NULL);
    pthread_barrier_init(&barrier, NULL, nproc);  // Initialize the barrier
    for (int i = 0; i<nproc; i++) {
        thread_data[i].tid=i;
        thread_data[i].nproc = nproc;
        thread_data[i].size = size;
        pthread_create(&threads[i],NULL,parallel_sum,(void*)&thread_data[i]);
    }

    for (int i = 0; i < nproc; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_barrier_destroy(&barrier);
    pthread_mutex_destroy(&lock);

}