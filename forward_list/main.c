#include "include/s_list.h"
#include <stdio.h>
#include <string.h>

int compar(void *ptr_a, void *ptr_b){
    int a = *(int *)ptr_a;
    int b = *(int *)ptr_b;
    return (a <= b) ? -1 : 1;
}

void print(s_list *node){
    for(s_list *tmp = node; tmp != NULL; tmp = tmp->next){
        printf("%d", *(int *)tmp->data);
        if (tmp->next != NULL)
            printf("->");
    }
    printf("\n");    
}

int main(int argc, char* argv[]){
    s_list *list = slist_new_node(0);
    int arr[10] = {41, 7, 90, 21, 44, 89, 73, 61, 0, 11};
    for (int i = 0; i < 10; i++){
        list = slist_push_back(list, &(arr[i]));
    }
    printf("size of the list is %ld\n", slist_size(list));
    print(list);
    list = slist_delete_node(list, slist_get_node(list, 3), compar);
    list = slist_sort(list, compar);
    list = slist_reverse(list);
    print(list);
    list = slist_clear(list);
    if (slist_empty(list)){
        printf("clear\n");
    }
    return 0;
}