#ifdef _EZ_THREAD_POOL_H_
#	define _EZ_THREAD_POOL_H_

typedef struct _ez_threadpool* pez_threadpool, ez_threadpool;
typedef struct _ez_job* pez_job, ez_job;
// typedef struct _ez_joblist* pez_joblist, ez_joblist;
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
extern void ez_threadpool_destory (pez_threadpool);

/*
 * Submit a job to run.
 */
extern int ez_threadpool_submit (pez_func, void*);
extern int ez_threadpool_submit_jobs (pez_job []);
extern int ez_threadpool_waitall (pez_threadpool);



#endif // ~ _EZ_THREAD_POOL_H_
