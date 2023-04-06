// Copyright (c) 2022 XMOS LIMITED. This Software is subject to the terms of the
// XMOS Public License: Version 1

#ifndef TUSB_CONFIG_H_
#define TUSB_CONFIG_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "app_conf.h"
#include "rtos_printf.h"

//--------------------------------------------------------------------
// COMMON CONFIGURATION
//--------------------------------------------------------------------

#define CFG_TUSB_RHPORT0_MODE      (OPT_MODE_DEVICE | OPT_MODE_FULL_SPEED)
#define CFG_TUSB_OS                OPT_OS_CUSTOM

#ifndef CFG_TUSB_DEBUG
#define CFG_TUSB_DEBUG             0
#endif

#define CFG_TUSB_MEM_ALIGN         __attribute__ ((aligned(8)))

#ifndef CFG_TUSB_DEBUG_PRINTF
#ifdef rtos_printf
#define CFG_TUSB_DEBUG_PRINTF      rtos_printf
#endif
#endif

//--------------------------------------------------------------------
// DEVICE CONFIGURATION
//--------------------------------------------------------------------

#define CFG_TUD_EP_MAX            12
#define CFG_TUD_TASK_QUEUE_SZ     8
#define CFG_TUD_ENDPOINT0_SIZE    64

#define CFG_TUD_XCORE_INTERRUPT_CORE     appconfUSB_INTERRUPT_CORE
#define CFG_TUD_XCORE_SOF_INTERRUPT_CORE appconfUSB_SOF_INTERRUPT_CORE
#define CFG_TUD_XCORE_IO_CORE_MASK       (1 << appconfXUD_IO_CORE)

//------------- CLASS -------------//
#define CFG_TUD_DFU               1
#define CFG_TUD_CDC               2
#define CFG_TUD_MSC               0
#define CFG_TUD_HID               0
#define CFG_TUD_MIDI              0
#define CFG_TUD_VENDOR            0

// DFU buffer size, it has to be set to the buffer size used in TUD_DFU_DESCRIPTOR
#define CFG_TUD_DFU_XFER_BUFSIZE    4096

// CDC FIFO size of TX and RX
#define CFG_TUD_CDC_RX_BUFSIZE   (TUD_OPT_HIGH_SPEED ? 512 : 64)
#define CFG_TUD_CDC_TX_BUFSIZE   (TUD_OPT_HIGH_SPEED ? 512 : 64)

// CDC Endpoint transfer buffer size, more is faster
#define CFG_TUD_CDC_EP_BUFSIZE   (TUD_OPT_HIGH_SPEED ? 512 : 64)

#ifdef __cplusplus
 }
#endif

#endif /* TUSB_CONFIG_H_ */
