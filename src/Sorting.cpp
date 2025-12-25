#include<iostream>
#include<vector>
#include<algorithm>

/*冒泡排序*/
void BubbleSorting(std::vector<int>& num) {
    size_t n = num.size();
    for (size_t i = 0; i < n - 1; ++i) {               
        for (size_t j = 0; j < n - i - 1; ++j) {       
            if (num[j] < num[j + 1]) {                 
                std::swap(num[j], num[j + 1]);
            }
        }
    }
}


/*冒泡排序优化*/
void BubbleSorting1(std::vector<int>& num) {
    size_t n = num.size();
    for (size_t i = 0; i < n - 1; ++i) {
        bool flag = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (num[j] < num[j + 1]) {
                std::swap(num[j], num[j + 1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}

int main() {

    std::vector<int> num{ 1,9,6,8,3,7,2 };
    BubbleSorting1(num);
    for (auto& ele : num) {
        std::cout << ele;
    }
    std::cout << std::endl;
    return 0;
}