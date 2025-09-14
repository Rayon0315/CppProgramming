#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int a, b, s;
    cout.setf(ios::showbase);
    a = 01137; b = 023362; s = a + b;

    cout << "八进制数：";
    cout << oct << a << "+" << b << "=" << s << endl;

    cout << "十进制数：";
    cout << dec << a << "+" << b << "=" << s << endl;

    cout << "十六进制数：";
    cout << hex << a << "+" << b << "=" << s << endl;

    cout << "Hello!\nI am Li Hua.\n";
    cout << "Hello!" << '\n' << "I am Li Hua." << '\n';
    cout << "Hello!" << endl << "I am Li Hua." << endl;
    
    cout << setw(10) << setfill('*') << setprecision(4) << 711.5612 << endl;

    return 0;
}