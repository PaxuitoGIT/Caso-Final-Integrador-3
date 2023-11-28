#include <string>
#include <variant>
#include <vector>
#include <json11/json11.hpp>

using namespace std;

class Variant {
public:
    using VariantType = std::variant<std::string, int, double, bool, std::vector<Variant>>;
    VariantType value;

    Variant() = default;
    Variant(VariantType value) : value(value) {}
}