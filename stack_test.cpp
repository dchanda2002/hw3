#include <iostream>
#include "stack.h"

using namespace std;

int main(){

	Stack<int> stack_ints;
	Stack<string> stack_strings;
	Stack<double> stack_doubles;

	// All should be empty
	cout << "Int Stack Empty: " << std::boolalpha << stack_ints.empty() << endl;
	cout << "String Stack Empty: " << std::boolalpha << stack_strings.empty() << endl;
	cout << "Double Stack Empty: " << std::boolalpha << stack_doubles.empty() << endl;
	
	cout << "Int Stack Size: " << stack_ints.size() << endl;
	cout << "String Stack Size: " << stack_strings.size() << endl;
	cout << "Double Stack Size: " << stack_doubles.size() << endl;

	// Add 2 items to each
	stack_ints.push(2);
	stack_ints.push(86);

	stack_strings.push("Super");
	stack_strings.push("hunter");

	stack_doubles.push(0.33);
	stack_doubles.push(34.0);

	cout << "Int Stack Empty: " << std::boolalpha << stack_ints.empty() << endl;
	cout << "String Stack Empty: " << std::boolalpha << stack_strings.empty() << endl;
	cout << "Double Stack Empty: " << std::boolalpha << stack_doubles.empty() << endl;

	cout << "Int Stack Size: " << stack_ints.size() << endl;
	cout << "String Stack Size: " << stack_strings.size() << endl;
	cout << "Double Stack Size: " << stack_doubles.size() << endl;

	// check stack items
	cout << "Int Stack Top: " << stack_ints.top() << endl;
	cout << "String Stack Top: " << stack_strings.top() << endl;
	cout << "Double Stack Len: " << stack_doubles.top() << endl;

	// pop once and check the result.

	stack_ints.pop();
	stack_strings.pop();
	stack_doubles.pop();

  cout << "\nPopped Once. \n" << endl;

	cout << "Int Stack Empty: " << std::boolalpha << stack_ints.empty() << endl;
	cout << "String Stack Empty: " << std::boolalpha << stack_strings.empty() << endl;
	cout << "Double Stack Empty: " << std::boolalpha << stack_doubles.empty() << endl;

	cout << "Int Stack Size: " << stack_ints.size() << endl;
	cout << "String Stack Size: " << stack_strings.size() << endl;
	cout << "Double Stack Size: " << stack_doubles.size() << endl;

	cout << "Int Stack Top: " << stack_ints.top() << endl;
	cout << "String Stack Top: " << stack_strings.top() << endl;
	cout << "Double Stack Len: " << stack_doubles.top() << endl;

	// pop again and check the result.

	stack_ints.pop();
	stack_strings.pop();
	stack_doubles.pop();

  cout << "\nPopped Again. \n" << endl;
	
	cout << "Int Stack Empty: " << std::boolalpha << stack_ints.empty() << endl;
	cout << "String Stack Empty: " << std::boolalpha << stack_strings.empty() << endl;
	cout << "Double Stack Empty: " << std::boolalpha << stack_doubles.empty() << endl;

	cout << "Int Stack Size: " << stack_ints.size() << endl;
	cout << "String Stack Size: " << stack_strings.size() << endl;
	cout << "Double Stack Size: " << stack_doubles.size() << endl;

	// checked, throw works!
	// cout << "Int Stack Top: " << stack_ints.top() << endl;
	// cout << "String Stack Top: " << stack_strings.top() << endl;
	// cout << "Double Stack Len: " << stack_doubles.top() << endl;
}