// Iterator
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

#define MIN_CAPACITY 10

// vector template, which implements an inner iterator class
template<class T, long N>
class Counter {
	
	struct Element{
		T value;
		unsigned int numberOfElements = 0;
	};
	
  	Element *data;
  	capacity = MIN_CAPACITY;
  	size = 0;
  	
public:
	Counter() : data(new T[MIN_CAPACITY]), size(0), capacity(MIN_CAPACITY) {}
	Counter(int capacity) : data(new T[capacity]), size(0), capacity(capacity) {}
	~Counter() {delete[] data;} 
	
	int getMax() return capacity;
	int getSize() return size;
	
	class OverIndexingException {
		string message;
		OverIndexingException(message) : message(message){		}
		public getMsg() {
			return message;
		}
	};
	
	bool checkAdd(T value){
	    int i = 0;
		while (i < size) {
	        if(data[i].value == value)
	        	data[i].numberOfElements++;
	        	return true;
	        i++;
	    }
	    return false;
    }
	
	bool operation += (T& value) {
		if(size+1 == capacity)
			throw OverIndexingException("Cannot be inserted");
			
		if(!contains(value))
			data[size++] = value;
	}
	
	bool checkRemove(T value){
	    int i = 0;
		while (i < size) {
	        if(data[i].value == value)
	        	if(data[i].numberOfElements != 0)
	        		data[i].numberOfElements--;
	        		
	        	return true;
	        i++;
	    }
	    return false;
    }
	
	bool operation -= (T& value) {
		if(size+1 == capacity)
			throw OverIndexingException("Cannot be inserted");
			
		if(!contains(value))
			data[size++] = value;
	}
	
  // iterator inner class, the proper methods have to the implemented
  class iterator {
  public:
    iterator() : _p(nullptr) {} // default constructor
    iterator(const iterator &it) : _p(it._p) {}  // copy constructor
    T& operator*() {return *_p;}  // dereference
    T* operator->() {return _p;}
    iterator& operator++() {++_p; return *this;}  // prefix increment
    iterator operator++(int) {iterator temp(*this); ++_p; return temp;}  // postfix increment
    iterator& operator--() {--_p; return *this;}  // prefix decrement
    iterator operator--(int) {iterator temp(*this); --_p; return temp;}  // postfix decrement
    bool operator==(const iterator &it) {return _p == it._p;}  // logical equal
    bool operator!=(const iterator &it) {return _p != it._p;}  // logical not equal
  private:
    iterator(T *p) : _p(p) {}  // private constructor, which sets the iterator to a given element
    T *_p;                     // the elements referred to by the iterator
    friend class Counter<T,N>;  // making Counter friend, so that it can access the private constructor
  };

  // reverse_iterator inner class, the proper methods have to the implemented
  class reverse_iterator {
  public:
    reverse_iterator() : _p(nullptr) {} // default constructor
    reverse_iterator(const reverse_iterator &it) : _p(it._p) {}  // copy constructor
    T& operator*() {return *_p;}  // dereference
    T* operator->() {return _p;}
    reverse_iterator& operator++() {--_p; return *this;}  // prefix increment
    reverse_iterator operator++(int) {reverse_iterator temp(*this); --_p; return temp;}  // postfix increment
    reverse_iterator& operator--() {++_p; return *this;}  // prefix decrement
    reverse_iterator operator--(int) {reverse_iterator temp(*this); ++_p; return temp;}  // postfix decrement
    bool operator==(const reverse_iterator &it) {return _p == it._p;}  // logical equal
    bool operator!=(const reverse_iterator &it) {return _p != it._p;}  // logical not equal
  private:
    reverse_iterator(T *p) : _p(p) {}  // private constructor, which sets the iterator to a given element
    T *_p;                     // the elements referred to by the iterator
    friend class Counter<T,N>;  // making Counter friend, so that it can access the private constructor
  };

  iterator begin() {return iterator(data);}  // creating an iterator, which points to the first element of the Counter
  iterator end() {return iterator(data + N);}  // creating an iterator, which points to the "element" after the last element of the Counter
  reverse_iterator rbegin() {return reverse_iterator(data+N-1);}  // creating an iterator, which points to the last element of the Counter
  reverse_iterator rend() {return reverse_iterator(data-1);}  // creating an iterator, which points to the "element" before the first element of the Counter

  // index operators
  T operator[](long i) const {return data[i];}
  T& operator[](long i) {return data[i];}
};

// initialize the Counter with random values
template<class T, long N>
void init(Counter<T,N>& v) {
  for (auto it = v.begin(); it != v.end(); ++it)
    *it = rand() % 100;
  /*for (auto &it : v)
    it = rand() % 100;*/
}

// print the elements of a vektor to the console
template<class T, long N>
void print(string s, Counter<T,N>& v) {
  cout << s;
  for (auto it = v.begin(); it != v.end(); ++it)
    cout << setw(4) << *it;
  /*for (const auto &it : v)
    cout << setw(4) << it;*/
  cout << endl;
}

// print the elements of a vektor to the console in reverse order
template<class T, long N>
void print_rev(string s, Counter<T,N>& v) {
  cout << s;
  auto it = v.end();
  for (--it; it != v.begin(); --it)
    cout << setw(4) << *it;
  cout << setw(4) << *it << endl;
}

// print the elements of a vektor to the console in reverse order
template<class T, long N>
void print_rev_it(string s, Counter<T,N>& v) {
  cout << s;
  for (auto it = v.rbegin(); it != v.rend(); ++it)
    cout << setw(4) << *it;
  cout << endl;
}

int main() {
  srand(time(0));

  Counter<int,5> v;
  init(v);
  print("v=", v);
  print_rev("v_rev=", v);
  print_rev_it("v_rev_it=", v);

  return 0;
}
/*
v=  34  50  75  76  44
*/
