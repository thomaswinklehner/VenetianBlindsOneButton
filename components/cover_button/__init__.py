import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor, cover
from esphome.const import CONF_ID

DEPENDENCIES = ["binary_sensor", "cover"]
MULTI_CONF = True

CONF_COVER_ID = "cover_id"
CONF_INPUT_ID = "input_id"
CONF_STOP_RELEASE_MAX = "stop_release_max"
CONF_GROUP_RELEASE_MIN = "group_release_min"

cover_button_ns = cg.esphome_ns.namespace("cover_button")
CoverButtonController = cover_button_ns.class_(
    "CoverButtonController", cg.Component
)


def _validate_press_times(config):
    stop_max = config[CONF_STOP_RELEASE_MAX].total_milliseconds
    group_min = config[CONF_GROUP_RELEASE_MIN].total_milliseconds
    if stop_max >= group_min:
        raise cv.Invalid(
            "stop_release_max must be shorter than group_release_min"
        )
    return config


CONFIG_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(CoverButtonController),
            cv.Required(CONF_COVER_ID): cv.use_id(cover.Cover),
            cv.Required(CONF_INPUT_ID): cv.use_id(binary_sensor.BinarySensor),
            cv.Optional(
                CONF_STOP_RELEASE_MAX, default="2s"
            ): cv.positive_time_period_milliseconds,
            cv.Optional(
                CONF_GROUP_RELEASE_MIN, default="5s"
            ): cv.positive_time_period_milliseconds,
        }
    ).extend(cv.COMPONENT_SCHEMA),
    _validate_press_times,
)


async def to_code(config):
    cg.add_global(
        cg.RawStatement(
            '#include "esphome/components/cover_button/cover_button.h"'
        )
    )
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    cover_var = await cg.get_variable(config[CONF_COVER_ID])
    input_var = await cg.get_variable(config[CONF_INPUT_ID])
    cg.add(var.set_cover(cover_var))
    cg.add(var.set_input(input_var))
    cg.add(var.set_stop_release_max(config[CONF_STOP_RELEASE_MAX]))
    cg.add(var.set_group_release_min(config[CONF_GROUP_RELEASE_MIN]))
