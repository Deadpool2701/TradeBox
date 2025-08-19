//
//  Money.hpp
//  TradeBox
//
//  Created by Amogh Mohta on 22/08/25.
//

#pragma once
#include <iostream>
#include <compare>

namespace tb {
struct Money {
    long long rupees{0};
    
    Money()=default;
    explicit Money(long long r) : rupees(r) {}

    static Money from_int(long long r) {
        return Money{r};
    }
    
    friend Money operator+(Money a, Money b) { return Money{a.rupees + b.rupees}; }
    friend Money operator-(Money a, Money b) { return Money{a.rupees - b.rupees}; }
    friend Money operator*(Money a, double factor) {
        return Money{ static_cast<long long>(a.rupees * factor)};
    }
    
    auto operator<=>(const Money&) const = default;
    long long to_int() const { return rupees; }
    
    friend std::ostream& operator<<(std::ostream& os, const Money& m) {
        os << m.rupees << " INR";
        return os;
    }
};

}

