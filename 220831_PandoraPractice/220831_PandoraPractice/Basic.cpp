#include <iostream>
using namespace std;

// 1. ������
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

// 2. ������ �迭
/*
#include <iostream>
using namespace std;
int main() {
    int arr[30][30] = { 0 };
    int num = 1; // 1���� ����
    int times = 0;
    cout << "������ ������ ����� ���� ���ڸ� �Է����ּ���(1 - 30) : ";
    cin >> times;

    // ���� ó��
    if (times > 30 || times < 1) {
        cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�. ���α׷��� ����˴ϴ�.";
        return 0;
    }

    int count = times;

    int i_idx = 0; int j_idx = -1; // index control
    int flag = 1;

    while (num <= times * times) {
        // ���� ���
        for (int i = 0; i < count; i++)
        {
            j_idx += flag;
            arr[i_idx][j_idx] = num;
            num++;
        }

        count--; // times�� * 1 > (times - 1)�� * 2 > ... 

        // ���� ���
        for (int j = 0; j < count; j++)
        {
            i_idx += flag;
            arr[i_idx][j_idx] = num;
            num++;
        }

        flag *= -1; // ������, �Ʒ� �̵� <-> ����, �� �̵� ��ȯ
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

// 3. ���ڿ� �ݴ�� �Է��ϱ�
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
    cout << "���ڿ��� �Է��ϼ��� : ";
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

// ����� call by reference�� ���� 
// �׳� �ݴ�� ����ϴ� �Ŷ� context ��ü���� ���� x
void ReverseString(string& context)
{
    cout << "== �ε����� �ݴ�� �����ؼ� ����ϱ� ==" << endl;
    for (int i = StringLength(context); i >= 0; i--)
        cout << context[i];
    cout << endl;
}

// -1�� �� ������ �ڿ� \0���ڸ� �����ϱ� ����
// ����� call by value�� ����
// ����� �迭�� �ٲٴ°Ŷ� ���� ����� �޾ƾ� context�� ������ ���� ����
void ReverseString_another(string context)
{
    cout << "== �� �ʿ� �ִ� �ε����� �ٲ㼭 ����ϱ� ==" << endl;
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

// 4. �κ��丮
/*
#include <iostream>
using namespace std;

class Inventory
{
private:
    int** inventory; // ����
    int* inventory_m; // ����
    int n, m; // ���� �Ҵ��� �� �޴� ũ��
public:
    Inventory(int _n, int _m); // ������
    ~Inventory(); // �Ҹ���
    void GetItem(int _x, int _y); // ������ ���� ����
    void UseItem(int _x, int _y); // ������ ���� ����
    void PrintItem(); // ������ ���� ���
};

Inventory::Inventory(int _n, int _m)
{
    this->n = _n;
    this->m = _m;

    // 2���� ���� �Ҵ�
    this->inventory = new int* [m];
    for (int i = 0; i < m; i++)
    {
        inventory_m = new int[n];
        this->inventory[i] = inventory_m;
    }

    // �ʱ�ȭ�� ����� ���������� ���ư�
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

// 5. ���� �����
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    int menu;
    const char* firstFile = "test.txt"; // txt ����
    int user;
    int sum = 0;
    string score, avg; // �޸��忡 ���� ����
    string line; // ���߿� �Ѳ����� �ֿܼ� ����ϱ� ���� ��

    // ���� ����
    ofstream ofs;
    ofs.open(firstFile, std::ios::out | std::ios::trunc);
    if (ofs.fail())
    {
        cerr << "Error!" << "\n";
        exit(1);
    }
    // �̾ ����
    ofstream ofs_app;
    ofs_app.open(firstFile, std::ios::out | std::ios::app);
    if (ofs_app.fail())
    {
        cerr << "Error!" << "\n";
        exit(1);
    }
    // �б�
    ifstream ifs;
    ifs.open(firstFile, std::ios::out);
    if (!ifs)
    {
        cerr << "Error!" << "\n";
        exit(1);
    }

    while (true) {
        cout << "================" << endl;
        cout << "1. ���Ͽ� ���� ���� ���� ����" << endl;
        cout << "2. ���Ͽ� ���� ���� �̾ ����" << endl;
        cout << "3. ������ ���� ���� ���� �ܼ� â�� ���" << endl;
        cout << "4. ����" << endl;
        cout << "================" << endl;

        cout << "� �۾��� �����Ͻðڽ��ϱ�? : ";
        cin >> menu;

        switch (menu) {
        case 1: // 1. ���� �����
            cout << "�� ���� ������ ������? : ";
            cin >> user;

            cout << user << "���� ���� �� ������ �Է����ּ���, ����� ������ �����ϴ�." << endl;
            cout << "�������� �������� ��������" << endl;
            cout << "ex)" << endl << "100 80 90" << endl << endl;;

            for (int i = 0; i < user; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> score;
                    sum += stoi(score);
                    ofs.write(score.c_str(), score.size());  // ����� �°� �Է�
                    ofs << " ";
                    ofs.flush(); // �ٷ� �޸��忡 ���
                }
                avg = to_string((float)sum / 3); // ��ձ��� ���ؼ� �Է��ϱ�
                ofs.write(avg.c_str(), avg.size());
                ofs << '\n';
                ofs.flush(); // �ٷ� �޸��忡 ���
                avg.clear();
                sum = 0;
            }
            cout << "�Է� �Ϸ� �� ���Ͽ� ���� ���� ���� ���Ⱑ �Ϸ�Ǿ����ϴ�." << endl;

            break;

        case 2: // 2. �߰��� �����
            cout << "�� ���� ������ �߰��� ������? : ";
            cin >> user;

            cout << user << "���� ���� �� ������ �Է����ּ���, ����� ������ �����ϴ�." << endl;
            cout << "�������� �������� ��������" << endl;
            cout << "ex)" << endl << "100 80 90" << endl << endl;

            // case1�� ��Ʈ���� �ٸ�
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
            cout << "�Է� �Ϸ� �� ���Ͽ� ���� ���� �̾ ���Ⱑ �Ϸ�Ǿ����ϴ�." << endl;

            break;

        case 3: // 3. ������ ��� ���� ���� �ҷ�����
            cout << "������ ��� ���� ������ �ҷ��ɴϴ�." << endl;
            cout << "����� ������ �����ϴ�." << endl;
            cout << "�������� �������� �������� ���" << endl;
            cout << "ex)" << endl << "10 20 30 20.0" << endl << endl;

            while (!ifs.eof()) {
                getline(ifs, line);
                // line�� ������� �׳� ������. ���ϸ� �� �� �� ���� ����
                if (line.empty() == true)
                {
                    break;
                }
                cout << line << endl;
            }

            break;

        case 4: { // 4. ����
            cout << "���α׷��� �����մϴ�" << endl;
            ofs.close();
            ofs_app.close();
            ifs.close();
            return 0;
        }

        default: { // 5. ����ó��
            cout << "�ùٸ� ���� �Է����ּ���." << endl;;
            break;
        }
        }
    }
    return 0;
}

