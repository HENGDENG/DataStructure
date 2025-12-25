#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<numeric>
////函数输出
template<typename T>
void printVector(const std::vector<T>& v) {
    for (const auto& x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

std::vector<int> generateShuffledSequence(size_t n, int start = 1) {
    std::vector<int> vec(n);
    std::iota(vec.begin(), vec.end(), start); // 填充为 start, start+1, ..., start+n-1

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g); // 打乱顺序

    return vec;
}


////选择排序
void selectSorting(std::vector<int>& num) {
    if (num.size() <= 1) return;
    for (size_t i = 0;i < num.size() - 1;++i) {
        int index=i;
        for (size_t k=index+1;k < num.size();++k) {
            if (num[index] < num[k]) {
                index=k;
            }
        }
        std::swap(num[i], num[index]);
    }

}


/*插入排序*/



int main() {
    // std::vector<int> num = { 2,5,88,6,9,4,33,21,9 };
    auto num = generateShuffledSequence(10, 1); // 1~10 的随机排列
    for (int x : num) std::cout << x << " ";
    std::cout << "\n";
    selectSorting(num);
    std::cout << "选择排序后的结果：";
    printVector(num);


    return 0;
}