#include <iostream>



int main()
{
    setlocale(LC_ALL, "");
    wchar_t st[3] {L'н', L'ß', L'G'};
    for(int i = 0; i<3; i++)
        std::wcout << st[i] << " " << std::endl;

    char32_t sr {U'м'};
    std::wcout << sr << " " << std::endl;

}
