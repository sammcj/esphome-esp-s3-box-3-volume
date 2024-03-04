#pragma once

#include "esphome/core/component.h"

namespace esphome
{
  namespace esp_box_volume
  {

    class ESPBoxVolume : public Component
    {
    public:
      void set_volume(float volume);
    };

  } // namespace esp_box_volume
} // namespace esphome
