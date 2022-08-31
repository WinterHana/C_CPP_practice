#include <iostream>
using namespace std;

// 1. 쉐도잉
/*
int main()
{
	int apples = 5;
	if (apples >= 5)
	{
		int apples; 
		apples = 10;
		cout << apples << endl;
	}
	cout << apples << endl;

	return 0;
}
*/

// 2. 달팽이 배열
/*
#include <iostream>
using namespace std;
int main() {
    int arr[30][30] = { 0 };
    int num = 1; // 1부터 시작
    int times = 0;
    cout << "달팽이 베열을 만들기 위해 숫자를 입력해주세요(1 - 30) : ";
    cin >> times;

    // 예외 처리
    if (times > 30 || times < 1) {
        cout << "숫자를 잘못 입력하셨습니다. 프로그램이 종료됩니다.";
        return 0;
    }

    int count = times;

    int i_idx = 0; int j_idx = -1; // index control
    int flag = 1;

    while (num <= times * times) {
        // 가로 담당
        for (int i = 0; i < count; i++)
        {
            j_idx += flag;
            arr[i_idx][j_idx] = num;
            num++;
        }

        count--; // times번 * 1 > (times - 1)번 * 2 > ... 

        // 세로 담당
        for (int j = 0; j < count; j++)
        {
            i_idx += flag;
            arr[i_idx][j_idx] = num;
            num++;
        }

        flag *= -1; // 오른쪽, 아래 이동 <-> 왼쪽, 위 이동 전환
    }

    for (int i = 0; i < times; i++) {
        for (int j = 0; j < times; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/

// 3. 문자열 반대로 입력하기
/*
#include <iostream>
#include <string>
using namespace std;

int StringLength(string& context);
void PrintString(string& context);
void ReverseString(string& context);
void ReverseString_another(string context);

int main()
{
    string context;
    cout << "문자열을 입력하세요 : ";
    getline(cin, context);

    PrintString(context);
    ReverseString_another(context);
    ReverseString(context);

    return 0;
}

int StringLength(string& context)
{
    int num = 0;
    int i = 0;
    while (context[i] != '\0')
    {
        i++;
        num++;
    }
    return num;
}

void PrintString(string& context)
{
    for (int i = 0; i < StringLength(context); i++)
        cout << context[i];
    cout << endl;
}

// 여기는 call by reference로 받음 
// 그냥 반대로 출력하는 거라서 context 자체에는 영향 x
void ReverseString(string& context)
{
    cout << "== 인덱스를 반대로 설정해서 출력하기 ==" << endl;
    for (int i = StringLength(context); i >= 0; i--)
        cout << context[i];
    cout << endl;
}

// -1을 한 이유는 뒤에 \0문자를 제외하기 위함
// 여기는 call by value로 받음
// 여기는 배열을 바꾸는거라서 값의 복사로 받아야 context에 영향을 주지 않음
void ReverseString_another(string context)
{
    cout << "== 양 쪽에 있는 인덱스를 바꿔서 출력하기 ==" << endl;
    char temp;
    for (int i = 0; i < StringLength(context) / 2; i++)
    {
        temp = context[i];
        context[i] = context[StringLength(context) - i - 1];
        context[StringLength(context) - i - 1] = temp;
    }
    cout << context << endl;
}
*/

// 4. 인벤토리
/*
#include <iostream>
using namespace std;

class Inventory
{
private:
    int** inventory; // 세로
    int* inventory_m; // 가로
    int n, m; // 동적 할당할 때 받는 크기
public:
    Inventory(int _n, int _m); // 생성자
    ~Inventory(); // 소멸자
    void GetItem(int _x, int _y); // 아이템 개수 증가
    void UseItem(int _x, int _y); // 아이템 개수 감소
    void PrintItem(); // 아이템 개수 출력
};

Inventory::Inventory(int _n, int _m)
{
    this->n = _n;
    this->m = _m;

    // 2차원 동적 할당
    this->inventory = new int* [m];
    for (int i = 0; i < m; i++)
    {
        inventory_m = new int[n];
        this->inventory[i] = inventory_m;
    }

    // 초기화를 해줘야 정상적으로 돌아감
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inventory[i][j] = 0;
        }
    }
}
Inventory::~Inventory()
{
    for (int i = 0; i < m; i++)
    {
        delete[] inventory[i];
    }
    delete[] inventory;

}

void Inventory::GetItem(int _x, int _y)
{
    inventory[_y][_x]++;
}

void Inventory::UseItem(int _x, int _y)
{
    inventory[_y][_x]--;
}

void Inventory::PrintItem()
{
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << inventory[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    int x, y;
    char order;
    cin >> n >> m;
    Inventory myInventory(n, m);

    while (true)
    {
        cin >> order;
        if (order == 'g')
        {
            cin >> x >> y;
            myInventory.GetItem(x, y);
        }

        else if (order == 'u')
        {
            cin >> x >> y;
            myInventory.UseItem(x, y);
        }
        else if (order == 'p')
        {
            myInventory.PrintItem();
            break;
        }
        else
        {
            continue;
        }
    }
    return 0;
}
*/

