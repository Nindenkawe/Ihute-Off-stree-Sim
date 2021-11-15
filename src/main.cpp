#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <ThingerESP8266.h>
#include <arduino_secrets.h>
#include <HCSR04.h>

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
#define trigPin D4
#define echoPin D5

long duration, dht;
int distance;

void setup() {
  //pinmode setup
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input;
  // open serial for monitoring
  Serial.begin(115200);

  // add WiFi credentials
  thing.add_wifi(SSID, SSID_PASSWORD);

  // resource output example (i.e. reading a sensor value)
  thing["distance"] >> outputValue(duration());
};

  // more details at http://docs.thinger.io/arduino/

void loop() {
  thing.handle();
  // Clears the trigPin
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}