#include <stdio.h>
#include "mydata.h"
#define NO_PROCCESS 100

// we suppose that the lower the number, the higher the priority

extern int processesArrival[5];
extern int proccessesTime[5];
extern int proccessesPriority[5];
extern int proccessesName[5];
extern int procCount;
extern int counter;
extern int results[50];
extern int currentProccess;

int findPriority(int currentTime) // finds process with highest priority
{
	int MinId = -1; // if no process, function returns -1
	int largeCONSTANT = NO_PROCCESS;
	for (int j = 0; j < procCount; j++)
	{
		if (currentTime >= processesArrival[j] && proccessesTime[j] > 0)
		{
			if (proccessesPriority[j] <= largeCONSTANT || largeCONSTANT == NO_PROCCESS)
			{
				largeCONSTANT = proccessesPriority[j];
				MinId = j;
			}
		}
	}
	return MinId;
}

void initiatePriority(int i) 
{

		currentProccess = findPriority(i); 
		if (currentProccess == -1) results[i] = NO_PROCCESS;
		else
		{
			if (proccessesTime[currentProccess] == 0) dataDelete(currentProccess); // finished process gets deleted
			else
			{
				results[i] = proccessesName[currentProccess]; 
				proccessesTime[currentProccess]--;
			}
		}
}
