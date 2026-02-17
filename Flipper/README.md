# DHT11 Sensor für Flipper Zero

Dieses Projekt zeigt, wie man einen DHT11 Temperatur- und Feuchtigkeitssensor mit dem Flipper Zero verwendet.

## Verdrahtung

```
DHT11 Sensor -> Flipper Zero GPIO
=================================
VCC   -> 3.3V (Pin 1)
GND   -> GND  (Pin 3)
DATA  -> PB3  (Pin 5)
```

## Installation

### Methode 1: Fertige App verwenden (empfohlen)

1. **Unitemp App** (unterstützt viele Sensoren):
   - Installieren von: https://lab.flipper.net/apps/unitemp
   - Unterstützt DHT11, DHT22, DS18B20, BMP280 und mehr

2. **DHT11 Sensor App** (speziell für DHT11):
   - GitHub: https://github.com/javi-canon/flipper-dht11-sensor
   - Konfigurierbare GPIO-Pins und Einheiten

### Methode 2: Eigene App kompilieren

1. Flipper Zero Development Environment einrichten
2. Dieses Projekt in `applications_user/dht11_example/` kopieren
3. Kompilieren mit: `ufbt`
4. `.fap` Datei auf den Flipper Zero kopieren

## Verwendung

1. Sensor wie oben beschrieben anschließen
2. App auf dem Flipper Zero starten
3. Temperatur und Luftfeuchtigkeit werden alle 2 Sekunden aktualisiert
4. Mit BACK-Taste die App beenden

## Code-Beispiel

Das Hauptbeispiel (`dht11_example.c`) zeigt:
- GPIO-Konfiguration für den DHT11
- Timing-kritische Kommunikation mit dem Sensor
- CRC-Prüfung der Daten
- Einfache GUI-Anzeige der Werte

## Fehlerbehebung

- **Keine Daten**: Verdrahtung prüfen, besonders DATA-Pin
- **Falsche Werte**: Stromversorgung prüfen, DHT11 braucht stabile 3.3V
- **Timeout**: Sensor zu weit vom Flipper entfernt (kurze Kabel verwenden)

## GPIO-Pin Alternativen

Falls Pin 5 (PB3) belegt ist, können Sie auch verwenden:
- Pin 6 (PB2)
- Pin 7 (PC3)

Passen Sie im Code `#define DHT_PIN` entsprechend an.