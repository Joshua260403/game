#include "optional.h"

#include <cassert>

void test_optional()
{
  #ifdef FIX_ISSUE_189
  // Initialize with a value
  {
    const int value = 42;
    const optional<int> x = value;
    assert(x.has_value());
    assert(x.value() == value);
  }
  // Reset the value
  {
    const int value = 42;
    optional<int> x = value * 2;
    assert(x.value() != value);
    x = value;
    assert(x.value() == value);
  }
  // No value
  {
    const optional<int> x;
    assert(!x.has_value());
    try
    {
      x.value();
      assert(!"Should not get here: there is no value");
    }
    catch (const exception&)
    {
      //Great! x should throw, as there is no value
    }
  }
  #endif // FIX_ISSUE_189
}
