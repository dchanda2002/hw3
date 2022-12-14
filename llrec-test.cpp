#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

// making structs for three functors: to filter evens, odds, and integers greater than 10

struct remOdd{
	bool operator()(int inp){
		if(inp % 2 != 0){
			return true;
		}
		return false;
	}
};

struct remEven{
	bool operator()(int inp){
		if(inp % 2 == 0){
			return true;
		}
		return false;
	}
};

struct remMoreTen{
	bool operator()(int inp){
		if(inp > 10){
			return true;
		}
		return false;
	}
};



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code


    // to test out llpivot, uncomment this

    // Node* small;
    // Node* big;
    // llpivot(head, small, big, 6);
    // print(small);
    // print(big);
    // print(head);

		// dealloc(small);
		// dealloc(big);
		// dealloc(head);

    // to test out llfilter, uncomment this

    remEven ev;
    remOdd od;
    remMoreTen te;

    Node* noOdds = llfilter(head, od);
    cout << "Without odd numbers: ";
		print(noOdds);
    Node* noTens = llfilter(noOdds, te);
		cout << "Without numbers greater than 10: ";
    print(noTens);
		Node* noEvens = llfilter(noTens, ev);
		cout << "Without even numbers (should be empty): ";
    print(noEvens);
    
		// no need to dealloc since list becomes empty
		
    return 0;

}
