#pragma once

#include "esphome/core/component.h"

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
