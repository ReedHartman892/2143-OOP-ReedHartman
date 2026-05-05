#include "Grayscale.h"

void Grayscale::apply(Grid& pixels) {
    for (auto& row : pixels) {
        for (Pixel& p : row) {
            int gray = (p.r + p.g + p.b) / 3;  // simple average
            p.r = p.g = p.b = gray;
        }
    }
}

std::string Grayscale::name() const {
    return "grayscale";
}