#include "FlipV.h"
#include <algorithm>

void FlipV::apply(Grid& pixels) {
    int height = static_cast<int>(pixels.size());

    for (int r = 0; r < height / 2; ++r) {
        std::swap(pixels[r], pixels[height - 1 - r]);
    }
}

std::string FlipV::name() const {
    return "flipV";
}