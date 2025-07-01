#include <chip_info.h>

void get_esp_info()
{
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);

    esp_info info;  
    info.major_rev = chip_info.revision / 100;
    info.minor_rev = chip_info.revision % 100;
    info.features = chip_info.features;
    print_esp_info(info,chip_info);
}

void print_esp_info(esp_info &info,esp_chip_info_t &chip_info)
{
    printf("This is %s chip with %d CPU core(s), %s%s%s%s, ",
           CONFIG_IDF_TARGET,
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
           (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");

    printf("silicon revision v%d.%d, ", info.major_rev, info.minor_rev);
    if (esp_flash_get_size(NULL, &info.flash_size) != ESP_OK)
    {
        printf("Get flash size failed");
        return;
    }

    printf("%" PRIu32 "MB %s flash\n", info.flash_size / (uint32_t)(1024 * 1024),
           (info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());

    for (int i = 10; i >= 0; i--)
    {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}