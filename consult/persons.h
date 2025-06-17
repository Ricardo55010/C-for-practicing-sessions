#ifndef PERSONS_H
#define PERSONS_H
//structure of person
typedef  struct Person{
    char name[20];
    struct Person* parent;
} Person;

#endif