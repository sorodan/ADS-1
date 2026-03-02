// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  for (uint64_t i = 2; i <= sqrt(value); i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 1;
  for (uint64_t i = 0; i < UINT64_MAX; i++) {
    if (checkPrime(i)) {
      if (count == n) {
        return i;
      }
      count++;
    }
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  for (uint64_t i = value + 1; i < UINT64_MAX; i++) {
    if (checkPrime(i)) {
      return i;
    }
  }
  return 0;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 0; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i >= lbound && i < hbound - 2; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
  }
  return count;
}
