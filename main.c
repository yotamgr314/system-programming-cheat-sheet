pthread_cleanup_pop(0) // NOTE : removes the callback cleanup function from the head of the list without executing it. 
pthread_cleanup_pop(0) // NOTE : removes the callback cleanup function from the head of the list and executing it. 
pthread_cleanup_push(cleanUpCallbackFunc,dynmicItem) // NOTE: register a callback function to the destructor stack which will get invoked once: 
                                                     // 01) a thead is canceld by other thread. 
                                                     // 02) pay attention: if the thread runs out of scope and we did not called pthread_cleanup_pop(1) then the callback clean up func wont execute ! 

