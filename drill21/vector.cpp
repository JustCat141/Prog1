#include "std_lib_facilities.h"

template<typename T>
void print_vector(const vector<T>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;    
}

// Unsafe method!
template<typename T>
T sum(const vector<T>& v)
{
    T s = 0;
    for (int i = 0; i < v.size(); i++)
    {
        s += v[i];
    }
    return s;
}

int main()
{
    const string path = "vector_data.txt";
    vector<double> vd;
    double temp;

    // Import from file
    ifstream reader(path);
    while(reader >> temp)
    {
        vd.push_back(temp);
    }

    print_vector(vd);

    vector<int> vi(vd.size());
    copy(vd.begin(),vd.end(),vi.begin());

    for (int i = 0; i < vi.size(); i++)
    {
        cout << "vd:" << vd[i] << '\t' << "vi: " << vi[i] << endl;
    }

    int isum = sum(vi);
    cout << "The sum of the int vector is: " << isum << endl;

    double dsum = accumulate(vd.begin(),vd.end(),0.0);
    cout << "The sum of the double vector is: " << dsum << endl;
    
    /*double dsum = 0;
    for(double elem : vd)
    {
        dsum += elem;
    }
    cout << dsum << endl;*/
    // prints only whole number??

    cout << "Difference (double - int vector) is: " << dsum - isum << endl;

    reverse(vd.begin(),vd.end());
    print_vector(vd);

    double mean = dsum / vd.size();
    cout << "Double vector mean is: " << mean << endl;

    vector<double> vd2;
    //auto it = copy_if(vd.begin(),vd.end(),vd2.begin(), [mean](double value) {return value < mean;});
    //vd2.resize(distance(vd2.begin(),it));
    for (int i = 0; i < vd.size(); i++)
    {
        if(vd[i] < mean) vd2.push_back(vd[i]);
    }
    
    
    cout << "Values below mean:\n";
    print_vector(vd2); 

    sort(vd.begin(),vd.end());
    print_vector(vd);
    
    return 0;
}