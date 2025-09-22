//
//  test_money.cpp
//  TradeBox
//
//  Created by Amogh Mohta on 22/08/25.
//

#include "test_money.hpp"
#include <cassert>
#include <iostream>
#include "Money.hpp"

using tb::Money;

namespace tb { namespace tests {

void run_test_money() {
    Money a = Money::from_int(100); // 100 INR
    Money b = Money::from_int(50);  // 50 INR

    Money sum = a + b;
    Money diff = a - b;
    Money mult = b * 2.0;

    assert(sum.to_int() == 150);
    assert(diff.to_int() == 50);
    assert(mult.to_int() == 100);

    std::cout << "[OK] test_money\n";
}

}}
