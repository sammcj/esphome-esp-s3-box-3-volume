import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import output
from esphome.const import CONF_ID
from . import ESPBoxVolume


# Correct namespace matching your C++ namespace
esp_box_volume_ns = cg.esphome_ns.namespace('esp_box_volume')
# Declaration of your class within the namespace
ESPBoxVolume = esp_box_volume_ns.class_('ESPBoxVolume', cg.Component)

# add the service to the namespace
set_volume = esp_box_volume_ns.service('set_volume')
set_volume_level = set_volume.template(cg.float)

# Add the service to the class
ESPBoxVolume.add(set_volume_level)

# Add the service to the component
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ESPBoxVolume),
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)

    cg.add(var.set_volume_level.set_service(set_volume_level))
    yield output.register_output(var, config)

    # Add the service to the component
    cg.add(set_volume_level.set_component(var))

    # Add the service to the class
    cg.add(set_volume_level.set_callback(var.set_volume_level_callback))
