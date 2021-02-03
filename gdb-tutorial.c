#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void function_one();
extern int function_sub(int a, int b);
extern void function_two();

struct LinkedList {
    int data;
    struct LinkedList *next;
};

int main()
{   int x = 1;
    int int_full[8] = {0xdeadbeef, 0xb01dface,
                    0xf005ba11, 0x5ca1ab1e,
                    0xca11ab1e, 0xba5eba11,
                    0x0ddba11, 0xb0a710ad};
    char *str_init_ptr = "this is a constant string";

    function_one();
    function_two();
}

/**************************************************************************/
void function_one()
{
    int x = 10;
    int y = 5;
    int z;

    z = function_sub(x, y);
    printf("x-y is %d\n", z);
}

int function_sub(int a, int b)
{
    int q = a -b;
    printf("I have computed q as %d\n", q);
    return q;
}

/**************************************************************************/


struct LinkedList *root = NULL;

void function_two()
{
    int i;
    struct LinkedList *toor;
    for(i = 0; i < 4; i++) {
        struct LinkedList *ptr = malloc(sizeof(struct LinkedList));
        ptr -> data = i;
        ptr -> next = root;
        root = ptr;
    }

    /* Now, print out the list */
    toor = root;
    while (!toor) {
        printf("Data is %d\n", toor -> data);
        toor = toor -> next;
    }
}