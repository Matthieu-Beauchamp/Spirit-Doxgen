#include <iostream>


/// \defgroup Lib Lib
/// Library contents

/// \ingroup Lib
/// @brief Bar
struct Bar{};

/// \ingroup Lib
/// @brief Baz son of Bar
struct Baz : public Bar {};

/// \ingroup Lib
/// @brief Calls foo
void foo()
{ std::cout << "foo";}