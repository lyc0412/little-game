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
	cout << "\n生命值 : " << get_hp() << endl;
	cout << "攻擊力 : " << get_atk() << endl;
	cout << "防禦力 : " << get_def() << endl;
	cout << "金錢   : " << get_money() << endl;
	cout << "戰鬥力 : " << get_ce() << endl;
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
	cout << "在一個遙遠的王國有一個神秘的小鎮\n鎮上有一間武器店、一間包子店、一塊休耕地和一座陰森的城堡\n"
		    "邪惡的神母米蘭達控制著小鎮並躲在陰森城堡裡\n而你的任務就是戰勝神母米蘭達解救小鎮 !!\n\n"
            "你可以在武器店添購想要的裝備\n在包子店填飽肚子\n在休耕地獵殺狼人來賺錢\n在陰森的城堡挑戰神母米蘭達" << endl;
	return menu();
}
int menu() {
	cout << "\n功能選單 :\n"
		"1. 去武器店逛逛\n"
		"2. 去包子店逛逛\n"
		"3. 去休耕地打怪賺錢\n"
		"4. 挑戰神母米蘭達 (推薦戰鬥力 : 1200)\n"
		"5. 查看目前狀態\n"
		"6. 離開\n"
		"請輸入你的選擇 : ";
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
			cout << "不合法的輸入會讓神母米蘭達變得更強大!!" << endl;
			cout << "請重新輸入 : ";
	}
}
void weapon_shop() {
	cout << "\n歡迎來到武器店 請問你要買什麼 ? (選擇離開才會離開武器店)\n"
		"1. 叉子 ($50 , 攻擊力 + 5)\n"
		"2. 斧頭 ($100 , 攻擊力 + 15)\n"
		"3. 霰彈槍 ($200 , 攻擊力 + 45)\n"
		"4. 盤子 ($50 , 防禦力 + 5)\n"
		"5. 盾牌 ($100 , 防禦力 + 15)\n"
		"6. 黃金鎧甲 ($200 , 防禦力 + 45)\n"
		"7. 離開\n"
		"請輸入你的選擇 : ";
	int op, prices;
	do {
		cin >> op;
		if (op == 7) break;
		if (op < 1 || op > 6) {
			cout << "請重新輸入 : ";
			continue;
		}
		if (price[op % 3] > ethon.get_money()) {
			cout << "錢不夠 !!\n請輸入你的選擇 : ";
			continue;
		}
		else {
			cout << "購買成功 !!" << endl;
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
	cout << "\n歡迎來到包子店 請問你要買什麼 ? (選擇離開才會離開包子店)\n"
		"1. 菜包 ($50 , 生命值 + 50)\n"
		"2. 肉包 ($100 , 生命值 + 150)\n"
		"3. 狗不理包子 ($200 , 生命值 + 450)\n"
		"4. 離開\n"
		"請輸入你的選擇 : ";
	int op, prices;
	do {
		cin >> op;
		if (op == 4) break;
		if (op < 1 || op > 3) {
			cout << "請重新輸入 : ";
			continue;
		}
		if (price[op % 3] > ethon.get_money()) {
			cout << "錢不夠 !!\n請輸入你的選擇 : ";
			continue;
		}
		else {
			cout << "購買成功 !!\n";
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
	cout << "\n你打敗了狼人 獲得 $" << ethon.get_ce() / 10 << endl;
	ethon.modify("money", ethon.get_ce() / 10);
	cout << "現在總共有 $" << ethon.get_money() << endl;
}
bool motherMiranda() {
	if (ethon.get_ce() > 1200) {
		cout << "\n恭喜 !! 你成功打敗神母米蘭達並解救神秘小鎮了" << endl;
		return true;
	}
	ethon.modify("hp", 0);
	cout << "\n你的戰鬥力不足  無法打敗神母米蘭達\n但是你趁神母米達不注意時成功逃走了" << endl;
	return false;
}