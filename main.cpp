/*
	Author: Kevin Ton,
	Project: POSIX Threading
	Filename: main.cpp
*/

#include <fstream>
#include "threading.h"
#include <semaphore.h>

using namespace std;

sem_t FLAG;
struct thread_data td[NUM_THREADS];
pthread_t threads[NUM_THREADS];
pthread_attr_t attr;
void *status;

void* thread(void* arg) {
//	sem_init(&FLAG, 0, 1);
	int rc;
	int i;
	void *status;
	pthread_t threads[NUM_THREADS];
	pthread_t ptid = pthread_self();
	ofstream out("QUOTE.txt");
	out << "Process ID: " << ptid << endl;

	for( i = 1; i < NUM_THREADS; i++ ) {
		
	sem_wait(&FLAG);
		if(NUM_THREADS % 2 == 0) {
			out << "Thread ID " << i << "\"Controlling complexity is the essence of computer programming.\" --Brian Kernigan" << endl;
		rc = pthread_create(&threads[i], NULL, threadManagement, (void *)&td);
		}
	sleep(3);

	for (int j = i + 1; j < NUM_THREADS; j++) {
		if(NUM_THREADS % 2 == 0) {
			out << "Thread ID " << i << ": " << "\"Computer science is no more about computers than astronomy is about telescopes.\" -Edsger Dijkstra" << endl;
		rc = pthread_join(threads[i], &status);
		//rc = pthread_join(&threads[i], NULL, threadManagement, (void *)&td);
		}
	}
	sem_post(&FLAG); 
}
	out.close();
}

int main(){
//	struct thread_data td[NUM_THREADS];
//	int i;
	sem_init(&FLAG, 0, 1);
	int i;
	int rc;
//	eventhreads();
//	pthread_t threads[NUM_THREADS];
//	pthread_t ptid = pthread_self();
	pthread_t t1, t2;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
//	ofstream out("QUOTE.txt");
//	out << "Process ID: " << ptid << endl;	
	for( i = 1; i < NUM_THREADS; i++ ) {
		cout << "Creating thread, in main(): " << i << endl;
		td[i].thread_id = i;

		//rc = pthread_create(&threads[i], &attr, threadManagement, (void *)i);
		rc = pthread_create(&threads[i], NULL, threadManagement, (void *)&td[i]);
	/*	pthread_create(&t1, NULL, thread, NULL);
		sleep(2);
		pthread_create(&t2, NULL, thread, NULL);
		pthread_join(t1, NULL);
		pthread_join(t2, NULL); */
/*		if(NUM_THREADS % 2 == 0){
			out << "Thread ID " << i << ": " << "\"Controlling complexity is the essence of computer programming.\" --Brian Kernigan" << endl;
		}
		for(int j = i + 1; j < NUM_THREADS; j++) {
			if(NUM_THREADS % 2 == 0) {
				out << "Thread ID " << i << ": " << "\"Computer science is no more about computers than astronomy is about telescopes.\" -Edsger Dijkstra" << endl;
			}
		} */
	//	td[i].message = "Thread";
		//rc = pthread_create(&threads[i], NULL, threadManagement, (void *)&td[i]);

		if (rc) {
			cout << "Error" << rc << endl;
			exit(-1);
		}
	}
	pthread_create(&t1, NULL, thread, NULL);
	sleep(2);
	pthread_create(&t2, NULL, thread, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	cout << "All Threads have completed their tasks" << endl;
	pthread_exit(NULL);
//	out.close();
	sem_destroy(&FLAG);
	return 0;
}
