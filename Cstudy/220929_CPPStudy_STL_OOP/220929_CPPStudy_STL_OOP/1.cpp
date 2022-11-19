#include <iostream>
#include <cstring>
using namespace std;

/* <Ŭ���� ����>
*  1. ���ӿ�����Ʈ : �⺻ ������, ���� �ҷ�����, ����, ����� ����(�����Լ� -> �������̵� ����)
*  2. �÷��̾� - ���ӿ�����Ʈ ��� :  ȸ��, ������, ���� ����, ����� ����(�������̵�)
*  3. ���� : ����� ����(�������̵�)
*/

// ������ ������ �� ����� ������
typedef enum PLAYER_CLASS {
	Warrior = 1,
	Archer,
	Wizard
} PlayerClass;

class GameObject {
protected:
	// �⺻ ������
	string job;
	string name;
	int level;
	int currentHp;
	int maxHp;
	int power;

	// �������� �� �� ü�� ���� ���
	int levelUpHp;

	// ���� Ȯ��
	bool isDead;

public:
	// getter, setter ����
	string getJob() { return this->job; }
	string getName() { return this->name; }
	int getLevel() { return this->level; }
	int getCurrentHp() { return this->currentHp; }
	int getMaxHp() { return this->maxHp; }
	int getPower() { return this->power; }
	bool getIsDead() { return this->isDead;  }

	void setJop(string _jop) { this->job = _jop; }
	void setName(string _name) { this->name = _name; }
	void setLevel(int _level) { this->level = _level; }
	void setCurrentHp(int _currentHp) { this->currentHp = _currentHp; }
	void setMaxHp(int _maxHp) { this->maxHp = _maxHp; }
	void setPower(int _power) { this->power = _power; }

	// ���� �Լ�
	void printInfo();											// ���� ���
	virtual void attacking(GameObject& target) = 0;				// ��ü�� ���������� �˸�
	void dameged(int _damage);									// ������� ����
};

void GameObject::dameged(int _damage)
{
	currentHp -= _damage;
	cout << name << "�� ���� ü�� : " << currentHp << " / " << maxHp << "\n";
	if (currentHp <= 0)
	{
		cout << name << "(���� : " << job << ")" << "�� �׾����ϴ�." << "\n";
		isDead = true;
	}
}

void GameObject::printInfo()
{
	cout << "�г��� : " << name << "\n";
	cout << "���� : " << job << "\n";
	cout << "���� : " << level << "\n";
	cout << "ü�� : " << currentHp << " / " << maxHp << "\n";
	cout << "�Ŀ� : " << power << "\n";
}

class Player : public GameObject {
public:
	Player(string _name);							// �ʺ��� ��ü ����
	void attacking(GameObject& target) override;
	void healing(int _heal);						// ȸ���� �� ���
	void levelUp(int _upPoint);						// ������ ���� �� �ɷ�ġ ���
	void changeJob(PlayerClass _player);			// ���� ����(Ŭ���� ������ ������ �����ϴ� ��)
};

Player::Player(string _name)
{
	this->name = _name;
	this->job = "�ʺ���";
	this->level = 1;
	this->currentHp = 50;
	this->maxHp = 50;
	this->power = 10;
	this->levelUpHp = 10;
	this->isDead = false;
}

void Player::attacking(GameObject& target)
{
	cout << target.getName() << "���� " << this->getPower() << "��ŭ�� �������� �־����ϴ�." << "\n";
	target.dameged(power);
}

void Player::healing(int _heal)
{
	this->currentHp += _heal;
	if (currentHp > maxHp)
	{
		currentHp = maxHp;
	}
	cout << _heal << "��ŭ ȸ���Ͽ� ���� HP�� " << this->getCurrentHp() << "�Դϴ�." << "\n";
}

void Player::levelUp(int _upPoint)
{
	level += _upPoint;
	maxHp += (levelUpHp * _upPoint);
	cout << _upPoint << "��ŭ ���� �� �߽��ϴ�." << "\n";
}

