#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void swap(int index1, int index2);
  int getParentIndex(int childIndex) const;
  int getChildrenIndex(int parentIndex) const;
  std::vector<T> heap_list;
  int m_ary;
  PComparator compare;

};

// Add implementation of member functions here

// swaps the items at two indices in the vector. 
template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(int index1, int index2){
	if(index1 == index2){
		return;               
	}
  T temp = heap_list[index1];
  heap_list[index1] = heap_list[index2];
  heap_list[index2] = temp;
}

// calculates the index of the parent node of any child node in the heap
template <typename T, typename PComparator>
int Heap<T,PComparator>::getParentIndex(int childIndex) const {
  return (childIndex - 1) / m_ary;
}

//calculates the index of the first child node of any parent node in the heap
template <typename T, typename PComparator>
int Heap<T, PComparator>::getChildrenIndex(int parentIndex) const {
  return (m_ary * parentIndex + 1);
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  m_ary = m;
  compare = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

// pushes new items into the heap into the vector, then does trickleUp 
// to get the item to the right place in the heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  heap_list.push_back(item);
	int itemIndex = size() - 1;
  int parentIndex = getParentIndex(itemIndex);

  // keep swapping until in right place
  while(compare(item, heap_list[parentIndex])){
		swap(itemIndex, parentIndex);
		itemIndex = parentIndex;
		parentIndex = getParentIndex(itemIndex);
	}
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_list.front();

}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap!");
  }
	swap(0, size() - 1);
	heap_list.pop_back();
	int itemIndex = 0;
	int childrenIndex = getChildrenIndex(itemIndex);
	bool betterChild = true;

  // while there exists a better child node, keep swapping
	while(betterChild){
		betterChild = false;
		int bestChild = -1;
		for(int i = 0; i < m_ary; i++){
      if(childrenIndex + i < (int) size()){
        bool comparison = compare(heap_list[childrenIndex + i], heap_list[itemIndex]);
        if(comparison){
          betterChild = true;
          if(bestChild == -1){
            bestChild = childrenIndex + i;
          } else if(compare(heap_list[childrenIndex + i], heap_list[bestChild])){
            bestChild = childrenIndex + i;
          }      
        }
      }
		}
		if(betterChild){
			swap(bestChild, itemIndex);
			itemIndex = bestChild;
			childrenIndex = getChildrenIndex(itemIndex);
		}
	}
}

// return true if the heap (vector) is empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  if(size() > 0){
    return false;
  }
  return true;
}

// use vector::size() to return heap size
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return heap_list.size();
}

#endif

