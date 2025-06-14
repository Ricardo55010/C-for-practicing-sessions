#include"../menu.h"
#include"../options.h"
#include<assert.h>
int numSteps = 0;

void testNumSteps(int counter);

int main(int argc, char *argv[]) {
    int counter = 0;
    printMenu();
    testNumSteps(counter);
    system("pause");
    return 0;
}

void testNumSteps(int counter){
    printf("numSteps: %d\n",numSteps);
    printf("counter: %d\n",counter);
    assert(numSteps == counter);
} 