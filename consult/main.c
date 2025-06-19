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
union unionExample{
    int registerOption;
    char searchOption;
}
;

struct MyFlags {
    unsigned int a : 1; // only 1 bit
    unsigned int b : 1; // only 1 bit
    unsigned int c : 2; // only 2 bit
};

char functionThatReceivesFunctionPointer(char(*functionToBeSent)(int,char)){
    return functionToBeSent(1,'a');
}
char functionToBeSent(int input1,char input2){
    return input1 + input2;
} 

int main(int argc, char *argv[]) {
    //initilization of variables
    int option = 0;
    int maxPersons = 1;
    union unionExample unionex;
    unionex.searchOption = 'a';
    printf("%c\n",unionex.searchOption);
    unionex.registerOption = 1;
    printf("%d\n",unionex.registerOption);
    struct MyFlags flags = {0, 1, 3};
    printf("%u\n",flags.a);
    printf("%u\n",flags.b);
    printf("%u\n",flags.c);
    char returnOfFunction = functionThatReceivesFunctionPointer(functionToBeSent);
    printf("argc: %c\n",returnOfFunction);
    Person * p = calloc(maxPersons,sizeof(Person));
    FILE * fp = fopen("log.txt","a+");
    calendar* c = calloc(1,sizeof(calendar));
    c->days = (day**) calloc(4,sizeof(day*));
    for(int i = 0; i < 4; i++){
        c->days[i] = calloc(7,sizeof(day));
        for(int j = 0; j < 7; j++){
            c->days[i][j].numDay = j+1;
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
