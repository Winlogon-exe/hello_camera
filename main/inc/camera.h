extern "C"
{
#include <esp_camera.h>
#include "esp_log.h"
#include "esp_mac.h"
#include <freertos/mpu_wrappers.h>
#include <freertos/projdefs.h>
#include "soc/rtc_cntl_reg.h"
}

static const char *TAG = "camera";

class Camera
{
private:
    camera_config_t config;

public:
    Camera();
    Camera(const Camera *copy) = delete;
    Camera(const Camera &&move) = delete;

public:
    esp_err_t init_camera();
    void init_camera_config();
    void capture_frame();
};