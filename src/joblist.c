#include "joblist.h"


pez_joblist ez_joblist_create () {
	pez_joblist list = NULL;

	list = (pez_joblist) malloc (sizeof (*list));
	if (! list) return list;

	list -> _next = list -> _head =
		list -> _tail = NULL;
	list -> _count = 0;
	list -> _job = NULL;

	return list;
}

pez_job ez_joblist_pop (pez_joblist _list) {
	pez_job ptr = NULL;
	if (! _list || ez_joblist_empty (_list)) 
		return ptr;

	/* Only one element.*/
	ptr = _list -> _head -> _job;
	if (_list -> _count == 1) {
		_list -> _next = _list -> _head
			= _list -> _tail = NULL;
		_list -> _job = NULL;
		_list -> _count --;
	} else {
		// TODO
	}
}

