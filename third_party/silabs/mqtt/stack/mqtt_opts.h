/**
 * @file
 * MQTT client options
 */

/*
 * Copyright (c) 2016 Erik Andersson
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Erik Andersson
 *
 */
#ifndef MQTT_OPTS_H
#define MQTT_OPTS_H

//#include "lwip/opt.h"

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * @defgroup mqtt_opts Options
 * @ingroup mqtt
 * @{
 */
#define MQTT_DEBUG  0x0
/**
 * Output ring-buffer size, must be able to fit largest outgoing publish message topic+payloads
 */
#define MQTT_OUTPUT_RINGBUF_SIZE 256

/**
 * Number of bytes in receive buffer, must be at least the size of the longest incoming topic + 8
 * If one wants to avoid fragmented incoming publish, set length to max incoming topic length + max payload length + 8
 */

#define MQTT_VAR_HEADER_BUFFER_LEN 128

/**
 * Maximum number of pending subscribe, unsubscribe and publish requests to server .
 */

#define MQTT_REQ_MAX_IN_FLIGHT 4

/**
 * Seconds between each cyclic timer call.
 */

#define MQTT_CYCLIC_TIMER_INTERVAL 5

/**
 * Publish, subscribe and unsubscribe request timeout in seconds.
 */

#define MQTT_REQ_TIMEOUT 30

/**
 * Seconds for MQTT connect response timeout after sending connect request
 */

#define MQTT_CONNECT_TIMOUT 100

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* LWIP_HDR_APPS_MQTT_OPTS_H */