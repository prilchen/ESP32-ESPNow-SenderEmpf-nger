# ESP-NOW Kommunikation mit ESP32

Dieses Projekt zeigt, wie zwei ESP32-Boards über ESP-NOW miteinander kommunizieren können.
Dieses Beispiel zeigt eine Broadcast Lösung, die mit weiteren ESP32 ergänzt werden kann ohne dem Sender die MAC Adressen mitzuteilen.

## Komponenten
- 2x ESP32-C6
- Rote LED
- Grüne LED
- Taster
- 2x Widerstände 220 Ohm

## Library 
- Verwendet wird die Arduino IDE in Version 2.3.x zusammen mit dem ESP32 Board Support Package ab Version 3, das über den Boardverwalter installiert wird.

## Dateien
- `espnow_sender.ino`: Sendet Nachrichten über ESP-NOW
- `espnow_receiver.ino`: Empfängt Nachrichten und zeigt sie im Serial Monitor

## Anleitung
1. `espnow_sender.ino` auf das erste ESP32-c6 mit Taster am Pin 4 und dann flashen
2. `espnow_receiver.ino` auf das zweite ESP32-c6 mit LED am Pin 2 und dann flashen
3. Beide Boards mit Strom versorgen und über Serial Monitor beobachten
4. Beim drücken des Tasters muss am anderen Board LED leuchten
5. Da dies eine Broadcast Lösung zeigt, können weiteren ESP32 ergänzt werden, ohne dem Sender die MAC Adressen mitzuteilen.

## Vorschau
![Beitragsbild ESP-NOW](https://prilchen.de/wp-content/uploads/2025/09/espnowmittext-1024x532.png)


## Hintergrund
ESP-NOW ist ein schnelles, verbindungsloses Kommunikationsprotokoll von Espressif. Ideal für IoT-Projekte ohne Netzwerk.
