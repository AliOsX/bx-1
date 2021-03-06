/*
 * Copyright 2010-2013 Branimir Karadzic. All rights reserved.
 * License: http://www.opensource.org/licenses/BSD-2-Clause
 */

#include "test.h"
#include <bx/thread.h>

int32_t threadExit0(void*)
{
	return 0;
}

int32_t threadExit1(void*)
{
	return 1;
}

TEST(thread)
{
	bx::Thread th;

	CHECK_EQUAL(th.isRunning(), false);

	th.init(threadExit0);
	CHECK_EQUAL(th.isRunning(), true);
	th.shutdown();

	CHECK_EQUAL(th.isRunning(), false);
	CHECK_EQUAL(th.getExitCode(), 0);

	th.init(threadExit1);
	CHECK_EQUAL(th.isRunning(), true);
	th.shutdown();

	CHECK_EQUAL(th.isRunning(), false);
	CHECK_EQUAL(th.getExitCode(), 1);
}
