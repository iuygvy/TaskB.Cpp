//Bartosz Bugajski
#include <string>
#include <cstdarg>
using namespace std;
#include "head.h"

int IndexOfNonZero(string, int = 0);
string MakeStringNormal(string, string = "", int = 0, int = 0);
void AddToArray(const string*, string*, int, int = 0);
int CharToInt(char);
char IntToChar(int);
string ReverseString(string, int, string = "");
string AddTwo(string, string, int, int, int = 0, string = "");
string DeletePlus(string, int, int = 0, string = "");
void VlToStringArr(va_list, string*, int, int = 0);

int SubtractUntilOneDigit(int& number, int i = 0)
{
    if(number < 10)
    {
        return i;
    }
    number -= 10;
    return SubtractUntilOneDigit(number, ++i);
}

string MultTwoHelp(string s1, int k, int i1, int carry = 0, string result = "")
{
    if(i1 <= 0 && carry == 0)
    {
        result = ReverseString(result, result.length()-1);
        return result;
    }
    int product = carry;
    if(i1 > 0)
    {
        product += k * CharToInt(s1[i1]);
    }
    carry = SubtractUntilOneDigit(product);
    result += IntToChar(product);
    return MultTwoHelp(s1, k, --i1, carry, result);
}

string MultTwo(string s1, string s2, int i1, int i2, int carry = 0, string result = "")
{
    if(i2 == 0)
    {
        return result;
    }
    string product = '+' + MultTwoHelp(s1, CharToInt(s2[i2]), s1.length()-1);
    product.resize(product.length() + s2.length() - 1 - i2, '0');
    result = AddTwo('+' + result, product, result.length(), product.length()-1);
    return MultTwo(s1, s2, i1, --i2, carry, result);
}

string MultAll(string* args, int n, int k = 0)
{
    if(k + 1 == n)
    {
        if(args[k][0] == '+')
        {
            args[k] = DeletePlus(args[k], args[k].length());
        }
        return args[k];
    }
    if(args[k][1] == '0' || args[k+1][1] == '0' )
    {
        return "0";
    }
    else if(args[k][0] == '+' && args[k+1][0] == '+' || args[k][0] == '-' && args[k+1][0] == '-')
    {
        args[k+1] = '+' + MultTwo(args[k], args[k+1], args[k].length()-1, args[k+1].length()-1);
    }
    else
    {
        args[k+1] = '-' + MultTwo(args[k], args[k+1], args[k].length()-1, args[k+1].length()-1);
    }
    return MultAll(args, n, ++k);
}

string Mult(int n, const string* args)
{
    string good[n];
    AddToArray(args, good, n);
    return MultAll(good, n);
}

string Mult(int n, ...)
{
    va_list vl;
    va_start(vl, n);
    string args[n];
    VlToStringArr(vl, args, n);
    va_end(vl);
    return Mult(n, args);
}

void Mult(string* result, int n, const string* args)
{
    *result = Mult(n, args);
}

void Mult(string* result, int n, ...)
{
    va_list vl;
    va_start(vl, n);
    string args[n];
    VlToStringArr(vl, args, n);
    va_end(vl);
    *result = Mult(n, args);
}

void Mult(string& result, int n, const string* args)
{
    result = Mult(n, args);
}

void Mult(string& result, int n, ...)
{
    va_list vl;
    va_start(vl, n);
    string args[n];
    VlToStringArr(vl, args, n);
    va_end(vl);
    result = Mult(n, args);
}