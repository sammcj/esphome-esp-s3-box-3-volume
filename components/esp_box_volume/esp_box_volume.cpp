#include "esphome.h"
#include "esp_box_volume.h"

namespace esphome
{
  namespace esp_box_volume
  {

    void VolumeController::setup()
    {
      // get the board handle from audio_hal_handle_t in the esp32_s3_box_3 project's board.h
      board_handle = audio_board_init();
    }

    void VolumeController::set_volume(int volume)
    {
      // set the volume using the board handle
      audio_hal_set_volume(board_handle, volume);
    }

  } // namespace esp_box_volume
} // namespace esphome
