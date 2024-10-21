#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main()
{
    List list = init(4);
    print(&list);
    push_back(&list, 5);
    print(&list);
}
