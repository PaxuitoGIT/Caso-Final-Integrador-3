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

    std::string to_string() {
        return std::visit([](auto&& arg) { return std::to_string(arg); }, value);
    }
}