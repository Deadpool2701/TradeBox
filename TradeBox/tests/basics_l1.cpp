//
//  basics_l1.cpp
//  TradeBox
//
//  Created by Amogh Mohta on 27/08/25.
//

#include "basics_l1.hpp"
#include <cassert>
#include <iostream>
#include <vector>
#include "Money.hpp"

using tb::Money;

namespace tb { namespace tests {

void run_test_basics_l1() {
    Money a1{100};
    Money a2 = Money{200};
    Money a3 = Money::from_int(300);
    Money a4;
    a4 = Money{400};

    assert(a1.to_int() == 100);
    assert(a2.to_int() == 200);
    assert(a3.to_int() == 300);
    assert(a4.to_int() == 400);

    // small reference/pointer checks (from earlier lesson)
    Money x{500};
    Money& ref = x;
    ref = Money{550};
    const Money& cref = x;
    assert(x.to_int() == 550);

    Money y{600};
    Money* p = &y;
    (*p) = Money{650};
    assert(y.to_int() == 650);

    auto m1 = Money{800};
    std::vector<Money> balances{ Money{100}, Money{200}, Money{300} };
    long long sum = 0;
    for (const auto& b : balances) sum += b.to_int();
    assert(sum == 600);

    // compare checks
    Money c1{100}, c2{200};
    assert(c1 < c2);
    assert(!(c2 < c1));
    assert(c1 == Money{100});

    std::cout << "[OK] basics_l1\n";
}

}} // namespace tb::tests
