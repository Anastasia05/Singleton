#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton& Instance()
	{
		static Singleton theSingleInstance;
		return theSingleInstance;
	}
	void info()
	{
		cout << "Я здесь единственный, нет никого похожего на меня!!!\n";
	}
	void setValue(int x)
	{
		value = x;
	}
	int getValue()
	{
		return value;
	}

private:
	int value = 0;
	Singleton() {};
	Singleton(const Singleton& root) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

int main()
{
	setlocale(0, "");
	Singleton &sing = Singleton::Instance();
	sing.info();
	cout << sing.getValue() << endl;
	sing.setValue(5);
	cout << sing.getValue() << endl;
	Singleton &sing2 = sing;
	sing2.setValue(10);
	cout << sing.getValue() << endl;
	return 0;
}