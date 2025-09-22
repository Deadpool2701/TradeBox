//
//  pointers_and_refs_exercises.cpp
//  TradeBox
//
//  Created by Amogh Mohta on 22/09/25.
//


#include "pointers_and_refs_exercises.hpp"
#include <cassert>
#include <vector>
#include <iostream>
#include "Money.hpp"
#include "RefsPtrsExercises.hpp" // your implementations must exist

namespace tb { namespace tests {

void run_test_pointers_and_refs() {
    // E1 - increase_in_place
    {
        tb::Money m{100};
        tb::increase_in_place(m, 0.10);
        assert(m.to_int() == 110);
    }

    // E2 - find_first_over
    {
        std::vector<tb::Money> v{ tb::Money{50}, tb::Money{120}, tb::Money{80} };
        const tb::Money* found{};
        bool ok = tb::find_first_over(v, 100, found);
        assert(ok && found && found->to_int() == 120);

        ok = tb::find_first_over(v, 1000, found);
        assert(!ok && found == nullptr);
    }

    // E3 - max_balance_ref
    {
        std::vector<tb::Money> v{ tb::Money{70}, tb::Money{300}, tb::Money{150} };
        const tb::Money& mx = tb::max_balance_ref(v);
        assert(&mx == &v[1]);
        assert(mx.to_int() == 300);
    }

    // E4 - swap_money
    {
        tb::Money a{10}, b{20};
        tb::swap_money(a, b);
        assert(a.to_int() == 20 && b.to_int() == 10);
    }

    // E5 - sum_range
    {
        std::vector<tb::Money> v{ tb::Money{10}, tb::Money{20}, tb::Money{30} };
        long long s = tb::sum_range(&v[0], &v[0] + v.size());
        assert(s == 60);
    }

    // E6 - rotate_left_inplace
    {
        std::vector<tb::Money> v{ tb::Money{1}, tb::Money{2}, tb::Money{3}, tb::Money{4} };
        tb::rotate_left_inplace(&v[0], &v[0] + v.size());
        assert(v[0].to_int() == 2 && v[1].to_int() == 3 && v[2].to_int() == 4 && v[3].to_int() == 1);
    }

    // E7 - find_and_update
    {
        std::vector<tb::Money> v{ tb::Money{10}, tb::Money{20}, tb::Money{30} };
        bool ok = tb::find_and_update(v, 20, 0.5);
        assert(ok);
        assert(v[1].to_int() == 30);
        ok = tb::find_and_update(v, 999, 0.1);
        assert(!ok);
    }

    // E8 - safe_factory
    {
        tb::Money m = tb::safe_factory(999);
        assert(m.to_int() == 999);
    }

    std::cout << "[OK] pointers_and_refs_exercises\n";
}

}} // namespace tb::tests
