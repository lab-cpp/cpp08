#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iterator>
#include <vector>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
    Span();

public:
    Span(unsigned int n);
    Span(const Span& src);
    Span& operator=(const Span& rhs);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename IT> void addNumber(IT begin, IT end) {
        if (_numbers.size() + std::distance(begin, end) > _maxSize) {
            throw FullException();
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    class FullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NotEnoughNumbersException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
