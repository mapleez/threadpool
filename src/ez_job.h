#ifdef _EZ_JOB_H_
#	define _EZ_JOB_H_

#include "ez_threadpool.h"

#	define EMPTY_EZ_JOB {NULL, NULL}

// TODO define job status.

typedef struct _ez_job {
	void* _args;
	pez_func _func;

	int _status;
} * pez_job, ez_job;

extern pez_job ez_job_create (pez_func, void*);
extern pez_job ez_job_destory (pez_job*);
extern int ez_job_status (pez_job);

#endif // ~ _EZ_JOB_H_

