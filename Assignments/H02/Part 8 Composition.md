# Composition In Plain English

| Composition means assembling behavior from parts, not becoming those parts.

Or more bluntly:

| "Has-a" beats "is-a" most of the time.

# Inheritance vs Composition (No Dragons Yet)

❌ Inheritance First Instinct

cpp;
  class ColoredPoint : public Point2D {
    Color color;
  }

problems:
 - Locked into Point2D forever
 - Inherits everything, wanted or not
 - Hard to evolve safely

# ✔️ Composition Approach

cpp;
  class ColoredPoint {
  private:
    Point2D position;
    Color color;
  }

Benefits:
 - Clear ownership
 - Modular behavior
 - Fewer unintended side effects

# The Big Takeaway
 - Inheritance expresses identity.
 - Composition expresses capability.
