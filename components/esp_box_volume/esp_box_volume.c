#include "esp_box_volume.h"
#include "esphome/core/log.h"
#include "board.h"

namespace esphome
{
  namespace esp_box_volume
  {

    static const char *const TAG = "esp_box_volume";

    void ESPBoxVolume::write_state(float state)
    {
      int volume = static_cast<int>(state * 100.0);
      ESP_LOGD(TAG, "Setting volume to: %d", volume);
      // Adjust this to match how your board library sets volume
      your_board_library_set_volume(volume);
    }

  } // namespace esp_box_volume
} // namespace esphome
