// GetTemperatureTask.h
#ifndef GETTEMPERATURETASK_H
    #define GETTEMPERATURETASK_H

    #include <ESP8266WiFi.h>
    #include <ESP8266HTTPClient.h>
    #include <WiFiClient.h>

    #include "App/data/temperature/TemperatureData.h"
    #include "App/Facades/Temperature/TemperatureSensorFacade.h"

    class GetTemperatureTask {
        public:
            GetTemperatureTask();
            static void run();
    };

#endif
