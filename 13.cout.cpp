#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setw(15) << setfill('*') << left << setprecision(8) << 1001.12345 << endl;
    return 0;
}