#include"menu.h"
inline void printMenu(){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    //print the first part of the menu
    printf("***********************************************************\n");
    printf("Welcome to our registration system, please choose an option\n");
    printf("Current time: %s\n",asctime(tm));
    printf("***********************************************************\n");
    printf("1- Register\n2- Search\n3- Exit\n4- Extra\n");
}

inline void getOption(int* option){
    scanf("%d",option);
    //based on the option, print the apporiate message
    switch(*option){
        case 1:
            printf("Register\n");
            break;
        case 2:
            printf("Search\n");
            break;
        case 3:
            printf("Exit\n");
            break;
        case 4:
            printf("Extra\n");
            break;
        default:
            printf("Invalid option\n");
            break;
    }
}