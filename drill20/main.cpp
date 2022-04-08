#include "std_lib_facilities.h"

// ???
template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for (Iter1 p = f1; p != e1; ++p)
        *f2++ = *p;
    return f2;
}

template<typename T>
void print_container(T container)
{
    for(auto& elem: container)
        cout << elem << ", ";

    cout << endl;
}

template<typename T>
void AddVals(T& type, int value)
{
    for(auto& elem : type)
        elem += value;
}

int main()
{
    try
    {
        int values[10] = {0,1,2,3,4,5,6,7,8,9};

        array<int, 10> array_int;
        copy(values,values + 10, array_int.begin());
        print_container(array_int);

        vector<int> vector_int(10);
        copy(values,values+10,vector_int.begin());
        print_container(vector_int);

        list<int> list_int(10);
        copy(values,values+10,list_int.begin());
        print_container(list_int);

        array<int, 10> array_copy = array_int;
        vector<int> vector_copy = vector_int;
        list<int> list_copy = list_int;

        AddVals(array_copy, 2);
        AddVals(vector_copy, 3);
        AddVals(list_copy, 5);

        print_container(array_copy);
        print_container(vector_copy);
        print_container(list_copy);

        array<int,10> valami;
        my_copy(array_copy.begin(),array_copy.end(),valami.begin());
        print_container(valami);

        array<int,10>::iterator search;
        search = find(valami.begin(), valami.end(), 3);

        if(search != valami.end())
            cout << "Value found at index: " << distance(valami.begin(),search) << endl;
        else
            cout << "Value not found!" << endl;

        return 0;
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << endl;
    }
    catch(...)
    {
        cerr << "Unexpected error!\n";
    }
}