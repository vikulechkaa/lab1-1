#include <iostream>
#include <string>
#include <Windows.h>

class Complex
{
private:
    double real;
    double imaginary;

public:
    // Конструктор за замовчуванням
    Complex() : real(0.0), imaginary(0.0) {}

    // Конструктор з параметрами
    Complex(double a, double b) : real(a), imaginary(b) {}

    // Метод ініціалізації
    void Init(double a, double b)
    {
        real = a;
        imaginary = b;
    }

    // Метод введення із клавіатури
    void Read() 
    {
        std::cout << "Введіть дійсну частину: ";
        std::cin >> real;
        std::cout << "Введіть уявну частину: ";
        std::cin >> imaginary;
    }

    // Метод вивідення на екран
    void Display()
    {
        std::cout << real;
        if (imaginary >= 0) 
        {
            std::cout << " + " << imaginary << "i";
        }
        else {
            std::cout << " - " << -imaginary << "i";
        }
        std::cout << std::endl;
    }

    // Перевантаження операції додавання
    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Перевантаження операції віднімання
    Complex operator-(const Complex& other) const 
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Перевантаження операції множення
    Complex operator*(const Complex& other) const 
    {
        return Complex(real * other.real - imaginary * other.imaginary, real * other.imaginary + imaginary * other.real);
    }

    // Перевантаження операції ділення
    Complex operator/(const Complex& other) const
    {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        return Complex((real * other.real + imaginary * other.imaginary) / denominator, (imaginary * other.real - real * other.imaginary) / denominator);
    }

    // Перевантаження операції порівняння
    bool operator==(const Complex& other) const
    {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    // Перевантаження операції знаходження сполученого числа
    Complex conj() const
    {
        return Complex(real, -imaginary);
    }

    // Перевантаження операції перетворення в рядок
    std::string toString() const 
    {
        std::string result = std::to_string(real);
        result += (imaginary >= 0) ? " + " : " - ";
        result += std::to_string(std::abs(imaginary)) + "i";
        return result;
    }
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Complex c1, c2, result;
    c1.Read();
    c2.Read();

    result = c1 + c2;
    std::cout << "Сума: " << result.toString() << std::endl;

    result = c1 - c2;
    std::cout << "Різниця: " << result.toString() << std::endl;

    result = c1 * c2;
    std::cout << "Добуток: " << result.toString() << std::endl;

    result = c1 / c2;
    std::cout << "Частка: " << result.toString() << std::endl;

    if (c1 == c2) 
    {
        std::cout << "Числа рівні." << std::endl;
    }
    else 
    {
        std::cout << "Числа не рівні." << std::endl;
    }

    Complex conjugate = c1.conj();
    std::cout << "Сполучене число: " << conjugate.toString() << std::endl;

    return 0;
}
