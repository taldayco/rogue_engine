#include <algorithm>
#include <vector>

class BArray {
public:
  // Set all elements of the boolean array to false
  static void setFalse(std::vector<bool> &toBeFalse);

  // Perform logical AND operation between two boolean arrays
  static std::vector<bool> andOp(const std::vector<bool> &a,
                                 const std::vector<bool> &b);

  // Perform logical OR operation between two boolean arrays
  static std::vector<bool> orOp(const std::vector<bool> &a,
                                const std::vector<bool> &b);

  // Perform logical NOT operation on a boolean array
  static std::vector<bool> notOp(const std::vector<bool> &a);

  // Check if each element of the integer array is equal to a specific value
  static std::vector<bool> isEqualTo(const std::vector<int> &a, int value);

  // Check if each element of the integer array is equal to any of the specified
  // values
  static std::vector<bool> isOneOf(const std::vector<int> &a,
                                   std::initializer_list<int> values);

  // Check if each element of the integer array is not equal to a specific value
  static std::vector<bool> isNotEqualTo(const std::vector<int> &a, int value);

  // Check if each element of the integer array is not equal to any of the
  // specified values
  static std::vector<bool> isNotOneOf(const std::vector<int> &a,
                                      std::initializer_list<int> values);
};
