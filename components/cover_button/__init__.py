import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor, cover
from esphome.const import CONF_ID

DEPENDENCIES = ["binary_sensor", "cover"]
MULTI_CONF = True

CONF_COVER_ID = "cover_id"
CONF_INPUT_ID = "input_id"
CONF_TILT_ENABLED = "tilt_enabled"
CONF_TILT_STEP = "tilt_step"
CONF_SHORT_PRESS_MAX = "short_press_max"
CONF_STOP_PRESS_MAX = "stop_press_max"
CONF_ALL_PRESS_MAX = "all_press_max"

cover_button_ns = cg.esphome_ns.namespace("cover_button")
CoverButtonController = cover_button_ns.class_(
    "CoverButtonController", cg.Component
)


def _validate_press_times(config):
    short_max = config[CONF_SHORT_PRESS_MAX].total_milliseconds
    stop_max = config[CONF_STOP_PRESS_MAX].total_milliseconds
    all_max = config[CONF_ALL_PRESS_MAX].total_milliseconds
    if not short_max < stop_max < all_max:
        raise cv.Invalid(
            "short_press_max, stop_press_max and all_press_max must increase"
        )
    return config


CONFIG_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(CoverButtonController),
            cv.Required(CONF_COVER_ID): cv.use_id(cover.Cover),
            cv.Required(CONF_INPUT_ID): cv.use_id(binary_sensor.BinarySensor),
            cv.Optional(CONF_TILT_ENABLED, default=False): cv.boolean,
            cv.Optional(CONF_TILT_STEP, default="10%"): cv.percentage,
            cv.Optional(
                CONF_SHORT_PRESS_MAX, default="1s"
            ): cv.positive_time_period_milliseconds,
            cv.Optional(
                CONF_STOP_PRESS_MAX, default="2s"
            ): cv.positive_time_period_milliseconds,
            cv.Optional(
                CONF_ALL_PRESS_MAX, default="5s"
            ): cv.positive_time_period_milliseconds,
        }
    ).extend(cv.COMPONENT_SCHEMA),
    _validate_press_times,
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    cover_var = await cg.get_variable(config[CONF_COVER_ID])
    input_var = await cg.get_variable(config[CONF_INPUT_ID])
    cg.add(var.set_cover(cover_var))
    cg.add(var.set_input(input_var))
    cg.add(var.set_tilt_enabled(config[CONF_TILT_ENABLED]))
    cg.add(var.set_tilt_step(config[CONF_TILT_STEP]))
    cg.add(var.set_short_press_max(config[CONF_SHORT_PRESS_MAX]))
    cg.add(var.set_stop_press_max(config[CONF_STOP_PRESS_MAX]))
    cg.add(var.set_all_press_max(config[CONF_ALL_PRESS_MAX]))
