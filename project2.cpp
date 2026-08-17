#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;

class BigInt {
    string number;
    bool isNegative;

    void removeLeadingZeros() {
        while(number[0] == '0' && number.length() > 1 ){
            number.erase(0, 1);
        }
        if(number == "0"){
            isNegative = false;
        }
    }

    int compareMagnitude(const BigInt& other) const {
        if (number.length() > other.number.length()){
            return 1;
        }
        else if (number.length() < other.number.length()){
            return -1;
        }
        else {
            if (number > other.number){
                return 1;
            }
            else if (number < other.number){
                return -1;
            }
            else {
               return 0;
            }
        }
        return 0;
    }

public:
    BigInt() {
        number = "0";
        isNegative = false;
    }

    BigInt(int64_t value) {
        if (value < 0){
            isNegative = true;
            value = abs(value);
            number = to_string(value);
        }
        else {
            isNegative = false;
            number = to_string(value);
        }
    }

    BigInt(const string& str) {
        if (str[0] == '-'){
            isNegative = true;
            number = str.substr(1);
        }
        else{
            isNegative = false;
            number = str;
        }
        removeLeadingZeros();
    }

    BigInt(const BigInt& other) {
        number = other.number;
        isNegative = other.isNegative;

    }

    // Destructor
    ~BigInt() {
        // TODO: Implement if needed
    }

    BigInt& operator=(const BigInt& other) {
        if (this != &other) {
            number = other.number;
            isNegative = other.isNegative;
        }
        return *this;
    }

    // Unary negation operator (-x)
    BigInt operator-() const {
        BigInt result(*this);
        // Zero stays non-negative so it never prints as "-0"
        if (result.number != "0") {
            result.isNegative = !result.isNegative;
        }
        return result;
    }

    // Unary plus operator (+x)
    BigInt operator+() const {
        BigInt result(*this);
        return result;
    }

    // Addition assignment operator (x += y)
    BigInt& operator+=(const BigInt& other) {
        // TODO: Implement this operator
        return *this;
    }

    // Subtraction assignment operator (x -= y)
    BigInt& operator-=(const BigInt& other) {
        // TODO: Implement this operator
        return *this;
    }

    // Multiplication assignment operator (x *= y)
    BigInt& operator*=(const BigInt& other) {
        // TODO: Implement this operator
        return *this;
    }

