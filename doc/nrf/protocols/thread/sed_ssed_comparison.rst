.. _thread_sed_ssed:

SED vs SSED
###########

SED
***

SEDs are MTDs (Minimal Thread Devices) that sleep most of the time in order to minimize the power consumption. 
They communicate with the Thread network by occasionally polling the parent router for any pending data. 

Kconfig options for SED configuration are:

* :kconfig:option:`CONFIG_OPENTHREAD_POLL_PERIOD` configure polling period. Higher polling frequency results in lower latency (better responsiveness), but also higher power consumption.

Poll period can also be configured in runtime. See ``pollperiod`` command in OpenThread CLI: `<https://github.com/openthread/openthread/blob/main/src/cli/README.md#pollperiod>`_.

SSED
****

SSEDs are further optimized for power consumption. 
A Thread Synchronized Sleepy End Device (SSED) is synchronized with its parent router and uses the radio only at scheduled intervals, by using the Coordinated Sampled Listening (CSL) feature introduced as one of `Thread 1.2 Base Features`_.
During those intervals, the device waits for the router to send it any data related to the desired device activity.
This reduces the network traffic (no polling) and the power consumption (radio is off most of the time).
The SSED does require sending packets occasionally to keep synchronization with the router.
However, unlike a regular SED, an SSED does not actively communicate with the router by polling and goes into the idle mode in-between the scheduled activity periods.
If there is no application-related traffic for a longer period of time, the SSED sends a data poll request packet to synchronize with the parent.
Overall, the SSED features further reduce energy consumption of the device and generate less data traffic compared to a standard Thread SED.


The |NCS| provides several Kconfig options that let you enable CSL and tweak the CSL parameters. Some of those parameters directly affect power consumption of the device:

* :kconfig:option:`CONFIG_OPENTHREAD_CSL_RECEIVER` enable SSED child mode.
* :kconfig:option:`CONFIG_OPENTHREAD_CSL_AUTO_SYNC` enable CSL autosync.
* :kconfig:option:`CONFIG_OPENTHREAD_CSL_TIMEOUT` specifies the default CSL timeout in seconds and corresponds to the ``csl timeout`` cli parameter.
* :kconfig:option:`CONFIG_OPENTHREAD_CSL_CHANNEL` specifies the default CSL channel and corresponds to the ``csl channel`` cli parameter.
* :kconfig:option:`CONFIG_OPENTHREAD_CSL_RECEIVE_TIME_AHEAD` specifies CSL receiver wake up margin in microseconds. This parameter directly affects the size of receive window and thus - power consumption.
* :kconfig:option:`CONFIG_OPENTHREAD_MIN_RECEIVE_ON_AHEAD` specifies minimum receiving time before start of MAC header in microseconds. This parameter directly affects the size of receive window and thus - power consumption.
* :kconfig:option:`CONFIG_OPENTHREAD_MIN_RECEIVE_ON_AFTER` specifies minimum receiving time after start of MAC header in microseconds. This parameter directly affects the size of receive window and thus - power consumption.
* :kconfig:option:`CONFIG_OPENTHREAD_PLATFORM_CSL_UNCERT` specifies fixed uncertainty of the Device for scheduling CSL Transmissions in units of 10 microseconds. This parameter directly affects the size of receive window and thus - power consumption.

Aditionally, there is a csl period parameter that should be configured in order to enable CSL. See ``csl period`` command in OpenThread CLI: `<https://github.com/openthread/openthread/blob/main/src/cli/README.md#csl-period-period>`_.

For more on csl cli parameters, see ``csl`` command in OpenThread CLI: `<https://github.com/openthread/openthread/blob/main/src/cli/README.md#csl>`_.

SED vs SSED
##################################

As SSED creates no drawbacks for transmission and provides reduced power consumption and less traffic, it is recommended to configure your SED devices as SSEDs whenever possible.
You can see the difference in power consumption under this link: :ref:`Thread power consumption <thread_power_consumption>`.

SED vs SSED activity
********************

.. figure:: overview/images/thread_sed_ssed_comparison.svg
   :alt: Comparison of Thread SED and Thread SSED radio activity

   Comparison of Thread SED and Thread SSED radio activity

For more general information about thread device roles, see :ref:`Thread device roles <thread_roles>`.
