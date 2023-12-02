#include "App/Task/GetTemperatureTask/GetTemperatureTask.h"

GetTemperatureTask::GetTemperatureTask()
{
}

void GetTemperatureTask::run() {
    Serial.println("GetTemperatureTask start");

    TemperatureData& temperatureData = TemperatureData::getInstance();
    TemperatureSensorFacade& temperatureSensor = TemperatureSensorFacade::getInstance();

    temperatureData.setOutdoorTemperature(temperatureSensor.getTemperatureC());

    WiFiClient client;
    HTTPClient http;

    float temp = temperatureData.getOutdoorTemperature();
    char buffer[20];
    sprintf(buffer, "%.2f", temp);

    String serverPath = "http://192.168.1.200:80/outdoor/temperature?temp=" + String(buffer);
    
    http.begin(client, serverPath.c_str());

    int httpResponseCode = http.GET();
    
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }

    http.end();

    Serial.println(temperatureData.getOutdoorTemperature());

    Serial.println("GetTemperatureTask done");
}
