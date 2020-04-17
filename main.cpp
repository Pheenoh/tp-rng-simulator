#include <iostream>
#include <cmath>

static int32_t RNG0 = 100;
static int32_t RNG1 = 100;
static int32_t RNG2 = 100;
static double RNG_val;

double calculate_rng() {
    double addend0, addend1, addend2, sum, remainder;
 
    RNG0 = (RNG0 * 171) % 30269;
    RNG1 = (RNG1 * 172) % 30307;
    RNG2 = (RNG2 * 170) % 30323;
    addend0 = ((0x4330000000000000 | (RNG2 ^ 0x80000000)) - 0x4330000080000000) / 30323.0f;
    addend1 = ((0x4330000000000000 | (RNG0 ^ 0x80000000)) - 0x4330000080000000) / 30269.0f;
    addend2 = ((0x4330000000000000 | (RNG1 ^ 0x80000000)) - 0x4330000080000000) / 30307.0f;
    sum = addend0 + addend1 + addend2;
    remainder = fmod(sum,1.0f);
    RNG_val = fabs(remainder);

    printf("New RNG seed 0: %d \n",RNG0);
    printf("New RNG seed 1: %d \n",RNG1);
    printf("New RNG seed 2: %d \n",RNG2);
    printf("remainder: %f \n", remainder);
    return RNG_val;
}

int main() {
    RNG_val = calculate_rng();
    printf("rng value: %f\n", RNG_val);
    printf("-----------\n");
    return 0;
}