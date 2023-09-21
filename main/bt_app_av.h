/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#ifndef __BT_APP_AV_H__
#define __BT_APP_AV_H__

#include <stdint.h>
#include "esp_a2dp_api.h"
#include "esp_avrc_api.h"
#include "driver/gpio.h"

/* input control service */
#define GP0_IO    18
#define GP1_IO    19
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<GP0_IO) | (1ULL<<GP1_IO))
#define NEXT_IO      34
#define STOP_IO      35
#define PREVIOUS_IO  39
#define PLAY_PAUSE   36
#define VOLUP_IO     32
#define VOLDOWN_IO   33
#define GPIO_INPUT_PIN_SEL  ((1ULL<<NEXT_IO) | (1ULL<<STOP_IO)  | (1ULL<<VOLUP_IO) | (1ULL<<VOLDOWN_IO))
#define ESP_INTR_FLAG_DEFAULT 0


/* log tags */
#define BT_AV_TAG       "BT_AV"
#define BT_RC_TG_TAG    "RC_TG"
#define BT_RC_CT_TAG    "RC_CT"

/**
 * @brief  callback function for A2DP sink
 *
 * @param [in] event  event id
 * @param [in] param  callback parameter
 */
void bt_app_a2d_cb(esp_a2d_cb_event_t event, esp_a2d_cb_param_t *param);

/**
 * @brief  callback function for A2DP sink audio data stream
 *
 * @param [out] data  data stream writteen by application task
 * @param [in]  len   length of data stream in byte
 */
void bt_app_a2d_data_cb(const uint8_t *data, uint32_t len);

/**
 * @brief  callback function for AVRCP controller
 *
 * @param [in] event  event id
 * @param [in] param  callback parameter
 */
void bt_app_rc_ct_cb(esp_avrc_ct_cb_event_t event, esp_avrc_ct_cb_param_t *param);

/**
 * @brief  callback function for AVRCP target
 *
 * @param [in] event  event id
 * @param [in] param  callback parameter
 */
void bt_app_rc_tg_cb(esp_avrc_tg_cb_event_t event, esp_avrc_tg_cb_param_t *param);

/**
 * @brief  setup input control service
 *
 */
void bt_app_input_ctrl_service(void);

#endif /* __BT_APP_AV_H__*/
