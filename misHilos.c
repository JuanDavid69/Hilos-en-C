#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NTHREADS 50


void *do_nothing(void*);

int main(int argc, char *argv[]) {
	pthread_t tid;
	int j;

	for (j = 0; j < NTHREADS; j++) {
		pthread_create(&tid, NULL, do_nothing, NULL);
	}
	for (j = 0; j < NTHREADS; j++) {
		pthread_join(tid, NULL);
	}
	
	
	return 0;
}

void *do_nothing(void *null) {
	printf("Hola mi id es %ld\n", pthread_self());
	pthread_exit(NULL);
}            
