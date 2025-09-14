#include<iostream>
using namespace std;

int main() {
    unsigned int gdp2022 = 0xffffff11;
    unsigned int temp = 0xff;
    unsigned int sum = gdp2022 + temp;
    cout << "sum = " << sum << endl;

    char letter1 = 'A';
    char letter2 = letter1 + 32;
    char letter3 = letter1 + letter2;
    cout << "letter1 = " << letter1 << endl;
    cout << "letter2 = " << letter2 << endl;
    cout << "letter3 = " << letter3 << endl;
    
    double gdp2023 = 126.06E12;
    cout << "gdp2022 + gdp2023 = " << gdp2022 + gdp2023 << endl;
    return 0;
}