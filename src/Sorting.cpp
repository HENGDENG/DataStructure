#include<iostream>
#include<vector>
#include<algorithm>
<<<<<<< HEAD
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

//-------------------------------------------//
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
/*插入排序*/

