#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

void print_book(struct book b)
{
    printf("Book: %s, Pages: %i, Price: %g\n", b.title, b.pages, b.price);
}

int main() {
    char* pstr1 = (char*)malloc(sizeof(char)*12);
    char* pstr2 = (char*)malloc(sizeof(char)*8);
    char* pstr3 = (char*)malloc(sizeof(char)*12);

    if (pstr1 == NULL)
        printf("Error. Can't allocate memory!\n");
    if (pstr2 == NULL)
        printf("Error. Can't allocate memory!\n");
    if (pstr3 == NULL)
        printf("Error. Can't allocate memory!\n");
    Book* p = (Book*)malloc(sizeof(Book)*3);
    if (p == NULL)
        printf("Error. Can't allocate memory!\n");
    char** pstr_heap1 = (char**)malloc(sizeof(char*));
    if (pstr_heap1 == NULL)
        printf("Error. Can't allocate memory!\n");
    *pstr_heap1 = &*pstr1;
    char** pstr_heap2 = (char**)malloc(sizeof(char*));
    if (pstr_heap2 == NULL)
        printf("Error. Can't allocate memory!\n");
    *pstr_heap2 = &*pstr2;
    char** pstr_heap3 = (char**)malloc(sizeof(char*));
    if (pstr_heap3 == NULL)
        printf("Error. Can't allocate memory!\n");
    *pstr_heap3 = &*pstr3;
    strcpy(pstr1, "Don Quixote");
    strcpy(pstr2, "Oblomov");
    strcpy(pstr3, "The Odyssey");
    p[0].title = *pstr_heap1;
    p[0].pages = 1000;
    p[0].price = 750.0;
    p[1].title = *pstr_heap2;
    p[1].pages = 400;
    p[1].price = 250.0;
    p[2].title = *pstr_heap3;
    p[2].pages = 500;
    p[2].price = 500.0;
    print_book(p[0]);
    print_book(p[1]);
    print_book(p[2]);
    free(pstr1);
    free(pstr2);
    free(pstr3);
    free(p);
    free(pstr_heap1);
    free(pstr_heap2);
    free(pstr_heap3);
}