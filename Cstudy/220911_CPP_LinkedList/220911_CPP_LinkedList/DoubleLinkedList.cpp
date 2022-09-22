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

// 출력
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

// 삭제
void deleteList(Node* _headNode, int _value)
{
	Node* node = _headNode->next;
	while (node != _headNode)
	{
		if (node->value == _value)
		{
			(node->prev)->next = node->next;
			(node->next)->prev = node->prev;
			delete node;
			return;
		}
		node = node->next;
	}
	cout << "삭제할 노드가 없습니다." << endl;
}
int main()
{
	// 초기화 : 처음 헤드의 양 쪽은 헤드를 가리키도록 함
	Node* head = new Node();
	head->prev = head;
	head->next = head;

	int order;
	int value;

	// 출력판
	while (true)
	{
		cout << "=================================================" << endl;
		cout << "1. 삽입 | 2. 삭제 | 3. 출력 | 다른 숫자 : 끝내기" << endl;
		cout << "=================================================" << endl;
		cout << "명령 번호 입력 : ";
		cin >> order;
		cout << "=================================================" << endl;
		switch (order)
		{
		case 1:
			cout << "삽입할 정수를 입력해주세요. : ";
			cin >> value;
			insertList(head, value);
			cout << "===현재 DoubleLinkedList입니다.===" << endl;
			printList(head);
			break;
		case 2:
			cout << "삭제할 정수를 입력해주세요. : ";
			cin >> value;
			deleteList(head, value);
			cout << "===현재 DoubleLinkedList입니다.===" << endl;
			printList(head);
			break;
		case 3:
			cout << "===현재 DoubleLinkedList입니다.===" << endl;
			printList(head);
			break;
		default:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
			break;
		}
	}
}