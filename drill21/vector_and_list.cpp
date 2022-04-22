#include "std_lib_facilities.h"

struct Item
{
    string name;
    int iid;
    double value;
    Item()
    {
        name = "null";
        iid = -1;
        value = 0;
    }
    Item(string _name, int _iid, double _value)
    {
        name = _name; 
        iid = _iid; 
        value = _value;
    }
};

void fill(string path, vector<Item>& items)
{
    ifstream read(path);

    Item input;
    while (read.peek() != EOF)
    {
        string name; read >> name;
        int iid; read >> iid;
        double value; read >> value;

        input = Item{name,iid,value};
        items.push_back(input);
    }
}

ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << '\t' << it.iid << '\t' << it.value;
}

void print_items(vector<Item>& items)
{
    for (int i = 0; i < items.size(); i++)
    {
        cout << items[i] << endl;
    }
}

struct compare_name
{
    bool operator()(const Item& a, const Item& b)
    {return a.name < b.name;}
};
struct compare_id
{
    bool operator()(const Item& a, const Item& b)
    {return a.iid < b.iid;}
};
struct compare_value
{
    bool operator()(const Item& a, const Item& b)
    {return a.value < b.value;}
};

int main()
{
    vector<Item> vi;
    fill("data.txt",vi);

    // sort
    sort(vi.begin(),vi.end(),compare_name());
    //print_items(vi);
    sort(vi.begin(),vi.end(),compare_id());
    //print_items(vi);
    sort(vi.begin(),vi.end(),compare_value());
    //print_items(vi);

    vi.push_back(Item{"horshe shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});

    //erase by name
    vector<Item>::iterator it = 
    find_if(vi.begin(),vi.end(), [](const Item& item) {return item.name == "farcry6";});
    vi.erase(it);
    it = find_if(vi.begin(),vi.end(), [](const Item& item) {return item.name == "air";});
    vi.erase(it);

    // erase by id
    it = find_if(vi.begin(),vi.end(), [](const Item& item) {return item.iid == 2;});
    vi.erase(it);
    it = find_if(vi.begin(),vi.end(), [](const Item& item) {return item.iid == 99;});
    vi.erase(it);

    //cout << vi.size() << endl;



    // List
    list<Item> li(10);
    copy(vi.begin(),vi.end(),li.begin());

    // sort
    li.sort(compare_name());
    li.sort(compare_id());
    li.sort(compare_value());

    li.push_back(Item{"horse shoe", 99, 12.34});
    li.push_back(Item{"Canon S400", 9988, 499.95});

    li.remove_if([](const Item& item) {return item.name == "farcry6";});
    li.remove_if([](const Item& item) {return item.name == "water";});

    li.remove_if([](const Item& item) {return item.iid == 2;});
    li.remove_if([](const Item& item) {return item.iid == 99;});

    //cout << li.size() << endl;
    return 0;
}