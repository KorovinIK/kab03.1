#include "histogram.h"

#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_negative()
{
double min = 0; double max = 0;
find_minmax({-2, -1, -3}, min, max);
assert(min == -3);
assert(max == -1);
}

void test_equal()
{
double min = 0; double max = 0;
find_minmax({3, 3, 3}, min, max);
assert(min == 3);
assert(max == 3);
}

void test_one_num()
{
double min = 0; double max = 0;
find_minmax({9}, min, max); assert(min == 9);
assert(max == 9);
}
void test_null(){
double min = 0; double max = 0;
find_minmax({}, min, max);
assert(min == 0);
assert(max == 0);
}
int
main() {
    test_positive();
    test_negative();
    test_equal();
    test_one_num();
}
