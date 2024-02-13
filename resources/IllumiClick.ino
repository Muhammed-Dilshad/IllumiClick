#include <FirebaseESP32.h>
#include <WiFi.h>

// Firebase configuration
#define FIREBASE_HOST "https://led-with-app-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "file:///E:/MD/python%20GUI/ledonline%202/led-with-app-firebase-adminsdk-poyif-b3e9ccd773.json"

// Wi-Fi configuration
#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASSWORD "your_wifi_password"

// LED pin configuration
#define LED_PIN 13 // Assuming the LED is connected to pin 13

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Read LED state from Firebase
  Firebase.getString("LED_STATE");
  if (Firebase.getString("LED_STATE") == "ON") {
    digitalWrite(LED_PIN, HIGH); // Turn ON the LED
  } else {
    digitalWrite(LED_PIN, LOW); // Turn OFF the LED
  }

  delay(1000); // Adjust delay as needed
}
