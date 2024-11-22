/*
    Класс Number - класс положительных больших чисел

    Большое число будет храниться в массиве в сегменте куча.
    В самом объекте будем хранить указатель на данные в куче.
    Также, в самом объекте будут храниться размер и вместимость массива.

        data - указатель, на элементы, хранящиеся в куче.
        capacity - размер массива data.
        size - сколько ячеек занимет число в массиве data, size <= capacity.

    По условию задачи класс Number должен поддерживать только положительные числа.
    Это сделано для того, чтобы задача не была слишком сложной.

    Каждый элемент массива должен содержать разряд числа в 100-ричной системе счисления (так как base = 100).
    По сути, каждый элемент массива должен хранить две цифры числа в десятичной записи.

    Значение 100 для системы счисления выбрано для того, чтобы задача была не такой сложной.
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа, размером 1 байт),
    то алгоритм печати на экран усложнится. Наиболее эффективный вариант - использование 64 битных чисел
    (то есть uint64_t вместо char) и базы 2^64, но это бы ещё сильнее усложнило эту задачу.

    Для удобства разряды числа хранятся в обратном порядке (это упрощает многие алгоритмы с такими числами). 
    Например, число 12345678 соответствует массиву:
    
        {78, 56, 34, 12}
    
    Для выделения/освобождения памяти в куче были использованы операторы new[] и delete[].
    Хотя можно было бы и использовать функции malloc и free из библиотеки cstdlib.

    Выделение/освобождения с использованием malloc/free:

        data = static_cast<char*>(std::malloc(capacity * sizeof(char)));
        ...
        std::free(data);

    То же самое с использованием new[]/delete[]:

        data = new char[capacity];
        ...
        delete[] data;

*/
#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Number 
{
private:
    static const int base = 100;

    char* data;
    std::size_t size;
    std::size_t capacity;

public:

    Number(int a) 
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0) 
            capacity = 1;

        // Выделяем память в куче и записывем число a в массив data
        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }

    Number() {
        capacity = 1;
        size = 1;
        data = new char[capacity];
        data[0] = 0;
    }

    Number(const Number& n) {
        size = n.size;
        capacity = n.capacity;
        data = new char[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = n.data[i];
        }
    }

    Number(const std::string& str) {
        std::string temp = "";
        int n = -1;
        if (str.size() % 2 == 0)
            size = str.size() / 2;
        else
            size = str.size() / 2 + 1;
        capacity = size;
        data = new char[capacity];
        for (int i = 1; i < str.size(); i += 2) {
            temp += str[i - 1];
            temp += str[i];
            n += 1;
            data[capacity-1-n] = std::stoi(temp);
            temp = "";
        }
        if (str.size() % 2 != 0) {
            temp += str[str.size() - 1];
            data[0] = std::stoi(temp);
        }
    }

    bool isEven(){
        if (data[0] % 2 == 0) {
            return true;
        }
        else
            return false;
    }

    ~Number() 
    {
        // Освобождаем память в куче
        delete [] data;
    }

    Number& operator=(const Number& n);
    friend Number operator+(Number a, Number b);
    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
    friend Number& operator+=(Number& a, const Number b);
};
std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    // Печатаем самый большой разряд
    stream << static_cast<int>(num.data[num.size - 1]);

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw используются для того, чтобы замостить ноликом, элемент будет меньше чем 10.
    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.size - 2 - i]);

    return stream;
}
Number& Number::operator=(const Number& n) {
        this->capacity = n.capacity;
        this->size = n.size;
        this->data = new char[this->capacity];
        for (int i = 0; i < n.size; i++)
            this->data[i] = n.data[i];
    return *this;
}
Number operator+(const Number a, const Number b) {
    Number result;
    char flag = 0;
    if (a.size >= b.size) {
        result.data = new char[a.size];
        for (int i = 0; i < a.size; i++)
            result.data[i] = 0;
        result.size = a.size;
        result.capacity = a.capacity;
        for (int i = 0; i < b.size; i++) {
            if (a.data[i] + b.data[i] < 100) {
                result.data[i] += a.data[i] + b.data[i];

            }
            else {
                result.data[i] += a.data[i] + b.data[i] - 100;
                flag = 1;
            }
            result.data[i + 1] += flag;
            flag = 0;
        }
        for (int i = b.size; i < a.size; i++) {
            result.data[i] = a.data[i];
        }
    }
    if (a.size < b.size) {
        result.data = new char[b.size];
        for (int i = 0; i < b.size; i++)
            result.data[i] = 0;
        result.size = b.size;
        result.capacity = b.capacity;
        for (int i = 0; i < a.size; i++) {
            if (a.data[i] + b.data[i] < 100) {
                result.data[i] = a.data[i] + b.data[i];
            }
            else {
                result.data[i] = a.data[i] + b.data[i] - 100;
                flag = 1;
            }
            result.data[i+1] += flag;
            flag = 0;
        }
        for (int i = a.size; i < b.size; i++) {
            result.data[i] = b.data[i];
        }
    }
    return result;
}
Number& operator+=( Number& a, const Number b) {
    Number temp = a + b;
    a = temp;
    return a;
}
Number Fib(int n) {
    if (n == 0) {
        Number result;
        return result;
    }
    if (n == 1) {
        Number result(1);
        return result;
    }
    static Number* temp = new Number[n];
    temp[n - 1] = Fib(n - 1);

    return temp[n - 1] + temp[n - 2];
}

