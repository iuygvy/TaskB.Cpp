//Bartosz Bugajski
#include <string>
#include <cstdarg>
using namespace std;
#include "head.h"


void VlToStringArr(va_list, string*, int, int = 0);

string Operation(string (*Fun)(int, const string*), int n, const string* args)
{
    return Fun(n, args);
}

string Operation(string (*Fun)(int, const string*), int n, ...)
{
    va_list vl;
    va_start(vl, n);
    string args[n];
    VlToStringArr(vl, args, n);
    va_end(vl);
    return Fun(n, args);
}

void Operation(string* result, string (*Fun)(int, const string*), int n, ...)
{
    va_list vl;
    va_start(vl, n);
    string args[n];
    VlToStringArr(vl, args, n);
    va_end(vl);
    *result = Fun(n, args);
}

void Operation(string* result, string (*Fun)(int, const string*), int n, const string* args)
{
    *result = Fun(n, args);
}

void Operation(string& result, void (*Fun)(string*, int, const string*), int n, const string* args)
{
    Fun(&result, n, args);
}

void Operation(string& result, void (*Fun)(string*, int, const string*), int n, ...)
{
    va_list vl;
    va_start(vl, n);
    string args[n];
    VlToStringArr(vl, args, n);
    va_end(vl);
    Fun(&result, n, args);
}