#include<stdio.h>
#include"menu.h"
#include"options.h"
#include"calendar.h"
#ifndef MAXSTEPS
#define MAXSTEPS 10
#endif

enum option{REGISTER = 1,SEARCH = 2,EXIT = 3,EXTRA = 4};
int numSteps = 0;
const int numOptions = 4;
int main(int argc, char *argv[]) {
    //initilization of variables
    int option = 0;
    int maxPersons = 1;
    Person * p = calloc(maxPersons,sizeof(Person));
    FILE * fp = fopen("log.txt","a+");
    calendar* c = calloc(1,sizeof(calendar));
    c->days = (day**) calloc(1,sizeof(day*));
    for(int i = 0; i < 4; i++){
        c->days[i] = calloc(7,sizeof(day));
        for(int j = 0; j < 7; j++){
            c->days[i][j].numDay = i;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 7; j++){
            printf("%d ",c->days[i][j].numDay);
        }
        printf("\n");
    }
    int currentPersons = 0;
    char name[20];
    //loop to execute the menu
    if(p == NULL) {
        if(strcmp(argv[1],"-f") == 0){
            while(p==NULL){
                printf("Retrying to allocate memory\n");
                p = calloc(maxPersons,sizeof(Person));
            }
        }
        else{
        printf("Memory error\n");
        return 1;
        }
    }
    do{
        printMenu();
        getOption(&option);
        switch(option){
            case REGISTER:
                doRegister(p,&maxPersons,&currentPersons);
                break;
            case SEARCH:
                doSearch(&currentPersons,p);
                break;
            case EXIT:
                doExit();
                break;
            case EXTRA:
                doExtra();
                break;
            default:
                printf("Invalid option\n");
                break;
        }
        fprintf(fp,"Actions taken so far: %d\n",numSteps);
    }while(option!=3 && (option > 0 && option <= numOptions) && numSteps < MAXSTEPS); //condition to stop the loop
    
    if(numSteps >= MAXSTEPS) 
        printf("Maximum number of steps reached\n");

    fclose(fp);//close file
    free(p);//release memory
    printf("Actions taken: %d\n",numSteps);
    system("pause");//for windows
    return 0;
}
