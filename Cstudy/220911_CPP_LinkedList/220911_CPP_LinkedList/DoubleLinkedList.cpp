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

// ���� : �� �ȵ� �ù�;;
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
	cout << "������ ��尡 �����ϴ�.";
}
int main()
{
	Node* head = new Node();
	int order;
	int value;
	while (true)
	{
		cout << "1. ���� 2. ���� 3. ��� 4. ������" << endl;
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
			cout << "�߸��� ���� �Է��߽��ϴ�." << endl;
		}

	}

	

	return 0;
}