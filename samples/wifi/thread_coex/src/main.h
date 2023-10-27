/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef MAIN_H_
#define MAIN_H_

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

#include <zephyr_coex.h>

extern int8_t wifi_rssi;
extern int8_t ot_tx_power;
extern int8_t ot_rssi;

/**
 * @brief Function to test Wi-Fi scan/connected-scan and BLE connection central/peripheral
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_scan_ot_discov(bool is_ant_mode_sep, bool test_openThread, bool test_wifi,
		bool is_ot_client, bool is_wifi_conn_scan);

/**
 * @brief Function to test Wi-Fi scan/connected-scan and BLE connection central/peripheral
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_scan_ot_connection(bool is_ant_mode_sep, bool test_openThread, bool test_wifi,
		bool is_ot_client, bool is_wifi_conn_scan);

/**
 * @brief Function to test Wi-Fi scan/connected-scan and BLE throughput central/peripheral
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_scan_ble_tput(bool is_ant_mode_sep, bool test_openThread, bool test_wifi,
		bool is_ot_client, bool is_wifi_conn_scan);

/**
 * @brief Function to test Wi-Fi connection and BLE throughput central/peripheral
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_con_ble_tput(bool test_wifi, bool is_ant_mode_sep,	bool test_openThread, bool is_ot_client);

/**
 * @brief Function to test Wi-Fi throughput client/server and BLE connection central/peripheral
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_tput_ot_discov(bool test_wifi, bool test_openThread, bool is_ot_client,
		bool is_wifi_server, bool is_ant_mode_sep, bool is_wifi_zperf_udp);

/**
 * @brief Function to test Wi-Fi throughput client/server and BLE connection central/peripheral
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_tput_ot_connection(bool test_wifi, bool test_openThread, bool is_ot_client,
		bool is_wifi_server, bool is_ant_mode_sep, bool is_wifi_zperf_udp);


/**
 * @brief Function to test Wi-Fi throughput client/server and BLE throughput central/peripheral
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_tput_ble_tput(bool test_wifi, bool is_ant_mode_sep, bool test_openThread,
		bool is_ot_client, bool is_wifi_server, bool is_wifi_zperf_udp);

/**
 * @brief Function to test Wi-Fi connection  stability with BLE connection central/peripheral
 * as interference.
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_con_stability_ot_connection_interference(bool test_wifi, bool test_openThread, bool is_ot_client,
	bool is_ant_mode_sep);

/**
 * @brief Function to test Wi-Fi connection stability with BLE throughput central/peripheral
 * as interference
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int wifi_con_stability_ble_tput_interference(bool test_wifi, bool is_ant_mode_sep, bool test_openThread,
	bool is_ot_client);

/**
 * @brief Function to test BLE connection central/peripheral stability with Wi-Fi scan/
 * connected-scan as interference
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int ot_con_stability_wifi_scan_interference(bool is_ant_mode_sep, bool test_openThread, bool test_wifi,
		bool is_ot_client, bool is_wifi_conn_scan);

/**
 * @brief Function to test BLE connection central/peripheral stability with Wi-Fi throughput
 * (client/server) as interference
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int ot_connection_stability_wifi_tput_interference(bool test_wifi, bool test_openThread, bool is_ot_client,
	bool is_wifi_server, bool is_ant_mode_sep, bool is_wifi_zperf_udp);

/**
 * @brief Function to test BLE connection central/peripheral functionality with Wi-Fi shutdown
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int ot_connection_wifi_shutdown(bool is_ot_client);

/**
 * @brief Function to test BLE throughput central/peripheral functionality with Wi-Fi shutdown
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int ble_tput_wifi_shutdown(bool is_ot_client);

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

#endif /* MAIN_H_ */
