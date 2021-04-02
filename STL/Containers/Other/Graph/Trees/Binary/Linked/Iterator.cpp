#include "Iterator.h"
#include <cassert>

template<class T>
Iterator<T>::Iterator(Position<T> start, bool is_end)
{
    if(!is_end && !start.empty())
    {
        s.push(start);

        while(!st.top().left().empty()) s.push(st.top().left());
    }
}

template<class T>
T Iterator<T>::operator*() const
{
    assert(!st.empty());
    return s.top().get();
}

template<class T>
Iterator<T>& Iterator<T>::operator++()
{

}

template<class T>
bool Iterator<T>::operator!= (const Iterator&) const
{
    return false;
}
