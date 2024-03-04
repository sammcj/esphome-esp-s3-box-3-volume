# Add these imports at the top
from esphome import automation
import esphome.config_validation as cv
from esphome.const import CONF_ID

# Add a configuration key for the service
CONF_SET_VOLUME = "set_volume"
CONF_VOLUME_LEVEL = "level"

# Update CONFIG_SCHEMA to include the custom service
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ESPBoxVolume),
    cv.Optional(CONF_SET_VOLUME): automation.validate_automation({
        cv.GenerateID(CONF_VOLUME_LEVEL): cv.use_id(ESPBoxVolume),
        cv.Required(CONF_VOLUME_LEVEL): cv.templatable(cv.percentage),
    }),
}).extend(cv.COMPONENT_SCHEMA)

# Modify to_code to register the custom service
def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)

    for conf in config.get(CONF_SET_VOLUME, []):
        trigger = cg.new_Pvariable(conf[CONF_VOLUME_LEVEL], var)
        yield automation.build_automation(trigger, [(float, "x")], conf[CONF_VOLUME_LEVEL])
