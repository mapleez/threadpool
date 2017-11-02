#include <stdlib.h>
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
	if (ez_joblist_empty (_list)) {
		_list -> _tail = _job;
		_list -> _head = _job;
	} else
		_list -> _tail -> _next = _job;

	_list -> _count ++;

	return _job;
}

/* Push multiple elements into list tail. */
int ez_joblist_push_m (pez_joblist _list, pez_job _jobs []) {
	int count = 0;
	pez_job* p = _jobs;
	if (! _list || ! p) 
		return 0;

	for (; p; ++ p) {
		pez_job res = ez_joblist_push (_list, *p);
		count += (int) (!! res);
	}
	return count;
}


/* TODO destroy. */
void ez_joblist_destroy (pez_joblist* _list) {
}

