#pragma once
#include <stdio.h>

#include <string>
#include <vector>

typedef void (*testFunc)(uint32_t *__test_cnt, uint32_t *__test_pass);
typedef std::pair<std::string, testFunc> testDesc;
extern std::vector<testDesc> tests;

#define CHECK(expr) \
do { \
    (*__test_cnt)++; \
    if (!(expr)) { \
        printf("\x1b[31m%s\x1b[0m\t %d %s\n", "\tnot ok", *__test_cnt, #expr); \
    } else { \
        (*__test_pass)++; \
    } \
} while (0)

#define CHECKF(expr, fmt, x...) \
do { \
    (*__test_cnt)++; \
    if (!(expr)) { \
        printf("\x1b[31m%s\x1b[0m\t %d %s\t\t", "\tnot ok", *__test_cnt, #expr); \
        printf(fmt, x); \
        putchar('\n'); \
    } else { \
        (*__test_pass)++; \
    } \
} while (0)

#define NEW_TEST(func) \
extern void func##test (uint32_t *__test_cnt, uint32_t *__test_pass); \
void __attribute__((constructor)) append_test##func (void) \
{ \
    tests.push_back(std::make_pair(std::string(#func), func##test)); \
} \
void func##test (uint32_t *__test_cnt, uint32_t *__test_pass)
