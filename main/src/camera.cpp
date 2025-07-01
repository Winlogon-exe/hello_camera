#include <camera.h>

esp_err_t Camera::cameraInit(const camera_config_t *config)
{
    esp_err_t err;
    err = esp_camera_init(config);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Camera init failed with error 0x%x", err);
        return err;
    }
}

void Camera::cameraConfig()
{
    esp_err_t err = cameraInit(getDefaultConfig());
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to init camera");
    }
    else
    {
        ESP_LOGI(TAG, "Camera initialized");
    }
}

const camera_config_t* Camera::getDefaultConfig()
{
    camera_config_t config;
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;
    config.pin_d0 = 5;
    config.pin_d1 = 18;
    config.pin_d2 = 19;
    config.pin_d3 = 21;
    config.pin_d4 = 36;
    config.pin_d5 = 39;
    config.pin_d6 = 34;
    config.pin_d7 = 35;
    config.pin_xclk = 0;
    config.pin_pclk = 22;
    config.pin_vsync = 25;
    config.pin_href = 23;
    config.pin_sscb_sda = 26;
    config.pin_sscb_scl = 27;
    config.pin_pwdn = 32;
    config.pin_reset = -1;
    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_JPEG;

    // Можно выбрать: FRAMESIZE_QVGA, SVGA, UXGA...
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 12; // от 0 (макс качество) до 63 (мин)
    config.fb_count = 1;
    
    return &config;
}
