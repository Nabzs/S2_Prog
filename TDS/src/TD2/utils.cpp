#include "utils.hpp"
#include <sstream>
#include <iterator>
#include <vector>

std::vector<std::string> split_string(const std::string& s) {
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}