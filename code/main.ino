#include <WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>

#define ONE_WIRE_BUS 4
#define LED_PIN 5
#define NUMPIXELS 1

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void reconnectMQTT() {

  while (!client.connected()) {

    Serial.println("Conectando ao MQTT...");

    if (client.connect("fernanda_termoPets_9876")) {

      Serial.println("MQTT conectado!");

    } else {

      Serial.println("Falha MQTT");
      delay(2000);

    }
  }
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao WiFi...");
  }

  Serial.println("WiFi conectado!");

  client.setServer(mqtt_server, 1883);

  sensors.begin();
  pixels.begin();
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {

    if (!client.connected()) {
      reconnectMQTT();
    }

    client.loop();
  }

  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  Serial.print("Temp: ");
  Serial.println(temp);

  if (temp <= 25) {
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  } else if (temp <= 30) {
    pixels.setPixelColor(0, pixels.Color(255, 255, 0));
  } else {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  }

  pixels.show();

  if (client.connected()) {

    char tempString[8];
    dtostrf(temp, 1, 2, tempString);

    client.publish("termoPets/temperatura", tempString);

    if (temp <= 25) {

     client.publish("termoPets/alerta", "SEGURO");

    } else if (temp <= 30) {

      client.publish("termoPets/alerta", "ATENCAO");

    } else {

      client.publish("termoPets/alerta", "PERIGO");

    }
  }

  delay(1000);
} 
