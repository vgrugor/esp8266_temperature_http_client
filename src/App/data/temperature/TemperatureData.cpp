#include "App/data/temperature/TemperatureData.h"

TemperatureData& TemperatureData::getInstance() {
    static TemperatureData instance;
    return instance;
}

void TemperatureData::initializeData() {
    this->outdoorTemperature = -100.0;
}

float TemperatureData::getOutdoorTemperature()
{
    return this->outdoorTemperature;
}

void TemperatureData::setOutdoorTemperature(float temperature)
{
    this->outdoorTemperature = temperature;
}
