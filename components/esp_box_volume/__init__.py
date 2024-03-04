import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from esphome.codegen import void

esp_box_volume_ns = cg.esphome_ns.namespace('esp_box_volume')
ESPBoxVolume = esp_box_volume_ns.class_('ESPBoxVolume', cg.Component)

# Define the service within the component
set_volume = ESPBoxVolume.add_method('set_volume', void, [(float, 'volume')])

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ESPBoxVolume),
    # Define a schema for the service call, if needed
    cv.Optional("default_volume"): cv.percentage,
}).extend(cv.COMPONENT_SCHEMA)

# Declare the ID for the component
CONF_ESP_BOX_VOLUME_ID = 'esp_box_volume_id'

# Service definition
def set_volume_args(var, config):
    arg = config['volume']
    template_ = yield cg.templatable(arg, var, cg.float_)
    cg.add(var.set_volume(template_))

# Register the service
@ESPBoxVolume.register_service('set_volume', 'float')
def set_volume(var, config):
    yield set_volume_args(var, config)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ESPBoxVolume),
    cv.GenerateID(CONF_ESP_BOX_VOLUME_ID): cv.use_id(ESPBoxVolume),
    # Additional configurations here
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
