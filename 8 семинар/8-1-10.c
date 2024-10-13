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

struct library
{
    Book* books;
    int number_of_books;
};
typedef struct library Library;
void library_create(Library* p, int number) {
    p->number_of_books = 3;
    p->books = (Book*)malloc(sizeof(Book) * p->number_of_books);
    if (p == NULL)
        printf("Error. Can't allocate memory!\n");
}
void library_set(Library a, int i, char title[50], int pages, float price) {
    a.books[i].pages = pages;
    a.books[i].price = price;
    strcpy(a.books[i].title, title);
}
Book* library_get(Library a, int i) {
    return &a.books[i];
}
void library_print(Library a) {
    for (int i = 0; i < a.number_of_books; i++) {
        print_book(a.books[i]);
    }
}
void library_destroy(Library* a) {
    free(a);
}
int main() {
    Library a;
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);
    library_print(a);
    print_book(*library_get(a, 1));
    library_destroy(&a);
}