#pragma once

#include "esphome/core/component.h"
#include "esphome/components/output/float_output.h"

namespace esphome
{
  namespace esp_box_volume
  {

    // define the component
    class ESPBoxVolume : public Component
    {
    public:
      void set_volume(float volume) { this->volume_service_->set_volume(volume); }

      void set_volume_service(ESPBoxVolumeService *volume_service) { this->volume_service_ = volume_service; }
    };

    // // expose a service for home assistant to use
    // class ESPBoxVolumeService : public Service
    // {
    // public:
    //   void set_volume(float volume) { static_cast<ESPBoxVolume *>(this->parent())->set_volume(volume); }
    // };

    // // define the output
    // class ESPBoxVolumeOutput : public output::FloatOutput, public ESPBoxVolume
    // {
    // public:
    //   void write_state(float state) override { this->set_volume(state); }
    // };

    // // define the output
    // class ESPBoxVolumeOutput : public output::FloatOutput, public ESPBoxVolume
    // {
    // public:
    //   void write_state(float state) override { this->set_volume(state); }
    // };

  } // namespace esp_box_volume
} // namespace esphome
