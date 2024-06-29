# Volume Controls for the ESP S3 Box 3 in esphome

## Example Usage

```yaml
external_components:
  - source: github://sammcj/esphome-esp-s3-box-3-volume@main
    components: [esp_box_volume]
    refresh: always

esp_box_volume:
  id: speaker_volume

on_boot:
  then:
    - output.set_level:
        id: speaker_volume
        level: 0.85  # 85% volume
```

For the moment I've copied my fork of https://github.com/jesserockz/esp32-s3-box-3-board/tree/main/esp32_s3_box_3 into esp32_s3_box_3, this is not ideal and I will look to change this once my PR is merged upstream.

My esp s3 box 3 config files are here if it helps: https://github.com/sammcj/esphome-esp-s3-box-3
