#ifndef _EZ_JOB_LIST_H_
#	define _EZ_JOB_LIST_H_

#include "ez_job.h"

typedef struct _ez_joblist* pez_joblist, ez_joblist;

/* An entity for job list. 
 * I use double linked list to implement.
 */
typedef struct _ez_joblist {
	/* Point to next element. */
	// pez_joblist _next;
	
	/* Point to header element. */
	pez_job _head;

	/* Point to tail element. */
	pez_job _tail;

	/* Maintain the count of element. */
	int _count;

	/* The value of this element. */
	// pez_job _job;
} * pez_joblist, ez_joblist;

/*
 * Note: This macro function do not check if input is NULL.
 * Return nonzero if empty. Otherwise zero.
 */
#	define ez_joblist_empty(___L)   (!((___L) -> _count))

/*
 * Create a job list with no element.
 * 
 * Return the entity of a joblist if successful.
 * Otherwise return NULL.
 */
extern pez_joblist ez_joblist_create ();

/*
 * Pop an element from passing joblist. If the
 * joblist is empty or NULL, this function return
 * NULL alse.
 */
extern pez_job ez_joblist_pop (pez_joblist);

/*
 * Push a new job into this joblist. If pez_joblist or
 * job is NULL , nothing will be done and return NULL.
 *
 * $1  The target joblist entity.
 * $2  The job to be pushed.
 *
 * Return $2, in any case.
 */
extern pez_job ez_joblist_push (pez_joblist, pez_job);

/*
 * Push multiple jobs into this joblist. If pez_joblist
 * is NULL, nothing will be done and return 0; If the
 * job array exists NULL element, it will be passed. We
 * only push nonNULL job.
 *
 * $1  The target joblist entity.
 * $2  A job array with nullable literal constant 
 *     JOB_ARRAY_STOP_ELEMENT at the tail.
 *
 * Return the actual pushed job count.
 */
extern int ez_joblist_push_m (pez_joblist, pez_job []);

/*
 * TODO Considering the design again and again !!!
 * Destroy a joblist. If this list exists at list one
 * job which status is waiting. This function will be
 * blocked until the job being scheduled by idle thread.
 * Then free all the memory.
 */
extern void ez_joblist_destroy (pez_joblist*);

#endif // ~ _EZ_JOB_LIST_H_

