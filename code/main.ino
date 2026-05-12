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

void setup_wifi() {
  delay(10);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Conectando ao WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("conectado");
    } else {
      Serial.print("erro, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void setup() {
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  sensors.begin();
  pixels.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C");

  if (temp <= 25) {
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  } else if (temp <= 30) {
    pixels.setPixelColor(0, pixels.Color(255, 255, 0));
  } else {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  }

  pixels.show();

  char tempString[8];
  dtostrf(temp, 1, 2, tempString);
  client.publish("termoPets/temperatura", tempString);

  delay(2000);
}
