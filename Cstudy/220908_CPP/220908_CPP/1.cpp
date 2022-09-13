#include <iostream>
using namespace std;

// 접근지정자 기본 : public <-> 클래스는 private
typedef struct node {
	struct node *next;
	int value;
} Node;

	
int main(void)
{
	Node* H;
	H = new Node;
	H->next = NULL;

	// insert 1
	Node* node1 = new Node;
	node1->value = 10;
	node1->next = NULL;
	H->next = node1;

	Node* node2 = new Node;
	node1->value = 20;
	node1->next = NULL;
	
	
	return 0;
}