#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  std::cout << "You have entered " << argc << " arguments:"
            << "\n";

  for (int i = 0; i < argc; ++i) std::cout << argv[i] << "\n";

  std::cout << "Using range-based for:" << std::endl;

  std::vector<std::string> arguments(argv, argv + argc);

  for (std::string& s : arguments) {
    std::cout << s << std::endl;
  }

  return 0;
}