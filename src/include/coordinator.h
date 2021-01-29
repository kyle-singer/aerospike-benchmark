/*******************************************************************************
 * Copyright 2008-2020 by Aerospike.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/
#pragma once

#include <pthread.h>

#include <benchmark.h>

// forward declare to avoid circular inclusion
struct threaddata;

struct thr_coordinator {
	pthread_barrier_t barrier;
	uint32_t n_threads;
};

struct coordinator_worker_args {
	struct thr_coordinator* coord;
	clientdata* cdata;

	// list of thread data pointers
	struct threaddata** tdatas;
	uint32_t n_threads;
};

/*
 * initializes the given thread coordinator struct
 */
int thr_coordinator_init(struct thr_coordinator*, uint32_t n_threads);

void thr_coordinator_free(struct thr_coordinator*);


/*
 * init function for the thread coordinator thread
 *
 * should be passed a pointer to a clientdata struct
 */
void* coordinator_worker(void* udata);
