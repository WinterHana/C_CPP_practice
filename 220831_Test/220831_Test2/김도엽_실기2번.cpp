#include <iostream>
using namespace std;

class Robot {
protected:
	string name;
	virtual string work() = 0;
public:
	void Print() { cout << name << " : " << work(); }
};


class RedRobot : public Robot
{
public:
	string work();
	RedRobot();
};

RedRobot::RedRobot()
{
	name = "���� �κ�";
}
string RedRobot::work()
{
	return "��� ���� \n";
}

class YellowRobot : public Robot
{
public:
	string work();
	YellowRobot();
};

YellowRobot::YellowRobot()
{
	name = "��� �κ�";
}
string YellowRobot::work()
{
	return "�ػ��� �ֱ� \n";
}

class BlueRobot : public Robot
{
public:
	string work();
	BlueRobot();
};

BlueRobot::BlueRobot()
{
	name = "�Ķ� �κ�";
}
string BlueRobot::work()
{
	return "���� �ֱ� \n";
}

Robot* GetRobot(int _idx)
{
	switch (_idx)
	{
	case 1:
	{
		Robot* Red = new RedRobot();
		return Red;
		break;
	}

	case 2:
	{
		Robot * Yellow = new YellowRobot();
		return Yellow;
		break;
	}
	case 3:
	{
		Robot* Blue = new BlueRobot();
		return Blue;
		break;
	}
	default:
		break;
	}
}
int main()
{
	Robot* robot;
	int idx;
	while (1)
	{
		cin >> idx;
		if (idx == -1) break;
		robot = GetRobot(idx);
		robot->Print();
		delete robot;
	}

	return 0;
}