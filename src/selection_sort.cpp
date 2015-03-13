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
#include <iostream>
#include <iterator>
#include <vector>

#include "misc.hpp"

template<class Iterator, typename Order>
Iterator
my_selection_sort(Iterator start, Iterator finish, Order ord)
{

    for ( ; start != finish; ++start) {
        Iterator smallest = start;

        // find the element that should be in the n-th position
        for (Iterator cursor = start; cursor != finish; ++cursor) {
            if (ord(*cursor, *smallest)) {
                smallest = cursor;
            }
        }

        // swap it so that it /is/ in the n-th position
        std::iter_swap(start, smallest);
    }
    return start;
}

int main(int argc, char** argv)
{
    struct comp {
        bool operator() (const int a, const int b) { return a < b; }
    };

    std::vector<int> numbers;
    numbers = { 12, 11, 8, 7, 6, 5, 4, 9, 5, 8 };
    my_selection_sort(std::begin(numbers), std::end(numbers),
                     [](const int a, const int b) { return a < b; });
    std::cout << std::endl;
    print_arr(numbers);

    numbers = { 1, 4, 6, 3, 7, 9 };
    my_selection_sort(std::begin(numbers), std::end(numbers),
                     [](const int a, const int b) { return a < b; });
    std::cout << std::endl;
    print_arr(numbers);

    return 0;
}

