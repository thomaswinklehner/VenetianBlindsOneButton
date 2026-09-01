
Install boneio-c-07-f01a40.yaml
INFO ESPHome 2025.12.6
INFO Reading configuration /config/esphome/boneio-c-07-f01a40.yaml...
WARNING GPIO2 is a strapping PIN and should only be used for I/O with care.
Attaching external pullup/down resistors to strapping pins can cause unexpected failures.
See https://esphome.io/guides/faq/#why-am-i-getting-a-warning-about-strapping-pins
WARNING GPIO0 is a strapping PIN and should only be used for I/O with care.
Attaching external pullup/down resistors to strapping pins can cause unexpected failures.
See https://esphome.io/guides/faq/#why-am-i-getting-a-warning-about-strapping-pins
INFO Generating C++ source...
INFO Compiling app... Build path: /data/build/boneio-c-07
Processing boneio-c-07 (board: nodemcu-32s; framework: espidf; platform: https://github.com/pioarduino/platform-espressif32/releases/download/55.03.31-2/platform-espressif32.zip)
--------------------------------------------------------------------------------
Installed esptool from tl-install path: /data/cache/platformio/packages/tool-esptoolpy
HARDWARE: ESP32 240MHz, 320KB RAM, 4MB Flash
 - contrib-piohome @ 3.4.4 
 - framework-espidf @ 3.50501.0 (5.5.1) 
 - tool-cmake @ 4.0.3 
 - tool-esp-rom-elfs @ 2024.10.11 
 - tool-esptoolpy @ 5.1.0 
 - tool-mklittlefs @ 3.2.0 
 - tool-ninja @ 1.13.1 
 - tool-scons @ 4.40801.0 (4.8.1) 
 - toolchain-xtensa-esp-elf @ 14.2.0+20241119
Creating a new virtual environment for IDF Python dependencies using uv
Using Python 3.12.10 environment at: /root/.platformio/penv/.espidf-5.5.1
Installing ESP-IDF's Python dependencies with uv
Using Python 3.12.10 environment at: /root/.platformio/penv/.espidf-5.5.1
Resolved 28 packages in 52.98s
Downloading pydantic-core (1.9MiB)
Downloading cryptography (4.0MiB)
 Downloaded pydantic-core
Downloading cryptography (4.0MiB)
 Downloaded cryptography
Prepared 18 packages in 2m 02s
Installed 28 packages in 44ms
 + annotated-types==0.8.0
 + certifi==2026.7.22
 + cffi==2.1.1
 + charset-normalizer==3.5.1
 + click==8.5.0
 + colorama==0.4.6
 + cryptography==44.0.3
 + esp-idf-kconfig==2.5.4
 + idf-component-manager==2.5.1
 + idna==3.19
 + jsonref==1.1.0
 + pathvalidate==3.3.1
 + psutil==7.2.2
 + pycparser==3.0
 + pydantic==2.11.10
 + pydantic-core==2.33.2
 + pydantic-settings==2.15.0
 + pyparsing==3.3.2
 + python-dotenv==1.2.3
 + requests==2.34.2
 + requests-file==3.0.1
 + requests-toolbelt==1.0.0
 + ruamel-yaml==0.19.1
 + tqdm==4.70.0
 + truststore==0.10.4
 + typing-extensions==4.16.0
 + typing-inspection==0.4.4
 + urllib3==1.26.20
Reading CMake configuration...
Dependency Graph
|-- ArduinoJson @ 7.4.2
Compiling .pioenvs/boneio-c-07/src/esphome/components/api/api_connection.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/api/api_frame_helper.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/api/api_frame_helper_plaintext.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/api/api_pb2.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/api/api_pb2_service.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/api/api_server.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/api/list_entities.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/api/proto.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/api/subscribe_state.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/binary_sensor/automation.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/binary_sensor/binary_sensor.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/binary_sensor/filter.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/cover/cover.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/cover_button/cover_button.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/display/display.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/display/display_buffer.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/display/rect.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/esp32/core.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/esp32/gpio.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/esp32/helpers.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/esp32/preferences.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/esphome/ota/ota_esphome.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/ethernet/ethernet_component.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/font/font.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/gpio/binary_sensor/gpio_binary_sensor.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/gpio/switch/gpio_switch.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/homeassistant/time/homeassistant_time.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/i2c/i2c.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/i2c/i2c_bus_esp_idf.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/ina219/ina219.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/json/json_util.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/lm75/lm75.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/logger/logger.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/logger/logger_esp32.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/logger/task_log_buffer.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/md5/md5.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/mdns/mdns_component.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/mdns/mdns_esp32.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/network/util.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/ota/ota_backend.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/ota/ota_backend_esp_idf.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/pcf8574/pcf8574.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/safe_mode/safe_mode.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/script/script.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/sensor/automation.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/sensor/filter.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/sensor/sensor.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/sha256/sha256.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/socket/bsd_sockets_impl.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/socket/socket.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/ssd1306_base/ssd1306_base.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/ssd1306_i2c/ssd1306_i2c.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/switch/automation.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/switch/switch.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/template/text_sensor/template_text_sensor.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/text_sensor/filter.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/text_sensor/text_sensor.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/time/automation.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/time/real_time_clock.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/time_based/time_based_cover.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/uptime/sensor/uptime_seconds_sensor.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/uptime/sensor/uptime_timestamp_sensor.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/venetian_blinds/cover/venetian_blinds.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/web_server/list_entities.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/web_server/ota/ota_web_server.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/web_server/web_server.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/web_server_base/web_server_base.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/web_server_idf/multipart.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/web_server_idf/utils.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/web_server_idf/web_server_idf.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/components/wind_alarm/wind_alarm.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/application.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/color.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/component.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/component_iterator.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/controller_registry.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/entity_base.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/helpers.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/log.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/ring_buffer.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/scheduler.cpp.o
Compiling .pioenvs/boneio-c-07/src/esphome/core/util.cpp.o
Compiling .pioenvs/boneio-c-07/src/main.cpp.o
Linking .pioenvs/boneio-c-07/firmware.elf
                            Memory Type Usage Summary                             
┏━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓
┃ Memory Type/Section ┃ Used [bytes] ┃ Used [%] ┃ Remain [bytes] ┃ Total [bytes] ┃
┡━━━━━━━━━━━━━━━━━━━━━╇━━━━━━━━━━━━━━╇━━━━━━━━━━╇━━━━━━━━━━━━━━━━╇━━━━━━━━━━━━━━━┩
│ Flash Code          │       401396 │          │                │               │
│    .text            │       401396 │          │                │               │
│ Flash Data          │       120112 │          │                │               │
│    .rodata          │       119856 │          │                │               │
│    .appdesc         │          256 │          │                │               │
│ IRAM                │        47147 │    35.97 │          83925 │        131072 │
│    .text            │        46119 │    35.19 │                │               │
Total image size: 578187 bytes (.bin may be padded larger)
│    .vectors         │         1028 │     0.78 │                │               │
│ DRAM                │        18076 │     10.0 │         162660 │        180736 │
│    .data            │         9532 │     5.27 │                │               │
│    .bss             │         8544 │     4.73 │                │               │
└─────────────────────┴──────────────┴──────────┴────────────────┴───────────────┘
Note: The reported total sizes may be smaller than those in the technical reference manual due to reserved memory and application configuration. The total flash size available for the application is not included by default, as it cannot be reliably determined due to the presence of other data like the bootloader, partition table, and application partition size.
RAM:   [=         ]   5.5% (used 18076 bytes from 327680 bytes)
Flash: [===       ]  31.5% (used 577931 bytes from 1835008 bytes)
Building .pioenvs/boneio-c-07/firmware.bin
Creating ESP32 image...
Successfully created ESP32 image.
merge_factory_bin([".pioenvs/boneio-c-07/firmware.bin"], [".pioenvs/boneio-c-07/firmware.elf"])
Info: bootloader.bin not found - skipping
Info: partition-table.bin not found - skipping
Info: ota_data_initial.bin not found - skipping
Info: boneio-c-07.bin not found - skipping
Using FLASH_EXTRA_IMAGES from PlatformIO environment
Merging binaries into /data/build/boneio-c-07/.pioenvs/boneio-c-07/firmware.factory.bin
Merging binaries with esptool
SHA digest in image updated.
Wrote 0x9d320 bytes to file '/data/build/boneio-c-07/.pioenvs/boneio-c-07/firmware.factory.bin', ready to flash to offset 0x0.
Successfully created /data/build/boneio-c-07/.pioenvs/boneio-c-07/firmware.factory.bin
esp32_copy_ota_bin([".pioenvs/boneio-c-07/firmware.bin"], [".pioenvs/boneio-c-07/firmware.elf"])
Copied firmware to /data/build/boneio-c-07/.pioenvs/boneio-c-07/firmware.ota.bin
======================== [SUCCESS] Took 518.09 seconds ========================

********************************************************************************
We found 47.20MB of unnecessary PlatformIO system data (temporary files, unnecessary packages, etc.).
Use `pio system prune --dry-run` to list them or `pio system prune` to save disk space.
INFO Successfully compiled program.
INFO Connecting to 192.168.0.127 port 3232...
INFO Connected to 192.168.0.127
INFO Uploading /data/build/boneio-c-07/.pioenvs/boneio-c-07/firmware.bin (578336 bytes)
Uploading: [============================================================] 100% Done...


INFO Upload took 2.28 seconds, waiting for result...
INFO OTA successful
INFO Successfully uploaded program.
INFO Starting log output from 192.168.0.127 using esphome API
INFO Successfully resolved boneio-c-07 @ 192.168.0.127 in 0.000s
INFO Successfully connected to boneio-c-07 @ 192.168.0.127 in 4.124s
INFO Successful handshake with boneio-c-07-f01a40 @ 192.168.0.127 in 0.057s
[18:32:31.176][I][app:194]: ESPHome version 2025.12.6 compiled on Sep  1 2026, 18:31:59
[18:32:31.176][I][app:196]: Project thomaswinklehner.venetian-blinds-one-button version 1.1.0
[18:32:31.183][C][logger:261]: Logger:
[18:32:31.183][C][logger:261]:   Max Level: DEBUG
[18:32:31.183][C][logger:261]:   Initial Level: DEBUG
[18:32:31.193][C][logger:267]:   Log Baud Rate: 115200
[18:32:31.193][C][logger:267]:   Hardware UART: UART0
[18:32:31.194][C][logger:274]:   Task Log Buffer Size: 768
[18:32:31.224][C][i2c.idf:090]: I2C Bus:
[18:32:31.226][C][i2c.idf:091]:   SDA Pin: GPIO17
[18:32:31.226][C][i2c.idf:091]:   SCL Pin: GPIO33
[18:32:31.226][C][i2c.idf:091]:   Frequency: 400000 Hz
[18:32:31.227][C][i2c.idf:101]:   Recovery: bus successfully recovered
[18:32:31.227][C][i2c.idf:111]: Results from bus scan:
[18:32:31.229][C][i2c.idf:117]: Found device at address 0x20
[18:32:31.234][C][i2c.idf:117]: Found device at address 0x21
[18:32:31.235][C][i2c.idf:117]: Found device at address 0x22
[18:32:31.244][C][i2c.idf:117]: Found device at address 0x23
[18:32:31.246][C][i2c.idf:117]: Found device at address 0x24
[18:32:31.246][C][i2c.idf:117]: Found device at address 0x3C
[18:32:31.255][C][i2c.idf:117]: Found device at address 0x40
[18:32:31.256][C][i2c.idf:117]: Found device at address 0x48
[18:32:31.284][C][pcf8574:024]: PCF8574:
[18:32:31.286][C][pcf8574:025]:   Address: 0x20
[18:32:31.287][C][pcf8574:026]:   Is PCF8575: YES
[18:32:31.292][C][pcf8574:024]: PCF8574:
[18:32:31.293][C][pcf8574:025]:   Address: 0x21
[18:32:31.295][C][pcf8574:026]:   Is PCF8575: YES
[18:32:31.310][C][pcf8574:024]: PCF8574:
[18:32:31.312][C][pcf8574:025]:   Address: 0x22
[18:32:31.312][C][pcf8574:026]:   Is PCF8575: NO
[18:32:31.316][C][pcf8574:024]: PCF8574:
[18:32:31.317][C][pcf8574:025]:   Address: 0x23
[18:32:31.319][C][pcf8574:026]:   Is PCF8575: YES
[18:32:31.334][C][pcf8574:024]: PCF8574:
[18:32:31.336][C][pcf8574:025]:   Address: 0x24
[18:32:31.337][C][pcf8574:026]:   Is PCF8575: YES
[18:32:31.341][C][switch.gpio:092]: GPIO Switch 'Buzzer'
[18:32:31.341][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.342][C][switch.gpio:029]:   Pin: GPIO2
[18:32:31.359][C][switch.gpio:092]: GPIO Switch 'cover_open_01_out01'
[18:32:31.359][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.360][C][switch.gpio:029]:   Pin: 15 via PCF8574
[18:32:31.362][C][switch.gpio:031]:   Interlocks:
[18:32:31.363][C][switch.gpio:035]:     cover_close_01_out02
[18:32:31.367][C][switch.gpio:092]: GPIO Switch 'cover_close_01_out02'
[18:32:31.367][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.368][C][switch.gpio:029]:   Pin: 14 via PCF8574
[18:32:31.369][C][switch.gpio:031]:   Interlocks:
[18:32:31.374][C][switch.gpio:035]:     cover_open_01_out01
[18:32:31.384][C][switch.gpio:092]: GPIO Switch 'cover_open_02_out03'
[18:32:31.384][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.385][C][switch.gpio:029]:   Pin: 13 via PCF8574
[18:32:31.387][C][switch.gpio:031]:   Interlocks:
[18:32:31.395][C][switch.gpio:035]:     cover_close_02_out04
[18:32:31.399][C][switch.gpio:092]: GPIO Switch 'cover_close_02_out04'
[18:32:31.399][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.415][C][switch.gpio:029]:   Pin: 12 via PCF8574
[18:32:31.415][C][switch.gpio:031]:   Interlocks:
[18:32:31.417][C][switch.gpio:035]:     cover_open_02_out03
[18:32:31.421][C][switch.gpio:092]: GPIO Switch 'cover_open_03_out05'
[18:32:31.421][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.425][C][switch.gpio:029]:   Pin: 11 via PCF8574
[18:32:31.435][C][switch.gpio:031]:   Interlocks:
[18:32:31.436][C][switch.gpio:035]:     cover_close_03_out06
[18:32:31.448][C][switch.gpio:092]: GPIO Switch 'cover_close_03_out06'
[18:32:31.448][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.448][C][switch.gpio:029]:   Pin: 10 via PCF8574
[18:32:31.456][C][switch.gpio:031]:   Interlocks:
[18:32:31.456][C][switch.gpio:035]:     cover_open_03_out05
[18:32:31.468][C][switch.gpio:092]: GPIO Switch 'cover_open_04_out07'
[18:32:31.468][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.469][C][switch.gpio:029]:   Pin: 9 via PCF8574
[18:32:31.476][C][switch.gpio:031]:   Interlocks:
[18:32:31.487][C][switch.gpio:035]:     cover_close_04_out08
[18:32:31.491][C][switch.gpio:092]: GPIO Switch 'cover_close_04_out08'
[18:32:31.491][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.491][C][switch.gpio:029]:   Pin: 8 via PCF8574
[18:32:31.497][C][switch.gpio:031]:   Interlocks:
[18:32:31.507][C][switch.gpio:035]:     cover_open_04_out07
[18:32:31.511][C][switch.gpio:092]: GPIO Switch 'cover_open_05_out09'
[18:32:31.511][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.518][C][switch.gpio:029]:   Pin: 15 via PCF8574
[18:32:31.518][C][switch.gpio:031]:   Interlocks:
[18:32:31.528][C][switch.gpio:035]:     cover_close_05_out10
[18:32:31.531][C][switch.gpio:092]: GPIO Switch 'cover_close_05_out10'
[18:32:31.531][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.538][C][switch.gpio:029]:   Pin: 14 via PCF8574
[18:32:31.538][C][switch.gpio:031]:   Interlocks:
[18:32:31.548][C][switch.gpio:035]:     cover_open_05_out09
[18:32:31.552][C][switch.gpio:092]: GPIO Switch 'cover_open_06_out11'
[18:32:31.552][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.559][C][switch.gpio:029]:   Pin: 13 via PCF8574
[18:32:31.569][C][switch.gpio:031]:   Interlocks:
[18:32:31.569][C][switch.gpio:035]:     cover_close_06_out12
[18:32:31.581][C][switch.gpio:092]: GPIO Switch 'cover_close_06_out12'
[18:32:31.581][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.582][C][switch.gpio:029]:   Pin: 12 via PCF8574
[18:32:31.589][C][switch.gpio:031]:   Interlocks:
[18:32:31.590][C][switch.gpio:035]:     cover_open_06_out11
[18:32:31.601][C][switch.gpio:092]: GPIO Switch 'cover_open_07_out13'
[18:32:31.601][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.602][C][switch.gpio:029]:   Pin: 11 via PCF8574
[18:32:31.610][C][switch.gpio:031]:   Interlocks:
[18:32:31.610][C][switch.gpio:035]:     cover_close_07_out14
[18:32:31.622][C][switch.gpio:092]: GPIO Switch 'cover_close_07_out14'
[18:32:31.622][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.623][C][switch.gpio:029]:   Pin: 10 via PCF8574
[18:32:31.630][C][switch.gpio:031]:   Interlocks:
[18:32:31.631][C][switch.gpio:035]:     cover_open_07_out13
[18:32:31.642][C][switch.gpio:092]: GPIO Switch 'cover_open_08_out15'
[18:32:31.642][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.643][C][switch.gpio:029]:   Pin: 9 via PCF8574
[18:32:31.651][C][switch.gpio:031]:   Interlocks:
[18:32:31.661][C][switch.gpio:035]:     cover_close_08_out16
[18:32:31.665][C][switch.gpio:092]: GPIO Switch 'cover_close_08_out16'
[18:32:31.665][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.671][C][switch.gpio:029]:   Pin: 8 via PCF8574
[18:32:31.672][C][switch.gpio:031]:   Interlocks:
[18:32:31.681][C][switch.gpio:035]:     cover_open_08_out15
[18:32:31.685][C][switch.gpio:092]: GPIO Switch 'cover_open_09_out17'
[18:32:31.685][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.692][C][switch.gpio:029]:   Pin: 0 via PCF8574
[18:32:31.702][C][switch.gpio:031]:   Interlocks:
[18:32:31.702][C][switch.gpio:035]:     cover_close_09_out18
[18:32:31.706][C][switch.gpio:092]: GPIO Switch 'cover_close_09_out18'
[18:32:31.706][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.712][C][switch.gpio:029]:   Pin: 1 via PCF8574
[18:32:31.722][C][switch.gpio:031]:   Interlocks:
[18:32:31.723][C][switch.gpio:035]:     cover_open_09_out17
[18:32:31.735][C][switch.gpio:092]: GPIO Switch 'cover_open_10_out19'
[18:32:31.735][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.735][C][switch.gpio:029]:   Pin: 2 via PCF8574
[18:32:31.743][C][switch.gpio:031]:   Interlocks:
[18:32:31.743][C][switch.gpio:035]:     cover_close_10_out20
[18:32:31.755][C][switch.gpio:092]: GPIO Switch 'cover_close_10_out20'
[18:32:31.755][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.756][C][switch.gpio:029]:   Pin: 3 via PCF8574
[18:32:31.763][C][switch.gpio:031]:   Interlocks:
[18:32:31.764][C][switch.gpio:035]:     cover_open_10_out19
[18:32:31.776][C][switch.gpio:092]: GPIO Switch 'cover_open_11_out21'
[18:32:31.776][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.776][C][switch.gpio:029]:   Pin: 4 via PCF8574
[18:32:31.784][C][switch.gpio:031]:   Interlocks:
[18:32:31.794][C][switch.gpio:035]:     cover_close_11_out22
[18:32:31.798][C][switch.gpio:092]: GPIO Switch 'cover_close_11_out22'
[18:32:31.798][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.798][C][switch.gpio:029]:   Pin: 5 via PCF8574
[18:32:31.804][C][switch.gpio:031]:   Interlocks:
[18:32:31.805][C][switch.gpio:035]:     cover_open_11_out21
[18:32:31.867][C][switch.gpio:092]: GPIO Switch 'cover_open_12_out23'
[18:32:31.867][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.868][C][switch.gpio:029]:   Pin: 6 via PCF8574
[18:32:31.870][C][switch.gpio:031]:   Interlocks:
[18:32:31.870][C][switch.gpio:035]:     cover_close_12_out24
[18:32:31.883][C][switch.gpio:092]: GPIO Switch 'cover_close_12_out24'
[18:32:31.883][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.884][C][switch.gpio:029]:   Pin: 7 via PCF8574
[18:32:31.886][C][switch.gpio:031]:   Interlocks:
[18:32:31.887][C][switch.gpio:035]:     cover_open_12_out23
[18:32:31.891][C][switch.gpio:092]: GPIO Switch 'cover_open_13_out25'
[18:32:31.891][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.892][C][switch.gpio:029]:   Pin: 0 via PCF8574
[18:32:31.896][C][switch.gpio:031]:   Interlocks:
[18:32:31.896][C][switch.gpio:035]:     cover_close_13_out26
[18:32:31.908][C][switch.gpio:092]: GPIO Switch 'cover_close_13_out26'
[18:32:31.908][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.909][C][switch.gpio:029]:   Pin: 1 via PCF8574
[18:32:31.916][C][switch.gpio:031]:   Interlocks:
[18:32:31.917][C][switch.gpio:035]:     cover_open_13_out25
[18:32:31.928][C][switch.gpio:092]: GPIO Switch 'cover_open_14_out27'
[18:32:31.928][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.929][C][switch.gpio:029]:   Pin: 2 via PCF8574
[18:32:31.937][C][switch.gpio:031]:   Interlocks:
[18:32:31.937][C][switch.gpio:035]:     cover_close_14_out28
[18:32:31.949][C][switch.gpio:092]: GPIO Switch 'cover_close_14_out28'
[18:32:31.949][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.950][C][switch.gpio:029]:   Pin: 3 via PCF8574
[18:32:31.957][C][switch.gpio:031]:   Interlocks:
[18:32:31.967][C][switch.gpio:035]:     cover_open_14_out27
[18:32:31.971][C][switch.gpio:092]: GPIO Switch 'cover_open_15_out29'
[18:32:31.971][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.972][C][switch.gpio:029]:   Pin: 4 via PCF8574
[18:32:31.978][C][switch.gpio:031]:   Interlocks:
[18:32:31.988][C][switch.gpio:035]:     cover_close_15_out30
[18:32:31.992][C][switch.gpio:092]: GPIO Switch 'cover_close_15_out30'
[18:32:31.992][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:31.998][C][switch.gpio:029]:   Pin: 5 via PCF8574
[18:32:31.999][C][switch.gpio:031]:   Interlocks:
[18:32:32.001][C][switch.gpio:035]:     cover_open_15_out29
[18:32:32.010][C][switch.gpio:092]: GPIO Switch 'cover_open_16_out31'
[18:32:32.010][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:32.019][C][switch.gpio:029]:   Pin: 6 via PCF8574
[18:32:32.029][C][switch.gpio:031]:   Interlocks:
[18:32:32.029][C][switch.gpio:035]:     cover_close_16_out32
[18:32:32.033][C][switch.gpio:092]: GPIO Switch 'cover_close_16_out32'
[18:32:32.033][C][switch.gpio:092]:   Restore Mode: always OFF
[18:32:32.039][C][switch.gpio:029]:   Pin: 7 via PCF8574
[18:32:32.050][C][switch.gpio:031]:   Interlocks:
[18:32:32.050][C][switch.gpio:035]:     cover_open_16_out31
[18:32:32.062][C][template.text_sensor:016]: Template Sensor 'Serial No.'
[18:32:32.062][C][template.text_sensor:023]:   Icon: 'mdi:expansion-card-variant'
[18:32:32.080][C][template.text_sensor:016]: Template Sensor 'Uptime'
[18:32:32.080][C][template.text_sensor:023]:   Icon: 'mdi:clock-start'
[18:32:32.089][C][template.text_sensor:016]: Template Sensor 'IP Address'
[18:32:32.090][C][template.text_sensor:023]:   Icon: 'mdi:ip-network'
[18:32:32.102][C][uptime.sensor:017]: Uptime Sensor 'wt32_uptime_seconds'
[18:32:32.102][C][uptime.sensor:017]:   State Class: 'total_increasing'
[18:32:32.102][C][uptime.sensor:017]:   Unit of Measurement: 's'
[18:32:32.102][C][uptime.sensor:017]:   Accuracy Decimals: 0
[18:32:32.111][C][uptime.sensor:027]:   Device Class: 'duration'
[18:32:32.112][C][uptime.sensor:031]:   Icon: 'mdi:timer-outline'
[18:32:32.121][C][uptime.sensor:033]:   Type: Seconds
[18:32:32.152][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 01 - Küche'
[18:32:32.152][C][gpio.binary_sensor:072]:   Pin: 0 via PCF8574
[18:32:32.155][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.174][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 02 - EZ SÜD'
[18:32:32.176][C][gpio.binary_sensor:072]:   Pin: 1 via PCF8574
[18:32:32.177][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.193][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 03 - EZ HEBE SÜD'
[18:32:32.194][C][gpio.binary_sensor:072]:   Pin: 2 via PCF8574
[18:32:32.196][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.216][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 04 - EZ HEBE NORD'
[18:32:32.218][C][gpio.binary_sensor:072]:   Pin: 3 via PCF8574
[18:32:32.219][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.241][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 05 - WZ'
[18:32:32.242][C][gpio.binary_sensor:072]:   Pin: 4 via PCF8574
[18:32:32.245][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.265][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 06 - Gäste West'
[18:32:32.267][C][gpio.binary_sensor:072]:   Pin: 5 via PCF8574
[18:32:32.268][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.289][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 07 - Gäste Nord'
[18:32:32.290][C][gpio.binary_sensor:072]:   Pin: 6 via PCF8574
[18:32:32.293][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.312][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 08 - KZ OST OST'
[18:32:32.314][C][gpio.binary_sensor:072]:   Pin: 8 via PCF8574
[18:32:32.315][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.336][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 09 - KZ OST SÜD'
[18:32:32.337][C][gpio.binary_sensor:072]:   Pin: 9 via PCF8574
[18:32:32.340][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.359][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 10 - KZ WEST SÜD'
[18:32:32.361][C][gpio.binary_sensor:072]:   Pin: 10 via PCF8574
[18:32:32.362][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.384][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 11 - KZ WEST WEST'
[18:32:32.384][C][gpio.binary_sensor:072]:   Pin: 11 via PCF8574
[18:32:32.386][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.408][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 12 - SR'
[18:32:32.409][C][gpio.binary_sensor:072]:   Pin: 12 via PCF8574
[18:32:32.410][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.432][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 13 - SZ'
[18:32:32.432][C][gpio.binary_sensor:072]:   Pin: 13 via PCF8574
[18:32:32.434][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.456][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 14 - ReserveRaff'
[18:32:32.457][C][gpio.binary_sensor:072]:   Pin: 14 via PCF8574
[18:32:32.459][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.481][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'IN 29 - Wind Alarm'
[18:32:32.481][C][gpio.binary_sensor:072]:   Pin: 0 via PCF8574
[18:32:32.483][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.487][C][gpio.binary_sensor:016]: GPIO Binary Sensor 'boneIO_button'
[18:32:32.489][C][gpio.binary_sensor:072]:   Pin: 7 via PCF8574
[18:32:32.489][C][gpio.binary_sensor:073]:   Mode: polling
[18:32:32.504][C][ina219:139]: INA219:
[18:32:32.504][C][ina219:140]:   Address: 0x40
[18:32:32.507][C][ina219:399]:   Update Interval: 30.0s
[18:32:32.508][C][ina219:017]:   Bus Voltage 'INA219 Bus Voltage'
[18:32:32.508][C][ina219:017]:     State Class: 'measurement'
[18:32:32.508][C][ina219:017]:     Unit of Measurement: 'V'
[18:32:32.508][C][ina219:017]:     Accuracy Decimals: 2
[18:32:32.510][C][ina219:027]:     Device Class: 'voltage'
[18:32:32.511][C][ina219:017]:   Shunt Voltage 'INA219 Shunt Voltage'
[18:32:32.511][C][ina219:017]:     State Class: 'measurement'
[18:32:32.511][C][ina219:017]:     Unit of Measurement: 'V'
[18:32:32.511][C][ina219:017]:     Accuracy Decimals: 2
[18:32:32.519][C][ina219:027]:     Device Class: 'voltage'
[18:32:32.529][C][ina219:017]:   Current 'INA219 Current'
[18:32:32.529][C][ina219:017]:     State Class: 'measurement'
[18:32:32.529][C][ina219:017]:     Unit of Measurement: 'A'
[18:32:32.529][C][ina219:017]:     Accuracy Decimals: 3
[18:32:32.539][C][ina219:027]:     Device Class: 'current'
[18:32:32.549][C][ina219:017]:   Power 'INA219 Power'
[18:32:32.549][C][ina219:017]:     State Class: 'measurement'
[18:32:32.549][C][ina219:017]:     Unit of Measurement: 'W'
[18:32:32.549][C][ina219:017]:     Accuracy Decimals: 2
[18:32:32.560][C][ina219:027]:     Device Class: 'power'
[18:32:32.563][C][lm75:020]: LM75:
[18:32:32.570][C][lm75:021]:   Address: 0x48
[18:32:32.571][C][lm75:399]:   Update Interval: 30.0s
[18:32:32.574][C][lm75:017]:   Temperature 'LM75B Temperature'
[18:32:32.574][C][lm75:017]:     State Class: 'measurement'
[18:32:32.574][C][lm75:017]:     Unit of Measurement: '°C'
[18:32:32.574][C][lm75:017]:     Accuracy Decimals: 1
[18:32:32.590][C][lm75:027]:     Device Class: 'temperature'
[18:32:32.594][C][homeassistant.time:010]: Home Assistant Time
[18:32:32.594][C][time:029]: Timezone: 'CET-1CEST,M3.5.0,M10.5.0/3'
[18:32:32.612][C][venetian_blinds.cover:036]: Venetian Blind 'Küche'
[18:32:32.612][C][venetian_blinds.cover:036]:   Assumed State: YES
[18:32:32.614][C][venetian_blinds.cover:036]:   Device Class: 'blind'
[18:32:32.622][C][venetian_blinds.cover:037]:   Open duration: 60.0s
[18:32:32.622][C][venetian_blinds.cover:038]:   Close duration: 60.0s
[18:32:32.632][C][venetian_blinds.cover:039]:   Tilt duration: 2.0s
[18:32:32.633][C][venetian_blinds.cover:040]:   Actuator activation: 0.0s
[18:32:32.654][C][venetian_blinds.cover:036]: Venetian Blind 'EZ SÜD'
[18:32:32.655][C][venetian_blinds.cover:036]:   Assumed State: YES
[18:32:32.657][C][venetian_blinds.cover:036]:   Device Class: 'blind'
[18:32:32.662][C][venetian_blinds.cover:037]:   Open duration: 60.0s
[18:32:32.664][C][venetian_blinds.cover:038]:   Close duration: 60.0s
[18:32:32.672][C][venetian_blinds.cover:039]:   Tilt duration: 2.0s
[18:32:32.673][C][venetian_blinds.cover:040]:   Actuator activation: 0.0s
[18:32:32.685][C][venetian_blinds.cover:036]: Venetian Blind 'EZ HEBE SÜD'
[18:32:32.692][C][venetian_blinds.cover:036]:   Assumed State: YES
[18:32:32.694][C][venetian_blinds.cover:036]:   Device Class: 'blind'
[18:32:32.703][C][venetian_blinds.cover:037]:   Open duration: 60.0s
[18:32:32.705][C][venetian_blinds.cover:038]:   Close duration: 60.0s
[18:32:32.713][C][venetian_blinds.cover:039]:   Tilt duration: 2.0s
[18:32:32.715][C][venetian_blinds.cover:040]:   Actuator activation: 0.0s
[18:32:32.726][C][venetian_blinds.cover:036]: Venetian Blind 'EZ HEBE NORD'
[18:32:32.734][C][venetian_blinds.cover:036]:   Assumed State: YES
[18:32:32.734][C][venetian_blinds.cover:036]:   Device Class: 'blind'
[18:32:32.744][C][venetian_blinds.cover:037]:   Open duration: 60.0s
[18:32:32.745][C][venetian_blinds.cover:038]:   Close duration: 60.0s
[18:32:32.755][C][venetian_blinds.cover:039]:   Tilt duration: 2.0s
[18:32:32.755][C][venetian_blinds.cover:040]:   Actuator activation: 0.0s
[18:32:32.767][C][venetian_blinds.cover:036]: Venetian Blind 'WZ'
[18:32:32.775][C][venetian_blinds.cover:036]:   Assumed State: YES
[18:32:32.776][C][venetian_blinds.cover:036]:   Device Class: 'blind'
[18:32:32.786][C][venetian_blinds.cover:037]:   Open duration: 60.0s
[18:32:32.787][C][venetian_blinds.cover:038]:   Close duration: 60.0s
[18:32:32.796][C][venetian_blinds.cover:039]:   Tilt duration: 2.0s
[18:32:32.796][C][venetian_blinds.cover:040]:   Actuator activation: 0.0s
[18:32:32.808][C][time_based.cover:014]: Time Based Cover 'Gäste West'
[18:32:32.808][C][time_based.cover:014]:   Assumed State: YES
[18:32:32.816][C][time_based.cover:014]:   Device Class: 'shutter'
[18:32:32.827][C][time_based.cover:015]:   Open Duration: 60.0s
[18:32:32.827][C][time_based.cover:015]:   Close Duration: 60.0s
[18:32:32.881][C][time_based.cover:014]: Time Based Cover 'Gäste Nord'
[18:32:32.882][C][time_based.cover:014]:   Assumed State: YES
[18:32:32.884][C][time_based.cover:014]:   Device Class: 'shutter'
[18:32:32.887][C][time_based.cover:015]:   Open Duration: 60.0s
[18:32:32.887][C][time_based.cover:015]:   Close Duration: 60.0s
[18:32:32.898][C][time_based.cover:014]: Time Based Cover 'KZ OST OST'
[18:32:32.899][C][time_based.cover:014]:   Assumed State: YES
[18:32:32.901][C][time_based.cover:014]:   Device Class: 'shutter'
[18:32:32.903][C][time_based.cover:015]:   Open Duration: 60.0s
[18:32:32.903][C][time_based.cover:015]:   Close Duration: 60.0s
[18:32:32.907][C][time_based.cover:014]: Time Based Cover 'KZ OST SÜD'
[18:32:32.908][C][time_based.cover:014]:   Assumed State: YES
[18:32:32.911][C][time_based.cover:014]:   Device Class: 'shutter'
[18:32:32.916][C][time_based.cover:015]:   Open Duration: 60.0s
[18:32:32.916][C][time_based.cover:015]:   Close Duration: 60.0s
[18:32:32.926][C][time_based.cover:014]: Time Based Cover 'KZ WEST SÜD'
[18:32:32.927][C][time_based.cover:014]:   Assumed State: YES
[18:32:32.929][C][time_based.cover:014]:   Device Class: 'shutter'
[18:32:32.936][C][time_based.cover:015]:   Open Duration: 60.0s
[18:32:32.936][C][time_based.cover:015]:   Close Duration: 60.0s
[18:32:32.940][C][time_based.cover:014]: Time Based Cover 'KZ WEST WEST'
[18:32:32.946][C][time_based.cover:014]:   Assumed State: YES
[18:32:32.956][C][time_based.cover:014]:   Device Class: 'shutter'
[18:32:32.958][C][time_based.cover:015]:   Open Duration: 60.0s
[18:32:32.958][C][time_based.cover:015]:   Close Duration: 60.0s
[18:32:32.979][C][time_based.cover:014]: Time Based Cover 'SR'
[18:32:32.979][C][time_based.cover:014]:   Assumed State: YES
[18:32:32.981][C][time_based.cover:014]:   Device Class: 'shutter'
[18:32:32.988][C][time_based.cover:015]:   Open Duration: 60.0s
[18:32:32.988][C][time_based.cover:015]:   Close Duration: 60.0s
[18:32:32.999][C][time_based.cover:014]: Time Based Cover 'SZ'
[18:32:33.000][C][time_based.cover:014]:   Assumed State: YES
[18:32:33.003][C][time_based.cover:014]:   Device Class: 'shutter'
[18:32:33.008][C][time_based.cover:015]:   Open Duration: 60.0s
[18:32:33.008][C][time_based.cover:015]:   Close Duration: 60.0s
[18:32:33.020][C][time_based.cover:014]: Time Based Cover 'ReserveRaff'
[18:32:33.021][C][time_based.cover:014]:   Assumed State: YES
[18:32:33.028][C][time_based.cover:014]:   Device Class: 'shutter'
[18:32:33.031][C][time_based.cover:015]:   Open Duration: 60.0s
[18:32:33.031][C][time_based.cover:015]:   Close Duration: 60.0s
[18:32:33.040][C][cover_button:056]: Cover button controller:
[18:32:33.041][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.049][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.060][C][cover_button:056]: Cover button controller:
[18:32:33.061][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.069][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.079][C][cover_button:056]: Cover button controller:
[18:32:33.080][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.082][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.091][C][cover_button:056]: Cover button controller:
[18:32:33.100][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.100][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.112][C][cover_button:056]: Cover button controller:
[18:32:33.113][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.120][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.130][C][cover_button:056]: Cover button controller:
[18:32:33.131][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.141][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.144][C][cover_button:056]: Cover button controller:
[18:32:33.151][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.152][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.163][C][cover_button:056]: Cover button controller:
[18:32:33.164][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.171][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.180][C][cover_button:056]: Cover button controller:
[18:32:33.183][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.192][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.196][C][cover_button:056]: Cover button controller:
[18:32:33.202][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.203][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.214][C][cover_button:056]: Cover button controller:
[18:32:33.215][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.223][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.232][C][cover_button:056]: Cover button controller:
[18:32:33.233][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.243][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.247][C][cover_button:056]: Cover button controller:
[18:32:33.254][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.254][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.266][C][cover_button:056]: Cover button controller:
[18:32:33.266][C][cover_button:057]:   Stop on release before: 2000ms
[18:32:33.274][C][cover_button:059]:   Move all on release at/after: 5000ms
[18:32:33.286][C][wind_alarm:023]: Wind alarm controller:
[18:32:33.287][C][wind_alarm:024]:   Active low: YES
[18:32:33.303][C][ssd1306_i2c:022]: I2C SSD1306
[18:32:33.303][C][ssd1306_i2c:022]:   Rotations: 0 °
[18:32:33.303][C][ssd1306_i2c:022]:   Dimensions: 128px x 64px
[18:32:33.305][C][ssd1306_i2c:023]:   Address: 0x3C
[18:32:33.307][C][ssd1306_i2c:024]:   Model: SH1106 128x64
[18:32:33.309][C][ssd1306_i2c:026]:   External VCC: NO
[18:32:33.309][C][ssd1306_i2c:026]:   Flip X: YES
[18:32:33.309][C][ssd1306_i2c:026]:   Flip Y: YES
[18:32:33.309][C][ssd1306_i2c:026]:   Offset X: 0
[18:32:33.309][C][ssd1306_i2c:026]:   Offset Y: 0
[18:32:33.309][C][ssd1306_i2c:026]:   Inverted Color: NO
[18:32:33.315][C][ssd1306_i2c:399]:   Update Interval: 1.0s
[18:32:33.345][C][ethernet:384]: Ethernet:
[18:32:33.345][C][ethernet:384]:   Connected: YES
[18:32:33.347][C][ethernet:647]:   IP Address: 192.168.0.127
[18:32:33.347][C][ethernet:647]:   Hostname: 'boneio-c-07-f01a40'
[18:32:33.347][C][ethernet:647]:   Subnet: 255.255.255.0
[18:32:33.347][C][ethernet:647]:   Gateway: 192.168.0.1
[18:32:33.347][C][ethernet:647]:   DNS1: 192.168.0.1
[18:32:33.347][C][ethernet:647]:   DNS2: 0.0.0.0
[18:32:33.349][C][ethernet:668]:   MAC Address: 5C:01:3B:F0:1A:43
[18:32:33.349][C][ethernet:668]:   Is Full Duplex: YES
[18:32:33.349][C][ethernet:668]:   Link Speed: 100
[18:32:33.356][C][ethernet:410]:   Power Pin: 16
[18:32:33.357][C][ethernet:412]:   CLK Pin: 0
[18:32:33.357][C][ethernet:412]:   MDC Pin: 23
[18:32:33.357][C][ethernet:412]:   MDIO Pin: 18
[18:32:33.357][C][ethernet:412]:   PHY addr: 1
[18:32:33.366][C][ethernet:419]:   Type: LAN8720
[18:32:33.370][C][web_server:335]: Web Server:
[18:32:33.370][C][web_server:335]:   Address: 192.168.0.127:80
[18:32:33.387][C][esphome.ota:092]: Over-The-Air updates:
[18:32:33.387][C][esphome.ota:092]:   Address: 192.168.0.127:3232
[18:32:33.387][C][esphome.ota:092]:   Version: 2
[18:32:33.396][C][safe_mode:018]: Safe Mode:
[18:32:33.396][C][safe_mode:018]:   Successful after: 60s
[18:32:33.396][C][safe_mode:018]:   Invoke after: 10 attempts
[18:32:33.396][C][safe_mode:018]:   Duration: 300s
[18:32:33.409][C][web_server.ota:241]: Web Server OTA
[18:32:33.418][C][api:211]: Server:
[18:32:33.418][C][api:211]:   Address: 192.168.0.127:6053
[18:32:33.418][C][api:211]:   Listen backlog: 4
[18:32:33.418][C][api:211]:   Max connections: 8
[18:32:33.419][C][api:223]:   Noise encryption: NO
[18:32:33.430][C][mdns:177]: mDNS:
[18:32:33.430][C][mdns:177]:   Hostname: boneio-c-07-f01a40
[18:32:58.798][D][sensor:135]: 'INA219 Bus Voltage': Sending state 23.78800 V with 2 decimals of accuracy
[18:32:58.802][D][sensor:135]: 'INA219 Shunt Voltage': Sending state 0.00427 V with 2 decimals of accuracy
[18:32:58.806][D][sensor:135]: 'INA219 Current': Sending state 0.04273 A with 3 decimals of accuracy
[18:32:58.809][D][sensor:135]: 'INA219 Power': Sending state 1.01136 W with 2 decimals of accuracy
[18:33:00.919][D][lm75:042]: Got Temperature=26.0°C
[18:33:00.922][D][sensor:135]: 'LM75B Temperature': Sending state 26.00000 °C with 1 decimals of accuracy
[18:33:25.541][I][safe_mode:042]: Boot seems successful; resetting boot loop counter
[18:33:25.558][D][esp32.preferences:149]: Writing 1 items: 0 cached, 1 written, 0 failed
[18:33:25.966][W][component:490]: display took a long time for an operation (51 ms)
[18:33:25.968][W][component:493]: Components should block for at most 30 ms
[18:33:28.820][D][text_sensor:097]: 'IP Address': Sending state '192.168.0.127'
[18:33:28.824][D][sensor:135]: 'INA219 Bus Voltage': Sending state 23.78800 V with 2 decimals of accuracy
[18:33:28.828][D][sensor:135]: 'INA219 Shunt Voltage': Sending state 0.00427 V with 2 decimals of accuracy
[18:33:28.832][D][sensor:135]: 'INA219 Current': Sending state 0.04273 A with 3 decimals of accuracy
[18:33:28.834][D][sensor:135]: 'INA219 Power': Sending state 1.01724 W with 2 decimals of accuracy
[18:33:30.542][D][text_sensor:097]: 'Uptime': Sending state '1m'
[18:33:30.545][D][sensor:135]: 'wt32_uptime_seconds': Sending state 65.19300 s with 0 decimals of accuracy
[18:33:30.978][D][lm75:042]: Got Temperature=26.0°C
[18:33:30.982][D][sensor:135]: 'LM75B Temperature': Sending state 26.00000 °C with 1 decimals of accuracy
[18:33:58.836][D][sensor:135]: 'INA219 Bus Voltage': Sending state 23.78800 V with 2 decimals of accuracy
[18:33:58.839][D][sensor:135]: 'INA219 Shunt Voltage': Sending state 0.00425 V with 2 decimals of accuracy
[18:33:58.843][D][sensor:135]: 'INA219 Current': Sending state 0.04292 A with 3 decimals of accuracy
[18:33:58.846][D][sensor:135]: 'INA219 Power': Sending state 1.01136 W with 2 decimals of accuracy
[18:34:01.030][D][lm75:042]: Got Temperature=26.5°C
[18:34:01.033][D][sensor:135]: 'LM75B Temperature': Sending state 26.50000 °C with 1 decimals of accuracy
