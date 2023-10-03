#include <iostream>
#include <cstddef>
#include <string>

void print(std::wstring&& text)
{
    
    std::wcout << text << std::endl;
}
 
std::wstring defaultMessage()
{
    std::wstring message{L"hello world"};
    return message;
}

int main()
{
// wchar
    setlocale(LC_ALL, "");
    wchar_t st[3] {L'н', L'ß', L'G'};
    for(int i = 0; i<3; i++)
        std::wcout << st[i] << " " << std::endl;

    char32_t sr {U'м'};
    std::wcout << sr << " " << std::endl;
// размер указателя
    char *sy;
    std::wcout << sizeof(sy) << " " << std::endl;
// size_t
    size_t x {55UL};
    std::wcout << x << " " << std::endl;
//вычитание указателей
    int* pointer;
    pointer = new int[3];
    int *pp = pointer + 1;
    ptrdiff_t size {0};
    size = pp - pointer;
    std::wcout << size << std::endl;
// rvalue
    print(defaultMessage()); // передаем rvalue


}
