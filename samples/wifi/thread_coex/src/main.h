/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);

#include <nrfx_clock.h>

#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/shell/shell.h>
#include <zephyr/shell/shell_uart.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/net/zperf.h>
#include <zephyr/net/net_if.h>
#include <zephyr/net/wifi_mgmt.h>
#include <zephyr/net/net_event.h>
#include <zephyr/net/socket.h>

#include "coex.h"
#include "fmac_main.h"

#define RSSI_INIT_VALUE 127
#define TXPOWER_INIT_VALUE 127

extern int8_t wifi_rssi;
extern int8_t ot_tx_power;
extern int8_t ot_rssi;

/**
 * @brief Function to test Wi-Fi scan/connected-scan and Thread discovery
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_scan_ot_discov(bool is_ant_mode_sep, bool test_thread, bool test_wifi,
		bool is_ot_client, bool is_wifi_conn_scan);

/**
 * @brief Function to test Wi-Fi scan/connected-scan and Thread connection
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_scan_ot_connection(bool is_ant_mode_sep, bool test_thread, bool test_wifi,
		bool is_ot_client, bool is_wifi_conn_scan);

/**
 * @brief Function to test Wi-Fi scan/connected-scan and Thread throughput client/server
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_scan_ot_tput(bool is_ant_mode_sep, bool test_thread, bool test_wifi,
		bool is_ot_client, bool is_wifi_conn_scan);

/**
 * @brief Function to test Wi-Fi connection and Thread discovery
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_con_ot_discov(bool test_wifi, bool is_ant_mode_sep,	bool test_thread, bool is_ot_client);

/**
 * @brief Function to test Wi-Fi connection and Thread throughput client/server
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_con_ot_tput(bool test_wifi, bool is_ant_mode_sep,	bool test_thread, bool is_ot_client);

/**
 * @brief Function to test Wi-Fi throughput client/server and Thread discovery
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_tput_ot_discov(bool test_wifi, bool test_thread, bool is_ot_client,
		bool is_wifi_server, bool is_ant_mode_sep, bool is_wifi_zperf_udp);

/**
 * @brief Function to test Wi-Fi throughput client/server and Thread connection
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_tput_ot_connection(bool test_wifi, bool test_thread, bool is_ot_client,
		bool is_wifi_server, bool is_ant_mode_sep, bool is_wifi_zperf_udp);


/**
 * @brief Function to test Wi-Fi throughput client/server and Thread throughput client/server
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_tput_ot_tput(bool test_wifi, bool is_ant_mode_sep, bool test_thread,
		bool is_ot_client, bool is_wifi_server, bool is_wifi_zperf_udp);

/**
 * @brief Function to test Wi-Fi connection stability with Thread discovery as interference
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_con_stability_ot_discov_interference(bool test_wifi, bool test_thread, bool is_ot_client,
		bool is_ant_mode_sep);

/**
 * @brief Function to test Wi-Fi connection stability with Thread throughput client/server
 * as interference
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_con_stability_ot_tput_interference(bool test_wifi, bool is_ant_mode_sep, bool test_thread,
	bool is_ot_client);

/**
 * @brief Function to test Thread connection stability with Wi-Fi scan/
 * connected-scan as interference
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int ot_con_stability_wifi_scan_interference(bool is_ant_mode_sep, bool test_thread, bool test_wifi,
		bool is_ot_client, bool is_wifi_conn_scan);

/**
 * @brief Function to test Thread connection stability with Wi-Fi throughput
 * (client/server) as interference
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int ot_connection_stability_wifi_tput_interference(bool test_wifi, bool test_thread, bool is_ot_client,
	bool is_wifi_server, bool is_ant_mode_sep, bool is_wifi_zperf_udp);

/**
 * @brief Function to test Thread discovery functionality with Wi-Fi shutdown
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_shutdown_ot_discov(bool is_ot_client);

/**
 * @brief Function to test Thread connection functionality with Wi-Fi shutdown
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_shutdown_ot_connection(bool is_ot_client);

/**
 * @brief Function to test Thread throughput client/server functionality with Wi-Fi shutdown
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_shutdown_ot_tput(bool is_ot_client);

/**
 * @brief memset_context
 *
 * @return No return value.
 */
void memset_context(void);
/**
 * @brief Handle net management callbacks
 *
 * @return No return value.
 */
void wifi_net_mgmt_callback_functions(void);

/**
 * @brief Wi-Fi init.
 *
 * @return None
 */
void wifi_init(void);

#endif /* MAIN_H_ */
