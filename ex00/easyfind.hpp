#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Item not found in container";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int target)
{
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end())
    {
        throw ::NotFoundException();
    }
    else
    {
        return it;
    }
}

#endif
