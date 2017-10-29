#ifdef _EZ_JOB_H_
#	define _EZ_JOB_H_

#include "ez_threadpool.h"

#	define JOB_STAT_INVALID 0
#	define JOB_STAT_RUN     1
#	define JOB_STAT_WAIT    2
#	define JOB_STAT_FINISH  3

/* A nullable literal constant for array. */
#	define JOB_ARRAY_STOP_ELEMENT {NULL, NULL, 0}

/*
 * A job entity.
 */
typedef struct _ez_job {
	/* Argument for running job. */
	void* _args;

	/* Function for this job. */
	pez_func _func;

	/* Job status flag. */
	int _status;
} * pez_job, ez_job;

/*
 * Create a job with function and its arguments ptr.
 * $1  function ptr.
 * $2  void ptr, point to argument structure for $1.
 * 
 * Return a new entity of job if successful. Otherwise
 * return NULL. 
 * 
 * Note: If $1 is NULL, this function will return NULL.
 *    For a job with no function is invalid !
 */
extern pez_job ez_job_create (pez_func, void*);

/*
 * Destory a job entity. This function will reverse the
 * memory and set ptr to NULL. Note the job function shell
 * not be interrupted if it's still running. 
 * 
 * Note: This function do not free the argument ptr!
 */
extern void ez_job_destroy (pez_job*);

#endif // ~ _EZ_JOB_H_

