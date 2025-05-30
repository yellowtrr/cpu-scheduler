#include <stdio.h>
#include "mydata.h"
#define NO_PROCCESS 100 

extern int processesArrival[5];
extern int proccessesTime[5];
extern int proccessesPriority[5];
extern int proccessesName[5];
extern int procCount;
extern int counter;
extern int results[50];
extern int currentProccess;

int getMinId(int currentTime) // finds process with the lowest remaining time
{
	int MinId = -1; // if no process, function will return -1
	int largeCONSTANT = NO_PROCCESS;
	for (int w = 0; w < procCount; w++)
	{
		if (currentTime >= processesArrival[w] && proccessesTime[w] > 0) 
		{
			if (proccessesTime[w] <= largeCONSTANT) 
			{
				largeCONSTANT = proccessesTime[w];
				MinId = w;
			}
		}
	}

	return MinId;
}

void initiateSrtf(int i) // algorithmos srtf
{

		currentProccess = getMinId(i); 
		if (currentProccess == -1) results[i] = NO_PROCCESS;
		else
		{
			if (proccessesTime[currentProccess] == 0) dataDelete(currentProccess); // finished process gets deleted
			else results[i] = proccessesName[currentProccess]; 

			proccessesTime[currentProccess]--; 
		}
	//}
}


