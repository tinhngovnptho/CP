#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, char> giai_ma = {
    {"1", 'a'}, {"2", 'b'}, {"3", 'c'},
    {"4", 'cc'}, {"5", 'cbc'}, {"6", 'abc'},
    {"7", 'bac'}, {"8", 'aac'}, {"9", 'cac'}
};

std::string giai_ma_xau(const std::string& ma_hoa) {
    std::string giai_ma_xau;
    std::string current_code;
    for (char c : ma_hoa) {
        current_code += c;
        if (giai_ma.find(current_code) != giai_ma.end()) {
            giai_ma_xau += giai_ma[current_code];
            current_code = "";
        }
    }
    return giai_ma_xau;
}

int main() {
    std::string ma_hoa = "1213";
    std::string giai_ma = giai_ma_xau(ma_hoa);
    if (giai_ma.empty()) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << "So nguyen tuong ung: " << giai_ma << std::endl;
    }
    return 0;
}
