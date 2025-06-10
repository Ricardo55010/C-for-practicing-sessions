#include"options.h"
void doSearch(int * currentPersons, Person * p){
    printf("Looking for the name: ");
    //iterate through the pointer to show all the names
    for(int i = 0; i < *currentPersons; i++){
        printf("Person number %i %s\n",i,p[i].name);
    }
    return;
};

void doRegister(Person * p, int* maxPersons, int* currentPersons){
    //check if the array is full
    if(*currentPersons == *maxPersons){
        (*maxPersons) *= 2;
        p = realloc(p,*maxPersons * sizeof(Person));
    }
    //save new Persona
    printf("Register the name:"); 
    scanf("%s",&((p+*currentPersons)->name));
    printf("The name %s was registered\n",(p + *currentPersons)->name);
    //increase current number of persons in the pointer
    (*currentPersons) ++;
    printf("current persons: %d\n",*currentPersons);
    printf("max persons: %d\n",*maxPersons);
    return;
};

void doExit(){  
    printf("Goodbye\n");
    return;
}   