//
//  RefsPtrsExercises.hpp
//  TradeBox
//
//  Created by Amogh Mohta on 22/09/25.
//

#ifndef RefsPtrsExercises_hpp
#define RefsPtrsExercises_hpp

#pragma once
#include <vector>
#include "Money.hpp"

namespace tb {

// E1
void increase_in_place(Money& m, double pct);

// E2
bool find_first_over(const std::vector<Money>& v,
                     long long thresholdRupees,
                     const Money*& out);

// E3
const Money& max_balance_ref(const std::vector<Money>& v);

// E4
void swap_money(Money& a, Money& b);

// E5
long long sum_range(const Money* begin, const Money* end);

// E6
void rotate_left_inplace(Money* begin, Money* end);

// E7
bool find_and_update(std::vector<Money>& v,
                     long long target,
                     double pct);

// E8
Money safe_factory(long long val);

} // namespace tb

#endif /* RefsPtrsExercises_hpp */
