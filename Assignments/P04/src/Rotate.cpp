#include "Rotate.h"
#include <vector>

Rotate::Rotate(int angle) : angle_(angle) {}

void Rotate::apply(Grid& pixels) {
    int height = static_cast<int>(pixels.size());
    if (height == 0) return;

    int width = static_cast<int>(pixels[0].size());

    // 0° → do nothing
    if (angle_ == 0) return;

    // 90° clockwise
    if (angle_ == 90) {
        Grid result(width, std::vector<Pixel>(height));

        for (int r = 0; r < height; ++r) {
            for (int c = 0; c < width; ++c) {
                result[c][height - 1 - r] = pixels[r][c];
            }
        }

        pixels = result;
    }

    // 180°
    else if (angle_ == 180) {
        Grid result(height, std::vector<Pixel>(width));

        for (int r = 0; r < height; ++r) {
            for (int c = 0; c < width; ++c) {
                result[height - 1 - r][width - 1 - c] = pixels[r][c];
            }
        }

        pixels = result;
    }

    // 270° clockwise
    else if (angle_ == 270) {
        Grid result(width, std::vector<Pixel>(height));

        for (int r = 0; r < height; ++r) {
            for (int c = 0; c < width; ++c) {
                result[width - 1 - c][r] = pixels[r][c];
            }
        }

        pixels = result;
    }
}

std::string Rotate::name() const {
    return "rotate(" + std::to_string(angle_) + ")";
}