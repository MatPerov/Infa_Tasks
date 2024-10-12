#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char** p1 = (char**)malloc(sizeof(char*));
    if (p1 == NULL)
        printf("Error. Can't allocate memory!\n");
    char* p = (char*)malloc(sizeof(char) * 14);
    if (p == NULL)
        printf("Error. Can't allocate memory!\n");
    *p1 = &*p;
    strcpy(*p1, "Cats and Dogs");
    printf("%s\n", *p1);

    free(p1);
    free(p);
}