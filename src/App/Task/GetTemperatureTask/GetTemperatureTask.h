// GetTemperatureTask.h
#ifndef GETTEMPERATURETASK_H
    #define GETTEMPERATURETASK_H

    #include "App/data/temperature/TemperatureData.h"
    #include "App/Facades/Temperature/TemperatureSensorFacade.h"

    class GetTemperatureTask {
        public:
            GetTemperatureTask();
            static void run();
    };

#endif
