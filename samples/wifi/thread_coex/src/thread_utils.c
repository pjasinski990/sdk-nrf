/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <string.h>
#include <stdlib.h>

#include "thread_utils.h"

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(thread_utils, CONFIG_LOG_DEFAULT_LEVEL);

#define DEVICE_NAME	CONFIG_BT_DEVICE_NAME
#define DEVICE_NAME_LEN (sizeof(DEVICE_NAME) - 1)

extern uint8_t wait4_peer_thread2_start_connection;

int thread_throughput_test_run(void)
{

	return 0;
}



int thread_throughput_test_init(bool is_thread_client)
{

	return 0;
}

int thread_throughput_test_exit(void)
{

	return 0;
}
