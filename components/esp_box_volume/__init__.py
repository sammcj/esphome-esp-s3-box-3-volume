import esphome.codegen as cg
from esphome import automation
from esphome.components import esp32
from esphome.core import CORE, coroutine
from esphome.const import CONF_ID

# Import your C++ classes
esp_box_volume_ns = cg.esphome_ns.namespace('esp_box_volume')
EspBoxVolume = esp_box_volume_ns.class_('EspBoxVolume', cg.Component)

# Define configuration variables
CONFIG_SCHEMA = esp32.ESP_PLATFORM_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(EspBoxVolume),

}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
