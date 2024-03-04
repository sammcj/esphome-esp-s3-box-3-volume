# Volume Controls for the ESP S3 Box 3 in esphome

## Example Usage

```yaml
external_components:
  - source: github://sammcj/esphome-esp-s3-box-3-volume@main
    components: [esp_box_volume]
    refresh: always

output:
  - platform: esp_box_volume
    id: my_volume_control

on_boot:
  then:
    - output.set_level:
        id: my_volume_control
        level: 0.85  # 85% volume
```
