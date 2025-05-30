#include <stdio.h>
#include "mydata.h"
#include "srtf.h"
#include "priority.h"

#define NO_PROCCESS 100

int procCount = 5; // num of processes
int processesArrival[5] = {NO_PROCCESS, NO_PROCCESS, NO_PROCCESS, NO_PROCCESS, NO_PROCCESS}; // array for arrival times
int proccessesTime[5] = {NO_PROCCESS, NO_PROCCESS, NO_PROCCESS, NO_PROCCESS, NO_PROCCESS}; // array for time a process needs to finish
int proccessesName[5] = {NO_PROCCESS, NO_PROCCESS, NO_PROCCESS, NO_PROCCESS, NO_PROCCESS}; // array for ID's
int proccessesPriority[5] = {NO_PROCCESS, NO_PROCCESS, NO_PROCCESS, NO_PROCCESS, NO_PROCCESS}; // array for priorities
int currentProccess; 
int counter; // how many processes have been added at a given time
int accumulator; // stores temporary values of virtual functions
int results[50]; 


void cpu(int num, int time, int (*func)(int num, int time))
{
	func(num, time); // virtual CPU, runs virtual functions
}

void kill() // function to kill current process
{
	dataDelete(currentProccess);	
}

int square(int num, int time) // Virtual function, calculates the square of a given number
{
	dataPush(time, 2, 5); // creates new process, needs 2 timing units to finish and has priority 5
	accumulator = num * num;
	return accumulator;
}

int halve(int num, int time) // Another virtual function
{
	dataPush(time, 5, 2); // creates new process, needs 5 timing units to finish and has priority 2
	accumulator = num / 2;
	return accumulator;
}

int testFunc(int num, int time) // You get the idea, another virtual function
{
	dataPush(time, 10, 0); // Needs 10 timing units to finish and has MAX priority (0)
	accumulator = num + 2;
	accumulator = accumulator * 2;
	accumulator = accumulator - 5;
	accumulator = accumulator * 2;
	return accumulator;
}


void displayResults() // printing GAANT
{
	for (int i = 0; i < 50; i++)
	{
		if (results[i] != NO_PROCCESS) printf("%d: P%d\n", i+1, results[i]);
		else printf("%d: %s\n", i+1, "IDLE PROCCESS");
	}
}


int main(void)
{

	for (int e = 0; e < 50; e++) results[e] = NO_PROCCESS; 
	for (int i = 0; i < 50; i++)
	{
		// example 1 for PRIORITY algorithm: 
		//if (i == 0) cpu(5, 0, square); // at time 0 scheduler receives process SQUARE
		//if (i == 1) cpu(5, 1, testFunc);
		//initiatePriority(i);

		// example 2 for PRIORITY algorithm:
		if (i == 0) cpu(5, 0, testFunc);
		if (i == 5) cpu(8, 5, halve);
		initiatePriority(i);

		// example 1 for SRTF algorithm:
		//if (i == 0) cpu(10, 0, halve);
		//if (i == 2) cpu(5, 2, square);
		//if (i == 6) cpu(6, 6, halve);
		//initiateSrtf(i);

		// example 2 for SRTF algorithm:
		//if (i == 0) cpu(12, 0, testFunc);
		//if (i == 1) cpu(3, 1, square);
		//if (i == 6) cpu(2, 6, square);
		//if (i == 8) cpu(12, 8, square);
		//if (i == 10) cpu(9, 10, square);
		//initiateSrtf(i);

		// STARVATION EXAMPLE
		//if (i == 0) cpu(5, i, square);
		//if (i == 1) cpu(12, i, testFunc);
		//if (i == 5) cpu(2, i, testFunc);
		//if (i == 9) cpu(3, i, testFunc);
		//initiatePriority(i);
	}
	displayResults();
	printf("%d\n", accumulator); // no real need for this, it will just print the result of the last virtual function
}
