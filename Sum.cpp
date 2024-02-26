//Bartosz Bugajski
#include <string>
#include <cstdarg>
using namespace std;
#include "head.h"


int IndexOfNonZero(string badstring, int n = 0)
{
    if(n == badstring.length())
    {
        return -1;
    }
    else if(badstring[n] != '0' && badstring[n] != '-' && badstring[n] != '+')
    {
        return n;
    }
    return IndexOfNonZero(badstring, ++n);
}

string MakeStringNormal(string badstring, string goodstring = "", int n = 0, int k = 0)
{
    if(n == 0)
    {
        n = IndexOfNonZero(badstring);
        if(n == -1)
        {
            return "+0";
        }
        if(badstring[0] == '-')
        {
            goodstring += '-';
        }
        else
        {
            goodstring += '+';
        }
    }
    else if(n == badstring.length())
    {
        return goodstring;
    }
    goodstring += badstring[n];
    return MakeStringNormal(badstring, goodstring, ++n, ++k);
}

void AddToArray(const string* badarray, string* goodarray, int n, int k = 0)
{
    if(n == k)
    {
        return;
    }
    *(goodarray+k) = MakeStringNormal(*(badarray+k));
    AddToArray(badarray, goodarray, n, ++k);
}

int CharToInt(char c)
{
    if(c == '0')
        return 0;
    else if(c == '1')
        return 1;
    else if(c == '2')
        return 2;
    else if(c == '3')
        return 3;
    else if(c == '4')
        return 4;
    else if(c == '5')
        return 5;
    else if(c == '6')
        return 6;
    else if(c == '7')
        return 7;
    else if(c == '8')
        return 8;
    return 9;
}

char IntToChar(int i)
{
    if(i == 0)
        return '0';
    else if(i == 1)
        return '1';
    else if(i == 2)
        return '2';
    else if(i == 3)
        return '3';
    else if(i == 4)
        return '4';
    else if(i == 5)
        return '5';
    else if(i == 6)
        return '6';
    else if(i == 7)
        return '7';
    else if(i == 8)
        return '8';
    return '9';
}

string ReverseString(string s, int n, string result = "")
{
    if(n == -1)
    {
        return result;
    }
    result += s[n];
    return ReverseString(s, --n, result);
}

string AddTwo(string s1, string s2, int i1, int i2, int carry = 0, string result = "")
{
    if(i1 <= 0 && i2 <= 0 && carry == 0)
    {
        result = ReverseString(result, result.length()-1);
        return result;
    }
    int sum = carry;
    if(i1 > 0 && i2 > 0)
    {
        sum += CharToInt(s1[i1]) + CharToInt(s2[i2]);
    }
    else if(i1 <= 0 && i2 > 0)
    {
        sum += CharToInt(s2[i2]);
    }
    else if(i1 > 0)
    {
        sum += CharToInt(s1[i1]);
    }
    carry = 0;
    if(sum >= 10)
    {
        sum -= 10;
        carry = 1;
    }
    result += IntToChar(sum);
    return AddTwo(s1, s2, --i1, --i2, carry, result);
}

string SubtractTwo(string s1, string s2, int i1, int i2, int carry = 0, string result = "")
{
    if(i1 <= 0)
    {
        result = ReverseString(result, result.length()-1);
        return result;
    }
    int sum = CharToInt(s1[i1]);
    sum -= carry;
    carry = 0;
    if(sum < 0)
    {
        sum += 10;
        carry = 1;
    }
    if(i2 > 0)
    {
        if(sum < CharToInt(s2[i2]))
        {
            sum += 10;
            carry = 1;
        }
        sum -= CharToInt(s2[i2]);
    }
    result += IntToChar(sum);
    return SubtractTwo(s1, s2, --i1, --i2, carry, result);
}

string DeletePlus(string arg, int n, int l = 0, string result = "")
{
    if(l == n)
    {
        return result;
    }
    if(arg[l] != '+' && arg[l] != '-')
    {
        result += arg[l];
    }
    return DeletePlus(arg, n, ++l, result);
}

string AddAll(string* args, int n, int k = 0)
{
    if(k + 1 == n)
    {
        args[k] = MakeStringNormal(args[k]);
        if(args[k][0] == '+')
        {
            args[k] = DeletePlus(args[k], args[k].length());
        }
        return args[k];
    }
    if(args[k][0] == '+' && args[k+1][0] == '+')
    {
        args[k+1] = "+" + AddTwo(args[k], args[k+1], args[k].length()-1, args[k+1].length()-1);
    }
    else if(args[k][0] == '-' && args[k+1][0] == '-')
    {
        args[k+1] = "-" + AddTwo(args[k], args[k+1], args[k].length()-1, args[k+1].length()-1);
    }
    else
    {
        if(args[k].length() > args[k+1].length())
        {
            args[k+1] = args[k][0] + SubtractTwo(args[k], args[k+1], args[k].length()-1, args[k+1].length()-1);
        }
        else if(args[k+1].length() > args[k].length())
        {
            args[k+1] = args[k+1][0] + SubtractTwo(args[k+1], args[k], args[k+1].length()-1, args[k].length()-1);
        }
        else
        {
            string s1 = args[k];
            string s2 = args[k+1];
            s1 = DeletePlus(s1, s1.length());
            s2 = DeletePlus(s2, s2.length());
            if(s1 > s2)
            {
                args[k+1] = args[k][0] + SubtractTwo(args[k], args[k+1], args[k].length()-1, args[k+1].length()-1);
            }
            else if(s2 > s1)
            {
                args[k+1] = args[k+1][0] + SubtractTwo(args[k+1], args[k], args[k+1].length()-1, args[k].length()-1);
            }
            else
            {
                args[k+1] = "+0";
            }
            args[k+1] = MakeStringNormal(args[k+1]);
        }
    }
    return AddAll(args, n, ++k);
}

void VlToStringArr(va_list vl, string* args, int n, int k = 0)
{
    if(k == n)
    {
        return;
    }
    args[k] = va_arg(vl, char*);
    VlToStringArr(vl, args, n, ++k);
}

string Sum(int n, const string* args)
{
    string good[n];
    AddToArray(args, good, n);
    return AddAll(good, n);
}

string Sum(int n, ...)
{
    va_list vl;
    va_start(vl, n);
    string args[n];
    VlToStringArr(vl, args, n);
    va_end(vl);
    return Sum(n, args);
}

void Sum(string* result, int n, const string* args)
{
    *result = Sum(n, args);
}

void Sum(string* result, int n, ...)
{
    va_list vl;
    va_start(vl, n);
    string args[n];
    VlToStringArr(vl, args, n);
    va_end(vl);
    *result = Sum(n, args);
}

void Sum(string& result, int n, const string* args)
{
    result = Sum(n, args);
}

void Sum(string& result, int n, ...)
{
    va_list vl;
    va_start(vl, n);
    string args[n];
    VlToStringArr(vl, args, n);
    va_end(vl);
    result = Sum(n, args);
}
