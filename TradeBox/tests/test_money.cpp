//
//  test_money.cpp
//  TradeBox
//
//  Created by Amogh Mohta on 22/08/25.
//

#include <cassert>
#include <iostream>
#include "Money.hpp"

using namespace tb;

int main2() {
    Money a = Money::from_int(100);
    Money b = Money::from_int(50);
    
    Money sum = a+b;
    Money diff = a-b;
    Money mult = b*2.0;
    
    assert(sum.to_int()==150);
    assert(diff.to_int()==50);
    assert(mult.to_int() == 100);
    
    std::cout << "All Money tests passed" << std::endl;
    return 0;
}
