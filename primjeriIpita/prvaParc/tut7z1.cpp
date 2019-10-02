#include <iostream>
#include <string>
template <typename NekiTip>
 auto F(NekiTip t) -> decltype(&t) {
 return new NekiTip(t);
 }

int main() {
   //std::string *x = F<std::string>("3");
   const char **x = F("3");
  std::cout << *x;
}
