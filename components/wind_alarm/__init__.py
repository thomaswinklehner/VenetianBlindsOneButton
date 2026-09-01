import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_ID

DEPENDENCIES = ["binary_sensor", "cover_button"]

CONF_INPUT_ID = "input_id"
CONF_ACTIVE_LOW = "active_low"

wind_alarm_ns = cg.esphome_ns.namespace("wind_alarm")
WindAlarmController = wind_alarm_ns.class_(
    "WindAlarmController", cg.Component
)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(WindAlarmController),
        cv.Required(CONF_INPUT_ID): cv.use_id(binary_sensor.BinarySensor),
        cv.Optional(CONF_ACTIVE_LOW, default=True): cv.boolean,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    cg.add_global(
        cg.RawStatement(
            '#include "esphome/components/wind_alarm/wind_alarm.h"'
        )
    )
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    input_var = await cg.get_variable(config[CONF_INPUT_ID])
    cg.add(var.set_input(input_var))
    cg.add(var.set_active_low(config[CONF_ACTIVE_LOW]))
