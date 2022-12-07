#include <iostream>

using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    virtual string classname()
    {
        return "Person";
    }
    virtual bool isA(const string& who)
    {
        return who == "Person";
    }

};
class Adult : public Person
{
protected:
    string job;
public:

    string classname() override
    {
        return "Adult";
    }
    bool isA(const string& who) override
    {
        return (who == "Person") || (who == "Adult");
    }
	void ChangeJob(string j)
	{
		job = j;
	}
};

class Programmer : public Adult
{
public:
	string classname() override
	{
		return "Programmer";
	}
    bool isA(const string& who) override
    {
        return (who == "Programmer") || (Adult::isA(who));
    }
};

class Child : public Person
{
public:
    string classname() override
    {
        return "Child";
    }
    bool isA(const string& who) override
    {
        return (who == "Person") || (who == "Child");
    }
   
};

int main()
{
    Person* arr[4] = { new Person, new Adult, new Child, new Programmer };
    //if (arr[1]->classname() == "Adult" || arr[1]->classname() == "Programmer" ......) может быть много проверок
    //if (arr[1]->isA("Adult")) проверяет всех потомков Adult 
    for (int i = 0; i < 4; i++)
    {
        if (arr[i]->isA("Adult"))
        {
            Adult* a = static_cast<Adult*> (arr[i]);
            a->ChangeJob("Google");
        }
    }
	for (int i = 0; i < 4; i++)
    {   
		Adult* a = dynamic_cast<Adult*> (arr[i]);
        if (a != nullptr)
        {
            a->ChangeJob("Google");
        }
		
	}
    return 0;
}

