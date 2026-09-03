#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        // Orthodox Canonical Form
        MutantStack();
        MutantStack(const MutantStack& src);
        MutantStack& operator=(const MutantStack& rhs);
        ~MutantStack();

        // Typedefs for iterator types!
        // std::stack exposes its underlying container via a protected member named `c`.
        // We can access `c`'s iterators by exposing them.
        typedef typename std::stack<T>::container_type::iterator iterator;

        // Core Functions
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif
