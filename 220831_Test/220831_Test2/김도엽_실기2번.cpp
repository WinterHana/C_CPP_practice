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
	name = "»¡°£ ·Îº¿";
}
string RedRobot::work()
{
	return "¹æ±ß ¿ô±â \n";
}

class YellowRobot : public Robot
{
public:
	string work();
	YellowRobot();
};

YellowRobot::YellowRobot()
{
	name = "³ë¶õ ·Îº¿";
}
string YellowRobot::work()
{
	return "¼Ø»çÅÁ ÁÖ±â \n";
}

class BlueRobot : public Robot
{
public:
	string work();
	BlueRobot();
};

BlueRobot::BlueRobot()
{
	name = "ÆÄ¶õ ·Îº¿";
}
string BlueRobot::work()
{
	return "À½·á ÁÖ±â \n";
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