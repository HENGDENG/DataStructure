#include<iostream>
#include<vector>
#include<unordered_map>
////二分查找

//双闭区间查找
int binarySearch(const std::vector<int>& num, int target) {
    int i = 0;
    int j = num.size() - 1;
    int index = 0;

    while (i <= j) {
        index = i + (j - i) / 2;
        if (num[index] == target) {
            return index;
        }
        else if (num[index] < target) {
            i = index + 1;
        }
        else j = index - 1;
    }
    return -1;
}

//左闭右开区间
int binarySearch1(const std::vector<int>& num, int target) {
    int i = 0;
    int j = num.size() - 1;
    int index = 0;

    while (i < j) {
        index = i + (j - i) / 2;
        if (num[index] == target) {
            return index;
        }
        else if (num[index] < target) {
            i = index + 1;
        }
        else j = index;
    }
    return -1;
}


int binarySearchInsertValue(const std::vector<int>& num, int target) {
    int left = 0;
    int right = num.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (num[mid] == target) {
            return mid; // Target found at index mid
        }
        else if (num[mid] < target) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid; // Search in the left half
        }
    }

    return left; // Target not found, return the index where it should be inserted
}

/* 二分查找插入点（存在重复元素） */
int binarySearchInsertion(const std::vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1; // 初始化双闭区间 [0, n-1]
    while (i <= j) {
        int m = i + (j - i) / 2; // 计算中点索引 m
        if (nums[m] < target) {
            i = m + 1; // target 在区间 [m+1, j] 中
        }
        else if (nums[m] > target) {
            j = m - 1; // target 在区间 [i, m-1] 中
        }
        else {
            j = m - 1; // 首个小于 target 的元素在区间 [i, m-1] 中
        }
    }
    // 返回插入点 i
    return i;
}

/* 二分查找最左一个 target */
int binarySearchLeftEdge(const std::vector<int>& nums, int target) {
    // 等价于查找 target 的插入点
    int i = binarySearchInsertion(nums, target);
    // 未找到 target ，返回 -1
    if (i == nums.size() || nums[i] != target) {
        return -1;
    }
    // 找到 target ，返回索引 i
    return i;
}

/* 二分查找最右一个 target */
int binarySearchRightEdge(const std::vector<int>& nums, int target) {
    // 等价于查找 target+1 的插入点，再减一
    int i = binarySearchInsertion(nums, target + 1);
    // 未找到 target ，返回 -1
    if (i == 0 || nums[i - 1] != target) {
        return -1;
    }
    // 找到 target ，返回索引 i-1
    return i - 1;
}


////哈希优化策略：以空间换时间

/*给定一个整数数组 nums 和一个目标元素 target ，请在数组中搜索“和”为 target 的两个元素，并返回它们的数组索引。返回任意一个解即可。*/
std::pair<int, int> findTwoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        if (map.find(target - nums[i]) != map.end()) {
            return { i, map[target - nums[i]] };
        }
        map[nums[i]] = i;
        //map.emplace(nums[i], i);
    }
    return { -1, -1 };
}



int main() {
    std::vector<int> num{};
    for (int i = 0;i <= 1000;++i) {
        num.push_back(i+1);
    }
    int index = binarySearch(num, 910);
    int index1 = binarySearch(num, 911);
    int target = 5;
    int result = binarySearchInsertValue(num, target);
    std::cout << "Index to insert " << target << " is: " << result << std::endl;
    std::cout << index << std::endl;
    std::cout << index1 << std::endl;
    std::cout << binarySearchInsertion(num, 910) << std::endl;
    std::cout << binarySearchLeftEdge(num, 910) << std::endl;
    std::cout << binarySearchRightEdge(num, 910) << std::endl;
    std::pair<int, int> result1 = findTwoSum(num, 1001);
    std::cout << "Indices of elements summing to 1001: (" << result1.first << ", " << result1.second << ")" << std::endl;

    return 0;
}
