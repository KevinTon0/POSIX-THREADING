/*
	Author: Kevin Ton,
	Project: POSIX Threading
	Filename: threading.cpp
*/

#include "threading.h"

using namespace std;

void *threadManagement(void *threadarg) {
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;
	
	cout << "Thread " << my_data->thread_id << " is running " << endl;
	//cout << " Message: " << my_data->message << endl;

	pthread_exit(NULL);
}

