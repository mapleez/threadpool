#ifdef _EZ_THREAD_POOL_H_
#	define _EZ_THREAD_POOL_H_

typedef struct _ez_threadpool* pez_threadpool, ez_threadpool;
typedef struct _ez_job* pez_job, ez_job;
typedef struct _ez_thread* pez_thread, ez_thread;

typedef void (*pez_func) (void*);

/*
 * Create a new threadpool. This function would be the 
 * first calling to use threadpool.
 * 
 * $1  Special a positive number to initialize threads.
 *     If a nagetive number or zero is passed, a NULL will
 *     be return.
 *
 * Return a new ez_threadpool pointer.
 */
extern pez_threadpool ez_threadpool_create (int);
extern void ez_threadpool_destory (pez_threadpool*);

/*
 * Submit a job to run. A job will be pushed into
 * inner job list, waiting an idle thread to pop, 
 * then running. That is, you can assume the submited
 * job is running after calling this function.
 *
 * $1  The threadpool entity.
 * $2  The function representing a job to run.
 * $3  The parameter pointer for job function. It
 * 	   depends on job functions.
 *
 * Return zero if successful, otherwise non zero.
 */
extern int ez_threadpool_submit (pez_threadpool, pez_func, void*);

/*
 * Submit multiple jobs to threadpool. Each job
 * will be pushed into inner job list in order,
 * waiting idle threads to pop and running them.
 *
 * $1  The threadpool entity.
 * $2  The job array.
 *
 * Return zero if successful, otherwise non zero.
 */
extern int ez_threadpool_submit_jobs (pez_threadpool, pez_job []);

/*
 * Wait all jobs in pez_threadpool to finish until
 * they returned and job list is empty.
 * 
 * $1  The threadpool entity.
 * $2  The waiting timeout. If -1 is given, Then the
 *     caller (generally the main thread) will be 
 *     blocked until all the jobs finished.
 */
extern void ez_threadpool_waitall (pez_threadpool, unsigned long);


#endif // ~ _EZ_THREAD_POOL_H_
