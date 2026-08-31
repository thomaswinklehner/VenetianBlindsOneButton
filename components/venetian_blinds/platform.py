import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import automation
from esphome.components import cover
from esphome.const import (
    CONF_ASSUMED_STATE,
    CONF_CLOSE_ACTION,
    CONF_CLOSE_DURATION,
    CONF_OPEN_ACTION,
    CONF_OPEN_DURATION,
    CONF_STOP_ACTION,
)

DEPENDENCIES = ["cover"]

CONF_TILT_DURATION = "tilt_duration"
CONF_ACTUATOR_ACTIVATION_DURATION = "actuator_activation_duration"

venetian_blinds_ns = cg.esphome_ns.namespace("venetian_blinds")
VenetianBlinds = venetian_blinds_ns.class_(
    "VenetianBlinds", cover.Cover, cg.Component
)


def _validate_durations(config):
    overhead = (
        config[CONF_TILT_DURATION].total_milliseconds
        + config[CONF_ACTUATOR_ACTIVATION_DURATION].total_milliseconds
    )
    if config[CONF_OPEN_DURATION].total_milliseconds <= overhead:
        raise cv.Invalid(
            "open_duration must be longer than tilt_duration plus "
            "actuator_activation_duration"
        )
    if config[CONF_CLOSE_DURATION].total_milliseconds <= overhead:
        raise cv.Invalid(
            "close_duration must be longer than tilt_duration plus "
            "actuator_activation_duration"
        )
    return config


CONFIG_SCHEMA = cv.All(
    cover.cover_schema(VenetianBlinds)
    .extend(
        {
            cv.Required(CONF_OPEN_ACTION): automation.validate_automation(
                single=True
            ),
            cv.Required(CONF_OPEN_DURATION): cv.positive_time_period_milliseconds,
            cv.Required(CONF_CLOSE_ACTION): automation.validate_automation(
                single=True
            ),
            cv.Required(CONF_CLOSE_DURATION): cv.positive_time_period_milliseconds,
            cv.Required(CONF_STOP_ACTION): automation.validate_automation(
                single=True
            ),
            cv.Required(CONF_TILT_DURATION): cv.positive_time_period_milliseconds,
            cv.Optional(
                CONF_ACTUATOR_ACTIVATION_DURATION, default="0ms"
            ): cv.positive_time_period_milliseconds,
            cv.Optional(CONF_ASSUMED_STATE, default=True): cv.boolean,
        }
    )
    .extend(cv.COMPONENT_SCHEMA),
    _validate_durations,
)


async def to_code(config):
    cg.add_global(
        cg.RawStatement(
            '#include "esphome/components/venetian_blinds/venetian_blinds.h"'
        )
    )
    var = await cover.new_cover(config)
    await cg.register_component(var, config)

    await automation.build_automation(
        var.get_stop_trigger(), [], config[CONF_STOP_ACTION]
    )

    cg.add(var.set_open_duration(config[CONF_OPEN_DURATION]))
    await automation.build_automation(
        var.get_open_trigger(), [], config[CONF_OPEN_ACTION]
    )

    cg.add(var.set_close_duration(config[CONF_CLOSE_DURATION]))
    await automation.build_automation(
        var.get_close_trigger(), [], config[CONF_CLOSE_ACTION]
    )

    cg.add(var.set_tilt_duration(config[CONF_TILT_DURATION]))
    cg.add(
        var.set_actuator_activation_duration(
            config[CONF_ACTUATOR_ACTIVATION_DURATION]
        )
    )
    cg.add(var.set_assumed_state(config[CONF_ASSUMED_STATE]))
