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

#include <stdio.h>
#include <string.h>

void
my_atoi(int num, char *buf)
{
    char neg = num < 0;
    unsigned char num_strlen = 1 + neg; // max value = 10(2^31)

    // num = neg ? -num : num;
    num *= neg ? -1 : 1;

    // i = Math.log_10(num)
    int c_num = num;
    while (c_num /= 10) { num_strlen++; }

    // needs to be done before the loop
    buf[num_strlen] = '\0';

    while (num_strlen--) {
        buf[num_strlen] = (char)(num % 10) + '0';
        num /= 10;
    }

    // since I'm looping to zero, I can't set this before the loop.
    if (neg) buf[0] = '-';
}

int
test_my_atoi(int num, char* expected)
{
    char buf[100];
    my_atoi(num, buf);

    return strcmp(buf, expected);
}

#define NTESTS 12
int
main(void)
{
    int test_ints[NTESTS] = {0, 1, 2, 33, 45, 654, 9023845, -1, -930824, -8, -77, -87};
    char* expected[NTESTS] = {"0", "1", "2", "33", "45", "654", "9023845", "-1", "-930824", "-8", "-77", "-87"};
    char test_status[NTESTS+1];

    printf("\n");
    for (int i = 0; i < NTESTS; i++) {
        test_status[i] = '.';

        char buf[100];
        my_atoi(test_ints[i], buf);
        if (strcmp(buf, expected[i])) {
            test_status[i] = '!';

            printf("expected: %s , actual %s\n", expected[i], buf);

            printf("\n");
        }
    }

    printf("%s\n", test_status);

    return 0;
}
