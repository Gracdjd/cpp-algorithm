#if !defined(MAXSUBARRAY_H)
#define MAXSUBARRAY_H

#include "../google_test/gtest.h"
#include "../src/maxsubarray.h"
#include <vector>
using Algorithm::Sort::find_max_crossing_subarray;

#define FIND_SUB(input, compare) begin = input.begin(); \
                        end = input.end(); \
                        mid = begin + std::distance(begin, end)/2; \
                        auto compare = find_max_crossing_subarray(begin,mid, end)

TEST(test_sort_subarray, find_max_crossing_subarray)
{
    std::vector<int> input1={1,2,3,4,5,6,7,8,9,10};
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> data1{input1.begin(), input1.end() - 1}; 
    auto begin = input1.begin();
    auto end = input1.end();
    auto mid = begin + std::distance(begin, end) / 2;
    auto  compare1 = find_max_crossing_subarray(begin,mid, end);

    std::vector<int> input2{2, 3, 4, 5, -1, -5};
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> data2{input2.begin(), input2.end() - 3};
    FIND_SUB(input2, compare2);
    EXPECT_EQ(compare1, data1);
    EXPECT_EQ(compare2, data2);
}
#endif // MAXSUBARRAY_H
