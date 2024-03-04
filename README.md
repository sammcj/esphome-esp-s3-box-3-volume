# Volume Controls for the ESP S3 Box 3 in esphome

## Example Usage

```yaml
external_components:
  - source: github://sammcj/esphome-esp-s3-box-3-volume@main
    components:
      - esp_box_volume
    refresh: 0s

esp_box_volume:
  volume: 85  # Set desired volume level here
```
