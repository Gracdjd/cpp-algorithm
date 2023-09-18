#if !defined(MERGESORT_H)
#define MERGESORT_H
#include <iterator>
#include <vector>
namespace Algorithm
{
    namespace Sort
    {
    template<typename Iterator, typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
    void merge(const Iterator begin, const Iterator end, const Iterator mid,CompareType compare = CompareType())  
    {
        typedef typename std::iterator_traits<Iterator>::value_type T;
        if(std::distance(begin, mid) <= 0 || std::distance(mid, end) <= 0) return;

        std::vector<T> result(begin, end);
        auto current = result.begin();
        auto left_current = begin;
        auto right_current = mid;

        while(left_current != mid && right_current != end)
        {
            if(compare(*left_current, *right_current))
            {
                *current++ = *left_current++;
            }
            else
            {
                *current++ = *right_current++;
            }
        }
        if(left_current == mid && right_current != end) std::copy(right_current, end, current);
        if(right_current == end && left_current != mid) std::copy(left_current, mid, current);

        std::copy(result.begin(), result.end(), begin);
    }   
    
    template<typename Iterator, typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
    void merge_sort(Iterator begin, Iterator end, CompareType compare = CompareType())
    {
        auto distance = std::distance(begin, end);
        if(distance <= 1) return;
        else
        {
            Iterator mid = begin + distance / 2;
            merge_sort(begin, mid, compare);
            merge_sort(mid, end, compare);
            merge(begin, end, mid, compare);
        }
    }
    } // namespace Sort
    
} // namespace Algorithm



#endif // MERGESORT_H
