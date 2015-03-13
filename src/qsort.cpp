// Copyright (c) 2014, Prajjwal Bhandari <pbhandari@pbhandari.ca>
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include <ctime>

#include "misc.hpp"

template<typename Iterator, typename Order>
void
my_qsort(Iterator start, Iterator finish, Order ord)
{
    using std::placeholders::_1;

    if (finish - start <= 1) return;

    // pick a random pivot and swap the first element with it
    Iterator pivot = start + (std::rand() % (finish - start));
    std::iter_swap(start, pivot);

    // partition everything but the pivot around the pivot
    Iterator part = std::partition(start + 1, finish,
                                   std::bind(ord, _1, *start));

    // put the pivot where it should be (the element before the pivot point is
    // guaranteed to be less than the pivot element)
    std::iter_swap(start, part - 1);

    // recurse on the two halves
    my_qsort(start, part - 1, ord);
    my_qsort(part + 1, finish, ord);
}

int main(int argc, char** argv)
{
    std::srand(std::time(nullptr));

    std::vector<int> numbers;

    numbers = { 12, 11, 8, 7, 6, 5, 4, 9, 5, 8 };
    my_qsort(std::begin(numbers), std::end(numbers),
            [] (const auto& num, const auto& piv) { return num < piv; });
    print_arr(numbers);

    numbers = { 9, 11, 8, 7, 6, 5, 4, 9, 5, 8 };
    my_qsort(std::begin(numbers), std::end(numbers),
            [] (const auto& num, const auto& piv) { return num < piv; });
    print_arr(numbers);

    numbers = { 6, 11, 8, 7, 5, 4, 9, };
    my_qsort(std::begin(numbers), std::end(numbers),
            [] (const auto& num, const auto& piv) { return num > piv; });
    print_arr(numbers);

    return 0;
}

