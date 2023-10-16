/**
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/** @file
 * @brief SR coexistence sample test bench
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "main.h"
#include <nrfx_clock.h>

#include <zephyr/logging/log.h>
#include "thread_utils.h"

LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);

/* to check if the OT device role is as expected */
char* ot_state                   = "router"; /* set to "leader" or "router"*/
uint32_t ot_state_chk_iteration  = 0;
uint32_t total_duration_to_check = 60; /* seconds */
uint32_t time_gap_between_checks = 5; /* seconds */
uint32_t max_iterations          = 1;
uint32_t ret_strcmp              = 1; /* set to non-zero */
bool is_ot_state_matched         = false;
uint32_t test_idle_time          = 600; /* seconds */
int main(void)
{
	thread_throughput_test_init(false);
	
	/*k_sleep(K_SECONDS(3));*/
	
	/*LOG_INF("Waiting for OT discover to complete");*/
	/*while (1) {*/
		/*if (is_ot_discovery_done) {*/
			/*break;*/
		/*} */
	/*}*/
	/*LOG_INF("OT discover complete");*/

	/*[> check OT device state periodically until the expected state is found <]*/
	/*max_iterations = total_duration_to_check/time_gap_between_checks;	*/
	/*LOG_INF("Check OT device state for every %d seconds..", time_gap_between_checks);*/
	/*LOG_INF("until the expected state is found (or) timeout of %d seconds", total_duration_to_check);*/
	
	/*LOG_INF("OT device expected state %s", ot_state);*/
	/*while(1) {*/
		/*ot_state_chk_iteration++;*/
		/*[> LOG_INF("ot_state_chk_iteration: %d",ot_state_chk_iteration); <]*/
		/*ret_strcmp = strcmp(ot_state, check_ot_state());*/

		/*[> exit when OT device role matches the expected state (or) timeout <]*/
		/*if (ret_strcmp == 0) {*/
			/*is_ot_state_matched = true;*/
			/*break;*/
		/*}*/
		/*if (ot_state_chk_iteration >= max_iterations) {*/
			/*is_ot_state_matched = false;*/
			/*break;*/
		/*}*/
		/*k_sleep(K_SECONDS(time_gap_between_checks));	*/
	/*}	*/
	/*if (is_ot_state_matched == true) {*/
		/*LOG_INF("OT device state matched with the expected role");*/
	/*} else {*/
		/*LOG_ERR("OT device state NOT matched with the expected role");*/
	/*}*/

	/*k_sleep(K_SECONDS(3));*/
	/*thread_throughput_test_exit();*/
	/*LOG_INF("exiting the test after open thread discovery");*/

	return 0;
}
