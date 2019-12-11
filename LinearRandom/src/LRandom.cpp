//
// Created by zxz on 2019/12/11.
//

#include "LRandom.h"

LRandom::LRandom(time_t t)
{
    generator = std::default_random_engine(t);
}

