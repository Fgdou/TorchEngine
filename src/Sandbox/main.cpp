#include <iostream>

#include "torch.h"

int main() {
    Torch::Log::setLogState(Torch::Log::INFO);
    LOG_INFO("Hello world %d", 10);
}
