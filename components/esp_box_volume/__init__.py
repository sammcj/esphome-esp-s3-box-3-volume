import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import output
from esphome.const import CONF_ID

DEPENDENCIES = ['output']

esp_box_ns = cg.esphome_ns.namespace('esp_box')
ESPBoxVolume = esp_box_ns.class_('ESPBoxVolume', output.FloatOutput, cg.Component)

CONFIG_SCHEMA = output.FLOAT_OUTPUT_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(ESPBoxVolume),
})

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield output.register_output(var, config)
    yield cg.register_component(var, config)
