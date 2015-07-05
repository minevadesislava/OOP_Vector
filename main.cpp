#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include "Vector.h"
using namespace std;

class Person
{
public:
	Person() : m_name("Georgi"), m_age(19) {}
	Person(string name, int age) : m_name(name), m_age(age) {}
private:
	string m_name;
	int m_age;
};
int main()
{
	Person st1("Ivan", 20);
	Person st2("Petur", 20);
	Vector<Person> Persons;
	Persons.push_back(st1);
	Persons.push_back(st2);
	Vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(121);
	v1.push_back(181);
	v1.push_back(253);
	cout << v1.back() << endl;
	v1.pop_back();
	cout << v1.back() << endl;
	cout << v1[4] << endl;
	v1.push_back(777);
	for (int i = 0; i < v1.size(); i++)
	{
	}
	cout << endl;
	Vector<string> v2;
	v2.push_back("de beaut?");
	v2.push_back("amour");
	v2.push_back("amiti?");
	for (int i = 0; i < v2.size(); i++)
	{
	}
	cout << endl;
	Vector<string> v3;
	v3.push_back("prehodonst");
	v3.push_back("confiance");
	v3.push_back("?ternit?");
	v3.insert(2, "bonne chance");
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v1[i] << " ";
		cout << v2[i] << " ";
		cout << v3[i] << " ";
		cout << endl;
	}
	
	v3.erase(0);
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	system("pause");
	return 0;
}
