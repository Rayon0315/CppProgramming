#include<iostream>
using namespace std;

int main() {
    char letter = 'A';
    cout << letter << endl;
    cout << "Hello * China!\n";
    cout << "Hello\tChina!\n";
    cout << "Hello * \bChina!\n";
    cout << "Hello*China!\nHello*World! \r";
    cout << "\101\102\103\104\x41\x42\x43\x44\n";
    //\b等效于backspace
    //\r使得光标回到行首，后续字符进行覆盖
    return 0;
}