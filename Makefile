CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec-test.cpp llrec.h llrec.cpp
	$(CXX) $(CXXFLAGS) llrec-test.cpp llrec.cpp -o llrec-test

stack-test: stack.h stack_test.cpp
	$(CXX) $(CXXFLAGS) stack_test.cpp -o stack-test

valgrind_llrec: 
	$(VALGRIND) ./llrec-test llrec-test1.in

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 