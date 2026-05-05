#include "FlipH.h"
#include <algorithm>

void FlipH::apply(Grid& pixels) {
    for (auto& row : pixels) {
        int width = static_cast<int>(row.size());

        for (int c = 0; c < width / 2; ++c) {
            std::swap(row[c], row[width - 1 - c]);
        }
    }
}

std::string FlipH::name() const {
    return "flipH";
}