extern "C"
{
    #include <esp_camera.h>
    #include "esp_log.h"
}

static const char *TAG = "camera";

class Camera
{
private:


public:
    Camera();
    Camera(const Camera* copy) = delete;
    Camera(const Camera&& move) = delete;
public:
    esp_err_t cameraInit(const camera_config_t* connfig);
    void cameraConfig();
    const camera_config_t* getDefaultConfig();
};