    // Division assignment operator (x /= y)
    BigInt& operator/=(const BigInt& other) {
        if(other.number=="0"){//division by zero
        throw runtime_error("Division bt zero");
        }
            bool finalsign=isNegative^other.isNegative;//detecting the sign
        
           if(compareMagnitude(other)==-1){//divisor greater 
               number="0";
               isNegative=false;
               return *this;}
        
        
            string result;
            BigInt divisor =other;
          divisor.isNegative=false;
         BigInt current("0");
        for(size_t i=0;i<number.length;i++){
            current=current*BigInt(10)+BigInt(number[i]-"0");
            int low=0,high=9,s=0;
            while(low<=high){
                int mid=(low+high)/2;
                BigInt product=divisor*BigInt(mid);
                if(product.compareMagnitude(current)<=0){
                    s=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
                BigInt product =divisor*BigInt(s);
                current=current-product;
                 result+=to_string(s);
        }
        number=result;
        isNegative=finalsign;
        removeLeadingZeros();
            
                
        return *this;
    }

    // Modulus assignment operator (x %= y)
    BigInt& operator%=(const BigInt& other) {
         if(other.number=="0"){//division by zero
        throw runtime_error("Division bt zero");
        }
        BigInt q=*this/other;
        *this=*this-(q*other);
        return *this;
    }

    // Pre-increment operator (++x)
    BigInt& operator++() {
        *this += BigInt(1);
        return *this;
    }

    // Post-increment operator (x++)
    BigInt operator++(int) {
        BigInt temp(*this);
        ++(*this);
        return temp;
    }

    // Pre-decrement operator (--x)
    BigInt& operator--() {
        *this -= BigInt(1);
        return *this;
    }

    // Post-decrement operator (x--)
    BigInt operator--(int) {
        BigInt temp(*this);
        --(*this);
        return temp;
    }

    // Convert BigInt to string representation
    string toString() const {
        // TODO: Implement this function
        return "";
    }

    friend ostream& operator<<(ostream& os, const BigInt& num) {
        if (num.number.empty()) {
            os << '0';
            return os;
        }
        if (num.isNegative && !(num.number.size() == 1 && num.number == "0")) {
            os << '-';
        }
        os << num.number;
        return os;
    }

    friend istream& operator>>(istream& is, BigInt& num) {
        string s;
        if (!(is >> s)) return is;
        bool neg = false;
        size_t idx = 0;
        if (!s.empty() && (s[0] == '+' || s[0] == '-')) {
            neg = (s[0] == '-');
            idx = 1;
        }
        if (idx >= s.size()) {
            is.setstate(ios::failbit);
            return is;
        }
        for (size_t i = idx; i < s.size(); ++i) {
            if (!isdigit(static_cast<unsigned char>(s[i]))) {
                is.setstate(ios::failbit);
                return is;
            }
        }
        num.number = s.substr(idx);
        num.isNegative = neg;
        num.removeLeadingZeros();
        return is;
    }
    friend bool operator==(const BigInt& lhs, const BigInt& rhs);
    friend bool operator<(const BigInt& lhs, const BigInt& rhs);
};

// Binary addition operator (x + y)
BigInt operator+(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO: Implement this operator
    return result;
}

// Binary subtraction operator (x - y)
BigInt operator-(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO: Implement this operator
    return result;
}

// Binary multiplication operator (x * y)
BigInt operator*(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO: Implement this operator
    return result;
}

// Binary division operator (x / y)
BigInt operator/(BigInt lhs, const BigInt& rhs) {
    BigInt result;
  lhs/=rhs;
    result=lhs;
    return result;
}

// Binary modulus operator (x % y)
BigInt operator%(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    lhs%=rhs;
    result=lhs;
    return result;
}

bool operator==(const BigInt& lhs, const BigInt& rhs) {
    return lhs.isNegative == rhs.isNegative && lhs.number == rhs.number;
}

bool operator!=(const BigInt& lhs, const BigInt& rhs) {
    return !(lhs == rhs);
}

bool operator<(const BigInt& lhs, const BigInt& rhs) {
    if (lhs == rhs) return false;
    if (lhs.isNegative != rhs.isNegative) return lhs.isNegative;

    int mag = lhs.compareMagnitude(rhs);
    if (!lhs.isNegative) {
        // both non-negative
        return (mag < 0);
    } else {
        return (mag > 0);
    }
}

bool operator<=(const BigInt& lhs, const BigInt& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const BigInt& lhs, const BigInt& rhs) {
    return rhs < lhs;
}

bool operator>=(const BigInt& lhs, const BigInt& rhs) {
    return !(lhs < rhs);
}

int main() {
    cout << "=== BigInt Class Test Program ===" << endl << endl;
    cout << "NOTE: All functions are currently empty." << endl;
    cout << "Your task is to implement ALL the functions above." << endl;
    cout << "The tests below will work once you implement them correctly." << endl << endl;

    /*
    // Test 1: Constructors and basic output
    cout << "1. Constructors and output:" << endl;
    BigInt a(12345);              // Should create BigInt from integer
    BigInt b("-67890");           // Should create BigInt from string
    BigInt c("0");                // Should handle zero correctly
    BigInt d = a;                 // Should use copy constructor
    cout << "a (from int): " << a << endl;        // Should print "12345"
    cout << "b (from string): " << b << endl;     // Should print "-67890"
    cout << "c (zero): " << c << endl;            // Should print "0"
    cout << "d (copy of a): " << d << endl << endl; // Should print "12345"

    // Test 2: Arithmetic operations
    cout << "2. Arithmetic operations:" << endl;
    cout << "a + b = " << a + b << endl;          // Should calculate 12345 + (-67890)
    cout << "a - b = " << a - b << endl;          // Should calculate 12345 - (-67890)
    cout << "a * b = " << a * b << endl;          // Should calculate 12345 * (-67890)
    cout << "b / a = " << b / a << endl;          // Should calculate (-67890) / 12345
    cout << "a % 100 = " << a % BigInt(100) << endl << endl; // Should calculate 12345 % 100

    // Test 3: Relational operators
    cout << "3. Relational operators:" << endl;
    cout << "a == d: " << (a == d) << endl;       // Should be true (12345 == 12345)
    cout << "a != b: " << (a != b) << endl;       // Should be true (12345 != -67890)
    cout << "a < b: " << (a < b) << endl;         // Should be false (12345 < -67890)
    cout << "a > b: " << (a > b) << endl;         // Should be true (12345 > -67890)
    cout << "c == 0: " << (c == BigInt(0)) << endl << endl; // Should be true (0 == 0)

    // Test 4: Unary operators and increments
    cout << "4. Unary operators and increments:" << endl;
    cout << "-a: " << -a << endl;                 // Should print "-12345"
    cout << "++a: " << ++a << endl;               // Should increment and print "12346"
    cout << "a--: " << a-- << endl;               // Should print "12346" then decrement
    cout << "a after decrement: " << a << endl << endl; // Should print "12345"

    // Test 5: Large number operations
    cout << "5. Large number operations:" << endl;
    BigInt num1("12345678901234567890");
    BigInt num2("98765432109876543210");
    cout << "Very large addition: " << num1 + num2 << endl;
    cout << "Very large multiplication: " << num1 * num2 << endl << endl;

    // Test 6: Edge cases and error handling
    cout << "6. Edge cases:" << endl;
    BigInt zero(0);
    BigInt one(1);
    try {
        BigInt result = one / zero;               // Should throw division by zero error
        cout << "Division by zero succeeded (unexpected)" << endl;
    } catch (const runtime_error& e) {
        cout << "Division by zero correctly threw error: " << e.what() << endl;
    }
    cout << "Multiplication by zero: " << one * zero << endl;        // Should be "0"
    cout << "Negative multiplication: " << BigInt(-5) * BigInt(3) << endl;  // Should be "-15"
    cout << "Negative division: " << BigInt(-10) / BigInt(3) << endl;       // Should be "-3"
    cout << "Negative modulus: " << BigInt(-10) % BigInt(3) << endl;        // Should be "-1"
    */

    return 0;
}
