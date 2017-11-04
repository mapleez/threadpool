#include <stdlib.h>
#include <stdio.h>
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

	}

	ez_joblist_destroy (&list);
	return 1;
}

/* Main entry */
int main (int argc, char * argv []) {
	if (
			_t_ez_joblist_create1 () &&
			_t_ez_joblist_push ()
	) puts ("t_ez_joblist ... ok!");
	else
		exit (1);

	return 0;
}
