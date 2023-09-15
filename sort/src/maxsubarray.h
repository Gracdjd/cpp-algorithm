#if !defined(MaxSubArray_H)
#define MaxSubArray_H

#include <vector>
#include <functional>

namespace Algorithm
{
    namespace Sort
    {
    //找到跨越中点的最大子数组
    template<typename Iterator, typename Compare = std::greater<typename std::iterator_traits<Iterator>::value_type>>
    std::pair<Iterator, Iterator> find_max_crossing_subarray(Iterator begin, Iterator mid, Iterator end, Compare compare = Compare())
    {
        // if(begin == end) return end;
        // else if(std::distance(begin, end) == 1) return begin;
        Iterator left_max = mid;
        Iterator right_max = mid;
        //从中点向左查找最大子数组
        typename std::iterator_traits<Iterator>::value_type left_sum = *mid;
        typename std::iterator_traits<Iterator>::value_type max_left_sum = *mid;

        for(Iterator it = mid - 1; it >= begin; --it)
        {
            left_sum += *it;
            if(compare(left_sum, max_left_sum))
            {
                max_left_sum = left_sum;
                left_max = it;
            }
        }

        //向右查找最大字数组
        typename std::iterator_traits<Iterator>::value_type right_sum = *mid;
        typename std::iterator_traits<Iterator>::value_type max_right_sum = *mid;
        for(Iterator it = mid + 1; it < end; ++it)
        {
            right_sum += *it;
            if(compare(right_sum, max_right_sum))
            {
                max_right_sum = right_sum;
                right_max = it;
            }
        }
        return std::make_pair(left_max, right_max);

    }
        
    } // namespace Sort
    
} // namespace Algorithm

#endif // MaxSubArray_H
