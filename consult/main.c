#include<stdio.h>
#include"menu.h"
#include"options.h"

int main(){
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
    }while(option!=3 && (option > 0 && option < 2)); //condition to stop the loop
    
    free(p);//release memory
    system("pause");//for windows
    return 0;
}
