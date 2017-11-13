#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include <assert.h>

void _func1 (void* args) {
	// Empty...
}

/* Check creation. */
int _t_ez_job_create1 () {
	pez_job job = ez_job_create (_func1, NULL);

	/* Not null */
	if (job != NULL) {
		ez_job_destroy (&job);
		assert (job == NULL);
	}

	/* Shell return NULL. */
	job = ez_job_create (NULL, NULL);
	assert (job == NULL);

	job = ez_job_create (_func1, (void*) _func1);
	if (job != NULL) {
		ez_job_destroy (&job);
		assert (job == NULL);
	}

	return 1;
}

/* Check fields. */
int _t_ez_job_create2 () {
	int data = 1024;
	pez_job job = ez_job_create (_func1, NULL);
	if (job != NULL) {
		assert (job -> _args == NULL);
		assert (job -> _func == _func1);
		assert (job -> _next == NULL);
		assert (job -> _prev == NULL);
		assert (job -> _status == JOB_STAT_WAIT);
		ez_job_destroy (&job);
	}

	job = ez_job_create (_func1, &data);
	if (job != NULL) {
		assert (job -> _args == &data);
		assert (job -> _func == _func1);
		assert (job -> _next == NULL);
		assert (job -> _prev == NULL);
		assert (job -> _status == JOB_STAT_WAIT);
		ez_job_destroy (&job);
	}

	return 1;
}

int _t_ez_job_copy () {
	pez_job job = ez_job_create (_func1, NULL);
	if (job != NULL) {
		pez_job newone = ez_job_copy (job);

		if (newone != NULL) {
			assert (job -> _args == newone -> _args);
			assert (job -> _status == newone -> _status);
			assert (job -> _prev == newone -> _prev);
			assert (job -> _func == newone -> _func);
			assert (job -> _next == newone -> _next);

			ez_job_destroy (newone);
		}

		ez_job_destroy (job);
	}
	return 1;
}


/* Main entry */
int main (int argc, char* argv []) {
	if (
			_t_ez_job_create1 () &&
			_t_ez_job_create2 () &&
			_t_ez_job_copy ()
	) puts ("t_ez_job ... ok!");
	else
		exit (1);

	return 0;
}
