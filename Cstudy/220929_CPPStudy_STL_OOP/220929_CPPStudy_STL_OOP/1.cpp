#include <iostream>
#include <cstring>
using namespace std;

/* <클래스 관계>
*  1. 게임오브젝트 : 기본 설정값, 정보 불러오기, 공격, 대미지 입음(가상함수 -> 오버라이딩 유도)
*  2. 플레이어 - 게임오브젝트 상속 :  회복, 레벨업, 직업 설정, 대미지 입음(오버라이딩)
*  3. 몬스터 : 대미지 입음(오버라이딩)
*/

// 직업을 변경할 때 사용할 열거형
typedef enum PLAYER_CLASS {
	Warrior = 1,
	Archer,
	Wizard
} PlayerClass;

class GameObject {
protected:
	// 기본 설정값
	string job;
	string name;
	int level;
	int currentHp;
	int maxHp;
	int power;

	// 레벨업을 할 때 체력 증가 계수
	int levelUpHp;

	// 죽음 확인
	bool isDead;

public:
	// getter, setter 설정
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

	// 공통 함수
	void printInfo();											// 정보 출력
	virtual void attacking(GameObject& target) = 0;				// 주체가 공격했음을 알림
	void dameged(int _damage);									// 대미지를 입음
};

void GameObject::dameged(int _damage)
{
	currentHp -= _damage;
	cout << name << "의 남은 체력 : " << currentHp << " / " << maxHp << "\n";
	if (currentHp <= 0)
	{
		cout << name << "(직업 : " << job << ")" << "이 죽었습니다." << "\n";
		isDead = true;
	}
}

void GameObject::printInfo()
{
	cout << "닉네임 : " << name << "\n";
	cout << "직업 : " << job << "\n";
	cout << "레벨 : " << level << "\n";
	cout << "체력 : " << currentHp << " / " << maxHp << "\n";
	cout << "파워 : " << power << "\n";
}

class Player : public GameObject {
public:
	Player(string _name);							// 초보자 객체 생성
	void attacking(GameObject& target) override;
	void healing(int _heal);						// 회복할 때 사용
	void levelUp(int _upPoint);						// 레벨업 했을 때 능력치 상승
	void changeJob(PlayerClass _player);			// 직업 변경(클래스 변수의 정보를 변경하는 식)
};

Player::Player(string _name)
{
	this->name = _name;
	this->job = "초보자";
	this->level = 1;
	this->currentHp = 50;
	this->maxHp = 50;
	this->power = 10;
	this->levelUpHp = 10;
	this->isDead = false;
}

void Player::attacking(GameObject& target)
{
	cout << target.getName() << "에게 " << this->getPower() << "만큼의 데미지를 주었습니다." << "\n";
	target.dameged(power);
}

void Player::healing(int _heal)
{
	this->currentHp += _heal;
	if (currentHp > maxHp)
	{
		currentHp = maxHp;
	}
	cout << _heal << "만큼 회복하여 현재 HP는 " << this->getCurrentHp() << "입니다." << "\n";
}

void Player::levelUp(int _upPoint)
{
	level += _upPoint;
	maxHp += (levelUpHp * _upPoint);
	cout << _upPoint << "만큼 레벨 업 했습니다." << "\n";
}

void Player::changeJob(PlayerClass _player)
{
	switch (_player)
	{
	case Warrior:
	{
		cout << "전사로 전직했습니다." << "\n";
		this->job = "전사";
		this->level = 1;
		this->currentHp = 1000;
		this->maxHp = 1000;
		this->power = 20;
		this->levelUpHp = 50;
		break;
	}
	case Archer:
	{
		cout << "궁수로 전직했습니다." << "\n";
		this->job = "궁수";
		this->level = 1;
		this->currentHp = 700;
		this->maxHp = 700;
		this->power = 15;
		this->levelUpHp = 50;
		break;
	}
	case Wizard:
	{
		cout << "마법사로 전직했습니다." << "\n";
		this->job = "마법사";
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
	cout << target.getName() << "에게 공격받아 체력이 " << this->getPower() << "만큼 감소했습니다." << "\n";
	target.dameged(power);
}
int main(void)
{
	string name;
	cout << "=======================================" << "\n";
	cout << "[보스 잡자]" << "\n";
	cout << "접속을 환영합니다. 기본 정보를 입력해주세요 :)" << "\n";
	cout << "닉네임을 입력해주세요(띄어쓰기 금지) : ";
	cin >> name;
	Player player(name);
	Monster boss("보스", "boss", 10, 500, 500, 10);
	cout << "플레이어가 생성되었습니다. 정보는 다음과 같습니다." << "\n";
	player.printInfo();

	cout << "=======================================" << "\n";
	cout << "보스자 죽을 때까지 다음의 작업을 수행할 수 있습니다." << "\n";
	cout << "1 - 공격" << "\n"
		<< "2 - 체력 20 회복" << "\n"
		<< "3 - 직업 설정" << "\n"
		<< "4 - 레벨 업" << "\n"
		<< "5 - 현재 플레이어 정보 출력" << "\n"
		<< "6 - 종료" << "\n";
	cout << "=======================================" << "\n";

	int num = 0;
	while (true)
	{
		cout << "수행하실 작업을 입력해주세요 : ";
		cin >> num;
		switch(num) 
		{
		case 1:
		{
			player.attacking(boss);
			cout << "\n";
			if (boss.getIsDead() == true) 
			{
				cout << "보스를 물리쳤습니다!" << "\n";
				cout << "이용해주셔서 감사합니다." << "\n";
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
			cout << "주의 ) 해당 직업의 초기 스탯으로 적용됩니다." << "\n"
				<< "1 - 전사" << "\n"
				<< "2 - 마법사" << "\n"
				<< "3 - 궁수" << "\n"
				<< "4 - 취소" << "\n"
				<< "원하시는 직업을 입력해주세요 : ";
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
				cout << "직업을 변경하지 않았습니다." << "\n";
				break;
			default:
				cout << "잘못된 값을 입력했습니다." << "\n";
				break;
			}
			break;
		}
		case 4:
		{
			int level;
			cout << "레벨을 얼마나 올릴까요? : ";
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
			cout << "이용해주셔서 감사합니다." << "\n";
			return 0;
		}
		default:
		{
			cout << "잘못된 숫자를 입력하셨습니다" << "\n";
			break;
		}
		}

		cout << "\n";
		boss.attacking(player);			// 보스는 항상 턴이 끝나면 공격을 한다.(잘못된 숫자를 입력해도)
		cout << "\n";

		if (player.getIsDead() == true)
		{
			cout << "당신은 죽었습니다..." << "\n";
			cout << "이용해주셔서 감사합니다." << "\n";
			return 0;
		}
	}
	return 0;
}