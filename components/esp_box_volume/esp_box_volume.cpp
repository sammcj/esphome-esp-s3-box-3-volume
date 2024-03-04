#include "esp_box_volume.h"
#include "esphome/core/log.h"
#include "../esp32_s3_box_3/board.h"

namespace esphome
{
  namespace esp_box_volume
  {

    static const char *const TAG = "esp_box_volume";

    void ESPBoxVolume::set_volume(float volume)
    {
      int vol = static_cast<int>(volume * 100.0);
      ESP_LOGD(TAG, "Setting volume to: %d", vol);
      audio_board_handle_t board_handle = audio_board_get_handle();
      if (!board_handle)
      {
        ESP_LOGE(TAG, "Invalid board handle, cannot set volume");
        return;
      }
      esp_err_t result = audio_board_set_volume(board_handle, vol);
      if (result != ESP_OK)
      {
        ESP_LOGE(TAG, "Failed to set volume, error: %d", result);
      }

      // update the state of the output
      this->publish_state(volume);

      // update the state of the service
      if (this->volume_service_)
      {
        this->volume_service_->publish_state(volume);
      }
    }

    void ESPBoxVolume::set_volume_service(ESPBoxVolumeService *volume_service)
    {
      this->volume_service_ = volume_service;
    }

    void ESPBoxVolumeService::set_volume(float volume)
    {
      static_cast<ESPBoxVolume *>(this->parent())->set_volume(volume);
    }

    void ESPBoxVolumeOutput::write_state(float state)
    {
      this->set_volume(state);
    }

  } // namespace esp_box_volume
} // namespace esphome
