/****************************************************************************
Copyright 2023 Michele Balistreri

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
****************************************************************************/

#include "uni_platform_robottino.h"

#ifndef CONFIG_IDF_TARGET_ESP32
#error "This file can only be compiled for ESP32"
#endif  // CONFIG_IDF_TARGET_ESP32

static void robottino_init(int argc, const char** argv) {
    ARG_UNUSED(argc);
    ARG_UNUSED(argv);
}

static void robottino_on_init_complete(void) {
}

static void robottino_on_device_connected(uni_hid_device_t* d) {
}

static void robottino_on_device_disconnected(uni_hid_device_t* d) {
}

static int robottino_on_device_ready(uni_hid_device_t* d) {
    return 0;
}

static void robottino_on_controller_data(uni_hid_device_t* d, uni_controller_t* ctl) {
}

static void robottino_on_oob_event(uni_platform_oob_event_t event, void* data) {
    ARG_UNUSED(event);
    ARG_UNUSED(data);
}

static int32_t robottino_get_property(uni_platform_property_t key) {
    // FIXME: support well-known uni_platform_property_t keys
    return 0;
}

struct uni_platform* uni_platform_robottino_create(void) {
    static struct uni_platform plat = {
        .name = "Robottino",
        .init = robottino_init,
        .on_init_complete = robottino_on_init_complete,
        .on_device_connected = robottino_on_device_connected,
        .on_device_disconnected = robottino_on_device_disconnected,
        .on_device_ready = robottino_on_device_ready,
        .on_oob_event = robottino_on_oob_event,
        .on_controller_data = robottino_on_controller_data,
        .get_property = robottino_get_property,
    };

    return &plat;
}
