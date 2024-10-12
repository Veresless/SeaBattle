#include <iostream>
#include "Tree.hpp"
#include "Vector.hpp"
using namespace Collections;
int main()
{
    Vector<int> vec;
    vec.push_back(5);
    vec.push_front(3);
    vec.push_back(8);
    for(int elem : vec) std::cout << elem << std::endl;
    std::cout << vec[0] << std::endl;
    std::cout << vec[1] << std::endl;
    std::cout << vec[2] << std::endl;
    std::cout << vec.pop_back() << std::endl;
    std::cout << vec.pop_front() << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vec[0] << std::endl;

    Tree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(7);
    tree.insert(8);
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(9);
    List<int> in;
    tree.inorder(in);
    for (int el : in) std::cout << el << std::endl;    std::cout << std::endl;
    tree.erase(5);
    tree.inorder(in);
    for (int el : in) std::cout << el << std::endl;
    return 0;
}
