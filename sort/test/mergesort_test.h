#if !defined(MERGESORT_TEST_H)
#define MERGESORT_TEST_H

#include "../src/mergesort.h"
#include "../../google_test/gtest.h"    
#include<vector>
using Algorithm::Sort::merge_sort;

TEST(test_mergesort, test_std_cointer)
{
    std::vector<int> data1{3, 4, 2, 1, 0, 0, 1, 1, 0};
    std::vector<int> data2{1};
    std::vector<int> data3{};

    std::vector<int> compare_data1{3, 4, 2, 1, 0, 0, 1, 1, 0}; ;
    std::vector<int> compare_data2{1};
    std::vector<int> compare_data3{};

    std::sort(data1.begin(), data1.end());
    merge_sort(compare_data1.begin(), compare_data1.end());
    std::sort(data2.begin(), data2.end());
    merge_sort(compare_data2.begin(), compare_data2.end());
    std::sort(data3.begin(), data3.end());
    merge_sort(compare_data3.begin(), compare_data3.end());
    EXPECT_EQ(data1, compare_data1);
    EXPECT_EQ(data2, compare_data2);
    EXPECT_EQ(data3, compare_data3);
}

#endif // MERGESORT_TEST_H


