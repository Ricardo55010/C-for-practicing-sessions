#include"menu.h"
inline void printMenu(){
    //print the first part of the menu
    printf("Welcome to our registration system, please choose an option\n");
    printf("1- Register\n2- Search\n3- Exit\n4- Extra\n");
}

inline void getOption(int* option){
    scanf("%d",option);
    //based on the option, print the apporiate message
    if(*option == 1){
        printf("Register\n");
    }
    if(*option == 2){
        printf("Search\n");
    }
    if(*option == 3){
        printf("Exit\n");
    }   
    if(*option == 4){
        printf("Extra\n");
    }
    if(*option > 4 || *option < 1){
        printf("Invalid option\n");
    }
}