#include <iostream>
#include "Stack.hpp"
using namespace std;


namespace StackAppSpace {
    void App() {
        Stack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);

        while (!stack.isEmpty()) {
            cout << stack.pop() << endl;
        }
    }
}