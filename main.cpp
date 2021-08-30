#include <iostream>
#include <string>
#include <vector>

enum note{
    DO = 1 << 1,
    RE = 1 << 2,
    MI = 1 << 3,
    FA = 1 << 4,
    SOL = 1 << 5,
    LA = 1 << 6,
    SI = 1 << 7,
};
int mask(std::string comb){
    int m = 0;
    for(int i = 0; i < comb.length(); i++){
        int c = comb[i] - '0';
        m|=1 << c;
    }
    return m;
}

std::string deMask(int m){
    std::string buf = "";
    if(m & DO)  buf += "DO ";
    if(m & RE)  buf += "RE ";
    if(m & MI)  buf += "MI ";
    if(m & FA)  buf += "FA ";
    if(m & SOL) buf += "SOL ";
    if(m & LA)  buf += "LA ";
    if(m & SI)  buf += "SI ";
    return buf;

}

int main() {
    std::vector<int> vec(12);

    for(int i = 0; i < vec.size();i++){
        std::string combination;
        getline(std::cin,combination);
        vec[i] = mask(combination);
    }

    for(int i = 0; i < vec.size();i++){
        std::cout << deMask(vec[i]) << std::endl;
    }

    return 0;
}
