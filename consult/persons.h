//structure of person
typedef  struct Person{
    char name[20];
    struct Person* parent;
} Person;