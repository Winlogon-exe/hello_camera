#pragma once

// ==== Пины подключения камеры (ESP32-CAM с OV2640) ====
#define CAM_PIN_PWDN       32
#define CAM_PIN_RESET      -1  // Не используется
#define CAM_PIN_XCLK       0
#define CAM_PIN_SIOD       26
#define CAM_PIN_SIOC       27

#define CAM_PIN_D0         5
#define CAM_PIN_D1         18
#define CAM_PIN_D2         19
#define CAM_PIN_D3         21
#define CAM_PIN_D4         36
#define CAM_PIN_D5         39
#define CAM_PIN_D6         34
#define CAM_PIN_D7         35

#define CAM_PIN_VSYNC      25
#define CAM_PIN_HREF       23
#define CAM_PIN_PCLK       22

// ==== Настройки камеры ====
#define CAM_XCLK_FREQ_HZ      10000000  // Можно поднять до 20000000
#define CAM_PIXEL_FORMAT      PIXFORMAT_GRAYSCALE  // FRAMESIZE_QVGA  = 320x240
#define CAM_FRAME_SIZE        FRAMESIZE_QVGA       // FRAMESIZE_96X96 = 96x96
#define CAM_FB_COUNT          1
#define CAM_GRAB_MODE         CAMERA_GRAB_WHEN_EMPTY
