#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#pragma warning(disable : 4996)

using namespace std;

class buildfleet
{
public:
	void Output()
	{
		Logo();
		cout << endl;
		setChoose();
	}

private:

	int acces,menu,menu1,approachmenu,menu2,menu3,menu4, succes = 0, cost,commoncounter;

	string choose,newveh, numofveh,veh,login;

	string password = "1111";

	void Logo()
	{
		cout << endl;
		cout << "\t\t #######################################################################" << endl;
		cout << "\t\t #      _       _           _       ______   _    __        ___        #" << endl;
		cout << "\t\t #     # #     # #         # #      #    #   #   # #       #   #       #" << endl;
		cout << "\t\t #    #   #   #   #       #   #     #    #   #  #  #      #     #      #" << endl;
		cout << "\t\t #   #     # #     #     #_____#    #    #   # #   #   __#_______#__   #" << endl;
		cout << "\t\t #  #       #       #   #       #   #    #   #     #   #           #   #" << endl;
		cout << "\t\t #                                                                     #" << endl;
		cout << "\t\t #######################################################################" << endl;
		cout << endl << endl;
	}

	void setChoose()
	{
		if (succes == 1 || succes == 2)
		{
			cout << "\t\t1.Смена пользователя" << endl;
			cout << "\t\t2.Справка" << endl;
			cout << "		3.Продолжить" << endl;
			cout << "\t\t0.Выход" << endl;
			cout << endl;
			cout << "		Ввод: ";
			cin >> approachmenu;
			switch (approachmenu)
			{
			case 1:
				cout << endl;
				cout << "\t\tВыберите пользователя: " << endl;
				cout << "\t\t1.Admin" << endl;
				cout << "\t\t2.User" << endl;
				cout << "		3.Назад" << endl;
				cout << endl;
				cout << "		Ввод: ";
				cin >> acces;
				setAcces(acces);
				break;
			case 2:
				cout << endl;
				Reference();
				cout << endl;
				Output();
				break;
			case 3:
				getApproach();
				cout << endl;
				break;
			case 0:
				exit(EXIT_SUCCESS);
			}
		}
		else
		{
			cout << "\t\t1.Выбор пользователя" << endl;
			cout << "\t\t2.Справка" << endl;
			cout << "\t\t0.Выход" << endl;
			cout << endl;
			cout << "		Ввод: ";
			cin >> menu;
			switch (menu)
			{
			case 1:
				cout << endl;
				cout << "\t\tВыберите пользователя: " << endl;
				cout << "\t\t1.Admin" << endl;
				cout << "\t\t2.User" << endl;
				cout << "		3.Назад" << endl;
				cout << endl;
				cout << "		Ввод: ";
				cin >> acces;
				setAcces(acces);
				break;
			case 2:
				cout << endl;
				Reference();
				Output();
				break;
			case 0:
				exit(EXIT_SUCCESS);
			default:
				cout << endl;
				cout << "		Неверное значение!" << endl;
				cout << endl;
				setChoose();
				break;
			}
		}
	}

	void Reference()
	{
		ifstream out("Reference.txt");
		char buff[80];
		while (out.eof() != true)
		{
			out.getline(buff, 80);
			cout << "\t\t" << buff << endl;
		}
		out.close();
	}

	void setAcces(int value)
	{
		string checkpassword;
		switch (value)
		{
			case 1:
				cout << endl;
				cout << "\t\tВведите пароль: ";
				cin >> checkpassword;
				if (checkpassword != password)
				{
					cout << "\t\tНеверный пароль, попробуйте снова" << endl;
					setAcces(acces);
				}
				else
				{
					cout << endl;
					cout << "\t\tВы вошли как администратор, теперь вам доступны все функции" << endl;
					succes = 1;
					getApproach();
				}
				break;
			case 2:
				cout << endl;
				cout << "		1.Войти" << endl;
				cout << "		2.Зарегистрироваться" << endl;
				check_user();
				break;
			case 3:
				Output();
				break;
			default:
				cout << endl;
				cout << "		Неверное значение!" << endl;
				cout << endl;
				cout << "\t\tВыберите пользователя: " << endl;
				cout << "\t\t1.Admin" << endl;
				cout << "\t\t2.User" << endl;
				cout << "		3.Назад" << endl;
				cout << endl;
				cout << "		Ввод: ";
				cin >> acces;
				setAcces(acces);
				break;
		}
	}

