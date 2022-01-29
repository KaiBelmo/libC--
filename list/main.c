#include "include/list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(d_list *list){
    for (node *i = list->head; i != NULL; i = i->next){
        if (i->prev != NULL)
            printf("<->");
        printf("\x1B[37;1m%d\x1B[0m", *(int *)i->data);
    }
    printf("\n");
}

int main()
{
    /*
    d_list *list = list_new(NULL);
    list = list_push_front(list, "aaaa");
    list = list_push_front(list, "uuuu");
    list = list_push_back(list, "bbbb");
    list = list_push_back(list, "cccc");
    list = list_push_back(list, "dddd");
    list = list_push_back(list, "eeee");
    list = list_insert_aftr_idx(list, "zzzz", 2);

    printf("%d\n", list->len);
    d_list *tmp = list_new("pppp");
    tmp = list_push_back(tmp, "oooo");
    tmp = list_push_back(tmp, "tttt");
    tmp = list_push_back(tmp, "rrrr");
    tmp = list_push_back(tmp, "wwww");
    d_list *a = list_concat(list, tmp);
    for (uint32_t  i = 0; i < list->len; i++){
        list = list_pop_front(list);
    }
    list = list_clear(list);
    if (list_empty(list) == true && list_empty(tmp) == true){
        printf("\nlist is empty\n");
    }
    */
    int a[5] = {3, 2, 7, 9, 17};
    int b[5] = {1, 4, 8, 19, 20};
    d_list *list_a = list_new(NULL);
    d_list *list_b = list_new(NULL);
    for (int i = 0; i < (int)(sizeof(a) / sizeof(a[1])); i++){
        list_a = list_push_back(list_a, &(a[i]));
    }
    for (int i = 0; i < (int)(sizeof(b) / sizeof(b[1])); i++){
        list_b = list_push_back(list_b, &(b[i]));
    }
    print(list_a);
    print(list_b);
    list_delete(list_a);
    list_delete(list_b);
    return 0;
}
