/*
 *	Singleton µ¥Àý
 */

class Singleton
{
private:
	static Singleton* _single;
	Singleton(){}
public:
	static Singleton* getInstance()
	{
		if (_single == nullptr)
		{
			_single = new Singleton();
		}

		return _single;
	}
};

Singleton* Singleton::_single = nullptr;


class SingleTon
{
private:
	SingleTon(){}
public:
	static SingleTon* getInstance()
	{
		static SingleTon *single = new SingleTon();
		return single;
	}
};