#include <stdio.h>  
#include <stdlib.h>  
//定义结点  
typedef struct __Node{  
    int data;  
    struct __Node *pre;  
    struct __Node *next;  
}Node;  

//定义带头结点的双向链表  
typedef struct __doublyLinkedList{  
    Node * head;  
}dLinkedList;
  
//初始化：头结点置空  
void init(dLinkedList *L){  
    if(L == NULL){  
        printf("list error\n");  
        return;  
    }  
    L->head = NULL;  
}
  
//插入数据
void insert(dLinkedList *L, int data){  
    Node *p = NULL;  
    if(L == NULL){  
        printf("list not exist\n");  
        return;  
    }  
      
    p = (Node*)malloc(sizeof(Node));  
    if(p == NULL){  
        printf("bad alloc!\n");  
        return;  
    }  
    p->data = data;  
    p->next = L->head;  
    if(L->head != NULL){  
        L->head->pre = p;  
    }  
    p->pre = NULL;  
    L->head = p;  
}
  
Node *search(dLinkedList L, int data){  
    Node *p = NULL;  
    if(L.head == NULL){  
        printf("list is empty\n");  
        return NULL;  
    }  
    p = L.head;  
      
    while(p != NULL && p->data != data){  
        p = p->next;  
    }  
    if(p != NULL){  
        printf("search %d success\n", data);  
        return p;  
    }  
    else{  
        printf("search %d failed\n", data);  
        return NULL;  
    }  
}  
void deleteFirstData(dLinkedList *L){  
    Node *p = NULL;  
    if(L == NULL){  
        printf("list error!\n");  
        return;  
    }  
    if(L->head == NULL){  
        printf("empty list!\n");  
        return;  
    }  
      
    p = L->head;  
    //only one element  
    if(p->next == NULL){  
        L->head = NULL;  
        free(p);  
        p = NULL;  
        printf("success delete first!\n");  
        return;  
    }  
    else{  
        L->head = p->next;  
        L->head->pre = NULL;  
        free(p);  
        p = NULL;  
        printf("success delete first!\n");  
        return;  
    }  
      
}  
void deleteData(dLinkedList *L, int data){  
    Node *p = NULL;  
    Node *pre = NULL;  
    printf("search...\n");  
    if((p = search(*L, data)) == NULL){  
        printf("delete %d failed\n", data);  
        return;  
    }  
    else{  
        //first element  
        if(p == L->head){  
            deleteFirstData(L);  
            return;  
        }  
        //last element  
        else if(p->next == NULL){  
            pre = p->pre;  
            pre->next = NULL;  
            free(p);  
            p = NULL;  
            printf("delete last success\n\n");  
            return;  
        }  
        else{  
            pre = p->pre;  
            pre->next = p->next;  
            p->next->pre = pre;  
            free(p);  
            p = NULL;  
            printf("delete %d success\n\n", data);  
            return;  
        }  
    }  
}  

void traversal(dLinkedList L){  
    Node *p = NULL;  
    if(L.head == NULL){  
        printf("empty list!\n");  
        return;  
    }  
    p = L.head;  
    while(p != NULL){  
        printf("%d ", p->data);  
        p = p->next;  
    }  
    printf("\niterator success\n\n");  
}  

void destroy(dLinkedList *L){  
    Node *p = NULL;  
    Node *temp = NULL;  
    if(L == NULL){  
        printf("list error\n");  
        return;  
    }  
    printf("destory list...\n");  
    p = L->head;  
    while(p != NULL){  
        temp = p;  
        p = p->next;  
        free(temp);  
        temp = NULL;  
    }  
    L->head = NULL;  
    printf("destory success!\n");  
}  

int main(int argc, char **args){  
    dLinkedList L;  
    int i;  
    memset(&L, 0, sizeof(dLinkedList));  
    init(&L);  
    traversal(L);  
    for(i=0;i<20;++i){  
        insert(&L, i);  
    }  
    traversal(L);  
    deleteFirstData(&L);  
    deleteFirstData(&L);  
    traversal(L);  
      
    deleteFirstData(&L);  
    deleteData(&L, 10);  
    deleteData(&L, 16);  
    deleteData(&L, 0);  
    traversal(L);  
      
    insert(&L, 100);  
    insert(&L, 99);  
    insert(&L, 98);  
    insert(&L, 97);  
    traversal(L);  
    deleteData(&L, 99);  
    deleteData(&L, 97);  
    deleteData(&L, 96);  
    traversal(L);  
    destroy(&L);  
    return 0;  
} 
