#include "crisp/base/list.hpp"

int main() {
  using namespace crisp::base::list;
  /// head
  {
    // This line will trigger a compile error:
    // using t0 = typename head<List<>>::type;

    using t1 = typename head<List<int>>::type;
    static_assert(is_same<t1, int>::value, "");

    using t2 = typename head<List<bool, int, char>>::type;
    static_assert(is_same<t2, bool>::value, "");
  }

  /// last
  {
    // This line will trigger a compile error:
    // using t0 = typename last<List<>>::type;

    using t1 = typename last<List<int>>::type;
    static_assert(is_same<t1, int>::value, "");

    using t2 = typename last<List<bool, int, char>>::type;
    static_assert(is_same<t2, char>::value, "");
  }

  /// init
  {
    // This line will trigger a compile error:
    // using t0 = typename init<int>::type;

    // This line will trigger a compile error:
    // using t1 = typename init<List<>>::type;

    using t2 = typename init<List<bool>>::type;
    static_assert(is_same<t2, List<>>::value, "");

    using t3 = typename init<List<bool, int>>::type;
    static_assert(is_same<t3, List<bool>>::value, "");

    using t4 = typename init<List<bool, int, char>>::type;
    static_assert(is_same<t4, List<bool, int>>::value, "");
  }

  ///  tail
  {
    using t0 = typename tail<List<int>>::type;
    static_assert(is_same<t0, List<>>::value, "");

    using t1 = typename tail<List<bool, int>>::type;
    static_assert(is_same<t1, List<int>>::value, "");

    using t2 = typename tail<List<bool, int, char>>::type;
    static_assert(is_same<t2, List<int, char>>::value, "");
  }

  /// prepended
  {
    using t0 = typename prepended<List<>, int>::type;
    static_assert(is_same<t0, List<int>>::value, "");

    using t1 = typename prepended<List<bool>, int>::type;
    static_assert(is_same<t1, List<int, bool>>::value, "");
  }

  /// appended
  {
    using t0 = typename appended<List<>, int>::type;
    static_assert(is_same<t0, List<int>>::value, "");

    using t1 = typename appended<List<bool>, int>::type;
    static_assert(is_same<t1, List<bool, int>>::value, "");
  }

  /// concat
  {
    using t0 = typename appended_all<List<>, List<>>::type;
    static_assert(is_same<t0, List<>>::value, "");

    using t1 = typename appended_all<List<int>, List<>>::type;
    static_assert(is_same<t1, List<int>>::value, "");

    using t2 = typename appended_all<List<>, List<int>>::type;
    static_assert(is_same<t2, List<int>>::value, "");

    using t3 =
        typename appended_all<List<int, bool>, List<int, char, bool>>::type;
    static_assert(is_same<t3, List<int, bool, int, char, bool>>::value, "");
  }

  // take
  {
    using l0 = List<>;
    using l1 = List<int, char, bool>;

    // This line will trigger a compile error:
    // using t0 = take<l0, Int<1>>::type;

    using t0 = take<l1, Int<0>>::type;
    static_assert(is_same<t0, List<>>::value, "");

    using t1 = take<l1, Int<1>>::type;
    static_assert(is_same<t1, List<int>>::value, "");

    using t2 = take<l1, Int<2>>::type;
    static_assert(is_same<t2, List<int, char>>::value, "");

    using t3 = take<l1, Int<3>>::type;
    static_assert(is_same<t3, List<int, char, bool>>::value, "");

    // This line will trigger a compile error:
    //    using t4 = take<l1, Int<4>>::type;
  }
  return 0;
}