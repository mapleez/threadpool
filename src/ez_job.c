// #include "ez_threadpool.h"
#include "ez_job.h"
#include <string.h>
#include <stdlib.h>

pez_job ez_job_create (pez_func _func, void* _args) {
	pez_job res = NULL;

	if (! _func) return res;

	res = (pez_job) malloc (sizeof (*res));
	if (! res) return res;

	res -> _args = _args;
	res -> _func = _func;
	res -> _next = res -> _prev = NULL;
	res -> _status = JOB_STAT_WAIT;
	return res;
}

void ez_job_destroy (pez_job* _job) {
	if (_job && *_job) {
		free (*_job);
		*_job = NULL;
	}
}

/* Copy all the fields */
pez_job ez_job_copy (pez_job _job) {
	size_t size = 0;
	if (! _job) return NULL;

	size = sizeof (*_job);
	pez_job res = (pez_job) malloc (size);
	if (! res) return NULL;

	memcpy (res, _job, size);
	return res;
}


