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

// ���
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

// ���� : ������������ �����
void insertList(Node* _headNode, int _value)
{
	Node* node = _headNode;
	Node *newNode = new Node(_value, nullptr, nullptr);

	while (node->next != _headNode)
	{
		// 1. �߰��� ������ ��ġ�� ã��
		if ((node->next)->value < newNode-> value)
		{
			// 1) newNode ����
			newNode->next = node->next;
			newNode->prev = node;

			// 2) �յ� node ����
			(node->next)->prev = newNode;
			node->next = newNode;

			return;
		}
		// ��ȸ
		node = node->next;
	}

	// 2. �� ���� ��� ����
	// 1) newNode�� ��� ���, �� �� ���� ����
	newNode->next = _headNode;
	newNode->prev = node;

	// 2) ��� ��尡 newNode�� ����
	_headNode->prev = newNode;
	// 3) �� ���� ��尡 newNode�� ����
	node->next = newNode;
}

// ����
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
	cout << "������ ��尡 �����ϴ�." << endl;
}
int main()
{
	// �ʱ�ȭ : ó�� ����� �� ���� ��带 ����Ű���� ��
	Node* head = new Node();
	head->prev = head;
	head->next = head;

	int order;
	int value;

	// �����
	while (true)
	{
		cout << "=================================================" << endl;
		cout << "1. ���� | 2. ���� | 3. ��� | �ٸ� ���� : ������" << endl;
		cout << "=================================================" << endl;
		cout << "��� ��ȣ �Է� : ";
		cin >> order;
		cout << "=================================================" << endl;
		switch (order)
		{
		case 1:
			cout << "������ ������ �Է����ּ���. : ";
			cin >> value;
			insertList(head, value);
			cout << "===���� DoubleLinkedList�Դϴ�.===" << endl;
			printList(head);
			break;
		case 2:
			cout << "������ ������ �Է����ּ���. : ";
			cin >> value;
			deleteList(head, value);
			cout << "===���� DoubleLinkedList�Դϴ�.===" << endl;
			printList(head);
			break;
		case 3:
			cout << "===���� DoubleLinkedList�Դϴ�.===" << endl;
			printList(head);
			break;
		default:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
			break;
		}
	}
}