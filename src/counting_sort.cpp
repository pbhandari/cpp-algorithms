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
#include <map>
#include <random>
#include <vector>
#include <ctime>

auto print_arr = [](const auto& vec) {
    std::copy(std::begin(vec), std::end(vec),
            std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
};

template<typename T, typename A, template<typename, typename> class Container,
         typename Order>
Container<T, A>
my_counting_sort(Container<T, A>& vec, Order ord)
{
    std::map<T, int, Order> items;
    for (auto& v : vec) {
        // add the item to the array if you can't find it
        if (items.find(v) == std::end(items)) { items.emplace(v, 0); }

        items[v]++;
    }

    // add the sorted elements to the vector
    int j = 0;
    for(auto it = std::begin(items); it != std::end(items); ++it) {
        for(int i = it->second; i; --i) {
            vec[j++] = it->first;
        }
    }

    return vec;
}

int main(int argc, char** argv)
{
    struct comp {
        bool operator() (const int a, const int b) { return a > b; }
    };

    std::vector<int> numbers;
    numbers = { 12, 11, 8, 7, 6, 5, 4, 9, 5, 8 };
    numbers = my_counting_sort(numbers, comp());
    print_arr(numbers);

    return 0;
}

