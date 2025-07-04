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
    return ESP_OK;
}

void Camera::init_camera_config()
{
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;

    config.pin_d0 = CAM_PIN_D0;
    config.pin_d1 = CAM_PIN_D1;
    config.pin_d2 = CAM_PIN_D2;
    config.pin_d3 = CAM_PIN_D3;
    config.pin_d4 = CAM_PIN_D4;
    config.pin_d5 = CAM_PIN_D5;
    config.pin_d6 = CAM_PIN_D6;
    config.pin_d7 = CAM_PIN_D7;

    config.pin_xclk = CAM_PIN_XCLK;
    config.pin_pclk = CAM_PIN_PCLK;
    config.pin_vsync = CAM_PIN_VSYNC;
    config.pin_href = CAM_PIN_HREF;
    config.pin_sccb_sda = CAM_PIN_SIOD;
    config.pin_sccb_scl = CAM_PIN_SIOC;
    config.pin_pwdn = CAM_PIN_PWDN;
    config.pin_reset = CAM_PIN_RESET;

    config.xclk_freq_hz = CAM_XCLK_FREQ_HZ;
    config.pixel_format = CAM_PIXEL_FORMAT;
    config.frame_size = CAM_FRAME_SIZE;
    config.fb_count = CAM_FB_COUNT;
    config.grab_mode = CAM_GRAB_MODE;
}

void Camera::start_record_video()
{
    ESP_LOGI(TAG, "Start Video Capture");
    while (true)
    {
        camera_fb_t *fb = esp_camera_fb_get();
        if (!fb)
        {
            ESP_LOGE(TAG, "Camera capture failed");
            vTaskDelay(pdMS_TO_TICKS(1000));
            break;
        }

        ESP_LOGD(TAG, "Grayscale frame: %zu bytes (%dx%d)", fb->len, fb->width, fb->height);
        render_ascii_frame(fb);
        esp_camera_fb_return(fb);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void Camera::render_ascii_frame(const camera_fb_t *fb)
{
    const uint8_t *buf = fb->buf; // указатель на массив пикселей
    int width = fb->width;
    int height = fb->height;

    for (int y = 0; y < height; y += 2)
    { 
        for (int x = 0; x < width; ++x)
        {
            uint8_t pixel = buf[y * width + x];
            int index = (pixel * (levels - 1)) / 255;
            putchar(asciiRamp[index]);
        }
        putchar('\n');
    }
    printf("\n\n");
}

