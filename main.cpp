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

       std::string to_json_string() {
        json j = value;
        return j.dump();
    }

    static Variant from_json_string(const std::string& jsonString) {
        json j = json::parse(jsonString);
        return Variant(j.get<VariantType>());
    }
}