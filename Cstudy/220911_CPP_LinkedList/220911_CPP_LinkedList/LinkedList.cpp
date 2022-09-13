#include <iostream>
#include <string>

using namespace std;
/*
typedef struct node {
    struct node* prev;
    struct node* next;
    int value;
} Node;

void initNode(Node** node) {
    *node = new Node;
    (*node)->prev = (*node)->next = NULL;
}

Node* getNode(int value, Node* prev, Node* next) {
    Node* node = new Node;
    node->value = value;
    node->prev = prev;
    node->next = next;
    return node;
}

void insertData(Node* headerNode, Node* tailNode, int value) {
    Node* node = headerNode;
    Node* newNode = getNode(value, NULL, NULL);

    while (node->next != tailNode) {
        if (node->value < newNode->value) {
            // newNode ÀÛ¾÷
            newNode->prev = node->prev;
            newNode->next = node;

            // 
            node->prev->next = newNode;
            node->prev = newNode;
            return;
        }
        node = node->next;
    }

    tailNode->prev = newNode;
    newNode->next = tailNode;
    node->next = newNode;
    newNode->prev = node;
}

void printNode(Node* headerNode) {
    Node* node = headerNode->next;
    while (node != NULL) {
        printf(" %d", node->value);
        node = node->next;
    }
}

int main(void) {

    Node* H;

    initNode(&H);

    while (1) {
        int num;
        scanf("%d", &num);

        if (num == 0)
            break;

        insertData(H, num);
    }

    printNode(H);

    return 0;
}
*/
/*

#include <iostream>
#include <string>

using namespace std;

typedef struct node {
   struct node *next;
   int value;
} Node;

void initNode(Node **node) {
   *node = new Node;
   (*node)->next = NULL;
}

Node *getNode(int value, Node *next) {
   Node *node = new Node;
   node->value = value;
   node->next = next;
   return node;
}

void insertData(Node *headerNode, int value) {
   Node *node = headerNode;
   Node *newNode = getNode(value, NULL);

   while (node->next != NULL) {
      if (node->next->value < newNode->value) {
         newNode->next = node->next;
         node->next = newNode;
         return;
      }
      node = node->next;
   }

   node->next = newNode;
}

void printNode(Node *headerNode) {
   Node *node = headerNode->next;
   while (node != NULL) {
      printf(" %d", node->value);
      node = node->next;
   }
}

int main(void) {

   Node *H;

   initNode(&H);

   while (1) {
      int num;
      scanf("%d", &num);

      if (num == 0)
         break;

      insertData(H, num);
   }

   printNode(H);

   return 0;
}

*/