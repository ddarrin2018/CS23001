#include "string.hpp"

int main(){
  String a;

  String b('z');

  std::cout << "string a cap: " << a.capacity() << std::endl;
  std::cout << "string b cap: " << b.capacity() << std::endl;

  std::cout << "string a len: " << a.length() << std::endl;
  std::cout << "string b len: " << b.length() << std::endl;

  String c("abc");
  const String d("xyz");

  std::cout << "str c index 1: " << c[1] << std::endl;
  std::cout << "str d index 1: " << d[1] << std::endl;

}
