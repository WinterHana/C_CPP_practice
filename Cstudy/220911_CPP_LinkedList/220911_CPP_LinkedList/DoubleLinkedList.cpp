#include <iostream>
#include <string>

using namespace std;
/*
typedef struct node {
	Node* prev;
	Node* next;
	int value;
}Node;
*/

class Node {
public:
	Node* prev;
	Node* next;
	int value;
	Node(int _value, Node* _prev, Node* next);
	Node();
};

Node::Node()
{
	value = NULL;
	prev = nullptr;
	next = nullptr;
}
Node::Node(int _value, Node* _prev, Node* _next)
{
	value = _value;
	prev = _prev;
	next = _next;
}

void printList(Node* _headNode)
{
	Node* node = _headNode->next;
	while (node != _headNode)
	{
		cout << " <-> " << node->value << " <-> ";
		node = node->next;
	}
	cout << endl;
}

// 삽입 : 내림차순으로 만들기
void insertList(Node* _headNode, int _value)
{
	Node* node = _headNode;
	Node *newNode = new Node(_value, nullptr, nullptr);

	while (node->next != _headNode)
	{
		// 1. 중간에 삽입할 위치를 찾음
		if ((node->next)->value < newNode-> value)
		{
			// 1) newNode 연결
			newNode->next = node->next;
			newNode->prev = node;

			// 2) 앞뒤 node 연결
			(node->next)->prev = newNode;
			node->next = newNode;

			return;
		}
		// 순회
		node = node->next;
	}

	// 2. 맨 끝에 노드 삽입
	// 1) newNode가 헤드 노드, 맨 끝 노드랑 연결
	newNode->next = _headNode;
	newNode->prev = node;

	// 2) 헤드 노드가 newNode랑 연결
	_headNode->prev = newNode;
	// 3) 맨 끝의 노드가 newNode랑 연결
	node->next = newNode;
}

// 삭제 : 왜 안돼 시바;;
void deleteList(Node* _headNode, int _value)
{
	Node* node = _headNode->next;
	while (node->next != _headNode)
	{
		if (node->value == _value)
		{
			(node->prev)->next = node->prev;
			(node->next)->prev = node->next;
			return;
		}
		node = node->next;
	}
	cout << "삭제할 노드가 없습니다.";
}
int main()
{
	Node* head = new Node();
	int order;
	int value;
	while (true)
	{
		cout << "1. 삽입 2. 삭제 3. 출력 4. 끝내기" << endl;
		cin >> order;
		switch (order)
		{
		case 1:
			cin >> value;
			insertList(head, value);
			break;
		case 2:
			cin >> value;
			deleteList(head, value);
			break;
		case 3:
			printList(head);
			break;
		case 4:
			return 0;
		default:
			cout << "잘못된 값을 입력했습니다." << endl;
		}

	}

	

	return 0;
}