#include <camera.h>

Camera::Camera()
{
}

esp_err_t Camera::init_camera()
{
    init_camera_config();

    esp_err_t err;
    err = esp_camera_init(&config);

    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Camera init failed with error 0x%x", err);
        return err;
    }
    ESP_LOGI(TAG, "Camera initialized");
    return ESP_OK;
}

void Camera::init_camera_config()
{
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;
    config.pin_d0 = GPIO_NUM_5;
    config.pin_d1 = GPIO_NUM_18;
    config.pin_d2 = GPIO_NUM_19;
    config.pin_d3 = GPIO_NUM_21;
    config.pin_d4 = GPIO_NUM_36;
    config.pin_d5 = GPIO_NUM_39;
    config.pin_d6 = GPIO_NUM_34;
    config.pin_d7 = GPIO_NUM_35;
    config.pin_xclk = GPIO_NUM_0;
    config.pin_pclk = GPIO_NUM_22;
    config.pin_vsync = GPIO_NUM_25;
    config.pin_href = GPIO_NUM_23;
    config.pin_sccb_sda = GPIO_NUM_26;
    config.pin_sccb_scl = GPIO_NUM_27;
    config.pin_pwdn = GPIO_NUM_32;
    config.pin_reset = -1;
    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_JPEG;
    config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;

    // Можно выбрать: FRAMESIZE_QVGA, SVGA, UXGA...
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 12; // от 0 (макс качество) до 63 (мин)
    config.fb_count = 1;
}

void Camera::capture_frame()
{
    camera_fb_t* fb = esp_camera_fb_get();
    if(!fb)
    {
        ESP_LOGE(TAG,"Camera capture failed");
        return;
    }

    ESP_LOGI(TAG,"Captured Frames: %zu bytes",fb -> len);
    ESP_LOGI(TAG, "Header: 0x%02X 0x%02X", fb->buf[0], fb->buf[1]);
    esp_camera_fb_return(fb);
}
