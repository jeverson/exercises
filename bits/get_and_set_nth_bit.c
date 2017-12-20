#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int get_nth_bit(int value, int n);
int set_nth_bit_to_one(int value, int n);
void print_bits(int value);

int main() {
    printf("Hello bit manipulation world!\n");
    int value = 100;
    print_bits(value);

    int i;
    for(i = 0; i < 8; i++) {
        int nth_bit = get_nth_bit(value, i);
        printf("%d[%d] = %d\n", value, i, nth_bit);
    }

    for(i = 0; i < 8; i++) {
        int new_num = set_nth_bit_to_one(value, i);
        printf("new num: %d\n", new_num);
    }
    return 0;
}

int get_nth_bit(int value, int n) {
    int check_bit = 1 << n;
    int and_bit = value & check_bit;
    return (and_bit == check_bit) ? 1 : 0;
}

int set_nth_bit_to_one(int value, int n) {
    int set_bit = 1 << n;    
    return value | set_bit;
}

void print_bits(int value) {
    unsigned int check_bit = 1 << sizeof(int) * 8 - 1;
    while (check_bit > 0) {
        int check = value & check_bit;
        int bit = (check == check_bit) ? 1: 0;
        printf("%d", bit);

        check_bit = check_bit >> 1;
    }
    printf("\n");
}