#ifndef INSERTSORT_H
#define INSERTSORT_H
#include <functional>
namespace Algorithm
{
    namespace Sort
    {
    /**/
    template<typename Iterator, typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
    void insert_sort(const Iterator begin, const Iterator end, CompareType compare = CompareType())
    {
        auto size = std::distance(begin, end);
        if(size < 1) return;

        Iterator current = begin;
        
        
        while (++current != end)
        {
            //preCur指向比current小的元素中的最大值
            auto preCur = current;
            while(preCur != begin && compare(*current, *(preCur - 1)))
            {
                --preCur;
            }
            auto key = *current;
            auto iter = current;

            while(iter != preCur)
            {
                *iter = *(iter - 1);
                iter--;
            }
            *iter = key;
        }

        
        

    }
    } // namespace Sort
    
} // namespace Alogorithm

#endif