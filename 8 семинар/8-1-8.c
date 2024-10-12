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
    char* pstr = (char*)malloc(sizeof(char));
    if (pstr == NULL)
        printf("Error. Can't allocate memory!\n");
    Book* p = (Book*)malloc(sizeof(Book));
    if (p == NULL)
        printf("Error. Can't allocate memory!\n");
    char** pstr_heap = (char**)malloc(sizeof(char*));
    if (pstr_heap == NULL)
        printf("Error. Can't allocate memory!\n");
    *pstr_heap = &*pstr;
    strcpy(pstr, "Don Quixote");
    p->title = *pstr_heap;
    p->pages = 1000;
    p->price = 750.0;
    print_book(*p);
    free(pstr);
    free(p);
    free(pstr_heap);
}
