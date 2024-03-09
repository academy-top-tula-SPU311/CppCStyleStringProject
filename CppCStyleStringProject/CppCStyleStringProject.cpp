#include <iostream>

void CStyleWelcome();

int StringLength(const char* str);
void StringCopy(char*& dest, const char* src);
void StringConcat(char*& dest, const char* src);

int main()
{
    const char* str{ "Hello world" };
    std::cout << StringLength(str) << "\n";
    str = "Hello people";

    char* str1 = new char[12] { "Hello world" };
    std::cout << StringLength(str1) << "\n";
    std::cout << str1 << "\n";

    StringCopy(str1, "Good by world");
    str1[7] = '*';
    std::cout << str1 << "\n";

    char* s1 = new char;
    char* s2 = new char;

    StringCopy(s1, "Hello");
    StringCopy(s2, "World");
    StringConcat(s1, s2);

    std::cout << s1 << "\n";
}

void CStyleWelcome()
{
    /*int array[] = { 1, 2, 3, 4, 5 };
    char str[] = "Hello world";
    str[5] = '$';

    const char* str1 = "Hello people";
    std::cout << str1 << "\n";

    str1 = "Good by people";
    std::cout << str1 << "\n";

    str1 = str;
    std::cout << str1 << "\n";

    char* str2 = new char[12];*/


    /* str[5] = '$';
     std::cout << str << "\n";*/
}

int StringLength(const char* str)
{
    int length{};

    /*while(str[length] != '\0')
        length++;*/
    while (str[length++]);

    return length - 1;
}

void StringCopy(char*& dest, const char* src)
{
    if (dest) delete[] dest;

    int length{ StringLength(src) + 1 };
    dest = new char[length];

    for (int i{}; i < length; i++)
        dest[i] = src[i];
    dest[length] = '\0';
}

void StringConcat(char*& dest, const char* src)
{
    int lengthDest = StringLength(dest);
    int lengthSrc = StringLength(src);
    
    char* strNew = new char[lengthDest + lengthSrc + 1];

    int index{};

    for (int i{}; i < lengthDest; i++)
        strNew[index++] = dest[i];

    for (int i{}; i < lengthSrc; i++)
        strNew[index++] = src[i];

    strNew[lengthDest + lengthSrc] = '\0';

    //delete[] dest;
    dest = strNew;
}
