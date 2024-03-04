import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from esphome.core import CORE

esp_box_volume_ns = cg.esphome_ns.namespace('esp_box_volume')
EspBoxVolume = esp_box_volume_ns.class_('EspBoxVolume', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(EspBoxVolume),
    cv.Optional('volume', default=85): cv.All(cv.int_range(min=0, max=100), cv.Coerce(int)),
}).extend(cv.COMPONENT_SCHEMA)
