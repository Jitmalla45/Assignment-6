#include <iostream>
using namespace std;

struct X {
    X() { cout << "default constructor\n"; }
    X(X&& x) { cout << "move constructor\n"; }
    X(const X& x) { cout << "copy constructor\n"; }
    X& operator=(const X&){ cout << "copy assignment\n"; return *this; }
    ~X() { cout << "Destructor\n"; }
};

// Function that takes an object by value and returns it
X foo(X x) {
    return x;  // Here, the returned object may use move or copy semantics
}

int main() {
    X obj;  // Calls default constructor
    obj = foo(obj);  // Invokes foo() and assigns its result to obj
}

/*
___________________Detailed Output and Reasoning_________________
Step-by-Step Execution with Outputs So Far:
Step 1: X obj;
    -The default constructor is called to create obj.
    Output so far: default constructor

Step 2: obj = foo(obj);
    -This line involves several steps, broken down below:
        foo(obj) call: foo takes a parameter by value, meaning the copy constructor is invoked to pass obj to foo.
        Output so far:  default constructor
                        copy constructor

        Inside foo: The local parameter x (a copy of obj) is returned from foo. When returning, move semantics are used, triggering the move constructor.
        Output so far:  default constructor
                        copy constructor
                        move constructor

        Assigning the result to obj: The result of foo(obj) is assigned to obj. This triggers the copy assignment operator.
        Output so far:  default constructor
                        copy constructor
                        move constructor
                        copy assignment

        Temporary object destruction: After the move, the temporary object created inside foo is destroyed, triggering the destructor.
        Output so far:  default constructor
                        copy constructor
                        move constructor
                        copy assignment
                        Destructor

Step 3: Exiting main()
    -At the end of main, the original obj goes out of scope, triggering its destructor.
    Final Output: default constructor
                    copy constructor
                    move constructor
                    copy assignment
                    Destructor
                    Destructor

Removing constexpr from Copy Assignment Operator:
    Effect: Removing constexpr has no effect on the output or behavior because the copy assignment operator is only used at runtime here. The output remains the same.




*/
