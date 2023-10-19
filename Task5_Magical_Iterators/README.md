# **Title: The Quest for the Magical Iterators**

## **Background Story**
In the ancient kingdom of Iteratia, a magical container exists, capable of holding various mystical elements. These elements, each with unique properties and abilities, are vital for maintaining the kingdom’s balance. However, the wisdom to harness these elements' powers has been lost over time. Legend speaks of three powerful iterators created to unveil the magical container’s potentials, each representing a different order of traversal through the container, uncovering various mystical elements’ aspects. Currently, the kingdom faces turmoil, and the wise King seeks a talented programmer's assistance to revive these iterators' powers.

## **Objective**
Your task is to develop a custom container class named "MagicalContainer" to store mystical elements represented by integers. Furthermore, you’ll implement three custom iterator classes to traverse the container in unique orders. Completing this assignment will deepen your understanding of custom iterators and their applications in C++.

## **Instructions**

### **Part A:**
1. **MagicalContainer Class:** 
    - Develop a user-defined container class named "MagicalContainer."
    - This class should store integers representing mystical elements.
    - Implement necessary functionalities such as adding elements, removing elements, and retrieving the container's size.
    - You can use a dynamic array or any other suitable data structure for internal storage.

2. **Custom Iterator Classes:**
    - Create three iterators named "AscendingIterator", "SideCrossIterator", and "PrimeIterator."
    - These iterators will enable traversal through the MagicalContainer in ascending order, cross order, and only prime numbers, respectively.
    
    **Iterator Operations should include:**
    - Default constructor
    - Copy constructor
    - Destructor
    - Assignment operator
    - Equality comparison (operator==)
    - Inequality comparison (operator!=)
    - GT, LT comparison (operator>, operator<)
    - Dereference operator (operator*)
    - Pre-increment operator (operator++)
    - `begin(type)`: Method returning the appropriate iterator pointing to the container’s first element.
    - `end(type)`: Method returning the appropriate iterator pointing one position past the container’s last element.

    **Operation Requirements:**
    - Iterators should operate in O(1) time and memory complexity.
    - Iterators must remain attached to the main container, updating based on the modifications in the container.

### **Part B:**
- **Full Implementation:** 
   - Complete the implementation ensuring that all tests pass successfully.

   **The following commands should run without errors:**
   
   ```bash
   bash grade
It is also recommended to run:
```bash
   make tidy
   make valgrind
