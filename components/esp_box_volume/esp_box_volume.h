#pragma once

#include "esphome/core/component.h"
#include "esphome/components/output/float_output.h"

namespace esphome
{
  namespace esp_box
  {

    class ESPBoxVolume : public Component, public output::FloatOutput
    {
    public:
      void setup() override
      {
        // Initialization, if required
      }

      void write_state(float state) override
      {
        // Convert state (0.0 - 1.0) to volume level (0 - 100)
        int volume = static_cast<int>(state * 100.0);
        // Call your board's volume setting function here
        audio_board_set_volume(board_handle, volume);
      }
    };

  } // namespace esp_box
} // namespace esphome
