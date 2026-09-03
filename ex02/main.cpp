#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
    std::cout << "--- 1. Testing MutantStack (Subject Test) ---" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "MutantStack Iteration: ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::stack<int> s(mstack);


    std::cout << "\n--- 2. Testing std::list (Control Group) ---" << std::endl;
    std::list<int> lstack;
    
    lstack.push_back(5);
    lstack.push_back(17);
    
    std::cout << "Back (Top): " << lstack.back() << std::endl;
    
    lstack.pop_back();
    
    std::cout << "Size: " << lstack.size() << std::endl;
    
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);
    
    std::list<int>::iterator lit = lstack.begin();
    std::list<int>::iterator lite = lstack.end();
    
    ++lit;
    --lit;
    
    std::cout << "std::list Iteration: ";
    while (lit != lite) {
        std::cout << *lit << " ";
        ++lit;
    }
    std::cout << std::endl;

    return 0;
}
