#include<iostream>
#include<cstring>
using namespace std;

class MyArray {
private:
    int* data;
    size_t size;
    void copyData(const int * src, size_t newSize);

public:
    MyArray(size_t siz);
    MyArray(const MyArray& other);

    int& operator [] (size_t index);
    const int& operator [] (size_t index) const;

    MyArray& operator = (const MyArray& other);
    MyArray operator + (const MyArray& other) const;
    MyArray operator - (const MyArray& other) const;
    bool operator == (const MyArray& other) const;

    ~MyArray();

    size_t getSize() const;
    
    friend ostream& operator << (ostream& out, const MyArray& arr);
    friend istream& operator >> (istream& in, MyArray& arr);
};

void MyArray::copyData(const int * src, size_t newSize) {
    for (size_t i = 0; i < newSize; i++) data[i] = src[i];
}

MyArray::MyArray(size_t siz) : size(siz), data(new int[siz]) {
    memset(data, 0, sizeof(int) * siz);
}
MyArray::MyArray(const MyArray& other): size(other.size), data(new int[other.size]) {
    copyData(other.data, other.size);
}

MyArray& MyArray::operator = (const MyArray& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[other.size];
        copyData(other.data, other.size);
    }
    return *this;
}

int& MyArray::operator [] (size_t index) {
    return data[index];
}
const int& MyArray::operator [] (size_t index) const {
    return data[index];
}

MyArray MyArray::operator + (const MyArray& other) const {
    MyArray result(size);
    if (size != other.size) {
        cout << "处理错误，输入的两数组必须长度相同。即将返回错误值！" << endl;
        return result;
        // exit(1);
    }
    for (size_t i = 0; i < size; i++) {
        result[i] = data[i] + other[i];
    }
    return result;
}
MyArray MyArray::operator - (const MyArray& other) const {
    MyArray result(size);
    if (size != other.size) {
        cout << "处理错误，输入的两数组必须长度相同。即将返回错误值！" << endl;
        return result;
        // exit(1);
    }
    for (size_t i = 0; i < size; i++) {
        result[i] = data[i] - other[i];
    }
    return result;
}
bool MyArray::operator == (const MyArray& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; i++) {
        if (data[i] != other[i]) {
            return false;
        }
    }
    return true;
}

MyArray::~MyArray() {
    delete[] data;
}

size_t MyArray::getSize() const {
    return size;
}

ostream& operator << (ostream& out, const MyArray& arr) {
    for (size_t i = 0; i < arr.getSize(); i++) {
        out << arr[i] << " ";
    }
    return out;
}
istream& operator >> (istream& in, MyArray& arr) {
    for (size_t i = 0; i < arr.getSize(); i++) {
        in >> arr[i];
    }
    return in;
}

int main() {
    MyArray A(5), B(5), C(6);
    int n = 5;
    for (int i = 0; i < n; i++) {
        A[i] = i + 1;
        B[i] = 2 * i;
    }

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << endl;

    MyArray sum1 = A + B;
    cout << "A + B: " << sum1 << endl;
    MyArray sum2 = A + C;
    cout << endl;

    MyArray sub1 = A - B;
    cout << "A - B:" << sub1 << endl;
    MyArray sub2 = A - C;
    cout << endl;

    MyArray A1 = A;
    cout << "A == B: " << (A == B) << endl;
    cout << "A == A1:" << (A == A1) << endl;
    cout << endl;

    cout << "请更改A" << endl;
    cin >> A;
    cout << "现在的A为:" << A << endl;

    return 0;
}