// 5. 파일 입출력
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    int menu;
    const char* firstFile = "test.txt"; // txt 파일
    int user;
    int sum = 0;
    string score, avg; // 메모장에 적을 변수
    string line; // 나중에 한꺼번에 콘솔에 출력하기 위해 씀

    // 새로 쓰기
    ofstream ofs;
    ofs.open(firstFile, std::ios::out | std::ios::trunc);
    if (ofs.fail())
    {
        cerr << "Error!" << "\n";
        exit(1);
    }
    // 이어서 쓰기
    ofstream ofs_app;
    ofs_app.open(firstFile, std::ios::out | std::ios::app);
    if (ofs_app.fail())
    {
        cerr << "Error!" << "\n";
        exit(1);
    }
    // 읽기
    ifstream ifs;
    ifs.open(firstFile, std::ios::out);
    if (!ifs)
    {
        cerr << "Error!" << "\n";
        exit(1);
    }

    while (true) {
        cout << "================" << endl;
        cout << "1. 파일에 유저 정보 새로 쓰기" << endl;
        cout << "2. 파일에 유저 정보 이어서 쓰기" << endl;
        cout << "3. 파일의 유저 정보 값을 콘솔 창에 출력" << endl;
        cout << "4. 종료" << endl;
        cout << "================" << endl;

        cout << "어떤 작업을 수행하시겠습니까? : ";
        cin >> menu;

        switch (menu) {
        case 1: // 1. 새로 만들기
            cout << "몇 명의 유저를 만들까요? : ";
            cin >> user;

            cout << user << "명의 유저 상세 정보를 입력해주세요, 양식은 다음과 같습니다." << endl;
            cout << "수학점수 국어점수 영어점수" << endl;
            cout << "ex)" << endl << "100 80 90" << endl << endl;;

            for (int i = 0; i < user; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> score;
                    sum += stoi(score);
                    ofs.write(score.c_str(), score.size());  // 사이즈에 맞게 입력
                    ofs << " ";
                    ofs.flush(); // 바로 메모장에 출력
                }
                avg = to_string((float)sum / 3); // 평균까지 구해서 입력하기
                ofs.write(avg.c_str(), avg.size());
                ofs << '\n';
                ofs.flush(); // 바로 메모장에 출력
                avg.clear();
                sum = 0;
            }
            cout << "입력 완료 및 파일에 유저 정보 새로 쓰기가 완료되었습니다." << endl;

            break;

        case 2: // 2. 추가로 만들기
            cout << "몇 명의 유저를 추가로 만들까요? : ";
            cin >> user;

            cout << user << "명의 유저 상세 정보를 입력해주세요, 양식은 다음과 같습니다." << endl;
            cout << "수학점수 국어점수 영어점수" << endl;
            cout << "ex)" << endl << "100 80 90" << endl << endl;

            // case1과 스트림만 다름
            for (int i = 0; i < user; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> score;
                    sum += stoi(score);
                    ofs_app.write(score.c_str(), score.size());
                    ofs_app << " ";
                    ofs_app.flush();
                }
                avg = to_string((float)sum / 3);
                ofs_app.write(avg.c_str(), avg.size());
                ofs_app << '\n';
                ofs_app.flush();
                avg.clear();
                sum = 0;
            }
            cout << "입력 완료 및 파일에 유저 정보 이어서 쓰기가 완료되었습니다." << endl;

            break;

        case 3: // 3. 파일의 모든 유저 정보 불러오기
            cout << "파일의 모든 유저 정보를 불러옵니다." << endl;
            cout << "양식은 다음과 같습니다." << endl;
            cout << "수학점수 국어점수 영어점수 평균" << endl;
            cout << "ex)" << endl << "10 20 30 20.0" << endl << endl;

            while (!ifs.eof()) {
                getline(ifs, line);
                // line이 비었으면 그냥 끝내기. 안하면 한 줄 더 띄우고 끝남
                if (line.empty() == true)
                {
                    break;
                }
                cout << line << endl;
            }

            break;

        case 4: { // 4. 종료
            cout << "프로그램을 종료합니다" << endl;
            ofs.close();
            ofs_app.close();
            ifs.close();
            return 0;
        }

        default: { // 5. 예외처리
            cout << "올바른 값을 입력해주세요." << endl;;
            break;
        }
        }
    }
    return 0;
}

