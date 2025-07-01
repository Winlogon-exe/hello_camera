#pragma once

extern "C"
{
    #include <stdio.h>
    #include <inttypes.h>
    #include "sdkconfig.h"
    #include "freertos/FreeRTOS.h"
    #include "freertos/task.h"
    #include "esp_chip_info.h"
    #include "esp_flash.h"
    #include "esp_mac.h"
    #include "esp_system.h"
}

struct esp_info
{
    unsigned major_rev;
    unsigned minor_rev;
    uint32_t flash_size;
    uint32_t features; 
};

void print_esp_info(esp_info &info,esp_chip_info_t &chip_info);
void get_esp_info();