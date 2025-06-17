#include"options.h"
void doSearch(int * currentPersons, Person * p){
    char name[20];
    numSteps++;
    printf("Looking for the name: ");
    scanf("%s",&name);
    //iterate through the pointer to show all the names
    printf("This is the full list\n");
    for(int i = 0; i < *currentPersons; i++){
        printf("Person number %i %s",i,(p+i)->name);
        if(strcmp(p[i].name,name) == 0){
            printf("<----This is the person\n");
            printf("it has %d characters\n",strlen(p[i].name));
            printf("it has %d bytes\n",sizeof(p[i].name));
            if(p[i].parent != NULL){
                printf("it has a parent\n");
                printf("the parent name is %s\n",p[i].parent->name);
            }
        }
        printf("\n");
    }

    return;
};

void doRegister(Person * p, int* maxPersons, int* currentPersons){
    int haveParent = 0;
    numSteps++;
    //check if the array is full
    if(*currentPersons == *maxPersons){
        (*maxPersons) *= 2;
        p = realloc(p,*maxPersons * sizeof(Person));
    }
    //save new Persona
    printf("Register the name:"); 
    scanf("%s",&((p+*currentPersons)->name));
    printf("The name %s was registered\n",(p + *currentPersons)->name);
    printf("do you have a parent? 1 for yes, 0 for no: ");
    scanf("%d",&haveParent);
    if(haveParent == 1){
        printf("Register the parent name:"); 
        (p+*currentPersons)->parent = calloc(1,sizeof(Person));
        scanf("%s",&((p+*currentPersons)->parent->name));
        printf("The name %s was registered\n",((p+*currentPersons)->parent)->name);
    }
    //increase current number of persons in the pointer
    (*currentPersons) ++;
    printf("current persons: %d\n",*currentPersons);
    printf("max persons: %d\n",*maxPersons);
    return;
};

void doExit(){  
    numSteps++;
    printf("Goodbye\n");
    return;
}

void doExtra(){
    static int counter = 0;
    printf("Counter: %d\n",counter);
    counter ++;
}