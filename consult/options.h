#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"persons.h"


void doRegister(Person * p, int* maxPersons, int* currentPersons);
void doSearch(int * currentPersons, Person * p);
void doExit();
void doExtra();

extern int numSteps;
