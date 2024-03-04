#pragma once

#include "esphome/core/component.h"
// include jesserockz/esp32-s3-box-3-board/esp32_s3_box_3/board.h
#include "esp32_s3_box_3/board.h"

namespace esphome
{
  namespace esp_box_volume
  {

    class VolumeController : public Component
    {
    public:
      void set_volume(int volume);
    };

  } // namespace esp_box_volume
} // namespace esphome
