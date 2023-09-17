#if !defined(MAXSUBARRAY_H)
#define MAXSUBARRAY_H

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
    //求字数族的和
    template<typename Iterator>
    typename std::iterator_traits<Iterator>::value_type sumOfSubarray(Iterator begin, Iterator end)
    {
        typename std::iterator_traits<Iterator>::value_type sum = *begin;
        while((++begin) != end)
        {
            sum += *begin;
        }
        return sum;
    }


    //主函数
    template<typename Iterator, typename Compare = std::greater<typename std::iterator_traits<Iterator>::value_type>,
    typename compareGE = std::greater_equal<typename std::iterator_traits<Iterator>::value_type>>
    std::pair<Iterator, Iterator> findMaxSubarray(Iterator begin, Iterator end, Compare compare = Compare(), compareGE ge = compareGE())
    {
        if(begin == end) return std::make_pair(begin, end);
        else if(std::distance(begin, end) == 1) return std::make_pair(begin, end);
        else
        {
            Iterator mid = begin + std::distance(begin, end)/2;
            std::pair<Iterator, Iterator> leftMax = findMaxSubarray(begin, mid, compare);
            std::pair<Iterator, Iterator> rightMax = findMaxSubarray(mid, end, compare);

            std::pair<Iterator, Iterator> crossMidMax = find_max_crossing_subarray(begin, mid, end, compare);


            if(ge(sumOfSubarray(leftMax.first, leftMax.second), sumOfSubarray(rightMax.first, rightMax.second)) &&
                ge(sumOfSubarray(leftMax.first, leftMax.second), sumOfSubarray(crossMidMax.first, crossMidMax.second)))
            {
                return leftMax;
            }
            else if(ge(sumOfSubarray(rightMax.first, rightMax.second), sumOfSubarray(leftMax.first, leftMax.second)) &&
                ge(sumOfSubarray(rightMax.first, rightMax.second), sumOfSubarray(crossMidMax.first, crossMidMax.second)))
            {
                return rightMax;
            }
            else
            {
                return crossMidMax;
            }
        }
    }
        
    } // namespace Sort
    
} // namespace Algorithm

#endif // MAXSUBARRAY_H
