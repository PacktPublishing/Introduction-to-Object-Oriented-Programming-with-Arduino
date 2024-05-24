#include <Arduino.h>

AsyncWebServer server(80);

// Create an Event Source on /events
AsyncEventSource events("/events");

String processor(const String& var) {
   return "";
}

void connectAP()
{
    Serial.println("Connecting to WiFi..");
    WiFi.begin(ssid, password);
    int cnt = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
        cnt++;

        if (cnt > 20)
            break;
    }
    Serial.println(WiFi.localIP());
}