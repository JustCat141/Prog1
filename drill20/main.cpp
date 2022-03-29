#include "std_lib_facilities.h"

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
// return an iterator to the element in [first:last) that has the highest value
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

int main()
{
    try
    {
        int array_int[10] = {0,1,2,3,4,5,6,7,8,9};
        vector<int> vector_int;
        list<int> list_int;

        for (int i = 0; i < 10; i++)
        {
            vector_int.push_back(i);
            list_int.push_back(i);
        }
        
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