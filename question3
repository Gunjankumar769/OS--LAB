#include<stdio.h>
#include<pthread.h>

pthread_mutex_t R1= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t R2= PTHREAD_MUTEX_INITIALIZER; 
pthread_mutex_t R3= PTHREAD_MUTEX_INITIALIZER;

void * P1()
{
    // Creates deadlock problem
    pthread_mutex_lock(&R1);
    printf( "Thread A \n");
    pthread_mutex_lock(&R2);
    pthread_mutex_unlock(&R1);
    pthread_mutex_unlock(&R2);    
}
 
void * P2()
{
    // Creates deadlock problem
    pthread_mutex_lock(&R2);
    printf( "Thread B \n");
    pthread_mutex_lock(&R1);
    pthread_mutex_lock(&R3);	
    pthread_mutex_unlock(&R2);
    pthread_mutex_unlock(&R1);
    pthread_mutex_unlock(&R3);
	
}

void * P3()
{
    // Creates deadlock problem
    pthread_mutex_lock(&R3);
    printf( "Thread C \n");
    pthread_mutex_lock(&R2);	
    pthread_mutex_unlock(&R3);
    pthread_mutex_unlock(&R2);
	
}

 
void ExecuteThreads()
{
	pthread_t t1,t2,t3;
	pthread_create(&t1,NULL,P1,NULL);
	pthread_create(&t2,NULL,P2,NULL);
	pthread_create(&t3,NULL,P3,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	 
	  printf( "Finished");
}
 
int main()
{
    ExecuteThreads();
 
    return 0;
}
