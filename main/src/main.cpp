/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <camera.h>

extern "C" void app_main() {
    Camera cam;
    cam.init_camera_config();
    cam.init_camera();
    cam.start_record_video();
}
