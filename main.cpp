#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

void loginadmin() {
	setlocale(LC_ALL, "RUS");
	fstream db;
	string alogin, apass, aline, avvod;
	cout << "Введите ваш админ логин: ";
	cin >> alogin;
	cout << "Введите ваш админ пароль: ";
	cin >> apass;
	avvod = alogin + "=" + apass;
	db.open("database_admins.txt", fstream::in | fstream::out | fstream::app);
	while (getline(db, aline)) {
		if (aline == avvod) {
			break;
		}
	}
	db.close();
	if (aline == avvod) {
		cout << "Вы авторизованы, как администратор!" << endl;
	}
	else {
		cout << "Аккаунт не найден!" << endl;
	}
}

void loginuser() {
	setlocale(LC_ALL, "RUS");
	fstream db;
	string llogin, lpass, line, vvod;
		cout << "Введите ваш логин: ";
		cin >> llogin;
		cout << "Введите ваш пароль: ";
		cin >> lpass;
		vvod = llogin + "=" + lpass;
		if (llogin.length() <= 16 && lpass.length() <= 64) {
			db.open("database_users.txt", fstream::in | fstream::out | fstream::app);
			while (getline(db, line)) {
				if (line == vvod) {
					break;
				}
			}
			db.close();
			if (line == vvod) {
				system("cls");
				cout << "Вы авторизованы, как пользователь!" << endl << endl;
			}
			else {
				system("cls");
				cout << "Аккаунт не найден!" << endl << endl;
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
			db.open("database_users.txt", fstream::in | fstream::out | fstream::app);
			db << rlogin << "=" << rpass << "\n";
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
		cout << "Выберите: \n1 - регистрация,\n2 - авторизация от имени пользователя,\n3 - авторизация от имени администратора.\n";
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
		case 3: {
			loginadmin();
		}
		default: {
			system("cls");
			cout << "Вы неправильно ввели данные! Попробуйте ещё раз!\n";
			break;
		}
		}
	}
	system("pause");
}
