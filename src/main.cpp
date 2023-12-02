#include <Arduino.h>

#include "App/Facades/WiFi/WiFiConnectionFacade.h"
#include "env.h"
#include "App/Facades/TaskScheduler/TaskSchedulerFacade.h"
#include "App/Facades/Temperature/TemperatureSensorFacade.h"
#include "App/Task/GetTemperatureTask/GetTemperatureTask.h"
#include "App/Logger/Logger.h"

WiFiConnectionFacade WiFiConnection {WIFI_SSID, WIFI_PASSWORD, WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET};
TaskSchedulerFacade& taskScheduler = TaskSchedulerFacade::getInstance();
TemperatureSensorFacade& temperatureSensor = TemperatureSensorFacade::getInstance();
Logger Ledlogger {GREEN_LED_PIN, RED_LED_PIN};


void setup() {
    Serial.begin(115200);

    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    Ledlogger.wifiConnection();
    WiFiConnection.initAndConnect();
    Ledlogger.wifiConnected();

    temperatureSensor.init();

    taskScheduler.addRepeatTaskInMinutes(10, GetTemperatureTask::run);
    taskScheduler.addTaskInSeconds(5, GetTemperatureTask::run);
}

void loop() {
    if(!WiFiConnection.isConnected()) {
        Ledlogger.wifiConnection();
        WiFiConnection.reconnect();
        Ledlogger.wifiConnected();
    }

    taskScheduler.handleTask();
}
