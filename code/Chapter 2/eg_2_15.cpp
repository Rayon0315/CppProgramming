#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string judge(int total) {
    if (total >= 90) return "优秀";
    else if (total >= 80) return "良好";
    else return "一般";
}

int main() {
    double total1, total2, total3;
    double moral, intellectual, physical, ability;
    cout << "输入三人的德育、智育、体育和能力积分：\n";

    cin >> moral >> intellectual >> physical >> ability;
    total1 = moral * 0.2 + intellectual * 0.5 + physical * 0.2 + ability * 0.1;
    cin >> moral >> intellectual >> physical >> ability;
    total2 = moral * 0.2 + intellectual * 0.5 + physical * 0.2 + ability * 0.1;
    cin >> moral >> intellectual >> physical >> ability;
    total3 = moral * 0.2 + intellectual * 0.5 + physical * 0.2 + ability * 0.1;

    cout << total1 << ':' << judge(total1) << endl;
    cout << total2 << ':' << judge(total2) << endl;
    cout << total3 << ':' << judge(total3) << endl;

    vector<double> tot = {total1, total2, total3};
    sort(tot.begin(), tot.end(), greater<int>());
    cout << "总分从高到低的顺序为：" << endl;
    cout << tot[0] << '\t' << tot[1] << '\t' << tot[2] << endl;

    return 0;
}