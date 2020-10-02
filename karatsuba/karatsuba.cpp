/* Karatsuba multiplication */
#include <iostream>


using namespace std;

int numDigits(int num);
int pow10(int n);



int karatsuba(int x, int y) {

    //base case of single digit * single digit
    if (x < 10 && y < 10)
        return x * y;
    
    //find number of digits of the 2 nums
    int num1 = numDigits(x);
    int num2 = numDigits(y);

    //store the biggest numDigits
    int n;
    if (num1 > num2)
        n = num1;
    else
        n = num2;

    //if n is odd
    if (n % 2)
        n++;

    // a is the first half of x, b is the second half
    int a = x / pow10(n / 2);
    int b = x % pow10(n / 2);

    // c is the first half of y, d is the second half
    int c = y / pow10(n / 2);
    int d = y % pow10(n / 2);

    //multiply the halves together with recursion
    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);

    int middleTerm = karatsuba(a + b, c + d) - ac - bd;
    
    //karatsuba formula for reference
    //(ac * 10 ^ n) + ((a + b) * (c + d) - ac - bd) * 10 ^ (n / 2) + bd;
    return ac * pow10(n) + middleTerm * pow10(n / 2) + bd;
}

// Helper function - returns number of digits
int numDigits(int num) {
    int n = 1;
    while (num / pow10(n)) {
        ++n;
    }
    return n;
}

// Helper function - integer exponentiation
int pow10(int n) {
    if (n == 0) {
        return 1;
    }
    return 10 * pow10(n - 1);
}
