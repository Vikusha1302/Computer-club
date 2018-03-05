class Admin;
class Player;
class Computer;


class Admin
{
private:
	string name;
protected:
	int hour;
	int start_time;
	int finish_time;
	int pay_hour;
	int pay;
public:
	Admin()
	{
		name = "Oleg Masluk";
		hour = 0;
		start_time = 12;
		finish_time = 12;
		pay_hour = 60;
		pay = 0;
	};
	Admin(string a, int b, int c, int d, int e, int f)
	{
		name = a;
		hour = b;
		start_time = d;
		finish_time = e;
		pay_hour = f;
		pay = c;
	};
	Admin(const Admin & admin)
	{
		name = admin.name;
		hour = admin.hour;
		start_time = admin.start_time;
		finish_time = admin.finish_time;
		pay_hour = admin.pay_hour;
		pay = admin.pay;
	};
	~Admin() {};
	void set_hour();
	int get_hour();
	void set_name();
	void get_name();
	void set_start_time();
	int get_start_time();
	int get_finish_time();
	int get_pay_hour();
	int get_pay();
	void price_list();
	void get_information();
	void end();
}; 

class Computer
{
protected:
	string model1 = "Lenovo";
	string model2 = "Asus";
	string model3 = "Acer";
	string model4 = "Fujitsu";
	string model5 = "Macbook";
	string model6 = "Dell";
	string model7 = "HP";
	string first = "DOTA";
	string second = "CS";
	string third = "WOT";
	string fourth = "FIFA";
	bool turn_computer = false;
	bool turn_game = false;
public:
	bool turn_on_computer();
	bool turn_off_computer();
	bool turn_on_game();
	bool turn_off_game();
};

class Player : public Computer, public Admin
{
private:
	string name;
	long long int telephone;
protected:
	int choice1;
	int choice2;
public:
	Player() {
		name = "Anya Gres'";
		telephone = 7811125;

	};
	Player(string a, long long int b) {
		name = a;
		telephone = b;
	};
	Player(const Player & temp) {
		name = temp.name;
		telephone = temp.telephone;

	};
	~Player() {};
	void set_name();
	void get_name();
	void set_telephone();
	void get_telephone();
	string get_choice1();
	string get_choice2();
	void check();
	void get_info();
	Player operator=(const Player * & a)
	{
		return Player(this->name, this->telephone);
	}
	friend ostream & operator <<(ostream & os, const Player & dt)
	{
		os << dt.name << '/' << dt.telephone << "\n";
		return os;
	}
};
