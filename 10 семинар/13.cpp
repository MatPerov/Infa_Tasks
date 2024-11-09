#include <iostream>
#include <string>
#include <vector>
void print(const std::vector<std::string>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

std::vector<std::string> prefixes(std::string str) {
    int i = 0;
    int n = 0;
    std::vector<std::string> result;
    std::string temp="";
    while (str[i] != '\0') {
        n += 1;
        i += 1;
    }
    for (int i = 0; i < n; i++) {
        temp += str[i];
        result.push_back(temp);
    }
    return result;
}
int main()
{
    std::vector<std::string> v = prefixes("Mouse");
    print(v);  // Должно напечатать M Mo Mou Mous Mouse
}