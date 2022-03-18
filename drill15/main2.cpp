#include "std_lib_facilities.h"

struct Person
{
    Person() {}
    Person(string first_name,string last_name, int age)
    {
        _f_name = first_name;
        _l_name = last_name;
        _age = age;
    
        if (age < 0 || age > 150)
        {
            error("Invalid age!");
        }
        if (ISNameContainsIllegalChars(first_name + last_name))
        {
            error("Invalid char");
        }
        if(first_name == last_name)
        {
            error("Same first and last name!");
        }
    }

public:
    string first_name() const {return _f_name; }
    string last_name() const {return _l_name;}
    int age() const { return _age; }
private:
    string _f_name; // Person's first name
    string _l_name; // Person's last name
    uint _age;  // Person's age
    
    char illegal_chars[14] {';',':','\"','\'','[',']','*','&','^','%','$','#','@','!'};

    bool ISNameContainsIllegalChars(string val)
    {
        for (int i = 0; i < val.size(); i++)
        {
            for (int j = 0; j < 14; j++)
            {
                if (val[i] == illegal_chars[j]){ return true; }
            }
        }
        return false;
    }
};

ostream& operator<<(ostream& os, const Person& p)
{
    return os << p.first_name() << " " << p.last_name() << " " << p.age();
}

istream& operator>>(istream& is, Person& p)
{
    string f_name;
    string l_name;
    int age;

    is >> f_name >> l_name >> age;
    p = Person(f_name,l_name,age);

    return is;
}

int main()
{
    try
    {
        vector<Person> people;
        cout << "Input format: \"First_name Last_name Age\" Exit with \'x\'!\n";
        string input;

        // Input
        for (Person p; cin >> p; ) {
            if (p.first_name() == "x") break;
            
            people.push_back(p);
        }
        // Output
        for(Person p : people)
            cout << p << endl;
        
        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
        return 1;
    }
    catch(...)
    {
        cerr << "Unknown error!" << endl;
        return 2;
    }
}