#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <chrono>
#include <windows.h>
#include <Psapi.h>

using namespace std;

class BigInt {
    string digits;
public:

    //Constructors:
    BigInt(unsigned long long n = 0);
    BigInt(string&);
    BigInt(const char*);
    BigInt(BigInt&);

    //Helper Functions:
    friend void divide_by_2(BigInt& a);
    friend bool Null(const BigInt&);
    friend int Length(const BigInt&);
    int operator[](const int)const;

    /* * * * Operator Overloading * * * */

//Direct assignment
    BigInt& operator=(const BigInt&);

    //Post/Pre - Incrementation
    BigInt& operator++();
    BigInt operator++(int temp);
    BigInt& operator--();
    BigInt operator--(int temp);

    //Addition and Subtraction
    friend BigInt& operator+=(BigInt&, const BigInt&);
    friend BigInt operator+(const BigInt&, const BigInt&);
    friend BigInt operator-(const BigInt&, const BigInt&);
    friend BigInt& operator-=(BigInt&, const BigInt&);

    //Comparison operators
    friend bool operator==(const BigInt&, const BigInt&);
    friend bool operator!=(const BigInt&, const BigInt&);

    friend bool operator>(const BigInt&, const BigInt&);
    friend bool operator>=(const BigInt&, const BigInt&);
    friend bool operator<(const BigInt&, const BigInt&);
    friend bool operator<=(const BigInt&, const BigInt&);

    //Multiplication and Division
    friend BigInt& operator*=(BigInt&, const BigInt&);
    friend BigInt operator*(const BigInt&, const BigInt&);
    friend BigInt& operator/=(BigInt&, const BigInt&);
    friend BigInt operator/(const BigInt&, const BigInt&);

    //Modulo
    friend BigInt operator%(const BigInt&, const BigInt&);
    friend BigInt& operator%=(BigInt&, const BigInt&);

    //Power Function
    friend BigInt& operator^=(BigInt&, const BigInt&);
    friend BigInt operator^(BigInt&, const BigInt&);

    //Read and Write
    friend ostream& operator<<(ostream&, const BigInt&);
    friend istream& operator>>(istream&, BigInt&);
};

