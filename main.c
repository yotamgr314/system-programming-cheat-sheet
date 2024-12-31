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

TERMS SECTION
/*
Deadlock - a situation on which a thread enters a waiting state, waiting for some resource to become available, for indefinite amount of time. 

*/