	void check_user()
	{
		int menu;
		cout << endl;
		cout << "		Ввод: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			log_in();
			break;
		case 2:
			sign_up();
			break;
		default:
			cout << endl;
			cout << "		Неверное значение!" << endl;
			cout << endl;
			setAcces(2);
			break;
		}
	}

	void sign_up()
	{
		string userpassword;
		ifstream out("userdata.txt");
		ofstream fout("userdata.txt",ios::app);
		cout << "		Введите логин: ";
		cin.ignore();
		getline(cin, login);
		cout << "		Введите пароль: ";
		getline(cin, userpassword);
		if (out.peek() == EOF)
		{
			fout << login << "\n";
			fout << userpassword;
		}
		else
		{
			fout << "\n" << login << "\n";
			fout << userpassword;
		}
		out.close();
		fout.close();
		cout << endl;
		cout << "		Регистрация прошла успешно!";
		setAcces(2);
	}

	void log_in()
	{
		string userpassword;
		ifstream out("userdata.txt");
		if (out.peek() == EOF)
		{
			cout << "		Вы не можете войти, т.к. на данный момент нет зарегистрированных пользователей." << endl;
			setAcces(2);
		}
		cout << "		Введите логин: ";
		cin.ignore();
		getline(cin, login);
		cout << "		Введите пароль: ";
		getline(cin, userpassword);
		char buff[255],buff1[255];
		while (!out.eof())
		{
			out.getline(buff, 255);
			out.getline(buff1, 255);
			if (buff == login && buff1 == userpassword)
			{
				cout << endl;
				cout << "		Вы успешно вошли как " << login << endl;
				succes = 2;
				getApproach();
				break;
			}
		}
		out.close();
		cout << endl;
		cout << "		Неправильный логин или пароль." << endl;
		cout << "		1.Повторить попытку" << endl;
		cout << "		2.Зарегистрироваться" << endl;
		check_user();
	}

	void getApproach()
	{
		if (succes == 2)
		{
			cout << "		1.Просмотреть парк техники"<<endl;
			cout << "		2.Арендовать технику" << endl;
			cout << "		3.Просмотреть список аренды" << endl;
			cout << "		4.Отменить аренду" << endl;
			cout << "		5.Изменить контактные данные аренды" << endl;
			cout << "		6.Выйти в главное меню" << endl;
			cout << endl;
			cout << "		Ввод: ";
			cin >> menu2;
			setApproach2();
		}
		if (succes == 1)
		{
			cout << "		1.Просмотреть парк техники" << endl;
			cout << "		2.Редактировать парк техники" << endl;
			cout << "		3.Просмотреть технику находящуюся в аренде" << endl;
			cout << "		4.Вернуть всю технику" << endl;
			cout << "		5.Направить технику на объект" << endl;
			cout << "		6.Вернуть технику в парк" << endl;
			cout << "		7.Техника находящаяся в работе" << endl;
			cout << "		8.Пользователи" << endl;
			cout << "		9.Выйти в главное меню" << endl;
			cout << endl;
			cout << "		Ввод: ";
			cin >> menu2;
			setApproach1();
		}
	}

	void Menu4()
	{
		cout << "		1.Добавить технику" << endl;
		cout << "		2.Удалить технику" << endl;
		cout << "		3.Редактировать описание техники" << endl;
		cout << "		0.Назад" << endl;

		cout << endl;
		cout << "		Ввод: ";
		cin >> menu4;
		cout << endl;

		switch (menu4)
		{
		case 1:
			addParkList();
			break;
		case 2:
			delParkList();
			break;
		case 3:
			change_description();
			break;
		case 0:
			getApproach();
			break;
		default:
			cout << endl;
			cout << "		Неверное значение!" << endl;
			Menu4();
			break;
		}
	}

	void setApproach2()
	{
		switch (menu2)
		{
		case 1:
			cout << endl;
			getParkList();
			cout << endl;
			cout << "		Выберите технику для просмотра подробной информации: " << endl;
			cout << "		Ввод: ";
			cin >> choose;
			check_numofveh(stoi(choose),5);
			cout << endl;
			getChoose();
			Menu3();
			break;
		case 2:
			cout << endl;
			rent_veh();
			Menu3();
			break;
		case 3:
			cout << endl;
			history_rent_user();
			Menu3();
			break;
		case 4:
			cout << endl;
			cancel_rent_user();
			Menu3();
			break;
		case 5:
			cout << endl;
			change_data_user();
			Menu3();
			break;
		case 6:
			cout << endl;
			setChoose();
			break;
		default:
			cout << endl;
			cout << "		Неверное значение!" << endl;
			cout << endl;
			getApproach();
			break;
		}
	}

	void setApproach1()
	{
		switch (menu2)
		{
		case 1:
			cout << endl;
			getParkList();
			cout << endl;
			cout << "		Выберите технику для просмотра подробной информации: " << endl;
			cout << "		Ввод: ";
			cin >> choose;
			check_numofveh(stoi(choose),4);
			cout << endl;
			getChoose();
			Menu3();
			break;
		case 2:
			cout << endl;
			Menu4();
			break;
		case 3:
			cout << endl;
			history_rent_admin();
			Menu3();
			break;
		case 4:
			cout << endl;
			clear_rent_admin();
			Menu3();
			break;
		case 5:
			cout << endl;
			sent_to_work();
			Menu3();
			break;
		case 6:
			cout << endl;
			return_to_park();
			Menu3();
			break;
		case 7:
			cout << endl;
			getinWORK();
			Menu3();
			break;
		case 8:
			cout << endl;
			menu_user();
			Menu3();
			break;
		case 9:
			cout << endl;
			setChoose();
			break;
		default:
			cout << endl;
			cout << "		Неверное значение!" << endl;
			cout << endl;
			getApproach();
			break;
		}
	}

	void getParkList()
	{
		ifstream out("ParkList.txt");
		ifstream out1("Vehdata.txt");
		int counter = 0;
		char buff[80],buff1[80];
		while (out.eof()!=true)
		{
			counter++;
			out.getline(buff, 80);
			out1.getline(buff1, 80);
			cout << "\t\t" << to_string(counter)+". " << buff << "-----" << buff1 << "ед." << endl;
		}
		out.close();
		out1.close();
	}

	void getChoose()
	{
		ifstream out(choose+".txt");
		char buff[255];
		while (out.eof() != true)
		{
			out.getline(buff, 255);
			cout << "\t\t" << buff << endl;
		}
		out.close();
	}

	void Menu3()
	{
		cout << endl;
		cout << "		1.Назад" << endl;
		cout << "		0.Выход" << endl;
		cout << endl;
		cout << "		Ввод: ";
		cin >> menu3;
		cout << endl;
		switch (menu3)
		{
		case 1:
			getApproach();
		case 0:
			exit(EXIT_SUCCESS);
		default:
			cout << endl;
			cout << "		Неверное значение!" << endl;
			cout << endl;
			Menu3();
		}
	}

	void addParkList()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		ifstream out("numofveh.txt");
		char buff[80];
		out.getline(buff, 80);
		numofveh = buff[0];
		int numofveh1 = stoi(numofveh);
		numofveh1 += 1;
		out.close();
		ofstream fout("ParkList.txt", ios::app);
		cout << "		Введите название техники: ";
		cin >> newveh;
		fout << "\n";
		fout << newveh;
		fout.close();
		ofstream fout1("numofveh.txt");
		fout1 << to_string(numofveh1);
		fout1.close();
		cout << endl;
		cout << "		Ввод описания осуществляется построчно, exit означает окончание ввода!"<<endl;
		int counter = 0;
		string description = "";
		cin.ignore();
		do
		{
			ofstream fout2(to_string(numofveh1) + ".txt",ios::app);
			cout << "		Ввод: ";
			getline(cin, description);
			if (description == "exit")
			{
				break;
			}
			else if (counter == 0)
			{
				counter++;
				fout2 << description;
				fout2.close();
			}
			else 
			{
				fout2 << "\n"+description;
				fout2.close();
			}
		} 
		while (true);
		ifstream out5("CostofRent.txt");
		ofstream fout3("CostofRent.txt",ios::app);
		cout << endl;
		cout << "		Введите стоимость аренды данной техники в $: ";
		int costmost;
		cin >> costmost;
		if (out5.peek() == EOF)
		{
			fout3 << costmost;
		}
		else
		{
			fout3 << "\n" << costmost;
		}
		out5.close();
		fout3.close();
		ifstream out3("Vehdata.txt");
		ofstream fout4("Vehdata.txt", ios::app);
		cout << endl;
		cout << "		Введите количество данной техники: ";
		int costmost1;
		cin >> costmost1;
		if (out3.peek() == EOF)
		{
			fout4 << costmost1;
		}
		else
		{
			fout4 << "\n" << costmost1;
		}
		out3.close();
		fout4.close();
		ifstream out4("Vehdatastart.txt");
		ofstream fout5("Vehdatastart.txt", ios::app);
		if (out4.peek() == EOF)
		{
			fout5 << costmost1;
		}
		else
		{
			fout5 << "\n" << costmost1;
		}
		out4.close();
		fout5.close();
		cout << endl;
		cout << "		Техника успешно добавлена!" << endl;
		cout << endl;
		getApproach();
	}

	void delParkList()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int num;
		getParkList();
		cout << endl;
		cout << "		Введите номер техники, которую хотите удалить: ";
		cin >> num;
		check_numofveh(num,1);

		ifstream out("numofveh.txt");
		char buff[80];
		out.getline(buff, 80);
		numofveh = buff[0];
		int numofveh1 = stoi(numofveh);
		numofveh1--;
		out.close();
		ofstream fout1("numofveh.txt");
		fout1 << to_string(numofveh1);
		fout1.close();

		del_line(to_string(num) + ".txt", num);

		if (num < numofveh1)
		{
			char buff1[255];
			char buff2[255];
			for (int i = num; i <= numofveh1; i++)
			{
				rename(strcpy(buff1, (to_string(i + 1) + ".txt").c_str()), strcpy(buff2, (to_string(i) + ".txt").c_str()));
			}
		}
		cout << endl;
		cout << "		Техника успешно удалена!" << endl;
		cout << endl;
		Menu4();
	}

	void check_numofveh(int num,int i)
	{
		ifstream out("numofveh.txt");
		char buff[80];
		out.getline(buff, 80);
		numofveh = buff[0];
		int numofveh1 = stoi(numofveh);
		out.close();
		if (num > numofveh1 || num < 1)
		{
			cout << endl;
			cout << "		Неверное значение!";
			cout << endl;
			if (i == 1)
			{
				delParkList();
			}
			else if (i == 2)
			{
				rent_veh();
			}
			else if (i == 3)
			{
				change_description();
			}
			else if (i == 4)
			{
				setApproach1();
			}
			else if (i == 5)
			{
				setApproach2();
			}
			else if (i == 6)
			{
				sent_to_work();
			}
		}
	}

	void del_line(string str, int num)
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int counter = 0;
		char buff[255];
		strcpy(buff, str.c_str());
		remove(buff);
		ifstream out("ParkList.txt");
		ifstream out2("numofveh.txt");
		out2.getline(buff, 255);
		numofveh = buff[0];
		int numofveh1 = stoi(numofveh);
		ofstream fout("temp.txt");
		char buff1[255];
		while (!out.eof()) 
		{
			counter++;
			if (counter == num)
			{
				out.getline(buff, 255);
			}
			else if (counter == numofveh1)
			{
				out.getline(buff1, 255);
				fout << buff1;
			}
			else 
			{
				out.getline(buff1, 255);
				fout << buff1;
				fout << "\n";
			}
		}
		out.close();
		fout.close();
		remove("ParkList.txt");
		rename("temp.txt", "ParkList.txt");

		int counter2 = 0;
		ifstream out3("CostofRent.txt");
		ofstream fout2("temp.txt");
		while (!out3.eof()) {
			counter2++;
			if (counter2 == num)
			{
				out3.getline(buff, 255);
			}
			else if (counter2 == numofveh1)
			{
				out3.getline(buff1, 255);
				fout2 << buff1;
			}
			else
			{
				out3.getline(buff1, 255);
				fout2 << buff1;
				fout2 << "\n";
			}
		}
		out3.close();
		fout2.close();
		remove("CostofRent.txt");
		rename("temp.txt", "CostofRent.txt");

		int counter3 = 0;
		ifstream out4("Vehdata.txt");
		ofstream fout3("temp.txt");
		while (!out4.eof()) {
			counter3++;
			if (counter3 == num)
			{
				out4.getline(buff, 255);
			}
			else if (counter3 == numofveh1)
			{
				out4.getline(buff1, 255);
				fout3 << buff1;
			}
			else
			{
				out4.getline(buff1, 255);
				fout3 << buff1;
				fout3 << "\n";
			}
		}
		out4.close();
		fout3.close();
		remove("Vehdata.txt");
		rename("temp.txt", "Vehdata.txt");

		int counter4 = 0;
		ifstream out5("Vehdata.txt");
		ofstream fout4("temp.txt");
		while (!out5.eof()) {
			counter4++;
			if (counter4 == num)
			{
				out5.getline(buff, 255);
			}
			else if (counter4 == numofveh1)
			{
				out5.getline(buff1, 255);
				fout4 << buff1;
			}
			else
			{
				out5.getline(buff1, 255);
				fout4 << buff1;
				fout4 << "\n";
			}
		}
		out5.close();
		fout4.close();
		remove("Vehdatastart.txt");
		rename("temp.txt", "Vehdatastart.txt");
	}

	void rent_veh()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		int menu4,counter = 1,numrentvehnew, timeofrent, numrentveh;

		cout << "		Выберите технику, которую хотите арендовать." << endl;
		getParkList();
		cout << endl;

		cout << "		Ввод: ";
		cin >> menu4;

		check_numofveh(menu4,2);
		char buff[255], buff1[255],buff2[255];
		ifstream out("ParkList.txt");
		ifstream out1("CostofRent.txt");
		while (!out.eof())
		{
			if (counter == menu4)
			{
				out.getline(buff, 255);
				out1.getline(buff1, 255);
				break;
			}
			else 
			{
				counter++;
				out.getline(buff, 255);
				out1.getline(buff1, 255);
			}
		}
		veh = buff;
		cost = stoi(buff1);
		out.close();
		out1.close();
		cout << endl;
		cout << "		Введите срок аренды(часы): ";
		cin >> timeofrent;
		cout << endl;
		cout << "		Введите количество техники для аренды: ";
		cin >> numrentveh;
		ifstream out2("Vehdata.txt");
		int counter1 = 1;
		while (!out2.eof())
		{
			if (counter1 == menu4)
			{
				out2.getline(buff, 255);
				break;
			}
			else
			{
				counter1++;
				out2.getline(buff1, 255);
			}
		}
		out2.close();
		numrentvehnew = stoi(buff) - numrentveh;
		if (numrentveh > stoi(buff))
		{
			cout << endl;
			cout << "		В парке недостаточно техники." << endl;
			rent_veh();
		}
		if (numrentveh == 0 || numrentveh < 0)
		{
			cout << endl;
			cout << "		Неверное значение количества техники." << endl;
			rent_veh();
		}
		cost *= timeofrent;
		cost *= numrentveh;
		cout << endl;
		question_rent_ofveh(timeofrent,numrentveh);

		int counter2 = 0;
		ifstream out4("Vehdata.txt");
		ifstream out5("numofveh.txt");
		out5.getline(buff, 255);
		numofveh = buff[0];
		int numofveh1 = stoi(numofveh);
		out5.close();
		ofstream fout("temp.txt");
		while (!out4.eof())
		{
			counter2++;
			if (counter2 == menu4)
			{
				out4.getline(buff1, 255);
				fout << numrentvehnew << "\n";
			}
			else if (counter2 == numofveh1)
			{
				out4.getline(buff1, 255);
				fout << buff1;
			}
			else
			{
				out4.getline(buff1, 255);
				fout << buff1;
				fout << "\n";
			}
		}
		out4.close();
		fout.close();
		remove("Vehdata.txt");
		rename("temp.txt", "Vehdata.txt");
		cout << endl;
		cout << "		Аренда произведена успешно!";
		cout << endl;
	}

	void question_rent_ofveh(int i,int j)
	{
		int choose1;
		cout << "		Это обойдётся вам в " << to_string(cost) << "$" << endl;
		cout << "		Вы согласны?" << endl;
		cout << "		1.Да" << endl;
		cout << "		2.Нет" << endl;
		cout << "		Ввод: ";
		cin >> choose1;
		switch (choose1)
		{
		case 1:
			write_rent(i,j);
			break;
		case 2:
			cout << endl;
			no_rentoveh();
			break;
		default:
			cout << endl;
			cout << "		Неверное значение!" << endl;
			cout << endl;
			question_rent_ofveh(i,j);
			break;
		}
	}

	void no_rentoveh()
	{
		cout << "		1.Выбрать другую технику" << endl;
		cout << "		2.Назад" << endl;
		cout << "		0.Выход" << endl;
		int menu;
		cout << "		Ввод: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			rent_veh();
			cout << endl;
			break;
		case 2:
			getApproach();
			break;
		case 0:
			exit(EXIT_SUCCESS);
		default:
			cout << endl;
			cout << "		Неверное значение!" << endl;
			cout << endl;
			no_rentoveh();
			break;
		}
	}

	void write_rent(int i,int j)
	{
		int counter = 1;
		string fio, numofphone;
		char buff[255];
		ifstream out(login + ".txt");
		ofstream fout(login + ".txt", ios::app);
		ifstream out1(login + "data.txt");
		ofstream fout1(login + "data.txt",ios::app);
		if (out1.is_open())
		{
			if (out.peek() == EOF)
			{
				fout << veh << "\n";
				fout << cost << "\n";
				fout << j << "\n";
				fout << i;
			}
			else
			{
				fout << "\n" << veh << "\n";
				fout << cost << "\n";
				fout << j << "\n";
				fout << i;
			}
			out.close();
			fout.close();
		}
		else
		{
			if (out.peek() == EOF)
			{
				fout << veh << "\n";
				fout << cost << "\n";
				fout << j << "\n";
				fout << i;
			}
			else
			{
				fout << "\n" << veh << "\n";
				fout << cost << "\n";
				fout << j << "\n";
				fout << i;
			}
			out.close();
			fout.close();
			cout << endl;
			cout << "		Введите ваше ФИО: ";
			cin.ignore();
			getline(cin, fio);
			cout << "		Введите ваш номер телефона: ";
			getline(cin, numofphone);
			num_of_phone(numofphone);
			
			if (out1.peek() == EOF)
			{
				fout1 << fio << "\n";
				fout1 << numofphone;
			}
			else
			{
				fout1 << "\n" << fio << "\n";
				fout1 << numofphone;
			}
			out1.close();
			fout1.close();
		}
	}

	void num_of_phone(string numofphone)
	{
		if (numofphone.length()<13)
		{
			cout << "		Неверное количество цифр, проверьте номер и повторите попытку." << endl;
			num_of_phone(numofphone);
		}
		
	}

	void change_description()
	{
		int vehnum, counter = 0, i;
		getParkList();
		cout << endl;
		cout << "		Введите номер техники описание которой хотите изменить." << endl;
		cout << "		Ввод: ";
		cin >> vehnum;
		cout << endl;
		check_numofveh(vehnum,3);
		char buff[255];
		ifstream out(to_string(vehnum) + ".txt");
		while (!out.eof())
		{
			counter++;
			out.getline(buff, 255);
			cout << "		" << counter << "." << buff << endl;
		}
		out.close();
		cout << endl;
		cout << "		Введите номер строки, которую хотите изменить." << endl;
		cout << "		Ввод: ";
		cin >> i;
		change_line(to_string(vehnum) + ".txt", i);
	}

	void change_line(string file,int i)
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int counter = 0;
		string newline;
		cout << endl;
		cout << "		Введите новую строку." << endl;
		cout << "		Ввод: ";
		cin.ignore();
		getline(cin, newline);
		char buff[255];
		ifstream out(file);
		ofstream fout("temp.txt");
		while (!out.eof()) {
			counter++;
			if (counter == i)
			{
				out.getline(buff, 255);
				fout << newline;
			}
			else
			{
				out.getline(buff, 255);
				fout << buff;
				fout << "\n";
			}
		}
		out.close();
		fout.close();
		remove(file.c_str());
		rename("temp.txt", file.c_str());
		cout << endl;
		getApproach();
	}

	void history_rent_user()
	{
		char buff[255];
		ifstream out(login + ".txt");
		if (out.is_open())
		{
			cout << "		Ваша история аренды:" << endl;
			while (!out.eof())
			{
				out.getline(buff, 255);
				cout << "		Техника: " << buff << endl;
				out.getline(buff, 255);
				cout << "		Стоимость аренды: " << buff << "$" << endl;
				out.getline(buff, 255);
				cout << "		В кол-ве: " << buff << "ед." << endl;
				out.getline(buff, 255);
				cout << "		Время аренды: " << buff << "ч." << endl;
			}
		}
		else
		{
			cout << "		На данный момент у вас нет арендованной техники." << endl;
		}
		out.close();
	}

	void history_rent_admin()
	{
		int counter = 0;
		string login;
		ifstream out("userdata.txt");
		char buff[255], buff1[255];
		while (!out.eof())
		{
			out.getline(buff, 255);
			out.getline(buff1, 255);
			login = buff;
			ifstream out1(login + ".txt");
			ifstream out2(login + "data.txt");
			if (out1.is_open())
			{
				out2.getline(buff, 255);
				cout << "		Техника записанная на: " << buff << endl;;
				out2.getline(buff, 255);
				cout << "		Номер телефона: " << buff << endl;
				cout << endl;
				counter++;
				while (!out1.eof())
				{
					out1.getline(buff, 255);
					cout << "		Техника: " << buff << endl;
					out1.getline(buff, 255);
					cout << "		Стоимость аренды: " << buff << "$" << endl;
					out1.getline(buff, 255);
					cout << "		В кол-ве: " << buff << "ед." << endl;
					out1.getline(buff, 255);
					cout << "		Время аренды: " << buff << "ч." << endl;
				}
				
			}
			else
			{
				cout << "		У пользователя " << login << " нет арендованной техники" << endl;
			}
			out1.close();
			out2.close();
		}
		out.close();
	}

	void clear_rent_admin()
	{
		int counter = 0;
		string login;
		ifstream out("userdata.txt");
		char buff[255], buff1[255],buff2[255];
		while (!out.eof())
		{
			out.getline(buff, 255);
			out.getline(buff1, 255);
			login = buff;
			remove(strcpy(buff2, (login + ".txt").c_str()));
			remove(strcpy(buff2, (login + "data.txt").c_str()));
		}
		out.close();
		cout << "		Вся техника возвращена." << endl;
		remove("Vehdata.txt");
		ifstream out1("Vehdatastart.txt");
		ifstream out2("numofveh.txt");
		out2.getline(buff, 255);
		numofveh = buff[0];
		int numofveh1 = stoi(numofveh);
		out2.close();
		ofstream fout("temp.txt");
		while (!out1.eof())
		{
			counter++;
			if (counter == numofveh1)
			{
				out1.getline(buff, 255);
				fout << buff;
			}
			else
			{
				out1.getline(buff, 255);
				fout << buff << "\n";
			}
		}
		out1.close();
		fout.close();
		rename("temp.txt", "Vehdata.txt");
		ofstream fout1("inWORK.txt");
		fout1.close();
	}

	void cancel_rent_user()
	{
		string veh;
		int numveh;
		ifstream out(login + ".txt");
		if (out.is_open())
		{
			char buff[255], buff1[255];
			while (!out.eof())
			{
				out.getline(buff, 255);
				veh = buff;
				check_num(veh);
				out.getline(buff, 255);
				out.getline(buff, 255);
				numveh = stoi(buff);
				return_num(numveh);
				out.getline(buff, 255);
			}
			out.close();
			remove(strcpy(buff1, (login + ".txt").c_str()));
			remove(buff1);
			strcpy(buff, (login + "data.txt").c_str());
			remove(buff);
			cout << "		Аренда отменена успешно." << endl;
		}
		else
		{
			cout << "		Вы ещё не арендовывали технику." << endl;
			cout << endl;
			getApproach();
		}
	}

	void check_num(string str)
	{
		char buff[255];
		int counter = 0;
		ifstream out("ParkList.txt");
		while (!out.eof())
		{
			counter++;
			out.getline(buff, 255);
			if (str == buff)
			{
				commoncounter = counter;
			}
		}
		out.close();
	}

	void return_num(int num)
	{
		int counter = 0;
		char buff[255];
		ifstream out2("numofveh.txt");
		out2.getline(buff, 255);
		numofveh = buff[0];
		int numofveh1 = stoi(numofveh);
		out2.close();
		ifstream out1("Vehdata.txt");
		ofstream fout("temp.txt");
		while (!out1.eof())
		{
			counter++;
			if (counter == commoncounter)
			{
				out1.getline(buff, 255);
				num += stoi(buff);
				fout << num << "\n";
			}
			else if (counter == numofveh1)
			{
				out1.getline(buff, 255);
				fout << buff;
			}
			else
			{
				out1.getline(buff, 255);
				fout << buff << "\n";
			}
		}
		out1.close();
		fout.close();
		remove("Vehdata.txt");
		rename("temp.txt", "Vehdata.txt");
	}

	void sent_to_work()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		int numofveh2, i, counter = 0,numrentvehnew;
		string object, veh;

		getParkList();
		cout << endl;
		cout << "		Выберите технику: ";
		cin >> numofveh2;
		check_numofveh(numofveh2, 6);
		cout << endl;

		cout << "		Введите количество: ";
		cin >> i;
		cout << endl;

		cout << "		Объект: ";
		cin.ignore();
		getline(cin, object);

		ifstream out1("ParkList.txt");
		char buff[255],buff2[255];
		while (!out1.eof())
		{
			counter++;
			if (counter == numofveh2)
			{
				out1.getline(buff2, 255);
				veh = buff2;
			}
			else
			{
				out1.getline(buff, 255);
			}
		}
		out1.close();

		ifstream out("inWORK.txt");
		ofstream fout("inWORK.txt", ios::app);
		if (out.peek() == EOF)
		{
			fout << veh << "\n";
			fout << i << "\n";
			fout << object;
		}
		else
		{
			fout << "\n" << veh << "\n";
			fout << i << "\n";
			fout << object;
		}
		out.close();
		fout.close();

		ifstream out2("Vehdata.txt");
		int counter1 = 1;
		while (!out2.eof())
		{
			if (counter1 == numofveh2)
			{
				out2.getline(buff, 255);
				break;
			}
			else
			{
				counter1++;
				out2.getline(buff, 255);
			}
		}
		out2.close();
		numrentvehnew = stoi(buff) - i;

		int counter2 = 0;
		ifstream out4("Vehdata.txt");
		ifstream out5("numofveh.txt");
		char buff1[255];
		out5.getline(buff, 255);
		numofveh = buff[0];
		int numofveh1 = stoi(numofveh);
		out5.close();
		ofstream fout2("temp.txt");
		while (!out4.eof())
		{
			counter2++;
			if (counter2 == numofveh2)
			{
				out4.getline(buff1, 255);
				fout2 << numrentvehnew << "\n";
			}
			else if (counter2 == numofveh1)
			{
				out4.getline(buff1, 255);
				fout2 << buff1;
			}
			else
			{
				out4.getline(buff1, 255);
				fout2 << buff1;
				fout2 << "\n";
			}
		}
		out4.close();
		fout2.close();
		remove("Vehdata.txt");
		rename("temp.txt", "Vehdata.txt");
		cout << endl;
		cout << "		Техника успешно отправлена" << endl;
	}

	void return_to_park()
	{
		string veh;
		int numveh;
		ifstream out("inWORK.txt");
		char buff[255], buff1[255];
		if (out.peek() == EOF)
		{
			cout << "		На данный момент нет техники находящейся в работе." << endl;
		}
		else
		{
			cout << "		Техника успешно возвращена." << endl;
		}
		while (!out.eof())
		{
			out.getline(buff, 255);
			veh = buff;
			check_num(veh);
			out.getline(buff, 255);
			numveh = stoi(buff);
			return_num(numveh);
			out.getline(buff, 255);
		}
		out.close();
		ofstream fout("inWORK.txt");
		fout.close();
	}

	void getinWORK()
	{
		ifstream out("inWORK.txt");
		char buff[255];
		if (out.peek() == EOF)
		{
			cout << "		На данный момент нет техники находящейся в работе." << endl;
		}
		else
		{
			while (!out.eof())
			{
				out.getline(buff, 255);
				cout << "		Техника: " << buff << endl;
				out.getline(buff, 255);
				cout << "		В кол-ве: " << buff << "ед." << endl;
				out.getline(buff, 255);
				cout << "		На обьекте: " << buff << endl;
			}
		}
		out.close();
	}

	void change_data_user()
	{
		string fio, numofphone;
		ifstream out(login + "data.txt");
		if (out.is_open())
		{
			ofstream fout(login + "data.txt");
			cout << "		Введите ваше ФИО: ";
			cin.ignore();
			getline(cin, fio);
			cout << "		Введите ваш номер телефона: ";
			getline(cin, numofphone);
			fout << fio << "\n";
			fout << numofphone;
			fout.close();
			cout << endl;
			cout << "		Ваши данные успешно изменены." << endl;
		}
		else
		{
			cout << "		Вы ещё не производили аренду техники." << endl;
		}
		out.close();
	}

	void menu_user()
	{
		int menu,user;
		cout << "		Выбериты, что вы хотите сделать." << endl;
		cout << "		1.Просмотреть список пользователей." << endl;
		cout << "		2.Удалить пользователя" << endl;
		cout << "		Ввод: ";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			get_user();
			break;
		case 2:
			get_user();
			cout << "		Выберите пользователя, которого хотите удалить: ";
			cin >> user;
			delete_user(user);
			break;
		default:
			cout << endl;
			cout << "		Неверное значение!" << endl;
			cout << endl;
			menu_user();
			break;
		}
	}

	void delete_user(int i)
	{
		int counter = 0;
		ifstream out("userdata.txt");
		char buff[255];
		if (out.is_open())
		{
			ofstream fout("temp.txt");
			while (!out.eof())
			{
				counter++;
				if (counter == i)
				{
					out.getline(buff, 255);
					out.getline(buff, 255);
				}
				else
				{
					out.getline(buff, 255);
					fout << buff << "\n";
					out.getline(buff, 255);
					fout << buff;
				}
			}
			out.close();
			fout.close();
			remove("userdata.txt");
			rename("temp.txt", "userdata.txt");
			cout << "		Пользователь успешно удалён" << endl;
		}
		else
		{
			cout << "		На данный момент нет зарегистрированных пользователей.";
		}
	}

	void get_user()
	{
		int i = 0;
		char buff[255];
		ifstream out("userdata.txt");
		while (!out.eof())
		{
			i++;
			out.getline(buff, 255);
			cout << "		" << i << "." << buff << endl;
			out.getline(buff, 255);
		}
		out.close();
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	buildfleet obj;
	obj.Output();
}