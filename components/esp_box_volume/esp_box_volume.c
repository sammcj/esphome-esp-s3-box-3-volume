#include "esp_box_volume.h"
#include "esphome/core/log.h"
#include "board.h" // Make sure this path is correct

namespace esphome
{
  namespace esp_box
  {

    static const char *const TAG = "esp_box.volume";

    void ESPBoxVolume::write_state(float state)
    {
      // Convert state (0.0 - 1.0) to volume level (0 - 100)
      int volume = static_cast<int>(state * 100.0);
      ESP_LOGD(TAG, "Setting volume to: %d", volume);

      // Use audio_board_get_handle() to get the board handle
      audio_board_handle_t board_handle = audio_board_get_handle();
      if (!board_handle)
      {
        ESP_LOGE(TAG, "Invalid board handle, cannot set volume");
        return;
      }

      // Now call the function to set the volume
      esp_err_t result = audio_board_set_volume(board_handle, volume);
      if (result != ESP_OK)
      {
        ESP_LOGE(TAG, "Failed to set volume, error: %d", result);
      }
    }

  } // namespace esp_box
} // namespace esphome
