#include <iostream>
using namespace std;

class worrier {
private:	
	int hp = 200;
	int atk = 20;
	int def = 20;
	int money = 20;
	int ce = 320;
public:
	int get_hp() { return hp; }
	int get_atk() { return atk; }
	int get_def() { return def; }
	int get_money() { return money; }
	int get_ce() {
		ce = hp + atk * 3 + def * 3;
		return ce;
	}
	void modify(string, int);
	bool dead();
	void state();
}ethon;

int price[3] = { 200,50,100 };
int bonus[3] = { 30,5,15 };
bool deafet_Miranda = false;
int story();
int menu();
void weapon_shop();
void bao_shop();
void werewolf();
bool motherMiranda();
void mission(int&);

int main() {
	int activity = story();
	while (activity != 6) {
		mission(activity);
		if (deafet_Miranda) break;
		activity = menu();
	}
	/*story();
	do {
		menu();
		mission(activity);
	} while (activity != 6);*/
	return 0;
}

bool worrier::dead() {
	if (get_hp() <= 0)
		return true;
	return false;
}
void worrier::state() {
	cout << "\n�ͩR�� : " << get_hp() << endl;
	cout << "�����O : " << get_atk() << endl;
	cout << "���m�O : " << get_def() << endl;
	cout << "����   : " << get_money() << endl;
	cout << "�԰��O : " << get_ce() << endl;
}
void worrier::modify(string s, int num) {
	if (s == "hp")
		hp += num;
	if (s == "atk")
		atk += num;
	if (s == "def")
		def += num;
	if (s == "money")
		money += num;
}
int story() {
	cout << "�b�@�ӻ��������꦳�@�ӯ������p��\n��W���@���Z�����B�@���]�l���B�@����Ѧa�M�@�y���˪�����\n"
		    "���c�����������F����ۤp��ø��b���˫�����\n�ӧA�����ȴN�O�Գӯ��������F�ѱϤp�� !!\n\n"
            "�A�i�H�b�Z�����K�ʷQ�n���˳�\n�b�]�l���񹡨{�l\n�b��Ѧa�y���T�H���ȿ�\n�b���˪������D�ԯ��������F" << endl;
	return menu();
}
int menu() {
	cout << "\n�\���� :\n"
		"1. �h�Z�����}�}\n"
		"2. �h�]�l���}�}\n"
		"3. �h��Ѧa�����ȿ�\n"
		"4. �D�ԯ��������F (���˾԰��O : 1200)\n"
		"5. �d�ݥثe���A\n"
		"6. ���}\n"
		"�п�J�A����� : ";
	int a;
	cin >> a;
	return a;
}
void mission(int &activity) {
	switch (activity) {
		case 1:
			weapon_shop();
			break;
		case 2:
			bao_shop();
			break;
		case 3:
			werewolf();
			break;
		case 4:
			deafet_Miranda = motherMiranda();
			break;
		case 5:
			ethon.state();
			break;
		default:
			cout << "���X�k����J�|�����������F�ܱo��j�j!!" << endl;
			cout << "�Э��s��J : ";
	}
}
void weapon_shop() {
	cout << "\n�w��Ө�Z���� �аݧA�n�R���� ? (������}�~�|���}�Z����)\n"
		"1. �e�l ($50 , �����O + 5)\n"
		"2. ���Y ($100 , �����O + 15)\n"
		"3. �żu�j ($200 , �����O + 45)\n"
		"4. �L�l ($50 , ���m�O + 5)\n"
		"5. �޵P ($100 , ���m�O + 15)\n"
		"6. �����Z�� ($200 , ���m�O + 45)\n"
		"7. ���}\n"
		"�п�J�A����� : ";
	int op, prices;
	do {
		cin >> op;
		if (op == 7) break;
		if (op < 1 || op > 6) {
			cout << "�Э��s��J : ";
			continue;
		}
		if (price[op % 3] > ethon.get_money()) {
			cout << "������ !!\n�п�J�A����� : ";
			continue;
		}
		else {
			cout << "�ʶR���\ !!" << endl;
		}
		switch (op) {
		case 1:
			ethon.modify("money", -50);
			ethon.modify("atk", 5);
			break;
		case 2:
			ethon.modify("money", -100);
			ethon.modify("atk", 15);
			break;
		case 3:
			ethon.modify("money", -200);
			ethon.modify("atk", 45);
			break;
		case 4:
			ethon.modify("money", -50);
			ethon.modify("def", 5);
			break;
		case 5:
			ethon.modify("money", -100);
			ethon.modify("def", 15);
			break;
		case 6:
			ethon.modify("money", -200);
			ethon.modify("def", 45);
			break;
		}
	} while (op != 7);

}
void bao_shop() {
	cout << "\n�w��Ө�]�l�� �аݧA�n�R���� ? (������}�~�|���}�]�l��)\n"
		"1. ��] ($50 , �ͩR�� + 50)\n"
		"2. �ץ] ($100 , �ͩR�� + 150)\n"
		"3. �����z�]�l ($200 , �ͩR�� + 450)\n"
		"4. ���}\n"
		"�п�J�A����� : ";
	int op, prices;
	do {
		cin >> op;
		if (op == 4) break;
		if (op < 1 || op > 3) {
			cout << "�Э��s��J : ";
			continue;
		}
		if (price[op % 3] > ethon.get_money()) {
			cout << "������ !!\n�п�J�A����� : ";
			continue;
		}
		else {
			cout << "�ʶR���\ !!\n";
		}
		switch (op) {
		case 1:
			ethon.modify("money", -50);
			ethon.modify("hp", 50);
			break;
		case 2:
			ethon.modify("money", -100);
			ethon.modify("hp", 150);
			break;
		case 3:
			ethon.modify("money", -200);
			ethon.modify("hp", 450);
			break;
		}
	} while (op != 4);

}
void werewolf() {
	cout << "\n�A���ѤF�T�H ��o $" << ethon.get_ce() / 10 << endl;
	ethon.modify("money", ethon.get_ce() / 10);
	cout << "�{�b�`�@�� $" << ethon.get_money() << endl;
}
bool motherMiranda() {
	if (ethon.get_ce() > 1200) {
		cout << "\n���� !! �A���\���ѯ��������F�øѱϯ����p��F" << endl;
		return true;
	}
	ethon.modify("hp", 0);
	cout << "\n�A���԰��O����  �L�k���ѯ��������F\n���O�A�X�����̹F���`�N�ɦ��\�k���F" << endl;
	return false;
}