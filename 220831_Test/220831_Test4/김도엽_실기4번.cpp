#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
* 현 문제 : guildList로 member가 넘어갈 때, 값의 복사가 일어남.
* >> 포인터로 해결해야함
* 
*/
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
	string getGuildName();
	void setName(string _name);	
	void setGuildName(string _guildName);

	Member(string _ID, string _nickname);
	Member();
};

Member::Member(string _ID, string _nickname)
{
	ID = _ID;
	nickname = _nickname;
	guildName = "무소속";
}
Member::Member()
{
	ID = "none";
	nickname = "none";
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

string Member::getGuildName()
{
	return this->guildName;
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
		cin >> order;
		switch (order)
		{
		case 1:
		{
			cin >> ID >> name;
			Member member(ID, name);
			memberList.push_back(member);
			break;
		}
		case 2:
		{
			cin >> ID >> name;
			for (int i = 0; i < memberList.size(); i++)
			{
				if (memberList[i].getID() == ID)
				{
					memberList[i].setName(name);
				}
			}
			break;
		}
		case 3:
		{
			cin >> ID >> name;
			bool MemberFind = false;
			bool GuildFind = false;
			Member* member;
			for (int k = 0; k < memberList.size(); k++)
			{
				if (memberList[k].getID() == ID)
				{
					member = memberList[k];
					MemberFind = true;
					break;
				}
			}
			
			if (member.getName() == "none")
			{
				cout << "맴버를 찾지 못했습니다.";
				break;
			}

			for (int i = 0; i < guildList.size(); i++)
			{
				if (guildList[i].getName() == name)
				{
					guildList[i].Members.push_back(member);
					GuildFind = true;
					break;
				}
			}
			if (GuildFind == false)
			{
				Guild guild(name);
				guild.Members.push_back(member);
				guildList.push_back(guild);

			}
			break;
		}
		case 4:
		{
			if (guildList.size() <= 0) break;
			for (int i = 0; i < guildList.size(); i++)
			{
				cout << guildList[i].getName() << endl;
			}
			break;
		}
		case 5:
		{
			cin >> name;
			for (int i = 0; i < guildList.size(); i++)
			{
				if (guildList[i].getName() == name)
				{
					for (int j = 0; j < guildList[i].Members.size(); j++)
					{
						cout << guildList[i].Members[j].getName() << endl;
					}
				}
				break;
			}
			break;
		}
		case 6:
		{
			cin >> ID;
			for (int i = 0; i < memberList.size(); i++)
			{
				if (memberList[i].getID() == ID)
				{
					cout << memberList[i].getGuildName() << endl;
					break;
				}
			}
			break;
		}
		case -1:
		{
			return 0;
		}

		default:
			break;
		}
	}


}