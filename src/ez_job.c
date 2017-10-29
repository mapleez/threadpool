#include "ez_job.h"
#include <stdlib.h>

pez_job ez_job_create (pez_func _func, void* _args) {
	pez_job res = NULL;

	if (! _func) return res;

	res = (pez_job) malloc (sizeof (*res));
	if (! res) return res;

	res -> _func = _func;
	res -> _args = _args;
	res -> _status = JOB_STAT_WAIT;
	return res;
}

void ez_job_destroy (pez_job* _job) {
	if (! _job && *_job) {
		free (*_job);
		*_job = NULL;
	}
}

