#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

class inf_int {
private:
    char* digits;
    unsigned int length;
    bool thesign;   // true if positive , false if negative.
    // ex) 15311111111111111 -> digits="11111111111111351", length=17, thesign=true;
    // ex) -12345555555555 -> digits="55555555554321", length=14, thesign=false
    // you may insert additional private members here.

    bool resize(int); // digits 메모리의 크기를 변경한다. (반환값 : 성공 여부)
    int compareAbsoluteDigits(const inf_int&) const; // 절댓값을 인자와 비교한다. (양수 : 내가 더 클때, 음수 : 내가 더 작을때, 0 : 같을 때)
    bool isZero() const; // 저장된 값이 0인지 판별
    void mul10(int mulCount = 1); // 저장된 값에 10을 mulCount번 곱한다.

public:
    inf_int();               // assign 0 as a default value
    inf_int(int);
    inf_int(const char*);
    inf_int(const inf_int&); // copy constructor
    ~inf_int(); // destructor

    inf_int& operator=(const inf_int&); // assignment operator

    friend bool operator==(const inf_int&, const inf_int&);
    friend bool operator!=(const inf_int&, const inf_int&);
    friend bool operator>(const inf_int&, const inf_int&);
    friend bool operator<(const inf_int&, const inf_int&);

    friend inf_int operator+(const inf_int&, const inf_int&);
    friend inf_int operator-(const inf_int&, const inf_int&);
    friend inf_int operator*(const inf_int&, const inf_int&);
    // friend inf_int operator/(const inf_int& , const inf_int&); // not required

    friend std::ostream& operator<<(std::ostream&, const inf_int&);
    // friend std::istream& operator>>(std::istream& , inf_int&);    // not required
};

inf_int::inf_int() {
    // 기본값으로 0 할당
    this->length = 1;
    this->digits = new char[this->length + 1];
    this->digits[0] = '0';
    this->digits[1] = '\0';
    this->thesign = true;
}

inf_int::inf_int(int n) {
    // 부호 처리 및 절댓값으로 변환
    if (n >= 0) {
        this->thesign = true;
    }
    else {
        this->thesign = false;
        n = -n;
    }

    // n의 자리수 세기
    if (n == 0) {
        this->length = 1;
    }
    else {
        int tempN = n;
        this->length = 0;
        while (tempN) {
            tempN /= 10;
            this->length++;
        }
    }

    this->digits = new char[this->length + 1];

    // n을 문자열로 변환해 저장 (규칙에 맞게 거꾸로 저장)
    for (int i = 0; i < this->length; i++) {
        this->digits[i] = n % 10 + '0';
        n /= 10;
    }
    this->digits[this->length] = '\0';
}

inf_int::inf_int(const char* str) {
    // 부호 처리
    if (str[0] == '-') {
        this->thesign = false;
        str++; // 부호 스킵
    }
    else if (str[0] == '+') {
        this->thesign = true;
        str++; // 부호 스킵
    }
    else {
        this->thesign = true;
    }

    this->length = strlen(str);
    this->digits = new char[this->length + 1];

    // 문자열을 규칙에 맞게 거꾸로 복사
    for (int i = 0; i < this->length; i++) {
        this->digits[i] = str[this->length - i - 1];
    }
    this->digits[this->length] = '\0';

    // 0일경우 부호는 무조건 플러스로 설정
    if (strcmp(this->digits, "0") == 0) {
        this->thesign = true;
    }
}

inf_int::inf_int(const inf_int& copy) {
    this->digits = new char[copy.length + 1];
    this->length = copy.length;
    this->thesign = copy.thesign;
    strcpy(this->digits, copy.digits);
}

inf_int::~inf_int() {
    delete[] this->digits;
}

// digits 메모리의 크기를 변경한다. (반환값 : 성공 여부)
bool inf_int::resize(int size) {
    if (size <= this->length) {
        return false;
    }

    char* newDigits = new char[size];
    strcpy(newDigits, this->digits);
    delete[] this->digits;
    this->digits = newDigits;
    return true;
}

// 절댓값을 인자와 비교한다. (양수 : 내가 더 클때, 음수 : 내가 더 작을때, 0 : 같을 때)
int inf_int::compareAbsoluteDigits(const inf_int& compare) const {
    // 길이가 긴 수가 절댓값이 크다.
    if (this->length != compare.length) {
        return (this->length - compare.length);
    }

    // 길이가 같은 경우에는 큰 자리의 숫자부터 작은 자리의 숫자까지 차례대로 비교한다.
    for (int i = this->length - 1; i >= 0; i--) {
        if (this->digits[i] != compare.digits[i]) {
            return (this->digits[i] - compare.digits[i]);
        }
    }

    // 모든 자리의 숫자가 동일하다면 절댓값이 같은 경우이다.
    return 0;
}

// 저장된 값이 0인지 판별
bool inf_int::isZero() const {
    return (strcmp(this->digits, "0") == 0);
}

// 저장된 값에 10을 mulCount번 곱한다.
void inf_int::mul10(int mulCount) {
    if (!this->isZero()) {
        this->resize(this->length + mulCount + 1);
        memmove(this->digits + mulCount, this->digits, this->length);
        for (int i = 0; i < mulCount; i++) {
            this->digits[i] = '0';
        }
        this->length += mulCount;
        this->digits[this->length] = '\0';
    }
}

inf_int& inf_int::operator=(const inf_int& copy) {
    // 기존의 동적할당한 메모리는 해제
    if (this->digits) {
        delete[] this->digits;
    }

    // copy의 데이터를 현재 객체로 복사
    this->digits = new char[copy.length + 1];
    this->length = copy.length;
    this->thesign = copy.thesign;
    strcpy(this->digits, copy.digits);

    return *this;
}

