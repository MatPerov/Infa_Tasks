#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dinarray.h"

int main()
{
    Dynarray a;
    init(&a, 0);
    push_back(&a, 10);
    push_back(&a, 20);
    push_back(&a, 30);
    print(&a);
    // проверка pop_back.
    printf("%i\n",pop_back(&a));
    print(&a);
    // проверка resize.
    push_back(&a, 30);
    printf("%i\n", a.size);
    resize(&a, 6);
    print(&a);
    printf("%i\n", a.size);
    resize(&a, 2);
    print(&a);
    // проверка shrink_to_fit.
    printf("size = %i, capacity = %i\n", a.size, a.capacity);
    shrink_to_fit(&a);
    printf("size = %i, capacity = %i\n", a.size, a.capacity);
    push_back(&a, 30);
    print(&a);
    // проверка shallow_copy.
    Dynarray b = shallow_copy(&a);
    print(&b);
    // проверка deep_copy.
    Dynarray c = deep_copy(&a);
    print(&c);
    printf("size = %i, capacity = %i\n", a.size, a.capacity);
    printf("size = %i, capacity = %i\n", c.size, c.capacity);
    destroy(&a);
}