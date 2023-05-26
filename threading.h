/*
	Author: Kevin Ton,
	Project: POSIX Threading
	Filename: threading.h
*/

#ifndef THREADING_H
#define THREADING_H
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <string.h>

#define NUM_THREADS 8

using namespace std;

struct thread_data {
	int thread_id;
	string eventhread;
	string oddthread;
};

//void* sleepingthread(void* arg);
void *threadManagement(void *threadarg);
#endif
