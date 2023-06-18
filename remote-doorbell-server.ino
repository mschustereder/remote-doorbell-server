#include <SoftwareSerial.h>

SoftwareSerial espSerial(0, 1); // RX, TX pins for ESP8266 communication
String ssid = "UPC0064066";
String password = "Tj8hRnkdvzvs";
String serverIP = "192.168.0.111"; // IP address of your Arduino in the local network
int serverPort = 80; // Port number for the web server
int buzzerPin = 12; // Pin number for the buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  espSerial.begin(9600);
  connectToWiFi();
  startServer();
}

void loop() {
  if (espSerial.available()) {
    Serial.println("hey new");
    ringBuzzer();
    // espSerial.println("response!");
    // String response = espSerial.readStringUntil('\n');
    // Serial.println(response);

    // if (response.indexOf("GET /ring") != -1) {
    //   ringBuzzer();
    // }
  }
}

void connectToWiFi() {
  espSerial.println("AT+CWMODE=1"); // Set ESP8266 to station mode
  delay(1000);
  espSerial.println("AT+QAP"); // Set ESP8266 to station mode
  delay(1000);
  espSerial.print("AT+CWJAP=\"");
  espSerial.print(ssid);
  espSerial.print("\",\"");
  espSerial.print(password);
  espSerial.println("\""); // Connect to WiFi network
  delay(3000);
}

void startServer() {
  Serial.println("Starting server...");
  espSerial.println("AT+CIPMUX=1"); // Enable multiple connections
  delay(1000);
  espSerial.print("AT+CIPSERVER=1,");
  espSerial.println(serverPort); // Start the server
  delay(1000);
}

void ringBuzzer() {
  digitalWrite(buzzerPin, HIGH);
  delay(500);
  digitalWrite(buzzerPin, LOW);
  delay(500);
}
