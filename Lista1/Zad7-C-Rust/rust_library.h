#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct DiophanticResult {
  uint8_t r;
  int64_t x;
  int64_t y;
} DiophanticResult;

uint64_t factorial_loop(uint64_t n);

uint64_t factorial_recursive(uint64_t n);

uint64_t gcd_loop(uint64_t a, uint64_t b);

uint64_t gcd_recursive(uint64_t a, uint64_t b);

struct DiophanticResult diophantic_loop(int64_t r0, int64_t r1, int64_t c);

struct DiophanticResult diophantic_recursive(int64_t r0, int64_t r1, int64_t c);

struct DiophanticResult diophantic_recursive_body(int64_t r0,
                                                  int64_t r1,
                                                  int64_t c,
                                                  int64_t s0,
                                                  int64_t s1,
                                                  int64_t t0,
                                                  int64_t t1);
