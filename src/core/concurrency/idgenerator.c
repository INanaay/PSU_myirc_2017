/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include "../../../inc/core/concurrency/idgenerator.h"

int idgenerator_init(idgenerator_t *generator)
{
	if (generator == NULL)
		return (EXIT_FAILURE);
	if (linkedlist_init(&generator->id_released_queue) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&generator->lock, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	generator->last_id = 0;
	generator->running = true;
	return (EXIT_SUCCESS);
}

void idgenerator_destroy(idgenerator_t *generator)
{
	pthread_mutex_lock(&generator->lock);
	generator->running = false;
	pthread_mutex_unlock(&generator->lock);
	linkedlist_destroy(&generator->id_released_queue);
	pthread_mutex_destroy(&generator->lock);
}

uint64_t idgenerator_get_id(idgenerator_t *generator)
{
	uint64_t result = 0;
	uint64_t *ptr = NULL;

	pthread_mutex_lock(&generator->lock);
	if (generator->running && generator->last_id <= UINT64_MAX) {
		if (generator->id_released_queue.length > 0) {
			ptr = (uint64_t *)(generator->id_released_queue.begin);
			linkedlist_remove_begin(&generator->id_released_queue);
			result = *ptr;
			free(ptr);
		}
		else {
			generator->last_id += 1;
			result = generator->last_id;
		}
	}
	pthread_mutex_unlock(&generator->lock);
	return (result);
}

bool idgenerator_release_id(idgenerator_t *generator, uint64_t id)
{
	bool result = false;
	uint64_t *ptr = malloc(sizeof(id));
	linkedlist_t *queue = &generator->id_released_queue;

	pthread_mutex_lock(&generator->lock);
	*ptr = id;
	linkedlist_append(queue, ptr);
	pthread_mutex_unlock(&generator->lock);
	return (result);
}
