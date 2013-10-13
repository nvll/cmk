#pragma once
#include <stdio.h>

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#define constructor __attribute__((constructor))
typedef void (*testFunc)(uint32_t *__test_cnt, uint32_t *__test_pass);
typedef std::pair<std::string, testFunc> testDesc;
extern std::vector<testDesc> tests;

#define GREEN "\x1b[32m"
#define RED   "\x1b[31m"
#define RESET "\x1b[0m"

#define MAKE_TEST(func) extern void func##_test (uint32_t *__test_cnt, uint32_t *__test_pass); \
void constructor reg_##func (void) { tests.push_back(::make_pair(::string(#func), func##_test)); }; \
void func##_test (uint32_t *__test_cnt, uint32_t *__test_pass)

int run_tests(void);

#define TEST_RET(f) { (*__test_cnt)++; if (f) (*__test_pass)++; }
#define TEST_EQ(t1, t2, s) TEST_RET(_TEST_EQ(t1, t2, s, __FUNCTION__, __FILE__, __LINE__))
template<class T> bool _TEST_EQ(T t1, T t2, const char *s, const char *name, const char *file, const int line)
{
    if (t1 != t2) {
        printf("%s%10s%s %s\n", RED, "FAILED", RESET ":", s);
        ::cout << "          (" << t1 << " != " << t2 << ") at " << file << ':' << line << endl;
        return false;
    }

    return true;
}

// We need a way to handle C strings so lexicographic comparisons can be done
template<class T> bool _TEST_EQ(const char *t1, const char *t2, const char *s, const char *name, const char *file, const int line)
{
    return _TEST_EQ(string(t1), string(t2), s, name, file, line);
}

// Handle cases where we don't care if it has a string message
#define ASSERT_EQ(t1, t2, s) TEST_RET(_ASSERT_EQ(t1, t2, s, __FUNCTION__, __FILE__, __LINE__))
template<class T> void _ASSERT_EQ(T t1, T t2, const char *s, const char *name, const char *file, const int line)
{
    if (!_TEST_EQ(t1, t2, s, name, file, line)) {
        printf(RED "          Test assertion failed, exiting test process %s\n" RESET, name);
        exit(1);
    }
}

template<class T> void _ASSERT_EQ(const char *t1, const char *t2, const char *s, const char *name, const char *file, const int line)
{
    return _ASSERT_EQ(string(t1), string(t2), s, name, file, line);
}
