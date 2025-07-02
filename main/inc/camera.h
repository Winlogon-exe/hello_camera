extern "C"
{
    #include <esp_camera.h>
    #include "esp_log.h"
    #include "esp_mac.h"
    #include <freertos/mpu_wrappers.h>
    #include <freertos/projdefs.h>
    #include <freertos/FreeRTOS.h>
    #include "soc/rtc_cntl_reg.h"
}

class Camera
{
private:
    camera_config_t config;

public:
    Camera();
    Camera(const Camera&) = delete;
    Camera(const Camera&&) = delete;

    Camera& operator=(const Camera&) = delete;
    Camera& operator=(const Camera&&) = delete;

public:
    esp_err_t init_camera();
    void init_camera_config();
    static void start_record_video(void* pvParameters);
};