#pragma once

#include <string>

#include "esphome/components/sensor/sensor.h"

#include "../p1_mini.h"

namespace esphome
{
    namespace p1_mini
    {
        class P1MiniTextSensor : public P1MiniTextSensorBase, public text_sensor::TextSensor, public Component
        {
        public:
            P1MiniTextSensor(std::string identifier)
                : P1MiniTextSensorBase{ identifier }
            {}

            virtual void publish_val(std::string value) override { publish_state(value); }

        };

    } // namespace p1_mini
} // namespace esphome
