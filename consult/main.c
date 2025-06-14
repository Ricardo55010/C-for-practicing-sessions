#include<stdio.h>
#include"menu.h"
#include"options.h"

int numSteps = 0;
int main(){
    printf("Steps taken so far: %d\n",numSteps);
    //initilization of variables
    int option = 0;
    int maxPersons = 1;
    Person * p = calloc(maxPersons,sizeof(Person));
    int currentPersons = 0;
    char name[20];
    //loop to execute the menu
    do{
        printMenu();
        getOption(&option);
        if(option == 1){
            doRegister(p,&maxPersons,&currentPersons);
        }
        if(option == 2){
            doSearch(&currentPersons,p);
        }
        if(option == 3){
            doExit();
        }
        if(option == 4){
            doExtra();
        }
    }while(option!=3 && (option > 0 && option < 5)); //condition to stop the loop
    
    free(p);//release memory
    printf("Steps taken so far: %d\n",numSteps);
    system("pause");//for windows
    return 0;
}
