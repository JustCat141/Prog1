#include "std_lib_facilities.h"

template<typename T1, typename T2>
void print_map(map<T1, T2>& m)
{
    for(auto const& elem : m)
    {
        cout << elem.first << "\t" << elem.second << endl;
    }
}

void read(map<string, int>& m) {
    string v;
    int value;
    
    cin >> v >> value;
    m[v] = value;
}

int getsum(const map<string, int>& m)
{
    int sum = 0;
    for(const auto elem : m)
    {
        sum += elem.second;
    }
    return sum;
}

int main()
{

    map<string,int> msi;

    msi["szuletesi_evem"] = 94;
    msi["asd"] = 12;
    msi["idk"] = 1;
    msi["lol"] = 23;
    msi["addasa"] = 2;
    msi["hat"] = 6;
    msi["xd"] = 3423;
    msi["t"] = 9;
    msi["oluso"] = 23;
    msi["mzp"] = 32;

    msi.clear();

    cout << "Type 10 values (string, int)!\n";
    for (int i = 0; i < 10; i++)
    {
        read(msi);
    }

    print_map(msi);

    cout << "The sum of the ints: " << getsum(msi) << endl;

    map<int, string> mis;
    for(const auto elem : msi)
        mis[elem.second] = elem.first;

    print_map(mis);
    return 0;
}