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
    Book** p = (Book**)malloc(sizeof(Book*));
    Book* p1 = (Book*)malloc(sizeof(Book));
    strcpy(p1->title, "Don Quixote");
    p1->pages = 1000;
    p1->price = 750.0;
    *p = &*p1;
    print_book(**p);
}