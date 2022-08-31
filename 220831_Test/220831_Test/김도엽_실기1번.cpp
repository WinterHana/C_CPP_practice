#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	string name;
	int man;
	vector<string> rank;
	stack<string> reward;

	cin >> man;
	for (int i = 0; i < man; i++)
	{
		cin >> name;
		rank.push_back(name);
		reward.push(name);
	}

	cout << "<순위>" << endl;
	for (int i = 0; i < man; i++)
	{
		cout << rank[i] << endl;;
	}

	cout << "<시상식>" << endl;

	for (int i = 0; i < man; i++)
	{
		cout << reward.top() << endl;
		reward.pop();
	}
}