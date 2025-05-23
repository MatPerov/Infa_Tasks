#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(struct book b)
{
    printf("Book: %s, Pages: %i, Price: %g\n", b.title, b.pages, b.price);
}

int main() {
    Book* p = (Book*)malloc(sizeof(Book));
    if (p == NULL)
        printf("Error. Can't allocate memory!\n");
    p->pages = 1000;
    p->price = 750.0;
    strcpy(p->title, "Don Quixote");
    print_book(*p);
    free(p);
}
