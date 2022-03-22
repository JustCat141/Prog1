#include "std_lib_facilities.h"

template<typename T> struct S
{
public:
    S() : val(T()) {}
    S(T type) { val = type; }

    void operator= (const T&);

    T& get();
    const T& get() const;
private:
    T val;
};
template<class T> T& S<T>::get()
{
    return val;
}

template<class T> const T& S<T>::get() const
{
    return val;
}

template<class T> void S<T>::operator=(const T& type)
{
    val = type;
}

template<class T> void read_val(T& v)
{
    cin >> v;
};

int main()
{
    try {
        S<int> s_int(5);
        S<char> s_char('a');
        S<double> s_double(56.2234);
        S<string> s_string("test");    
        
        vector<int> h;
        h.push_back(10);
        h.push_back(14);
        h.push_back(50);
        S<vector<int>> s_vector_int(h);

        cout << s_int.get() << endl 
            << s_char.get() << endl 
            << s_double.get() << endl 
            << s_string.get() << endl 
            /*<< s_vector_int.get() << endl*/;
        cout << "Set" << endl;
        s_int = 20;
        s_char = 'k';
        s_double = 3.1416;
        s_string = "very nice";

        cout << s_int.get() << endl 
            << s_char.get() << endl 
            << s_double.get() << endl 
            << s_string.get() << endl 
            /*<< s_vector_int.get() << endl*/;

        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }
    catch(...)
    {
        cerr << "Unknown error!" << endl;
    }
}