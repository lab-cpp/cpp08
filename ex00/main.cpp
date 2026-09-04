#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <vector>

int main() {
    std::cout << "--- Testing std::vector ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try {
        std::cout << "Searching for 30..." << std::endl;
        std::vector<int>::iterator it = ::easyfind(vec, 30);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Searching for 99..." << std::endl;
        it = ::easyfind(vec, 99);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    try {
        std::cout << "Searching for 15..." << std::endl;
        std::list<int>::iterator it2 = ::easyfind(lst, 15);
        std::cout << "Found: " << *it2 << std::endl;

        std::cout << "Searching for 100..." << std::endl;
        it2 = ::easyfind(lst, 100);
        std::cout << "Found: " << *it2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
