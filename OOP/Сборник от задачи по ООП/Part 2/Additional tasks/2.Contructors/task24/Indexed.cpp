#include "Indexed.h"

Indexed::Indexed(const size_t num)
{
    current = 0;
    max = num;
    arr = new int[max];
}
Indexed::Indexed(const Indexed& other)
{
    current = other.current;
    max = other.max;
    arr = new int[max];
    for (size_t i = 0; i < current; i++)
    {
        arr[i] = other.arr[i];
    }
}
Indexed::~Indexed()
{
    delete[]arr;
}

Indexed& Indexed::operator=(const Indexed& other)
{
    if (this != &other)
    {
        current = other.current;
        max = other.max;
        arr = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

size_t Indexed::size()const
{
    return current;
}
int Indexed::operator[](const size_t index)
{
    return arr[index];
}

bool Indexed::member(const int data)const
{
    for (size_t i = 0; i < current; i++)
    {
        if (arr[i] == data)
        {
            return true;
        }
    }
    return false;
}
size_t Indexed::getTimes(const int data)const
{
    size_t counter = 0;
    for (size_t i = 0; i < current; i++)
    {
        if (arr[i] == data)
        {
            counter++;
        }
    }
    return counter;
}
void Indexed::remove(const int data)
{
    if (current == -1)
    {
        return;
    }
    else if (!this->member(data))
    {
        return;
    }

    Indexed temp;
    size_t index;
    for (size_t i = 0; i < current; i++)
    {
        if (arr[i] == data)
        {
            index = i;
        }
    }
    current--;
    for (size_t i = 0; i < index; i++)
    {
        temp.add(arr[i]);
    }
    for (size_t i = index; i < current + 1; i++)
    {
        temp.add(arr[i + 1]);
    }

    *this = temp;
}
void Indexed::add(const int data)
{
    if (current + 1 >= max)
    {
        max++;
        int* temp = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            temp[i] = arr[i];
        }
        delete[]arr;
        arr = new int[max];
        for (size_t i = 0; i < current; i++)
        {
            arr[i] = temp[i];
        }
        delete[]temp;
    }
    arr[current++] = data;
}
void Indexed::addBefore(const int data, const size_t index)
{
    if (index > current)
    {
        std::cout << "You cannot add an element there!\n";
        return;
    }
  
    Indexed temp(current);
    for (size_t i = 0; i < index; i++)
    {
        //std::cout << arr[i] << "error1\n";
        temp.add(arr[i]);
    }
    temp.add(data);
    for (size_t i = index + 1, j = i - 1; i < current + 1; i++, j++)
    {
        //td::cout << arr[i - index] << "error2\n";
        temp.add(arr[j]);
    }
    *this = temp;   
}
void Indexed::addAfter(const int data, const size_t index)
{
    if (index > current)
    {
        return;
    }
    Indexed temp(current);
    for (size_t i = 0; i <= index; i++)
    {
        temp.add(arr[i]);
    }
    temp.add(data);
    for (size_t i = index + 2, j = index + 1; i < current + 1; i++, j++)
    {
        temp.add(arr[j]);
    }

    *this = temp;
}
void Indexed::remove(const size_t index)
{
    Indexed temp(current - 1);
    for (size_t i = 0; i < index; i++)
    {
        temp.add(arr[i]);
    }
    for (size_t i = index + 1; i < current; i++)
    {
        temp.add(arr[i]);
    }
    
    *this = temp;
}

Indexed Indexed::intersection(const Indexed& other)
{
    Indexed temp(1);
    for (size_t i = 0; i < current; i++)
    {
        for (size_t j = 0; j < other.current; j++)
        {
            if (!temp.member(arr[i]))
            {
                size_t count1 = getTimes(arr[i]), count2 = other.getTimes(arr[i]);
                if (count1 >= count2)
                {
                    while (count2 > 0)
                    {
                        temp.add(arr[i]);
                        count2--;
                    }
                }
                else
                {
                    while (count1 > 0)
                    {
                        temp.add(arr[i]);
                        count1--;
                    }
                }
            }
        }
    }
    

    return temp;
}
Indexed Indexed::merge(const Indexed& other)
{
    Indexed temp(current + other.current);
    for (size_t i = 0; i < current; i++)
    {
        temp.add(arr[i]);
    }
    for (size_t i = 0; i < other.current; i++)
    {
        temp.add(other.arr[i]);
    }
    
    return temp;
}
Indexed Indexed::difference(const Indexed& other)
{
    Indexed temp = this->intersection(other);
    Indexed temp2 = *this;
    for (size_t i = 0; i < temp.size(); i++)
    {
        temp2.remove(temp.arr[i]);
        temp2.current--;
    }
    
    return temp2;
}

void Indexed::print()const
{
    std::cout << "Indexed-------\n";
    for (size_t i = 0; i < current; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n--------------\n";
}