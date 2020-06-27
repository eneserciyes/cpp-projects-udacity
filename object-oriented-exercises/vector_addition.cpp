#include <iostream>
#include <stdexcept>
#include <vector>

class AddableVector : public std::vector<int> {
 public:
  std::vector<int> operator+(const vector<int>& addend) {
    if (this->size() != addend.size())
      throw std::invalid_argument("Vectors must have equal dimensions!");
    else {
      vector<int> result;
      for (int i = 0; i < this->size(); i++) {
        result.push_back((*this)[i] + addend[i]);
      }
      return result;
    }
  }
};

int main() {
  std::vector<int> v{1, 2, 3};
  AddableVector v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  AddableVector v2;
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(6);

  for (auto const& i : v1 + v2) {
    std::cout << i << "\n";
  }
}