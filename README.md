# Volume Controls for the ESP S3 Box 3 in esphome

## Example Usage

```yaml
external_components:
  - source: github://sammcj/esphome-esp-s3-box-3-volume@main
    components:
      - esp_box_volume
    refresh: 0s

output:
  - platform: custom
    type: float
    lambda: |-
      auto esp_box_volume = new esp_box::ESPBoxVolume();
      App.register_component(esp_box_volume);
      return {esp_box_volume};
    outputs:
      id: esp_box_volume_output

on_boot:
  then:
    - output.set_level:
        id: esp_box_volume_output
        level: 0.85  # 85% volume
```
