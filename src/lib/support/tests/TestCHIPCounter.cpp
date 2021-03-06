/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <nlunit-test.h>

#include <support/CHIPCounter.h>

static void CheckStartWithZero(nlTestSuite * inSuite, void * inContext)
{
    chip::MonotonicallyIncreasingCounter counter;
    NL_TEST_ASSERT(inSuite, counter.GetValue() == 0);
}

static void CheckInitialize(nlTestSuite * inSuite, void * inContext)
{
    chip::MonotonicallyIncreasingCounter counter;

    NL_TEST_ASSERT(inSuite, counter.Init(4321) == CHIP_NO_ERROR);
    NL_TEST_ASSERT(inSuite, counter.GetValue() == 4321);
}

static void CheckAdvance(nlTestSuite * inSuite, void * inContext)
{
    chip::MonotonicallyIncreasingCounter counter;

    NL_TEST_ASSERT(inSuite, counter.Init(22) == CHIP_NO_ERROR);
    NL_TEST_ASSERT(inSuite, counter.GetValue() == 22);
    NL_TEST_ASSERT(inSuite, counter.Advance() == CHIP_NO_ERROR);
    NL_TEST_ASSERT(inSuite, counter.GetValue() == 23);
    NL_TEST_ASSERT(inSuite, counter.Advance() == CHIP_NO_ERROR);
    NL_TEST_ASSERT(inSuite, counter.GetValue() == 24);
}

/**
 *   Test Suite. It lists all the test functions.
 */

// clang-format off
static const nlTest sTests[] =
{
    NL_TEST_DEF("Start with zero", CheckStartWithZero),
    NL_TEST_DEF("Can initialize",  CheckInitialize),
    NL_TEST_DEF("Can Advance",     CheckAdvance),
    NL_TEST_SENTINEL()
};
// clang-format on

/**
 *  Set up the test suite.
 */
static int TestSetup(void * inContext)
{
    return (SUCCESS);
}

/**
 *  Tear down the test suite.
 */
static int TestTeardown(void * inContext)
{
    return (SUCCESS);
}

int main(int argc, char * argv[])
{
    // clang-format off
    nlTestSuite theSuite = {
        "chip-counter",
        &sTests[0],
        TestSetup,
        TestTeardown
    };
    // clang-format on

    // Generate machine-readable, comma-separated value (CSV) output.
    nl_test_set_output_style(OUTPUT_CSV);

    // Run test suit againt one context.
    nlTestRunner(&theSuite, NULL);

    return nlTestRunnerStats(&theSuite);
}
