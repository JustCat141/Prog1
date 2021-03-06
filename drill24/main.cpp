#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>

using namespace Numeric_lib;

/*template<typename T>
void print_size(T obj)
{
    //cout << "Size of " << decltype(obj) << ": " << sizeof(obj);
    cout << typeid(char).name();
}*/

void program_4()
{
    cout << "Program 4: Type intiger nubers!" << endl;

    vector<int> raw_ints;
    int input_value;


    while (cin >> input_value)
    {
        raw_ints.push_back(input_value);
    }   

    for(int i = 0; i < raw_ints.size(); i++)
    {
        if (raw_ints[i] <= 0)
        {
            cout << "Number " << raw_ints[i] << " has no squareroot!\n";
        }
        else
        {
            cout << "Number " << raw_ints[i] << " squareroot is: " << sqrt(raw_ints[i]) << endl;
        }
    }
    cout << endl;
}

int main()
{
    // 1, Variables
    cout << "Variables size:" << endl;
    cout << "Char size:\t" << sizeof(char) << endl;
    cout << "Short size:\t" << sizeof(short) << endl;
    cout << "Int size:\t" << sizeof(char) << endl;
    cout << "Long size:\t" << sizeof(long) << endl;
    cout << "Float size:\t" << sizeof(float) << endl;
    cout << "Double size:\t" << sizeof(double) << endl;
    cout << "Int* size:\t" << sizeof(int*) << endl;
    cout << "Double* size:\t" << sizeof(double*) << endl;
    cout << endl;

    // 2, Matrix

    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    cout << "Matrixes size:" << endl;
    cout << "a matrix's size: " << sizeof(a) << endl;
    cout << "b matrix's size: " << sizeof(b) << endl;
    cout << "c matrix's size: " << sizeof(c) << endl;
    cout << "d matrix's size: " << sizeof(d) << endl;
    cout << "e matrix's size: " << sizeof(e) << endl;
    cout << endl;

    // 3, Print number of elements

    cout << "Number of Matrixes elements:" << endl;
    cout << "a matrix's element size: " << a.size() << endl;
    cout << "b matrix's element size: " << b.size() << endl;
    cout << "c matrix's element size: " << c.size() << endl;
    cout << "d matrix's element size: " << d.size() << endl;
    cout << "e matrix's element size: " << e.size() << endl;
    cout << endl;

    // 4, program4
    program_4();

    // 5, floating-point values in matrix
    cout << "Type 10 floating point nubers!" << endl;
    Matrix<double> double_matrix(10);

    for (int i = 0; i < 10; i++)
    {
        cin >> double_matrix[i];
    }

    for (int i = 0; i < double_matrix.size(); i++)
    {
        cout << i+1 << ". element's value in the matrix is: " << double_matrix[i] << endl;
    }
    cout << endl;


    // 6, Multiplication
    int n;
    int m;

    cout << "n and m: ";
    cin >> n >> m;

    Matrix<int,2> matrix2d(n+1,m+1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix2d[i][j] = i * j;
            cout << matrix2d[i][j] << ", ";
        }
        cout << endl;
    }
    
    // 7 Complex numbers
    cout << "Type 10 complex numbers: ";
    Matrix<complex<double>> complex_matrix(10);
    complex<double> input_value;

    for (int i = 0; i < 10; i++)
    {
        cin >> input_value;
        complex_matrix[i] = input_value;
    }
    complex<double> sum = accumulate(complex_matrix.data(), complex_matrix.data() + complex_matrix.size(), complex<double>());
    cout << "The sum is: " << sum << endl;
    
    // 8, 2DMatrix intigers
    cout << "Type 6 intigers!\n";
    Matrix<int, 2> m2(2,3);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> m2[i][j];
        }
    }
    cout << "m2:\n" << m2 << endl;
    
    return 0;
}