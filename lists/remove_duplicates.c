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
void remove_duplicates(node* source);

int main() {
    printf("Hello World!\n");
  
    node* head = create_node(1);
    node* current = head;
    int i = 1;
    while (i <= 10) {
        current->next = create_node(i);
        current = current->next;
        current->next = create_node(i);
        current = current->next;
        i++;
    }
    print_list(head);
    remove_duplicates(head);
    print_list(head);
   
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

void remove_duplicates(node* source) {

    if (source == NULL) {
        return;
    }

    node* prev = source;
    node* current = source->next;

    while (current != NULL) {
       if (current->data == prev->data) {

           prev->next = current->next;


           current->next = NULL;
           free(current);

           current = prev->next;
           continue;
       }

        prev = current;
        current = current->next;
    }

}