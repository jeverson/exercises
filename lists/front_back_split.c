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
void append_second_list(node** a, node** b);
void front_back_split(node** source, node** frontRef, node** backRef);

int main() {
    printf("Hello World!\n");
  
    node* head = create_node(10);
    node* current = head;
    int i = 11;
    while (i <= 20) {
        current->next = create_node(i);
        current = current->next;
        i++;
    }
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

void front_back_split(node** source, node** frontRef, node** backRef) {
    assert(source != NULL);
    
    node* slow = *source;
    node* fast = *source;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL && fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    *frontRef = *source;
    *backRef = slow->next;
  
    slow->next = NULL;
    source = NULL;    
}