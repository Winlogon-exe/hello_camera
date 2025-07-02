#include <camera.h>
static const char *TAG = "camera";

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
    xTaskCreatePinnedToCore(start_record_video, "start_record_video", 4096, NULL, 5, NULL, 1);

    ESP_LOGI(TAG, "Camera start_video");
    return ESP_OK;
}

void Camera::init_camera_config()
{
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
    config.pin_sccb_sda = 26;
    config.pin_sccb_scl = 27;
    config.pin_pwdn = 32;
    config.pin_reset = -1;

    config.xclk_freq_hz = 10000000;                  
    config.pixel_format = PIXFORMAT_GRAYSCALE;      
    config.frame_size = FRAMESIZE_QVGA;           
    config.fb_count = 1;                           
    config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
}

void Camera::start_record_video(void* pvParameters)
{
    while(true)
    {
        camera_fb_t* fb = esp_camera_fb_get();
        if(!fb)
        {
            ESP_LOGE(TAG,"Camera capture failed");
            vTaskDelay(pdMS_TO_TICKS(1000));
            continue;
        }
        ESP_LOGI(TAG, "Grayscale frame: %zu bytes (%dx%d)", fb->len, fb->width, fb->height);
        esp_camera_fb_return(fb);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
