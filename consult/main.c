#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

typedef struct{
    char name[20];
    
} Person;
int main(){
    int option = 0;
    Person * p = calloc(1,sizeof(Person));

    do{
        printMenu();
        getOption(&option);
        if(option == 1){
           printf("Register the name:"); 
           scanf("%s",p->name);
           printf("The name %s was registered\n",p->name);
        }
    }while(option>3 || option <1);
    system("pause");
    return 0;
}
