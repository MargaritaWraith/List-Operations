#ifndef _TEMP
#define	_TEMP

using namespace std;

class AA
{
public:
	AA() { num++; cout << "A() " << this << endl; };
	~AA() { num--; cout << "~A() " << this << endl; };

	static void PrintNum() { cout << num << endl; };
private:
	static int num;
};


void CheckTemp();

#endif