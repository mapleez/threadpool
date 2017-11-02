#include <stdlib.h>
#include "ez_threadpool.h"
#include "joblist.h"

typedef struct _ez_threadpool {
	pez_joblist _joblist;
	pez_thread _threads;

	int _thread_count;
} * pez_threadpool, ez_threadpool;

pez_threadpool ez_threadpool_create (int init_count) {
	pez_threadpool tp = NULL;

	if (init_count <= 0) return tp;

	// TODO
	
}

