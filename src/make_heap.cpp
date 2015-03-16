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

#include <vector>
#include <iostream>

#include "misc.hpp"

template<typename Container, typename Order>
bool
re_heap(Container& arr, size_t idx, Order ord)
{
    size_t old_idx = idx;

    size_t parent = (idx - 1) / 2;
    while(idx && !ord(arr[parent], arr[idx])) {
        std::swap(arr[idx], arr[parent]);

        idx = parent;
        parent = (idx - 1) / 2;
    }

    // return whether or not something was swapped
    // (i.e. if we did not swap anything old_idx would have changed)
    return old_idx == idx;
}

template<typename Container, typename Order>
Container
my_make_heap(Container arr, size_t curr, Order ord)
{
    if (curr == 0) return arr;

    bool swapped = re_heap(arr, curr, ord);
    return my_make_heap(arr, curr - swapped, ord);
}

int
main(int argc, char** argv)
{

    std::vector<int> numbers;

    numbers = { 12, 11, 7, 6, 5, 4, 9, };
    numbers = my_make_heap(numbers, numbers.size() - 1,
            [] (const auto& num, const auto& piv) { return num < piv; });
    print_arr(numbers);

    numbers = { 9, 11, 7, 6, 5, 4, 8 };
    numbers = my_make_heap(numbers, numbers.size() - 1,
            [] (const auto& num, const auto& piv) { return num < piv; });
    print_arr(numbers);

    numbers = { 6, 11, 8, 7, 5, 4, 9, };
    numbers = my_make_heap(numbers, numbers.size() - 1,
            [] (const auto& num, const auto& piv) { return num > piv; });
    print_arr(numbers);

    std::cout << std::endl;
}
