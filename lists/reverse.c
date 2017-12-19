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
node* reverse(node* list);

int main() {
    printf("Hello World!\n");
  
    node* a = create_node(1);
    node* cur = a;
    int i = 2;
    while (i <= 9) {
        cur->next = create_node(i);
        cur = cur->next;
        i += 2;
    }
    print_list(a);

    node* r = reverse(a);
    print_list(r);
   
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

node* reverse(node* list) {
    assert(list != NULL);

    node* prev = NULL;
    node* current = list;
    node* next = NULL;
    while (current != NULL) {
        
        next = current->next;

        current->next = prev;
        prev = current;

        current = next;
    }
    return prev;
}