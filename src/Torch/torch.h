//
// Created by fgdou on 2/24/22.
//
#ifndef TORCH_H
#define TORCH_H

#include "Log.h"
#include <cassert>
#include <memory>
#include <string>
#include <vector>

#define ASSERT(x, str) if(!(x)){ \
    LOG_ERROR(str) ;              \
    assert(x) ;                  \
}

namespace Torch{

    template<class T>
    using Ref = std::shared_ptr<T>;

}

#endif