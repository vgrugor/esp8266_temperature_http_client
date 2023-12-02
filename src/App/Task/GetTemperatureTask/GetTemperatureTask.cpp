#include "App/Task/GetTemperatureTask/GetTemperatureTask.h"

GetTemperatureTask::GetTemperatureTask()
{
}

void GetTemperatureTask::run() {
    Serial.println("GetTemperatureTask start");

    TemperatureData& temperatureData = TemperatureData::getInstance();
    TemperatureSensorFacade& temperatureSensor = TemperatureSensorFacade::getInstance();

    temperatureData.setOutdoorTemperature(temperatureSensor.getTemperatureC());

    Serial.println(temperatureData.getOutdoorTemperature());

    Serial.println("GetTemperatureTask done");
}
