#pragma once

#include "esphome/core/component.h"
#include "esphome/components/output/float_output.h"

namespace esphome
{
  namespace esp_box_volume
  {

    class ESPBoxVolume : public Component, public output::FloatOutput
    {
    public:
      void write_state(float state) override;
    };

  } // namespace esp_box_volume
} // namespace esphome
