#include <iostream>
#include<Windows.h>

class Pair 
{
private:
    int first;
    int second;

public:
    void Init(int h, int m) 
    {
        if (h >= 0 && m >= 0 && m < 60) 
        {
            first = h;
            second = m;
        }
        else 
        {
            std::cerr << "Некоректні значення годин або хвилин!" << std::endl;
        }
    }

    void Read() 
    {
        int h, m;
        std::cout << "Введіть години: ";
        std::cin >> h;
        std::cout << "Введіть хвилини: ";
        std::cin >> m;
        Init(h, m);
    }

    void Display() 
    {
        std::cout << "Години: " << first << ", Хвилини: " << second << std::endl;
    }

    int minutes() 
    {
        return first * 60 + second;
    }
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Pair pair;
    pair.Read();
    pair.Display();
    int totalMinutes = pair.minutes();
    std::cout << "Загальна кількість хвилин: " << totalMinutes << std::endl;
    return 0;
}
