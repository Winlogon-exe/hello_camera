set(SOURCES
    "src/main.cpp"
    "src/chip_info.cpp"
    "src/camera.cpp"
    "src/video_sender.cpp"
)

set(INCLUDES
    "inc"
)

set(EXTRA_COMPONENT_DIRS components/esp32-camera)

idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS ${INCLUDES}
    REQUIRES esp32-camera
    PRIV_REQUIRES spi_flash
)

