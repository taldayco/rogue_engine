#include "BArray.h"

void BArray::setFalse(std::vector<bool> &toBeFalse) {
  std::fill(toBeFalse.begin(), toBeFalse.end(), false);
}

std::vector<bool> BArray::andOp(const std::vector<bool> &a,
                                const std::vector<bool> &b) {
  std::vector<bool> result(a.size());
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 std::logical_and<>());
  return result;
}

std::vector<bool> BArray::orOp(const std::vector<bool> &a,
                               const std::vector<bool> &b) {
  std::vector<bool> result(a.size());
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 std::logical_or<>());
  return result;
}

std::vector<bool> BArray::notOp(const std::vector<bool> &a) {
  std::vector<bool> result(a.size());
  std::transform(a.begin(), a.end(), result.begin(), std::logical_not<>());
  return result;
}

std::vector<bool> BArray::isEqualTo(const std::vector<int> &a, int value) {
  std::vector<bool> result(a.size());
  std::transform(a.begin(), a.end(), result.begin(),
                 [value](int x) { return x == value; });
  return result;
}

std::vector<bool> BArray::isOneOf(const std::vector<int> &a,
                                  std::initializer_list<int> values) {
  std::vector<bool> result(a.size(), false);
  for (int val : values) {
    std::transform(a.begin(), a.end(), result.begin(), result.begin(),
                   [val](int x, bool current) { return current || x == val; });
  }
  return result;
}

std::vector<bool> BArray::isNotEqualTo(const std::vector<int> &a, int value) {
  return notOp(isEqualTo(a, value));
}

std::vector<bool> BArray::isNotOneOf(const std::vector<int> &a,
                                     std::initializer_list<int> values) {
  return notOp(isOneOf(a, values));
}
