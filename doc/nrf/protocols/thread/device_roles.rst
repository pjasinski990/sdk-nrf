.. _thread_roles:

Thread device roles
###############################

.. contents::
   :local:
   :depth: 2

This page describes roles of Thread devices and how to configure them in the |NCS|.
For additional information about Thread device roles, visit the 
`OpenThread documentation <https://openthread.io/guides/thread-primer/node-roles-and-types>`_.

.. _thread_roles_overview:

Roles overview
**************

The main division of Thread devices is based on their ability exist in a network without a parent.
The main difference is whether the device maintains a routing table (doesn't need a parent) or not (needs a parent).
Thread devices can be either Full Thread Devices (FTD) or Minimal End Devices (MTD). FTDs maintain a routing table, 
while MTDs do not and forward all their messages to parent instead.

Other role separation that can be made is based on the device's ability to route messages. We can divide thread devices 
into Routers and End Devices. Routers can route messages, while End Devices cannot. FTDs can be either Routers or End Devices,
while MTDs can only be End Devices. Only Routers can function as parents.

.. _thread_ftd:

Full Thread Devices
===================

In order to maintain the routing table, FTDs keep their radio on at all times. An important difference between FTDs and MTDs 
is that the former subscribe to special "all-routers" multicast addresses (ff02::2 and ff03::2, see `IPv6 multicast addressing <https://openthread.io/guides/thread-primer/ipv6-addressing#multicast>`_). 
Because of those reasons, typically, they consume more power than MTDs (which can turn their radio off to save power).

Full Thread Devices can be further divided into three categories:

* Router
* Router Eligible End Device (REED)
* Full End Device (FED)

Routers can be regarded as the backbone of a Thread network. They maintain the routing table and forward messages to other devices.
A router is required for a MED to join the network. Routers can also be used to extend the network range (unlike End Devices).

Routers and REEDs have routing capabilities, while FEDs do not.
REEDs function similar to FEDs, but they can become Routers if needed - if a REED is the only device in range of an End Device trying to join 
the network (see `network joining <https://openthread.io/guides/thread-primer/network-discovery#join_an_existing_network>`_), 
it will promote itself to a Router. Conversely, when a Router has no children it can downgrade itself to a REED.

FEDs don't require a parent to function, but they can't become parents (Routers) themselves.

.. _thread_mtd:

Minimal Thread Devices
======================

Minimal Thread Devices (MTDs) are devices that do not maintain a routing table. They are typically low-power devices that
are not always on. They can only be End Devices, and they always need a parent to function. They forward all their messages to their parent.

Minimal Thread Devices can be further divided into three categories:

* Minimal End Device (MED)
* Sleepy End Device (SED)
* Synchonized Sleepy End Device (SSED)

MEDs are the most basic MTDs. They operate analogically to FEDs, but they don't keep a routing table. MEDs radio is always on.

SEDs try to limit their power consumption by sleeping most of the time. They wake up periodically to poll for messages from their parent.
After waking up, they send a data request to their parent. If the parent has any pending messages, it will send them to the SED.
In other case, the parent will send a "no pending messages" response.

SSEDs operate similarly to Sleepy End Devices, but they are synchronized with their parent. They wake up at the same time as their parent, 
eliminating the need for polling for messages. If the parent has messages for the SSED, it sends them during the designated transmission window. 
The SED will allow the transmission to finish if a radio activity is detected during the transmission window.
Conversely, if there is no radio activity during the specified transmission window duration (indicating the parent has no messages for the SSED), 
the SSED returns to sleep. This synchronization results in lower power consumption, primarily because the SSED doesn't need to poll for messages, 
thereby keeping transmission windows short. To see more information about SSED activity, visit :ref:`thread_sed_ssed`.


.. _thread_roles_configuring:

Roles configuration
*******************
See :ref:`thread_ug_device_type` for information about how to configure Thread device type.
