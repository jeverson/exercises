#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node;
struct node {
    int data;
    node* next;
};

node* create_node(int data);
void print_list(node* head);
node* sorted_merge(node* a, node* b);

int main() {
    printf("Hello World!\n");
  
    node* a = create_node(1);
    node* cur = a;
    int i = 2;
    while (i <= 2) {
        cur->next = create_node(i);
        cur = cur->next;
        i += 2;
    }
    print_list(a);

    node* b = create_node(2);
    cur = b;
    i = 3;
    while (i <= 9) {
        cur->next = create_node(i);
        cur = cur->next;
        i += 2;
    }
    print_list(b);

    node* m = sorted_merge(a, b);
    print_list(m);
   
    return 0;
}

node* create_node(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    return newNode;
}

void print_list(node* head) {
    printf("printing list: \n");
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node* sorted_merge(node* a, node* b) {
    assert(a != NULL || b != NULL);

    if (a == NULL) {
        return b;
    }

    if (b == NULL) {
        return a;
    }

    node* head;
    if (a->data < b->data) {
        head = a;
        a = a->next;
    }   
    else 
    {
        head = b;
        b = b->next;
    } 
    head->next = NULL;

    node* curr = head;
    while (a != NULL && b != NULL) {

        if (a->data < b->data) {
            curr->next = a;
            a = a->next;        
        } else  {
            curr->next = b;
            b = b->next;              
        }

        curr = curr->next;
        
    }  

    if (a != NULL) {
        curr->next = a;
    }  
    else {  
        curr->next = b;
    }
    
    return head;
}