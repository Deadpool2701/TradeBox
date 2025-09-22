//
//  test_runner.cpp
//  TradeBoxTests
//
//  Created by Amogh Mohta on 23/09/25.
//

#include <stdio.h>

#include <iostream>
#include "test_money.hpp"
#include "basics_l1.hpp"
#include "pointers_and_refs_exercises.hpp"

int main() {
    std::cout << "Running TradeBoxTests...\n";

    tb::tests::run_test_money();
    tb::tests::run_test_basics_l1();
    tb::tests::run_test_pointers_and_refs();

    std::cout << "All tests passed ✅\n";
    return 0;
}
