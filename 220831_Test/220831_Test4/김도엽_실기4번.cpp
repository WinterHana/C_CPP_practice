#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 1. 맴버
class Member
{
private:
	string ID;
	string nickname;
	string guildName;

public:
	string getID();
	string getName();
	void setName(string _name);	
	void setGuildName(string _guildName);

	Member(string _ID, string _nickname);
};

Member::Member(string _ID, string _nickname)
{
	ID = _ID;
	nickname = _nickname;
	guildName = "무소속";
}
string Member::getID()
{
	return this->ID;
}

string Member::getName()
{
	return this->nickname;
}

void Member::setName(string _name)
{
	this->nickname = _name;
}

void Member::setGuildName(string _guildName)
{
	this->guildName = _guildName;
}

// 2. 길드
class Guild
{
private:
	string name;
public:
	vector<Member> Members;
	string getName();
	Guild(string _name);
};

Guild::Guild(string _name)
{
	name = _name;
}

string Guild::getName()
{
	return this->name;
}

int main()
{
	vector<Guild> guildList;
	vector<Member> memberList;
	int order;
	string ID, name;

	while (true)
	{
		cout << "명령 번호 / 아이디 / 닉네임 또는 길드명 /" << endl;
		cin >> order >> ID >> name;
		switch (order)
		{
		case 1:
		{
			Member member(ID, name);
			memberList.push_back(member);
			break;
		}
		case 2:
		{
			for (int i = 0; i < memberList.size(); i++)
			{
				if (memberList[i].getID() == ID)
				{
					memberList[i].setName(name);
				}
			}
		}
		case 3:
		{
			for (int i = 0; i < guildList.size(); i++)
			{
				if (guildList[i].getName() == name)
				{

					guildList[i].Members.push_back()
				}
			}
		}
		}
	}


}