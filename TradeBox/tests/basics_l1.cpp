//
//  basics_l1.cpp
//  TradeBox
//
//  Created by Amogh Mohta on 27/08/25.
//

#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include "Money.hpp"

using tb::Money;

int main() {
    // ---------- 1) Initialization vs Assignment ----------
    Money a1{100};          // A: direct-initialize with braces (uniform init)
    Money a2 = Money{200};  // B: copy-initialize from a temporary (NRVO likely elides copy)
    Money a3 = Money::from_int(300); // C: factory for clarity
    Money a4;               // D: default constructed (0 INR)
    a4 = Money{400};        // E: assignment after construction

    assert(a1.to_int() == 100);
    assert(a2.to_int() == 200);
    assert(a3.to_int() == 300);
    assert(a4.to_int() == 400);

    // ---------- 2) References ----------
    Money x{500};
    Money& ref = x;         // F: ref aliases x; no copy
    ref = Money{550};       // G: assigns to x through the reference
    const Money& cref = x;  // H: const reference (binds to any value, read-only view)
    // cref.to_int() works; cref = Money{...}; // ❌ compile error (can’t rebind a ref, and it’s const)

    assert(x.to_int() == 550);

    // ---------- 3) Pointers ----------
    Money y{600};
    Money* p = &y;          // I: pointer stores address of y
    (*p) = Money{650};      // J: dereference pointer, assign new value to y
    Money* const cp = &y;   // K: const pointer (pointer itself immutable), pointee mutable
    const Money* pc = &y;   // L: pointer-to-const (pointee read-only through this view)
    // *pc = Money{700};    // ❌ can’t write via pointer-to-const

    assert(y.to_int() == 650);

    // ---------- 4) const with compound types ----------
    const Money z{700};     // M: a top-level const object: z is immutable
    const Money* pcz = &z;  // N: pointer-to-const (can point to const or non-const objects)
    // *pcz = Money{710};   // ❌ cannot modify z via pcz
    Money* q = &y;          // O: non-const pointer to non-const
    Money* const cq = &y;   // P: const pointer (address fixed), value mutable
    const Money* const cpcz = &z; // Q: const pointer to const value

    // ---------- 5) auto type inference ----------
    auto m1 = Money{800};   // R: auto deduces Money
    auto m2 = m1 + Money{20}; // S: deduces Money from operator+
    auto val = m2.to_int(); // T: deduces long long

    assert(val == 820);

    // ---------- 6) Range-based for ----------
    std::vector<Money> balances{ Money{100}, Money{200}, Money{300} }; // U: aggregate with braces
    long long sum = 0;
    for (const auto& b : balances) { // V: const& avoids copies
        sum += b.to_int();
    }
    assert(sum == 600);

    // Mutating loop (e.g., apply 10% haircut to simulate risk adjustment)
    for (auto& b : balances) {       // W: non-const ref: mutate in-place
        b = b * 0.9;                 // X: uses operator*
    }
    long long sum2 = 0;
    for (const auto& b : balances) sum2 += b.to_int();
    assert(sum2 == 540); // 90 + 180 + 270

    // ---------- 7) Namespaces quick taste ----------
    // We already used tb::Money via 'using tb::Money;' above.
    // Best practice in headers: DO NOT use 'using namespace'; qualify with tb::.

    std::cout << "Basics L1 passed ✅" << std::endl;
    return 0;
}
