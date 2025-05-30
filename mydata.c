#include "mydata.h"

#define NO_PROCCESS 100

extern int processesArrival[5]; 
extern int proccessesTime[5];
extern int proccessesPriority[5];
extern int proccessesName[5];
extern int procCount;
extern int counter;

void dataPush(int arrival, int timeToFinish, int priority) // creates new process
{
    counter++;
    for (int i = procCount - 1; i > 0; i--)
    {
        processesArrival[i] = processesArrival[i - 1]; // processes that existed before get shifted to the right
        proccessesTime[i] = proccessesTime[i - 1];
        proccessesPriority[i] = proccessesPriority[i - 1];
        proccessesName[i] = proccessesName[i - 1];
    }

    processesArrival[0] = arrival; // new process is at index 0
    proccessesTime[0] = timeToFinish;
    proccessesPriority[0] = priority;
    proccessesName[0] = counter;

}

void dataDelete(int id) // deletes a process
{
    for (int k = id; k < procCount - 1; k++)
    {
        processesArrival[k] = processesArrival[k + 1]; 
        proccessesTime[k] = proccessesTime[k + 1];
        proccessesPriority[k] = proccessesPriority[k + 1];
        proccessesName[k] = proccessesName[k + 1];
    }

    processesArrival[procCount - 1] = NO_PROCCESS; 
    proccessesTime[procCount - 1] = NO_PROCCESS;
    proccessesPriority[procCount - 1] = NO_PROCCESS;
    proccessesName[procCount - 1] = NO_PROCCESS;

}
