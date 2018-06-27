/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#include <stdio.h>
#include <pthread.h>
#include "../../../inc/core/concurrency/threadpool.h"

static void *threadpool_wait(void *threadpool)
{
	threadpool_task_t *task;
	threadpool_t *pool = (threadpool_t *)threadpool;

	while (pool->running || pool->task_queue.length > 0)
	{
		pthread_mutex_lock(&pool->lock);
		while (pool->task_queue.length == 0 && pool->running)
			pthread_cond_wait(&pool->task_added, &pool->lock);
		if (pool->task_queue.length > 0)
		{
			task = pool->task_queue.begin->value;
			linkedlist_remove_begin(&pool->task_queue);
			pthread_mutex_unlock(&pool->lock);
			task->function(task->args);
		}
	}
	pthread_mutex_unlock(&pool->lock);
	pthread_exit(NULL);
	return (NULL);
}

int threadpool_destroy(threadpool_t *pool)
{
	pthread_t *thread;
	linkedlist_t *threads = &pool->threads;
	linkedlist_t *queue = &pool->task_queue;

	pthread_mutex_lock(&pool->lock);
	pool->running = false;
	pthread_mutex_unlock(&pool->lock);
	pthread_cond_broadcast(&pool->task_added);
	pthread_mutex_unlock(&pool->lock);
	for (node_t *node = threads->begin; node != NULL; node = node->next)
	{
		thread = (pthread_t *)node->value;
		pthread_join(*thread, NULL);
	}
	pthread_mutex_destroy(&pool->lock);
	pthread_cond_destroy(&pool->task_added);
	for (node_t *node = threads->begin; node != NULL; node = node->next)
		free(node->value);
	for (node_t *node = queue->begin; node != NULL; node = node->next)
		free(node->value);
	linkedlist_destroy(queue);
	linkedlist_destroy(threads);
	return (EXIT_SUCCESS);
}

int threadpool_add_task(threadpool_t *pool, threadpool_task_function func,
			threadpool_task_args args)
{
	threadpool_task_t *task = malloc(sizeof(threadpool_task_t));

	if (task == NULL)
		return (-1);
	task->args = args;
	task->function = func;
	pthread_mutex_lock(&pool->lock);
	linkedlist_append(&pool->task_queue, task);
	pthread_cond_signal(&pool->task_added);
	pthread_mutex_unlock(&pool->lock);
	return (EXIT_SUCCESS);
}

static int threadpool_init_intern(threadpool_t *pool, size_t tcount)
{
	pthread_t *thread = NULL;

	if (linkedlist_init(&pool->threads) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (linkedlist_init(&pool->task_queue) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&pool->lock, NULL) != EXIT_SUCCESS ||
		pthread_cond_init(&pool->task_added, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	pool->running = true;
	for (size_t index = 0; index < tcount; index++)
	{
		thread = malloc(sizeof(pthread_t));
		pthread_create(thread, NULL, &threadpool_wait, (void *)pool);
		linkedlist_append(&pool->threads, thread);
	}
	return (EXIT_SUCCESS);
}

int threadpool_init(threadpool_t *pool, size_t tcount)
{
	if (threadpool_init_intern(pool, tcount) != EXIT_SUCCESS)
	{
		threadpool_destroy(pool);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
