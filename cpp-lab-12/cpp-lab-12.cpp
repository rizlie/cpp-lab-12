#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class RangeIterator
{
private:
    typename vector<T>::iterator current;
    typename vector<T>::iterator end_iter;
public:
    RangeIterator(typename vector<T>::iterator begin, typename vector<T>::iterator end) :current(begin), end_iter(end) {}

    RangeIterator operator++()
    {
        ++current;
        return *this;
    }

    RangeIterator operator++(int)
    {
        RangeIterator temp = *this;
        ++(*this);
        return temp;
    }

    RangeIterator operator--()
    {
        --current;
        return *this;
    }

    RangeIterator operator--(int)
    {
        RangeIterator temp = *this;
        --(*this);
        return temp;
    }

    T& operator*()
    {
        return *current;
    }

    bool operator==(const RangeIterator& other) const
    {
        return current == other.current;
    }

    bool operator!=(const RangeIterator& other) const
    {
        return current != other.current;
    }
};


int main()
{
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7 };
    RangeIterator<int> iter_begin(vec.begin(), vec.end());
    RangeIterator<int> iter_end(vec.end(), vec.end());

    for (auto it = iter_begin; it != iter_end; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}