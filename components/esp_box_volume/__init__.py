import esphome.codegen as cg
from esphome import core
from esphome.core import coroutine_with_priority, CORE
from esphome import automation
import esphome.config_validation as cv
from esphome.const import CONF_ID

DEPENDENCIES = ['esp32']

esp_box_volume_ns = cg.esphome_ns.namespace('esp_box_volume')
EspBoxVolume = esp_box_volume_ns.class_('EspBoxVolume', cg.Component)

CONFIG_SCHEMA = cv.COMPONENT_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(EspBoxVolume),
    # Define your component's configuration options here
})

@coroutine_with_priority(100.0)
def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    # Setup actions or configurations specific to this component
