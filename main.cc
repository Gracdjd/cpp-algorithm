#include "sort/test/insertsort_test.h"
#include "sort/test/maxsubarray_test.h"
#include "sort/test/mergesort_test.h"
int main(int argc,char** argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    // ::testing::FLAGS_gtest_filter = "test_mergesort.test_std_cointer";
    return RUN_ALL_TESTS();
}

