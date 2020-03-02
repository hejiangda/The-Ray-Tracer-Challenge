#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include <Hello.h>
using cucumber::ScenarioScope;

struct HelloCtx {
    Hello *ptrHello;
    string actualResponse;
};

GIVEN("^An instance of Hello class is created$") {
    ScenarioScope<HelloCtx> context;
    context->ptrHello = new Hello();
}

WHEN("^The sayHello method is invoked$") {
    ScenarioScope<HelloCtx> context;
    context->actualResponse = context->ptrHello->sayHello();
}

THEN("^It should return$") {
    string expectedResponse = "Hello BDD!";
    ScenarioScope<HelloCtx> context;
    EXPECT_EQ(expectedResponse, context->actualResponse);
}