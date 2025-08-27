// verwendetes Entwicklungsboard ESP32-C6

#include <WiFi.h>
#include <esp_now.h>

#define BUTTON_PIN 4

typedef struct {
  bool tasterGedrueckt;
} struct_message;

struct_message daten;

uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init fehlgeschlagen!");
    return;
  }

  // Broadcast-Peer registrieren
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Fehler beim Hinzufügen des Broadcast-Peers!");
    return;
  }

  Serial.println("Sender bereit – Tasterstatus wird per Broadcast gesendet.");
}

void loop() {
  daten.tasterGedrueckt = digitalRead(BUTTON_PIN) == LOW;

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)&daten, sizeof(daten));

  if (result == ESP_OK) {
    Serial.printf("Gesendet: %s\n", daten.tasterGedrueckt ? "GEDRÜCKT" : "NICHT gedrückt");
  } else {
    Serial.println("Sende-Fehler!");
  }

  delay(500);
}
