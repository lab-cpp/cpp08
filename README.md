# C++ Module 08 - Templated Containers, Iterators, Algorithms

## Overview
This module introduces the **Standard Template Library (STL)**, which is arguably the most powerful feature of C++. The STL is built on three main pillars that work seamlessly together:

### 1. Containers
Containers are data structures that store collections of objects. The STL provides various types:
- **Sequence Containers:** Store data in a linear manner (e.g., `std::vector`, `std::list`, `std::deque`).
- **Associative Containers:** Store data using keys for fast retrieval (e.g., `std::map`, `std::set`).
- **Container Adaptors:** These are not entirely new containers; they wrap an existing container and restrict its interface to provide specific behavior. For example, `std::stack` restricts a container (usually a `std::deque`) to only allow Last-In-First-Out (LIFO) operations (`push`, `pop`, `top`). Because of this restriction, container adaptors intentionally **do not have iterators**.

### 2. Iterators
Iterators are objects that point to elements inside a container. You can think of them as smart, safe pointers. 
Instead of looping over a container using an index (`i = 0`), you use iterators to traverse from `container.begin()` to `container.end()`. 
Iterators are the magic "bridge" that allows algorithms to interact with containers without needing to know how the container is actually built under the hood.

### 3. Algorithms
The `<algorithm>` header provides a massive library of pre-written functions that operate on containers using iterators. 
Instead of writing a `for` loop to find a number, sort an array, or copy data, you use `std::find`, `std::sort`, or `std::copy`. 

**Golden Rule of Module 08:** If an STL algorithm exists to do the job, you **must** use it. Writing manual `for` loops when an algorithm could have been used is heavily penalized in evaluation.
