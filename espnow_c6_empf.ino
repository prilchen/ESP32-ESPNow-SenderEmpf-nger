// verwendetes Entwicklungsboard ESP32-C6

#include <WiFi.h>
#include <esp_now.h>

// Struktur für empfangene Daten
typedef struct {
  bool tasterGedrueckt;
} struct_message;

struct_message empfangeneDaten;

// Callback-Funktion bei Empfang 
void OnDataRecv(const esp_now_recv_info *recv_info, const uint8_t *incomingData, int len) {
  memcpy(&empfangeneDaten, incomingData, sizeof(empfangeneDaten));

  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
           recv_info->src_addr[0], recv_info->src_addr[1], recv_info->src_addr[2],
           recv_info->src_addr[3], recv_info->src_addr[4], recv_info->src_addr[5]);

  Serial.printf("Empfangen von %s → Tasterstatus: %s\n",
                macStr,
                empfangeneDaten.tasterGedrueckt ? "GEDRÜCKT" : "NICHT gedrückt");

  // Beispielhafte Reaktion: LED an GPIO 2 schalten
  digitalWrite(2, empfangeneDaten.tasterGedrueckt ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);

  // GPIO 2 als Ausgang für LED oder Relais
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW); // Initialzustand: aus

  // WiFi im Station Mode aktivieren
  WiFi.mode(WIFI_STA);

  // ESP-NOW initialisieren
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init fehlgeschlagen!");
    return;
  }

  // Empfangs-Callback registrieren
  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("ESP-NOW Empfänger bereit.");
}

void loop() {
  // Keine aktive Logik im Loop nötig – alles passiert im Callback
  delay(1000);
}


