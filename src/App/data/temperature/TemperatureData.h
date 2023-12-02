// TemperatureData.h
#ifndef TEMPERATUREDATA_H
    #define TEMPERATUREDATA_H

    #include <Arduino.h>
    //#include <map>

    class TemperatureData {
        public:
            static TemperatureData& getInstance();
            void initializeData();
            float getOutdoorTemperature();
            void setOutdoorTemperature(float temperature);

        private:
            float outdoorTemperature;
            TemperatureData() = default;
            ~TemperatureData() = default;
            TemperatureData(const TemperatureData&) = delete;
            TemperatureData& operator=(const TemperatureData&) = delete;
    };

#endif
