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

/* Main entry */
int main (int argc, char* argv []) {
	if (
			_t_ez_job_create1 ()
	) puts ("t_ez_job ... ok!");
	else
		exit (1);

	return 0;
}
