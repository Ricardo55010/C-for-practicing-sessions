#include"menu.h"
void printMenu(){
    printf("Welcome to our registration system, please choose an optionq\n");
    printf("1- Register\n2- Search\n3- Exit\n");
}

void getOption(int* option){
    scanf("%d",option);
    if(*option == 1){
        printf("Register\n");
    }
    if(*option == 2){
        printf("Search\n");
    }
    if(*option == 3){
        printf("Exit\n");
    }   
    if(*option > 3 || *option < 1){
        printf("Invalid option\n");
    }
}