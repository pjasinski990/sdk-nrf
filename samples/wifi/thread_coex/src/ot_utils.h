/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef OT_UTILS_H_
#define OT_UTILS_H_

#include <stdint.h>
#include <stdbool.h>

#define TXPOWER_INIT_VALUE 127
#define RSSI_INIT_VALUE 127

/**
 * Initialize BLE throughput test
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int bt_throughput_test_init(bool is_ot_client);

/**
 * @brief Run BLE throughput test
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int bt_throughput_test_run(void);


/**
 * @brief Run OpenThread discovery test
 */
void ot_discovery_test_run(void);

/**
 * @brief Run OpenThread connection test
 */
void ot_conn_test_run(void);

/**
 * @brief Exit BLE throughput test
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int bt_throughput_test_exit(void);
/**
 * Initialize BLE scan --> connection test
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int ot_connection_init(bool is_ot_client);

/**
 * @brief Initialization for BT connection
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int bt_disconnect_central(void);

/**
 * @brief Start BLE advertisement
 *
 * @return None
 */
void adv_start(void);

/**
 * @brief Start BLE scan
 *
 * @return None
 */
void scan_start(void);

/**
 * @brief Read BLE RSSI
 *
 * @return None
 */
void read_conn_rssi(uint16_t handle, int8_t *rssi);

/**
 * @brief Set BLE Tx power
 *
 * @return None
 */
void set_tx_power(uint8_t handle_type, uint16_t handle, int8_t tx_pwr_lvl);

/**
 * @brief Get BLE Tx power
 *
 * @return None
 */
void get_tx_power(uint8_t handle_type, uint16_t handle, int8_t *tx_pwr_lvl);

//========================================================================================== Thread

/**
 * @brief Start OpenThread discovery
 *
 * @return None
 */
void ot_start_discovery(void);


/**
 * Initialize Thread throughput test
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int ot_initialization(bool is_thread_client);

/**
 * @brief Run Thread throughput test
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int thread_throughput_test_run(void);

/**
 * @brief Exit Thread throughput test
 *
 * @return Zero on success or (negative) error code otherwise.
 */
int ot_device_disable(void);

/**
 * @brief Check state of the thread device
 *
 * @return None.
 */
const char* ot_check_device_state(void);

#endif /* OT_UTILS_H_ */
