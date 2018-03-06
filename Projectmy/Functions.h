void Admin::set_hour()
{
	cin >> hour;
}

int Admin::get_hour()
{
	return hour;
}

void Admin::set_name()
{
	cout << "What`s is your name, Admin?";
	cin >> name;
}

void Admin::get_name()
{
	cout << "Hello, dear player. I am an admin of the computer club. My name is " << name << ". I hope you will become over our regular customer" << endl;
	cout << "Say me your name and give your telephone number";
}

void Admin::set_start_time()
{
	cout << "What is time now? ";
	cin >> start_time;
}

int Admin::get_start_time()
{
	while (start_time > 23)
	{
		start_time = start_time - 24;
	}
	return start_time;
}

int Admin::get_finish_time()
{
	finish_time = get_start_time() + get_hour();
	if (finish_time == 24)
	{
		finish_time = 0;
	}
	if (finish_time > 24)
	{
		finish_time = finish_time - 24;
	}
	return finish_time;
}

int Admin::get_pay_hour()
{
	if (hour <= 3)
	{
		pay_hour = 60;
	}
	if (hour > 3 && hour <= 6)
	{
		pay_hour = 55;
	}
	if (hour > 6)
	{
		pay_hour = 50;
	}
	return pay_hour;
}

int Admin::get_pay()
{
	pay = get_hour() * get_pay_hour();
	return pay;
}

void Admin::price_list()
{
	cout << "Dear, player. Look at price-list: " << endl << endl;
	cout << "\t\tPrice-list \n\tTill 3 hours\n - 60 $/hour \n\n\tOver 3 hours and till 6 hours \n - 55 $/hour \n\n\tOver 6 hours \n - 50 $/hour \n\n";
}

void Admin::get_information()
{
	cout << "Dear, player! You will be playing for " << get_hour() << " hours, from " << get_start_time() << ":00 to " << get_finish_time() << ":00\nYou should pay " << get_pay_hour() << "$/hour. To sum up, you will be playing for " << get_hour() << " hour(s) and you should pay " << get_pay() << "$ at all.\n\t\t\t\t\tHAVE A GOOD GAME!!!\n";
}

void Admin::end()
{
	for (int i = 0; i < get_hour(); i++)
	{
		cout << ".";
		cout << endl;
	}
	cout << "\t\t\t\t\tYour session is end. We will be waiting for you!" << endl;
}

bool Computer::turn_on_computer()
{
	cout << "Computer is on\n";
	return turn_computer = true;
}
bool Computer::turn_off_computer()
{
	cout << "Session is ended\n";
	return turn_computer = false;
}
bool Computer::turn_on_game()
{
	cout << "Game is on\n";
	return turn_game = true;;
}
bool Computer::turn_off_game()
{

	cout << "Game is off\n";
	return turn_game = false;
}

void Player::set_name()
{
	cout << "What is your name?" << endl;
	cin >> name;
}

void Player::get_name()
{
	cout << endl << "My name is " << name << endl;
}

void Player::set_telephone()
{
	cout << "What is your telephone number?" << endl;
	cin >> telephone;
}

void Player::get_telephone()
{
	cout << endl << "My telephone number is " << telephone << endl;
}

string Player::get_choice1()
{
	cout << endl << "Choose the model of computer: \n1.Lenovo\n2.Asus\n3.Acer\n4.Fujitsu\n5.Macbook\n6.Dell\n7.HP" << endl;
	cin >> choice1;
	switch (choice1)
	{
	case 1: cout << "Lenovo";
		return model1;
	case 2: cout << "Asus";
		return model2;
	case 3: cout << "Acer";
		return model3;
	case 4: cout << "Fujitsu";
		return model4;
	case 5: cout << "Macbook";
		return model5;
	case 6: cout << "Dell";
		return model6;
	case 7: cout << "HP";
		return model7;
	default: break;
	}
}

string Player::get_choice2()
{
	cout << endl << "Choose the game: \n1.DOTA\n2.CS\n3.WOT\n4.FIFA" << endl;
	cin >> choice2;
	switch (choice2)
	{
	case 1: cout << "DOTA";
		return first;
	case 2: cout << "CS";
		return second;
	case 3: cout << "WOT";
		return third;
	case 4: cout << "FIFA";
		return fourth;
	default: break;
	}
}

void Player::check() 
{
	if (turn_computer == true && turn_game == true)
	{
		get_info();
	}
	else
	{
		if (turn_computer == false)
		{
			cout << "You don`t turn on computer. Do it\n";
			turn_on_computer();
		}
		if (turn_game == false)
		{
			cout << "You don`t turn on game. Do it\n";
			turn_on_game();
		}
		get_info();
	}
}

void Player::get_info()
{
	cout << endl << "You will be playing in " << get_choice2() << endl << "On " << get_choice1() << " computer" << endl;
}

