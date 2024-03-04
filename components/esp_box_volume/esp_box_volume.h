#pragma once

#include "esphome/core/component.h"

namespace esphome
{
  namespace esp_box_volume
  {

    // define the component
    class ESPBoxVolume : public Component
    {
    public:
      void set_volume(float volume);
    };

    // expose a service for home assistant to use
    class ESPBoxVolumeService : public Service
    {
    public:
      void set_volume(float volume) { static_cast<ESPBoxVolume *>(this->parent())->set_volume(volume); }
    };

  } // namespace esp_box_volume
} // namespace esphome
