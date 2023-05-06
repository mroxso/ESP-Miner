#ifndef WORK_QUEUE_H
#define WORK_QUEUE_H

#include <pthread.h>
#include "stratum_api.h"

#define QUEUE_SIZE 3

typedef struct {
    char * buffer[QUEUE_SIZE];
    int head;
    int tail;
    int count;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} work_queue;

void queue_init(work_queue *queue);
void queue_enqueue(work_queue *queue, char * new_work);
char * queue_dequeue(work_queue *queue, int *termination_flag);

#endif // WORK_QUEUE_H