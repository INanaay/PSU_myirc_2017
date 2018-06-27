/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#ifndef PSU_MYFTP_2017_THREADPOOL_H
#define PSU_MYFTP_2017_THREADPOOL_H

#include <stdlib.h>
#include <stdbool.h>
#include "../linkedlist/linkedlist.h"

typedef int64_t threadpool_task_id;
typedef void * threadpool_task_args;
typedef void *(*threadpool_task_function)(void *);

struct threadpool_task_s
{
	threadpool_task_id id;
	threadpool_task_args args;
	threadpool_task_function function;
};
typedef struct threadpool_task_s threadpool_task_t;

struct threadpool_s
{
	bool running;

	pthread_mutex_t lock;
	pthread_cond_t task_added;

	linkedlist_t threads;
	linkedlist_t task_queue;
};
typedef struct threadpool_s threadpool_t;

int threadpool_destroy(threadpool_t *pool);
int threadpool_init(threadpool_t *pool, size_t tcount);
int threadpool_add_task(threadpool_t *pool, threadpool_task_function func,
			threadpool_task_args args);

#endif //PSU_MYFTP_2017_THREADPOOL_H
