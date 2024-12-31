PTHREAD.H API SECTION
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
int pthread_create(thread1, NULl, functionTheThreadWillExecute, argumentsTheFuncNeeds);

int pthread_exit(void *retval); // NOTE: terminates the thread. NOTE: retval is the return value of the thread.

int pthread_join(threadToWaitFor, void **retval); // NOTE: Waits for a thread to terminate and retrieves its return value via **retval.

pthread_t pthread_self(void); // NOTE: returns the thread id of the thread who called it.

int pthread_equal(pthread_t t1, pthread_t t2); // NOTE: checks if two thread's id are equal.


pthread_cleanup_pop(0) // NOTE : removes the callback cleanup function from the head of the list without executing it. 
pthread_cleanup_pop(0) // NOTE : removes the callback cleanup function from the head of the list and executing it. 
pthread_cleanup_push(cleanUpCallbackFunc,dynmicItem) // NOTE: register a callback function to the destructor stack which will get invoked once: 
                                                     // 01) a thead is canceld by other thread. 
                                                     // 02) pay attention: if the thread runs out of scope and we did not called pthread_cleanup_pop(1) then the callback clean up func wont execute ! 


pthread_mutex_t // NOTE: a data type which represents mutex variable. 
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER; // NOTE: a mutex variable must be initialize with PTHREAD_MUTEX_INITIALIZER or with the pthread_mutex_init() function.

pthread_mutex_lock(pthread_mutex_t *mutex); // NOTE : a way for a thread to lock a mutex. in the mutex is locked at the time pthread_mutex_lock is called the thread blocks until it is unlocked.
pthread_mutex_unlock(pthread_mutex_t *mutex); // NOTE a way for a thread to unlock a mutex. 

pthread_mutex_trylock(pthread_mutex_t* mutex); // NOTE : a way for a thread to lock a mutex asynchoarncly (without blocking).
                                               // 01) if the mutex is unlocked at the time of calling, the mutex becomes locked and the return value is 0.
                                               // 02) if the mutex is locked at the time of calling, the function returns instantly with a failure status of EBUSY.


// CONDITION VARIABLE :
pthread_cond_t qcond = PTHREAD_COND_INITIALIZER; // NOTE: before condition variable can be used it must be initalized by calling the pthread_cond_init func or staticly by PTHREAD_COND_INITALIZER.
                                                 // 01) the condition variable must be protected with mutex to avoid race condition. 

// SYNCHRONISED THREADS SECTION
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex); // NOTE: used to make a thread wait for a condition variable to be signaled.
                                                                     // NOTE: 01) cond is a pointer to a avriable the thread will wait on.

int pthread_cond_timedwait(pthread_cond_t *condVar, pthread_mutex_t *mutex, const struct timespec *abstime); // condVar is the condition we wait upon, mutex is the muted used to lock the condVar, obstime sets a limit on the time we wait.

pthread_cond_signal()

pthread_cond_broadcast()





TERMS SECTION
/*
Deadlock - a situation on which a thread enters a waiting state, waiting for some resource to become available, for indefinite amount of time. 
reasons that cause a deadlock: 
01) the same thread tries to lock the same mutex twice. (the first lock will work, but the second one will cause it to wait for ever since he is the one holding the lock.)
*/
