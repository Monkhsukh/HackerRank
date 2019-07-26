// Effective vector addition without temporal vectors.
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

// Helper class for the sums of vectors
template<class T, long N, class Left, class Right>
class VectorSum;

// Definition of own vector class
template<class T, N>
class Vector {
  T data[N];  // array of size N for storing elements of type T
public:
  // operator=, whose right hand side is not a Vector, but a VectorSum representing the sum of vectors,
  // for which operator[] is implemented. Enables expressions like v3 = v1 + v2
  template<class Left, class Right>
  Vector<T,N>& operator=(const VectorSum<T,N,Left,Right>& v) {  
    for (long i = 0; i < N; ++i)
      data[i] = v[i];
    return *this;
  }

  T operator[](long i) const {return data[i];}
  T& operator[](long i) {return data[i];}
};

// Helper class, which stores only references to left and right hand side operands
template<class T, long N, class Left, class Right>
class VectorSum {
  const Left &left;
  const Right &right;
public:
  VectorSum(const Left &l, const Right &r) : left(l), right(r) {}
  // operator[], which returns the sum of the i-th elements of the left and right hand side operands
  T operator[](long i) const { return left[i] + right[i]; }  
};                                                                      

// operator+ only creates a VectorSum object
// inline function, which expects two Vector type object references, and returns VectorSum object,
// which only stores the references, and the addition will happen only in operator[]
// -std=c++1y
template<class T, long N>
inline auto operator+(const Vector<T,N> &l, const Vector<T,N> &r) {
  return VectorSum<T,N,Vector<T,N>,Vector<T,N>>(l,r);
}
// operator+ only creates a VectorSum object
// inline function, which expects a VectorSum and Vector type object reference, and returns VectorSum object,
// which only stores the references, and the addition will happen only in operator[]
// -std=c++1y
template<class T, long N, class Left, class Right>
inline auto operator+(const VectorSum<T,N,Left,Right> &l, const Vector<T,N> &r) {   
  return VectorSum<T,N,VectorSum<T,N,Left,Right>,Vector<T,N>>(l,r);
}

// function for initializing a vector with random numbers
template<class T, long N>
void init(Vector<T,N>& v) {
  for (long i = 0; i < N; ++i)
    v[i] = rand() % 100;
}

template<class T, long N>
void print(string s, Vector<T,N>& v) {
  cout << s;
  for (long i = 0; i < N; ++i)
    cout << setw(4) << v[i];
  cout << endl;
}

int main() {
  Vector<int,5> v1;
  init(v1);
  print("v1 = ", v1);

  Vector<int,5> v2;
  init(v2);
  print("v2 = ", v2);

  Vector<int,5> v3;

  v3 = v1 + v2;
  print("v1 + v2 = ", v3);

  v3 = v1 + v1 + v2;
  print("v1 + v1 + v2 = ", v3);

  v3 = (v1 + v1) + v2;
  print("(v1 + v1) + v2 = ", v3);

  return 0;

/*
  v3 = v1 + (v1 + v2);
  print("v1 + (v1 + v2) = ", v3);

  v3 = (v1 + v2) + (v1 + v2);
  print("(v1 + v2) + (v1 + v2) = ", v3);
*/
}
