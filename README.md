# ESP-NOW Kommunikation mit ESP32

Dieses Projekt zeigt, wie zwei ESP32-Boards über ESP-NOW miteinander kommunizieren können.
Dieses Beispiel zeigt eine Broadcast Lösung, die mit weiteren ESP32 ergänzt werden kann ohne dem Sender die MAC Adressen mitzuteilen.

## 🔧 Komponenten
- 2x ESP32-C6 
- Arduino IDE 2.3.x mit ESP32 Board Support ab Version 3

## 📂 Dateien
- `espnow_sender.ino`: Sendet Nachrichten über ESP-NOW
- `espnow_receiver.ino`: Empfängt Nachrichten und zeigt sie im Serial Monitor

## 🚀 Anleitung
1. `espnow_sender.ino` auf das erste ESP32-c6 mit Taster am Pin 4 und dann flashen
2. `espnow_receiver.ino` auf das zweite ESP32-c6 mit LED am Pin 2 und dann flashen
3. Beide Boards mit Strom versorgen und über Serial Monitor beobachten
4. Beim drücken des Tasters muss am anderen Board LED leuchten
5. Da dies eine Broadcast Lösung zeigt, können weiteren ESP32 ergänzt werden, ohne dem Sender die MAC Adressen mitzuteilen.

## 📸 Vorschau
<img width="1538" height="801" alt="image" src="https://github.com/user-attachments/assets/90e4f89b-b57c-4a2e-8d37-25ebc0ad141d" />


## 🧠 Hintergrund
ESP-NOW ist ein schnelles, verbindungsloses Kommunikationsprotokoll von Espressif. Ideal für IoT-Projekte mit geringem Stromverbrauch.
