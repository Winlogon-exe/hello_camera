extern "C"
{
#include <esp_camera.h>
#include <esp_log.h>
#include <esp_mac.h>
#include <freertos/mpu_wrappers.h>
#include <freertos/projdefs.h>
#include <freertos/FreeRTOS.h>
#include <soc/rtc_cntl_reg.h>
#include <proj_macros.h>
#include <span>
}

class Camera
{
private:
    camera_config_t config;
    const int levels = 10;
    const char *asciiRamp = " .:-=+*#%@"; // От тёмного к яркому

public:
    Camera();

public:
    esp_err_t init_camera();
    void init_camera_config();
    void start_record_video();
    void render_ascii_frame(const camera_fb_t *fb);
};