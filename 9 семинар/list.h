#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
    struct node* prev;
};
typedef struct node Node;

struct list
{
    Node* head;
    Node* tail;
    size_t size;
};
typedef struct list List;

void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}

void print(const List* pl)
{
    printf("List: ");
    Node* temp = pl->head;
    for (size_t i = 0; i < pl->size; ++i) {
        printf("%i ", temp->value);
        temp = temp->next;
    }

    printf("\n");
}

void clear(List* pl)
{
    for (size_t i = 0; i < pl->size; ++i) {
        ((pl->head)[i]).value = 0;
        if (i == 0) {
            ((pl->head)+i)->prev = NULL;
            ((pl->head)+i)->next = (pl->head)+ i + 1;
        }
        else if (i == pl->size - 1) {
            ((pl->head)+i)->prev = (pl->head)+i - 1;
            ((pl->head)+i)->next = NULL;
        }
        else {
            ((pl->head)+i)->prev = (pl->head)+i - 1;
            ((pl->head)+i)->next = (pl->head)+i + 1;
        }

    }
}

List init(size_t n) {
    List list;
    if (n == 0) {
        list.head = NULL;
        list.tail = NULL;
        list.size = 0;
    } 
    else {
        Node* pl = (Node*)ecmalloc(n * sizeof(Node));
        list.head = pl;
        list.tail = pl + n - 1;
        list.size = n;
        clear(&list);
    }
    return list;
}

void reserve(List* pl, size_t new_capacity)
{

    Node* new_data = (Node*)ecmalloc(new_capacity * sizeof(Node));

    for (size_t i = 0; i < pl->size; ++i)
    {
        new_data[i] = pl->head[i];
    }
    new_data[pl->size].value = 3;
    free(pl->head);
    pl->head = new_data;
}
void push_back(List* pl,int value) {
    reserve(pl, pl->size + 1);
    Node temp = { value,NULL,pl->head + pl->size - 1 };
    pl->head[pl->size-1].next = &temp;
    pl->head[pl->size] = temp;
    pl->size += 1;
}