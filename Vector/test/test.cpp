//
// Created by zxz on 2019/12/9.
//

#include "test.h"
#include "../../LinearRandom/src/LRandom.h"

void test2()
{
    double array[] = {1, 3, 4, 6, 8};
    Vector v(5, array);
}

void testRandom()
{
    LRandom lRandom(time(nullptr));
    auto v1 = lRandom.randVector(5, 0, 10);
    auto v2 = lRandom.randVector(5, 0, 10);
    v1.print();
    printf("\n------\n");
    v2.print();
    printf("\n------\n");
    printf("Inner product: %.2f", v1.innerProduct(v2));
    printf("\n--Outer Product---\n");
    v1.outerProduct(v2).print();
}

void Vector_test()
{
    testRandom();
}
