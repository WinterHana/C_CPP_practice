// 1. string ����
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	string singer;

	cout << song + "�� �θ� ������?" << endl;
	cout << "��Ʈ : ù���ڴ� " << elvis[0] << endl;

	getline(cin, singer);

	if (singer == elvis) cout << "�����Դϴ�!" << endl;
	else cout << "�����Դϴ�. ������ " << elvis << "�Դϴ�!" << endl;

	return 0;
}
*/

// 2. Class ����
#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int _r);
	~Circle();
	double getArea();
	int getRadius();
	void setRadius(int _r);
};

Circle::Circle()
{
	this->radius = 1;
}

Circle::Circle(int _r)
{
	this->radius = _r;
}

Circle::~Circle()
{
	cout << "�������� " << radius << "�� ���� �Ҹ��߽��ϴ�." << endl;
}

double Circle::getArea()
{
	return radius * radius * 3.14;
}

int Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(int _r)
{
	this->radius = _r;
}

int main()
{
	// Ŭ���� ��ü ��Ծ��
	/*
	Circle donut;
	Circle pizza(15);

	cout << "������ ���̴� " << pizza.getArea() << "�Դϴ�." << endl;

	// ��ü �����ͷ� ����
	Circle* p;
	p = &donut; 
	cout << "������ ���̴� " << p->getArea() << "�Դϴ�." << endl; // (*p).getArea

	// 2���� �迭
	Circle circles[2][3];

	circles[0][0].setRadius(1);
	circles[0][1].setRadius(2);
	circles[0][2].setRadius(3);
	circles[1][0].setRadius(4);
	circles[1][1].setRadius(5);
	circles[1][2].setRadius(6);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Circle [" << i << "," << j << "]�� ������ ";
			cout << circles[i][j].getArea() << "�Դϴ�" << endl;
		}
	
	}
	*/

	// ���� �Ҵ�
	int* p = new int(20);
	if (!p) return 0;
	cout << *p << endl;
	*p = 5;
	cout << *p << endl;
	int n = *p;
	cout << *p << " " << n << endl;
	delete p;

	Circle* q = new Circle(30);
	delete q;

	int* arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = new int[5];
	}

	for (int i = 0; i < 10; i++) delete[] arr[i];

	int k = 10; int m = 5;
	int** arr2 = new int* [k];
	for (int i = 0; i < k; i++)
	{
		arr2[i] = new int[m];
	}

	for (int i = 0; i < k; i++) delete[] arr2[i];
	delete[] arr2;
	return 0;
}