#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

typedef struct{
    char name[20];
    
} Person;
int main(){
    int option = 0;
    int maxPersons = 1;
    Person * p = calloc(maxPersons,sizeof(Person));
    int currentPersons = 0;
    char name[20];
    

    do{
        printMenu();
        getOption(&option);
        if(option == 1){
            if(currentPersons == maxPersons){
                maxPersons *= 2;
                p = realloc(p,maxPersons*sizeof(Person));
            }
           printf("Register the name:"); 
           scanf("%s",&((p+currentPersons)->name));
           printf("The name %s was registered\n",(p+currentPersons)->name);
           currentPersons++;
           printf("current persons: %d\n",currentPersons);
           printf("max persons: %d\n",maxPersons);
        }
        if(option == 2){
            printf("Looking for the name: ");
            for(int i = 0; i < currentPersons; i++){
                printf("Person number %i %s\n",i,p[i].name);
            }
        }
        if(option == 3){
            printf("Goodbye\n");
        }
    }while(option!=3 && (option > 0 && option < 2));
    system("pause");
    return 0;
}
