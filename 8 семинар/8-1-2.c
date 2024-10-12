#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* p = (char*)malloc(sizeof(char)*9);
    if (p == NULL)
    printf("Error. Can't allocate memory!\n");
    strcpy(p,"Elephant");
    printf("%s\n", p);

    free(p);
}