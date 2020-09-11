#include <stdio.h>
#include <malloc.h>
#include <alloca.h>

extern void afunc(void);

int bss_var;
int data_var = 42;

int main(int argc, char **argv)
{
    char *p, *h;

    printf("Text Locations - \n");
    printf("\tAddress of main - %p\n", main);
    printf("\tAddress of afunc - %p\n", afunc);

    printf("Stack Locations - \n");
    afunc();

    p = (char *)alloca(32);
    if (p != NULL)
    {
        printf("\tStart of alloca()'ed array - %p\n", p);
        printf("\tEnd of alloca()'ed array - %p\n", p + 31);
    }

    printf("Data Locations - \n");
    printf("\tAddress of data_var - %p\n", &data_var);

    printf("BSS Locations - \n");
    printf("\tAddress of bss_var - %p\n", &bss_var);

    printf("Heap Location - \n");
    h = (char *)malloc(100);
    if (h != NULL)
    {
        printf("\tInitial End of heap - %p\n", h);
        printf("\tNew End of heap - %p\n", h + 99);
    }
}

void afunc(void)
{
    static int level = 0;
    auto int stack_var;

    if (++level == 3)
        return;

    printf("\tStack level %d, address of stack_var - %p\n",
           level, &stack_var);
    afunc();
}
