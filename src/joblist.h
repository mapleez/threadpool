#ifdef _EZ_JOB_LIST_H_
#	define _EZ_JOB_LIST_H_

#include "ez_job.h"

typedef struct _ez_joblist {
	pez_job _next;
	pez_job _head;
	pez_job _tail;

	int _count;
} * pez_joblist, ez_joblist;


extern pez_joblist ez_joblist_create ();
extern pez_job ez_joblist_pop (pez_joblist);
extern pez_job ez_joblist_push (pez_joblist, pez_job);
extern pez_job ez_joblist_push_m (pez_joblist, pez_job []);
extern ez_joblist_destory (pez_joblist*);

#endif // ~ _EZ_JOB_LIST_H_

