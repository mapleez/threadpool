#include <stdlib.h>
// #include <stdio.h> // FORDEBUG
#include "joblist.h"

/* Create an entity. */
pez_joblist ez_joblist_create () {
	pez_joblist list = NULL;

	list = (pez_joblist) malloc (sizeof (*list));
	if (! list) return list;

	list -> _head = list -> _tail = NULL;
	list -> _count = 0;

	return list;
}

/* Pop one element from list header. */
pez_job ez_joblist_pop (pez_joblist _list) {
	pez_job ptr = NULL;
	if (! _list || ez_joblist_empty (_list)) 
		return ptr;

	ptr = _list -> _head;

	/* Only one element.*/
	if (_list -> _count == 1) {
		_list -> _head = _list -> _tail = NULL;
	} else {
		pez_job new_head = ptr -> _next;
		new_head -> _prev = NULL;
		_list -> _head = new_head;
	}

	_list -> _count --;

	/* It's better to set next 
	 * ptr to NULL. */
	ptr -> _next = NULL;
	return ptr;
}

/* Push an element into list tail. */
pez_job ez_joblist_push (pez_joblist _list, pez_job _job) {
	if (! _list || ! _job) return NULL;

	_job -> _next = NULL;
	_job -> _prev = _list -> _tail;
	if (ez_joblist_empty (_list))
		_list -> _head = _job;
	else
		_list -> _tail -> _next = _job;

	_list -> _tail = _job;
	_list -> _count ++;

	return _job;
}

/* Push multiple elements into list tail. */
int ez_joblist_push_m (pez_joblist _list, ez_job _jobs []) {
	int count = 0;
	pez_job p = _jobs;

	/* TODO error ??? */
	if (! _list || ! _jobs) return 0;

	for (; p && p -> _status != JOB_STAT_INVALID; ++ p) {
		pez_job newcopy = ez_job_copy (p);
		pez_job res = ez_joblist_push (_list, newcopy);
		count += (int) (!! res);
	}
	return count;
}


/* 
 * Destroy the job list. 
 */
void ez_joblist_destroy (pez_joblist* _list) {
	if (! _list || ! *_list) return;

	/* Free each element. */
	pez_joblist l = *_list;
	pez_job p = ez_joblist_pop (l);
	while (p) {
		pez_job tmp = p -> _next;
		ez_job_destroy (&p);
		p = tmp;
	}

	/* Free list memory. */
	free (l);
	*_list = NULL;
}


