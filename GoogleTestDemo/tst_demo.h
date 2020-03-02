#ifndef TST_DEMO_H
#define TST_DEMO_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QString>
using namespace testing;

TEST(demo, demo)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}
TEST(string,string)
{
    QString str="Hello";

    ASSERT_EQ(str.toUpper(),QString("HELLO"));
}
#endif // TST_DEMO_H
