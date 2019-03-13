#include <roman.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << format::roman(std::stoul(argv[1])) << '\n';
}