void Player::changeJob(PlayerClass _player)
{
	switch (_player)
	{
	case Warrior:
	{
		cout << "����� �����߽��ϴ�." << "\n";
		this->job = "����";
		this->level = 1;
		this->currentHp = 1000;
		this->maxHp = 1000;
		this->power = 20;
		this->levelUpHp = 50;
		break;
	}
	case Archer:
	{
		cout << "�ü��� �����߽��ϴ�." << "\n";
		this->job = "�ü�";
		this->level = 1;
		this->currentHp = 700;
		this->maxHp = 700;
		this->power = 15;
		this->levelUpHp = 50;
		break;
	}
	case Wizard:
	{
		cout << "������� �����߽��ϴ�." << "\n";
		this->job = "������";
		this->level = 1;
		this->currentHp = 500;
		this->maxHp = 500;
		this->power = 30;
		this->levelUpHp = 30;
		break;
	}
	}

}

class Monster : public GameObject {
public:
	Monster(string _name, string _job, int _level, int _currentHp, int _maxHp, int _power);
	void attacking(GameObject& target) override;
};


Monster::Monster(string _name, string _job, int _level, int _currentHp, int _maxHp, int _power)
{
	this->name = _name;
	this->job = _job;
	this->level = _level;
	this->currentHp = _currentHp;
	this->maxHp = _maxHp;
	this->power = _power;
}

void Monster::attacking(GameObject& target)
{
	cout << target.getName() << "���� ���ݹ޾� ü���� " << this->getPower() << "��ŭ �����߽��ϴ�." << "\n";
	target.dameged(power);
}
int main(void)
{
	string name;
	cout << "=======================================" << "\n";
	cout << "[���� ����]" << "\n";
	cout << "������ ȯ���մϴ�. �⺻ ������ �Է����ּ��� :)" << "\n";
	cout << "�г����� �Է����ּ���(���� ����) : ";
	cin >> name;
	Player player(name);
	Monster boss("����", "boss", 10, 500, 500, 10);
	cout << "�÷��̾ �����Ǿ����ϴ�. ������ ������ �����ϴ�." << "\n";
	player.printInfo();

	cout << "=======================================" << "\n";
	cout << "������ ���� ������ ������ �۾��� ������ �� �ֽ��ϴ�." << "\n";
	cout << "1 - ����" << "\n"
		<< "2 - ü�� 20 ȸ��" << "\n"
		<< "3 - ���� ����" << "\n"
		<< "4 - ���� ��" << "\n"
		<< "5 - ���� �÷��̾� ���� ���" << "\n"
		<< "6 - ����" << "\n";
	cout << "=======================================" << "\n";

	int num = 0;
	while (true)
	{
		cout << "�����Ͻ� �۾��� �Է����ּ��� : ";
		cin >> num;
		switch(num) 
		{
		case 1:
		{
			player.attacking(boss);
			cout << "\n";
			if (boss.getIsDead() == true) 
			{
				cout << "������ �����ƽ��ϴ�!" << "\n";
				cout << "�̿����ּż� �����մϴ�." << "\n";
				return 0;
			}
			break;
		}
		case 2:
		{
			player.healing(20);
			break;
		}
		case 3:
		{
			int job;
			cout << "���� ) �ش� ������ �ʱ� �������� ����˴ϴ�." << "\n"
				<< "1 - ����" << "\n"
				<< "2 - ������" << "\n"
				<< "3 - �ü�" << "\n"
				<< "4 - ���" << "\n"
				<< "���Ͻô� ������ �Է����ּ��� : ";
			cin >> job;
			switch (job)
			{
			case 1:
				player.changeJob(Warrior);
				break;
			case 2:
				player.changeJob(Wizard);
				break;
			case 3:
				player.changeJob(Archer);
				break;
			case 4:
				cout << "������ �������� �ʾҽ��ϴ�." << "\n";
				break;
			default:
				cout << "�߸��� ���� �Է��߽��ϴ�." << "\n";
				break;
			}
			break;
		}
		case 4:
		{
			int level;
			cout << "������ �󸶳� �ø����? : ";
			cin >> level;
			player.levelUp(level);
			break;
		}
		case 5:
		{
			player.printInfo();
			break;
		}
		case 6:
		{
			cout << "�̿����ּż� �����մϴ�." << "\n";
			return 0;
		}
		default:
		{
			cout << "�߸��� ���ڸ� �Է��ϼ̽��ϴ�" << "\n";
			break;
		}
		}

		cout << "\n";
		boss.attacking(player);			// ������ �׻� ���� ������ ������ �Ѵ�.(�߸��� ���ڸ� �Է��ص�)
		cout << "\n";

		if (player.getIsDead() == true)
		{
			cout << "����� �׾����ϴ�..." << "\n";
			cout << "�̿����ּż� �����մϴ�." << "\n";
			return 0;
		}
	}
	return 0;
}