BigInt::BigInt(string& s) {
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(unsigned long long nr) {
    do {
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}
BigInt::BigInt(const char* s) {
    digits = "";
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(BigInt& a) {
    digits = a.digits;
}

bool Null(const BigInt& a) {
    if (a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}
int Length(const BigInt& a) {
    return a.digits.size();
}
int BigInt::operator[](const int index)const {
    if (digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}
bool operator==(const BigInt& a, const BigInt& b) {
    return a.digits == b.digits;
}
bool operator!=(const BigInt& a, const BigInt& b) {
    return !(a == b);
}
bool operator<(const BigInt& a, const BigInt& b) {
    int n = Length(a), m = Length(b);
    if (n != m)
        return n < m;
    while (n--)
        if (a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}
bool operator>(const BigInt& a, const BigInt& b) {
    return b < a;
}
bool operator>=(const BigInt& a, const BigInt& b) {
    return !(a < b);
}
bool operator<=(const BigInt& a, const BigInt& b) {
    return !(a > b);
}

BigInt& BigInt::operator=(const BigInt& a) {
    digits = a.digits;
    return *this;
}

BigInt& BigInt::operator++() {
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9; i++)
        digits[i] = 0;
    if (i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}
BigInt BigInt::operator++(int temp) {
    BigInt aux;
    aux = *this;
    ++(*this);
    return aux;
}

BigInt& BigInt::operator--() {
    if (digits[0] == 0 && digits.size() == 1)
        throw("UNDERFLOW");
    int i, n = digits.size();
    for (i = 0; digits[i] == 0 && i < n; i++)
        digits[i] = 9;
    digits[i]--;
    if (n > 1 && digits[n - 1] == 0)
        digits.pop_back();
    return *this;
}
BigInt BigInt::operator--(int temp) {
    BigInt aux;
    aux = *this;
    --(*this);
    return aux;
}

BigInt& operator+=(BigInt& a, const BigInt& b) {
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if (m > n)
        a.digits.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n; i++) {
        if (i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if (t)
        a.digits.push_back(t);
    return a;
}
BigInt operator+(const BigInt& a, const BigInt& b) {
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}

BigInt& operator-=(BigInt& a, const BigInt& b) {
    if (a < b)
        throw("UNDERFLOW");
    int n = Length(a), m = Length(b);
    int i, t = 0, s;
    for (i = 0; i < n; i++) {
        if (i < m)
            s = a.digits[i] - b.digits[i] + t;
        else
            s = a.digits[i] + t;
        if (s < 0)
            s += 10,
            t = -1;
        else
            t = 0;
        a.digits[i] = s;
    }
    while (n > 1 && a.digits[n - 1] == 0)
        a.digits.pop_back(),
        n--;
    return a;
}
BigInt operator-(const BigInt& a, const BigInt& b) {
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}

BigInt& operator*=(BigInt& a, const BigInt& b)
{
    if (Null(a) || Null(b)) {
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            v[i + j] += (a.digits[i]) * (b.digits[j]);
        }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i];
    }
    for (int i = n - 1; i >= 1 && !v[i]; i--)
        a.digits.pop_back();
    return a;
}
BigInt operator*(const BigInt& a, const BigInt& b) {
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}

BigInt& operator/=(BigInt& a, const BigInt& b) {
    if (Null(b))
        throw("Arithmetic Error: Division By 0");
    if (a < b) {
        a = BigInt();
        return a;
    }
    if (a == b) {
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a.digits.resize(cat.size());
    for (i = 0; i < lgcat; i++)
        a.digits[i] = cat[lgcat - i - 1];
    a.digits.resize(lgcat);
    return a;
}
BigInt operator/(const BigInt& a, const BigInt& b) {
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}

BigInt& operator%=(BigInt& a, const BigInt& b) {
    if (Null(b))
        throw("Arithmetic Error: Division By 0");
    if (a < b) {
        return a;
    }
    if (a == b) {
        a = BigInt();
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a = t;
    return a;
}
BigInt operator%(const BigInt& a, const BigInt& b) {
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}

BigInt& operator^=(BigInt& a, const BigInt& b) {
    BigInt Exponent, Base(a);
    Exponent = b;
    a = 1;
    while (!Null(Exponent)) {
        if (Exponent[0] & 1)
            a *= Base;
        Base *= Base;
        divide_by_2(Exponent);
    }
    return a;
}
BigInt operator^(BigInt& a, BigInt& b) {
    BigInt temp(a);
    temp ^= b;
    return temp;
}

void divide_by_2(BigInt& a) {
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while (a.digits.size() > 1 && !a.digits.back())
        a.digits.pop_back();
}

istream& operator>>(istream& in, BigInt& a) {
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const BigInt& a) {
    for (int i = a.digits.size() - 1; i >= 0; i--)
        cout << (short)a.digits[i];
    return cout;
}

class Timer {
public:
    Timer() : start_time(chrono::high_resolution_clock::now()) {}

    void reset() {
        start_time = chrono::high_resolution_clock::now();
    }

    double elapsed() const {
        return chrono::duration<double, milli>(chrono::high_resolution_clock::now() - start_time).count();
    }

private:
    chrono::high_resolution_clock::time_point start_time;
};

class MemoryTracker {
public:
    MemoryTracker() {
        update();
    }

    void update() {
        HANDLE hProcess = GetCurrentProcess();
        PROCESS_MEMORY_COUNTERS pmc;
        if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
            current_usage = pmc.WorkingSetSize / 1024;
        }
        CloseHandle(hProcess);
    }

    SIZE_T getUsage() const {
        return current_usage;
    }

private:
    SIZE_T current_usage;
};

//Driver code with some examples
int main()
{
    // Initialize variables and parse values into BigInteger class
    BigInt first("5555123456789987654321");
    BigInt second("2222987654321123456789");
    
    MemoryTracker tracker;
    Timer timer;

    // Calculate execution time and memory usage of sum operation
    BigInt sumValue;
    sumValue = (first + second);
    cout << "Sum of first and second = " << sumValue << '\n';
    cout << "Elapsed time for sum operation: " << timer.elapsed() << " ms\n";
    timer.reset();
    tracker.update();
    cout << "Memory usage: " << tracker.getUsage() << " KB\n";

    // Calculate execution time and memory usage of subtract operation
    BigInt subValue;
    subValue = (first - second);
    cout << "Subtract of first and second = " << subValue << '\n';
    cout << "Elapsed time for subtract operation: " << timer.elapsed() << " ms\n";
    timer.reset();
    tracker.update();
    cout << "Memory usage: " << tracker.getUsage() << " KB\n";

    // Calculate execution time and memory usage of multiply operation
    BigInt mulValue;
    mulValue = (first * second);
    cout << "Multiply of first and second = " << mulValue << '\n';
    cout << "Elapsed time for multiply operation: " << timer.elapsed() << " ms\n";
    timer.reset();
    tracker.update();
    cout << "Memory usage: " << tracker.getUsage() << " KB\n";

    // Calculate execution time and memory usage of divide operation
    BigInt divValue;
    divValue = (first / second);
    cout << "Divide of first and second = " << divValue << '\n';
    cout << "Elapsed time for divide operation: " << timer.elapsed() << " ms\n";
    timer.reset();
    tracker.update();
    cout << "Memory usage: " << tracker.getUsage() << " KB\n";

    // Calculate execution time and memory usage of modulo operation
    BigInt modValue;
    modValue = (first % second);
    cout << "Modulo of first and second = " << modValue << '\n';
    cout << "Elapsed time for modulo operation: " << timer.elapsed() << " ms\n";
    timer.reset();
    tracker.update();
    cout << "Memory usage: " << tracker.getUsage() << " KB\n";

    // Calculate execution time and memory usage of power operation
    BigInt powValue, power("10"), expo("1000");
    powValue = (power ^ expo);
    cout << "Subtract of first and second = " << powValue << '\n';
    cout << "Elapsed time for power operation: " << timer.elapsed() << " ms\n";
    timer.reset();
    tracker.update();
    cout << "Memory usage: " << tracker.getUsage() << " KB\n";

    return 0;
}
