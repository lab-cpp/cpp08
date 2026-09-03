#include "Span.hpp"

#include <algorithm>
#include <numeric>
#include <stdexcept>

Span::Span(unsigned int n) : _maxSize(n)
{
    _numbers.reserve(n);
}

Span::~Span()
{
}

Span::Span(const Span& src)
{
    *this = src;
}

Span& Span::operator=(const Span& rhs)
{
    if (this != &rhs)
    {
        this->_maxSize = rhs._maxSize;
        this->_numbers = rhs._numbers;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_numbers.size() == _maxSize)
    {
        throw FullException();
    }
    else
    {
        _numbers.push_back(number);
    }
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
    {
        throw NotEnoughNumbersException();
    }

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    std::vector<int> result(tmp.size());
    std::adjacent_difference(tmp.begin(), tmp.end(), result.begin());
    return *std::min_element(result.begin() + 1, result.end());
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
    {
        throw NotEnoughNumbersException();
    }
    return *std::max_element(_numbers.begin(), _numbers.end()) -
           *std::min_element(_numbers.begin(), _numbers.end());
}

const char* Span::FullException::what() const throw()
{
    return "Span is already full!";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers to find a span!";
}
