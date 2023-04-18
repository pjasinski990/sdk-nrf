.. _thread_sed_ssed:

SED vs SSED
###########

SED
***

SEDs are MTDs (Minimal Thread Devices) that sleep most of the time in order to minimize the power consumption. 
They communicate with the Thread network by occasionally polling the parent router for any pending data. 

Important kconfig options for SEDs are:

* :kconfig:option:`CONFIG_OPENTHREAD_MTD_SED` enable SED
* :kconfig:option:`CONFIG_OPENTHREAD_POLL_PERIOD` configure polling period. Higher polling frequency results in lower latency (better responsiveness), but also higher power consumption.

Poll period can olso be configured in runtime. See ``pollperiod`` command in OpenThread CLI: `<https://github.com/openthread/openthread/blob/main/src/cli/README.md#pollperiod>`_.

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

CSL parameters can be configured in runtime. See ``csl`` command in OpenThread CLI: `<https://github.com/openthread/openthread/blob/main/src/cli/README.md#csl>`_.

SED vs SSED activity
####################

.. figure:: overview/images/thread_sed_ssed_comparison.svg
   :alt: Comparison of Thread SED and Thread SSED radio activity

   Comparison of Thread SED and Thread SSED radio activity

For more general information about thread device roles, see :ref:`Thread device roles <thread_roles>`.
