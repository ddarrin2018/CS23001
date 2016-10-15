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

  String e = c + d; 
  std::cout << "string c len: " << c.length() << std::endl;
  std::cout << "string d len: " << d.length() << std::endl;
  std::cout << "string e len: " << e.length() << std::endl;
  //std::cout << "string c+d: " <<(c+d) << std::endl;

 // print string e
  std::cout << "string e: ";
  for (int i=0; i < e.length(); ++i) {
	  std::cout << e[i];
  }
  std::cout << std::endl;
}
