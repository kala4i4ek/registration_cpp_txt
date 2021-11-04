#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

void loginuser() {
	setlocale(LC_ALL, "RUS");
	fstream db;
	string llogin, lpass, line, vvod, avvod;
		cout << "Введите ваш логин: ";
		cin >> llogin;
		cout << "Введите ваш пароль: ";
		cin >> lpass;
		vvod = "user:" + llogin + "=" + lpass;
		avvod = "administrator:" + llogin + "=" + lpass;
		cout << avvod;
		if (llogin.length() <= 16 && lpass.length() <= 64) {
			db.open("database.txt", fstream::in | fstream::out | fstream::app);
			while (getline(db, line)) {
				if (line == avvod) {
					break;
				}
				if (line == vvod) {
					break;
				}
			}
			cout << line;
			db.close();
			if (line == avvod) {
				system("cls");
				cout << "Вы авторизованы, как администратор!\n\n";
			}
			else {
				if (line == vvod) {
					system("cls");
					cout << "Вы авторизованы, как пользователь!\n\n";
				}
				else {
					system("cls");
					cout << "Аккаунт не найден!\n\n";
				}
			}
		}
		else {
			system("cls");
			cout << "Пароль или логин превышают максимальное ограничение!\n";
		}
}

void registration() {
	int sch = 0;
	while (sch == 0) {
		setlocale(LC_ALL, "RUS");
		fstream db;
		string rlogin, rpass;
		SetConsoleCP(1251);
		cout << "Введите ваш новый логин: ";
		cin >> rlogin;
		cout << "Введите ваш новый пароль: ";
		cin >> rpass;
		if (rlogin.length() <= 16 && rpass.length() <= 64) {
			db.open("database.txt", fstream::in | fstream::out | fstream::app);
			db << "user:" << rlogin << "=" << rpass << "\n";
			SetConsoleCP(866);
			db.close();
			sch++;
		}
		else {
			system("cls");
			cout << "Пароль или логин превышают максимальное ограничение!\n"; 
		} 
	} 
}

int main() {
	setlocale(LC_ALL, "RUS");
	int vibor, sch1 = 0;
	while (true) {
		cout << "Выберите: \n1 - регистрация,\n2 - авторизация.\n";
		cin >> vibor;
		switch (vibor) {
		case 1: {
			registration();
			break;
			}
		case 2: {
			loginuser();
			break;
			}
		default: {
			system("cls");
			cout << "Вы неправильно ввели данные! Попробуйте ещё раз!\n";
			break;
			}
		}
	}
	system("pause");
	return 0;
}
