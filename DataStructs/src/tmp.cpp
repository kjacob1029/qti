#include <iostream>

template <int N, int D> 
struct Frak
{
  static const long Num = N;
  static const long Den = D;
};

template <int N, typename X>
struct ScalarMult
{
  typedef Frak<N*X::Num, X::Den> result;
};


template <int N> struct Factorial {
  static const int result = N * Factorial<N-1>::result;
};

template <> struct Factorial<0> {
  static const int result = 1;
};

// Using variadic types
//

template<typename T>
T adder(T c)
{
  return c;
}

template <typename T,typename... Args>
T adder(T first, Args... args) 
{
  return first + adder(args...);
}

int main()
{
  std::cout << Factorial<5>::result << std::endl;
  typedef Frak<3, 4> TF;
  typedef ScalarMult<4, TF>::result SM;
  std::cout << SM::Num << "/" << SM::Den << std::endl;

  long sum = adder(1,2,3,4,5,6);
  std::string s1="a", s2="b", s3="c", s4="d";
  std::string ssum = adder(s1, s2, s3, s4);

  std::cout << "sum: " << sum << ", ssum: " << ssum << std::endl;

  return 0;
}