bool operator==(const inf_int& a, const inf_int& b) {
    // 부호가 일치하고 절댓값도 일치해야함
    return (strcmp(a.digits, b.digits) == 0) && (a.thesign == b.thesign);
}

bool operator!=(const inf_int& a, const inf_int& b) {
    return !operator==(a, b);
}

bool operator>(const inf_int& a, const inf_int& b) {
    if (a.thesign != b.thesign) {
        // 부호가 다르다면 양수인 것이 더 큰 것이다.
        // a의 부호진리값이 비교 결과와 같게 된다.
        return a.thesign;
    }
    else {
        int absCmp = a.compareAbsoluteDigits(b); // a의 절댓값이 크면 양수, b의 절댓값이 크면 음수, 같으면 0
        if (a.thesign == true) {
            // 둘 다 양수라면 절댓값이 큰 것이 큰 수이다.
            return (absCmp > 0); // a의 절댓값이 크면 true
        }
        else {
            // 둘 다 음수라면 절댓값이 작은 것이 큰 수이다.
            return (absCmp < 0); // b의 절댓값이 크면 true
        }
    }
}

bool operator<(const inf_int& a, const inf_int& b) {
    if (operator>(a, b) || operator==(a, b)) {
        return false;
    }
    else {
        return true;
    }
}

inf_int operator+(const inf_int& a, const inf_int& b) {
    inf_int left = a, right = b;

    if (left.compareAbsoluteDigits(right) < 0) {
        inf_int temp = left;
        left = right;
        right = temp;
    }

    if (right.isZero()) {
        return left;
    }

    if (left.thesign == right.thesign) {
        int carry = 0;

        for (int i = 0; i < left.length; i++) {
            int sum = left.digits[i] - '0' + carry;
            if (i < right.length) {
                sum += right.digits[i] - '0';
            }

            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            left.digits[i] = sum + '0';
        }

        if (carry) {
            // 최종적으로 자리 올림이 발생하면 추가 자리수가 필요하므로 동적 할당을 다시 한다.
            left.length++;
            left.resize(left.length + 1);
            left.digits[left.length - 1] = '1';
            left.digits[left.length] = '\0';
        }

        if (left.isZero()) {
            left.thesign = true;
        }

        return left;
    }
    else {
        // 부호가 다른 경우 우항의 부호를 반전하고 뺄셈으로 처리한다.
        // a+b = a-(-b) 성질 이용
        right.thesign = !right.thesign;
        return left - right;
    }
}

inf_int operator-(const inf_int& a, const inf_int& b) {
    inf_int left = a, right = b;

    if (left.thesign != right.thesign) {
        // 부호가 다른 경우 우항의 부호를 반전하고 덧셈으로 처리한다.
        // a-b = a+(-b) 성질 이용
        right.thesign = !right.thesign;
        return left + right;
    }

    if (left.thesign == false && right.thesign == false) {
        // 부호가 둘 다 음수이면 둘 다 부호를 반전하고 빼는 순서를 뒤바꾼다.
        // a-b = (-b)-(-a) 성질 이용
        left.thesign = !left.thesign;
        right.thesign = !right.thesign;
        return right - left;
    }

    int absCmp = left.compareAbsoluteDigits(right);
    if (absCmp < 0) {
        inf_int temp = left;
        left = right;
        right = temp;
        left.thesign = false;
    }
    else if (absCmp > 0) {
        left.thesign = true;
    }
    else {
        return inf_int(0);
    }

    if (right.isZero()) {
        return left;
    }

    int carry = 0;
    for (int i = 0; i < left.length; i++) {
        int sum = left.digits[i] - '0' + carry;
        if (i < right.length) sum -= right.digits[i] - '0';

        if (sum < 0) {
            sum += 10;
            carry = -1;
        }
        else {
            carry = 0;
        }
        left.digits[i] = sum + '0';
    }

    // 뺄셈 결과에는 0이 맨 앞에 붙어있을 수도 있다.
    // 아래 코드로 leading zero를 제거한다.
    for (int i = left.length - 1; i >= 1; i--) {
        if (left.digits[i] == '0') {
            left.digits[i] = '\0';
            left.length--;
        }
        else {
            break;
        }
    }

    if (left.isZero()) {
        left.thesign = true;
    }

    return left;
}

inf_int operator*(const inf_int& a, const inf_int& b) {
    inf_int left = a, right = b;

    if (left.isZero() || right.isZero()) {
        return inf_int(0);
    }

    bool signFlag = true;
    if (left.thesign != right.thesign) {
        signFlag = false;
    }
    left.thesign = true;
    right.thesign = true;

    inf_int leftMultipliedBy[10];
    for (int i = 1; i < 10; i++) {
        leftMultipliedBy[i] = leftMultipliedBy[i - 1] + left;
    }

    inf_int result;

    for (int i = 0; i < right.length; i++) {
        if (right.digits[i] == '0') {
            continue;
        }

        inf_int temp = leftMultipliedBy[right.digits[i] - '0'];
        temp.mul10(i);
        result = result + temp;
    }

    result.thesign = signFlag;
    return result;
}

ostream& operator<<(ostream& out, const inf_int& a) {
    if (a.thesign == false) {
        out << '-';
    }

    for (int i = a.length - 1; i >= 0; i--) {
        out << a.digits[i];
    }

    return out;
}

int main() {
    string aStr, bStr;
    cin >> aStr >> bStr;

    inf_int a = aStr.c_str(), b = bStr.c_str();
    cout << a + b;
    return 0;
}