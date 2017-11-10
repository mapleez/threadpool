#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <assert.h>

static void _test_func (void* args) {
	// ...
}

/* Check creation. */
int _t_ez_joblist_create1 () {
	pez_joblist list = ez_joblist_create ();
	ez_joblist_destroy (&list);
	return 1;
}

int _t_ez_joblist_push1 () {
	pez_joblist list = ez_joblist_create ();
	size_t num = 0;
	static ez_job jobs [] = {
		{NULL, _test_func },
		{NULL, _test_func },
		{NULL, _test_func },
		{NULL, _test_func },
		{NULL, _test_func },
		{NULL, _test_func },
		{NULL, _test_func },
		JOB_ARRAY_STOP_ELEMENT // terminal element.
	};

	num = sizeof (jobs) / sizeof (struct _ez_job);
	num --; // the terminal element.
	if (list) {
		int x = ez_joblist_push_m (list, jobs);
		assert (num == x);
	}

	ez_joblist_destroy (&list);
	return 0;
}

/* Check push */
int _t_ez_joblist_push () {
	int c = 0;
	pez_joblist list = ez_joblist_create ();

	/* push NULL */
	pez_job res = ez_joblist_push (list, NULL);
	assert (res == NULL);
	assert (list -> _count == 0);
	assert (list -> _head == list -> _tail 
			&& list -> _head == NULL);

	/* create a new job and push. */
	res = ez_job_create ((pez_func) _t_ez_joblist_create1, NULL);
	if (res != NULL) {
		/* Push a job. */
		pez_job tmp = ez_joblist_push (list, res);
		assert (tmp == res);
		assert (list -> _count == 1);
		assert (list -> _head == list -> _tail 
				&& list -> _head == tmp);

		/* Push multiple jobs. */
		c = 10;
		while (-- c) {
			pez_job t = ez_job_create (_test_func, NULL);
			assert (ez_joblist_push (list, t) == t);
			assert (tmp -> _next == t);
			assert (t -> _prev == tmp);
			assert (list -> _count == 10 - c + 1);
			tmp = t;
		}

		assert (list -> _count == (10));
	}

	/* free all the memory for each job element. */
	ez_joblist_destroy (&list);
	return 1;
}

/* Main entry */
int main (int argc, char * argv []) {
	if (
			_t_ez_joblist_create1 () &&
			_t_ez_joblist_push () &&
			_t_ez_joblist_push1 ()
	) puts ("t_ez_joblist ... ok!");
	else
		exit (1);

	return 0;
}
