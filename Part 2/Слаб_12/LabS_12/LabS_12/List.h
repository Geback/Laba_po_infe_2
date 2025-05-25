#pragma once
#include"header.h"

template<typename T>
class List
{
public:
    List() { _size = mlst.size(); }
    void add(T value);
    void print();
    void plus_mid();
    void searchAndDel();
    void plusMinMax();
    int size() { return _size; }
    int _size;
    multiset<T> mlst;
};




template<typename T>
void List<T>::add(T value)
{
    mlst.insert(value);
    ++_size;
}

template<typename T>
void List<T>::print()
{
    int n = 0;
    for (const auto& elem : mlst)
    {
        cout << ++n << ". " << elem << endl;
    }
    cout << endl;
}

template<typename T>
inline void List<T>::plus_mid()
{
    T midl = 0;
    for (auto& i : mlst)
        midl = midl + i;
    mlst.insert(midl / mlst.size());
    ++_size;
}

template<typename T>
inline void List<T>::searchAndDel()
{
    T min, max;
    cout << "Введите диапазон для поиска:\n" << "min: "; cin >> min;
    cout << "max: "; cin >> max;
    auto left = mlst.lower_bound(min);
    auto right = mlst.upper_bound(max);
    mlst.erase(left, right);
    _size = mlst.size();
}

template<typename T>
inline void List<T>::plusMinMax()
{
    multiset<T> temp;
    T min = *mlst.begin(), max = *mlst.begin();
    for (auto& i : mlst)
    {
        if (i < min) min = i;
        if (!(i < max)) max = i;
    }
    cout << "min element: " << min << endl;
    cout << "max element: " << max << endl;
    for (auto& i : mlst)
        temp.insert(i + min + max);
    mlst.swap(temp);
}