#include<stdio.h>
#include"menu.h"
#include"options.h"
int numSteps = 0;

int main(){
    //initilization of variables
    int option = 0;
    int maxPersons = 1;
    Person * p = calloc(maxPersons,sizeof(Person));
    FILE * fp = fopen("log.txt","a+");
    int currentPersons = 0;
    char name[20];
    //loop to execute the menu
    if(p == NULL) {
        printf("Memory error\n");
        return 1;
    }
    do{
        printMenu();
        getOption(&option);
        switch(option){
            case 1:
                doRegister(p,&maxPersons,&currentPersons);
                break;
            case 2:
                doSearch(&currentPersons,p);
                break;
            case 3:
                doExit();
                break;
            case 4:
                doExtra();
                break;
        }
        fprintf(fp,"Steps taken so far: %d\n",numSteps);
    }while(option!=3 && (option > 0 && option < 5)); //condition to stop the loop
    
    free(p);//release memory
    printf("Actions taken so far: %d\n",numSteps);
    system("pause");//for windows
    return 0;
}
