#include "BArray.h"

namespace rogue_engine {
  
void BArray::setFalse(std::vector<bool>& toBeFalse) {
    std::fill(toBeFalse.begin(), toBeFalse.end(), false);
}

std::vector<bool> BArray::andOp(const std::vector<bool>& a, const std::vector<bool>& b) {
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] && b[i];
    }
    return result;
}

std::vector<bool> BArray::orOp(const std::vector<bool>& a, const std::vector<bool>& b) {
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] || b[i];
    }
    return result;
}

std::vector<bool> BArray::notOp(const std::vector<bool>& a) {
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = !a[i];
    }
    return result;
}

std::vector<bool> BArray::is(const std::vector<int>& a, int v1) {
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = (a[i] == v1);
    }
    return result;
}

std::vector<bool> BArray::isOneOf(const std::vector<int>& a, const std::vector<int>& v) {
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = std::find(v.begin(), v.end(), a[i]) != v.end();
    }
    return result;
}

std::vector<bool> BArray::isNot(const std::vector<int>& a, int v1) {
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = (a[i] != v1);
    }
    return result;
}

std::vector<bool> BArray::isNotOneOf(const std::vector<int>& a, const std::vector<int>& v) {
    std::vector<bool> result(a.size(), true);
    for (size_t i = 0; i < a.size(); ++i) {
        if (std::find(v.begin(), v.end(), a[i]) != v.end()) {
            result[i] = false;
        }
    }
    return result;
}
}//namespace rogue_engine
