#include <iostream>
#include <iomanip>
#include <cstring>
#include <complex>
#include <string>
int f(char x) { return x; }
int f(int x) { return x + 1; }
int f(float x) { return 5 / x; }
int f(double x) { return x; }
int f(const char x[]) { return std::strlen(x); }
int f(std::string x) { return x.size() + 1; }
template <typename Tip>
 int g(Tip x) { return f(x); }
int main() {
 std::string s("4");
 std::cout << g(4) << g<float>(4) << g(4.) << g('4') << g<int>('4') << std::endl;
 std::cout << g("4") << g(s) << g("444") << g<std::string>("444") << std::endl;
 int a(5), b(a), &c(a);
 const int d(a), &e(a), &f(a + 0);
 a += 2; std::cout << a << b << c << d << e << f << std::endl;
 double u(9); std::complex<double> v(u), w(-v);
 std::cout << std::sqrt(u) << std::setw(7) << std::sqrt(v) << " "
 << std::sqrt(w) << std::endl;
 return 0;
}