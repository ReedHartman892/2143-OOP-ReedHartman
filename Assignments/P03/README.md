# Program 3 — Image Filter Pipeline

## Overview

This program implements an image processing pipeline using the **Strategy Pattern**. Each image operation is encapsulated as a filter class that inherits from a common `Filter` interface. A `Pipeline` object applies these filters in sequence, allowing flexible and ordered image transformations based on command-line input.

The order of filters is significant: applying the same filters in different sequences can produce different results.

---

## Implemented Filters

### Grayscale

Converts each pixel to grayscale by averaging its RGB values:

```
gray = (r + g + b) / 3
```

Each pixel’s red, green, and blue channels are then set to this value.

**Why this method?**
The average method was chosen for its simplicity and efficiency. It provides a fast approximation of grayscale without requiring floating-point operations.

---

### FlipH (Horizontal Flip)

Mirrors the image left-to-right by swapping pixels across the vertical center line.

---

### FlipV (Vertical Flip)

Mirrors the image top-to-bottom by swapping entire rows across the horizontal center line.

---

### Rotate

Rotates the image clockwise by:

* 0° (no change)
* 90° (width and height swap)
* 180° (same dimensions)
* 270° (width and height swap)

This is implemented by creating a new pixel grid and remapping each pixel to its new position.

---

## Example Commands

### 1. Grayscale only

```
./imgtool images/Hulda.jpg out1.png --grayscale
```

---

### 2. Brighten then grayscale

```
./imgtool images/Hulda.jpg out2.png --brighten 50 --grayscale
```

---

### 3. Grayscale then brighten (different result)

```
./imgtool images/Hulda.jpg out3.png --grayscale --brighten 50
```

---

### 4. Flip horizontally and vertically

```
./imgtool images/Hulda.jpg out4.png --flipH --flipV
```

---

### 5. Full pipeline with rotation

```
./imgtool images/Hulda.jpg out5.png --grayscale --brighten 30 --blur --rotate 90
```

---

## Key Concepts

* **Strategy Pattern**: Each filter is interchangeable and independent.
* **Pipeline Execution**: Filters are applied in the exact order specified by the user.
* **In-place vs Copy Operations**:

  * Most filters modify pixels in place.
  * Some (like blur and rotate) require a temporary grid to avoid data corruption.

---

## Notes

* Pixel values are not clamped during filtering; clamping occurs during image save.
* Rotation by 90° and 270° changes image dimensions.
* The program supports multiple image formats via the stb_image library.

---

## Summary

This program demonstrates how object-oriented design patterns can be used to build flexible and extensible systems. Adding new filters requires only creating a new class, without modifying existing pipeline logic.