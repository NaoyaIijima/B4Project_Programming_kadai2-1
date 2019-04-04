#include<sstream>
#include<iostream>

std::stringstream ss;

int main(void)
{
    ss << std::hex << 123;
    std::string s = ss.str(); // "10"

    std::cout << s << std::endl;

    return 0;
}
