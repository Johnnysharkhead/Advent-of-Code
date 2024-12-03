#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

int whetherSafe(const std::vector<int> &vec) {
    if (!std::is_sorted(vec.begin(), vec.end()) && !std::is_sorted(vec.begin(), vec.end(), std::greater<int>())) {
        return 0;
    }

    for (int i{0}; i < vec.size()-1; ++i) {
        if (std::abs(vec[i] - vec[i + 1]) > 3 || std::abs(vec[i] - vec[i + 1]) < 1) {
            return 0;
        }
    }
    return 1;
}

int main() {

    std::ifstream fileName {"input.txt"};  
    std::vector <int> v {};

    std::string line;

    while (std::getline(fileName, line)){
        std::istringstream iss(line);
        int value;
        while(iss >> value){
            v.push_back(value);
        }
        v.push_back(-1); //换行插入-1
    }


    std::vector<int> temp{};
    int result{0};

    auto it = v.begin(); // initialize iterator of vector

    while(it != v.end()){
        if(*it == -1){
            // for (auto num : temp){
            //     std::cout << num << " ";
            // }
            // std::cout << std::endl;
            result = result + whetherSafe(temp);
            temp.clear();
            it = v.erase(v.begin(), it+1);
        }
        else{
            temp.push_back(*it);
            ++it;
        }
    }

    std::cout << "Safe number: " << result << std::endl;

}