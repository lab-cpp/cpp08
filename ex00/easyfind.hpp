#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // For std::find
#include <exception>

// Exception to throw if item is not found
class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Item not found in container";
        }
};

// TODO: Implement the easyfind function template
// It takes a container of type T, and an integer to find.
// Use std::find to search for the integer.
// If std::find returns the end iterator, throw NotFoundException.
// Otherwise, return the iterator to the found element.

template <typename T>
typename T::iterator easyfind(T& container, int target) {
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end()) {
		throw ::NotFoundException();
	} else {
		return it;
	}
}

#endif
