/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_IDGENERATOR_H
#define PSU_MYIRC_2017_IDGENERATOR_H

#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include "../linkedlist/linkedlist.h"

struct idgenerator_s
{
	bool running;
	uint64_t last_id;
	pthread_mutex_t lock;
	linkedlist_t id_released_queue;
};
typedef struct idgenerator_s idgenerator_t;

int idgenerator_init(idgenerator_t *generator);
void idgenerator_destroy(idgenerator_t *generator);
uint64_t idgenerator_get_id(idgenerator_t *generator);
bool idgenerator_release_id(idgenerator_t *generator, uint64_t id);

#endif //PSU_MYIRC_2017_IDGENERATOR_H
