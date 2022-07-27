
#include <TFT_eSPI.h>
#include <SPI.h>

// 18x18 wifi icon bitmap in 565 format
const uint16_t wifi_icon[324] = {
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // row 0, 18 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // row 1, 36 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // row 2, 54 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x2A2A, 0x4C54, 0x655A, 0x6D9B, 0x6D9B, 0x655A, 0x5455, 0x2A4B, 0x0041, 0x0000, 0x0000, 0x0000, 0x0000, // row 3, 72 pixels
  0x0000, 0x0000, 0x0000, 0x32AD, 0x655A, 0x5D5A, 0x5D5A, 0x5539, 0x4CB7, 0x4CB7, 0x5539, 0x5D5A, 0x5D5A, 0x655A, 0x32CD, 0x0000, 0x0000, 0x0000, // row 4, 90 pixels
  0x0000, 0x0041, 0x5476, 0x5D3A, 0x5519, 0x2AAD, 0x0883, 0x0000, 0x0000, 0x0000, 0x0000, 0x0882, 0x2A8D, 0x54F9, 0x5D3A, 0x5496, 0x0062, 0x0000, // row 5, 108 pixels
  0x0000, 0x4C55, 0x5519, 0x3BD2, 0x0041, 0x0000, 0x0000, 0x08E4, 0x19A7, 0x19A7, 0x08E4, 0x0000, 0x0000, 0x0041, 0x3BB2, 0x5519, 0x4C96, 0x0000, // row 6, 126 pixels
  0x0000, 0x222A, 0x2ACE, 0x0000, 0x0000, 0x2A6C, 0x54F8, 0x5519, 0x4CF9, 0x4CF9, 0x5519, 0x54F8, 0x2A8C, 0x0000, 0x0000, 0x2AAD, 0x224B, 0x0000, // row 7, 144 pixels
  0x0000, 0x0000, 0x0000, 0x0020, 0x4414, 0x4CF8, 0x4CB7, 0x3330, 0x19C9, 0x19C9, 0x332F, 0x4CB7, 0x4CF8, 0x4434, 0x0020, 0x0000, 0x0000, 0x0000, // row 8, 162 pixels
  0x0000, 0x0000, 0x0000, 0x08E4, 0x44D8, 0x3392, 0x0041, 0x0000, 0x0882, 0x0882, 0x0000, 0x0041, 0x3371, 0x44D8, 0x1105, 0x0000, 0x0000, 0x0000, // row 9, 180 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x08C4, 0x0000, 0x1167, 0x4C96, 0x4CD8, 0x4CD8, 0x4C96, 0x1987, 0x0000, 0x08C4, 0x0000, 0x0000, 0x0000, 0x0000, // row 10, 198 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4497, 0x3C76, 0x2B30, 0x2B0F, 0x3C76, 0x4497, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // row 11, 216 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x11A8, 0x0905, 0x1167, 0x1167, 0x0905, 0x19C9, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // row 12, 234 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0062, 0x3C76, 0x3C76, 0x0082, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // row 13, 252 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x2BB3, 0x2BD3, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // row 14, 270 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // row 15, 288 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // row 16, 306 pixels
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
}; // row 17, 324 pixels


// For the breakout, you can use any 2 or 3 pins
// These pins will also work for the 1.8" TFT shield
#define TFT_CS     D1
#define TFT_RST    D0  // you can also connect this to the Arduino reset
// in which case, set this #define pin to -1!
#define TFT_DC     D2


TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h
//=========================================================================
// WiFi
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "credentials.h"
//const char* ssid     = "xxxxx";
//const char* password = "xxxx";
//=========================================================================
// OTA
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
//=========================================================================
// Date/Time/NTP
// https://github.com/mcxiaoke/ESPDateTime
#include <ESPDateTime.h>
//=========================================================================
const int STATE_OFF = 0;
const int STATE_ON = 1;
const int STATE_BOOST = 2;
int _state = STATE_OFF;
byte _triggered = 0;
int _progressRadius = 0;
const byte _relayOutputPin = D6;    //D4 is the internal LED
//=========================================================================
const byte _boostInterruptPin = D3;
void IRAM_ATTR boostInterruptISR() {
  if (_triggered == 0)
  {
    // Has to be declared before interrupt definition
    if (_state != STATE_BOOST)
    {
      _state = STATE_BOOST;
    }
    else
    {
      _state =  STATE_OFF;
    }
    _triggered = 1;
  }
}
//=========================================================================

void setup(void) {
  Serial.begin(9600);

  tft.init();
  tft.setRotation(3);
  tft.fillScreen(ST7735_BLACK);
  connectWiFi();
  initOTA();
  setupDateTime();

  pinMode(_boostInterruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(_boostInterruptPin), boostInterruptISR, FALLING);

  pinMode(_relayOutputPin, OUTPUT);

  tft.fillScreen(ST7735_BLACK);
  drawWiFiState();
  Serial.println("Exiting Setup()");
}

void loop() {
  debounce();
  setState();
  drawBorder();
  drawText();
  delay(100);
}

bool connectWiFi() {
  // Init WiFi
  Serial.println("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    drawConnecting();
    Serial.print(".");
    delay(5);
  }
  Serial.println("");
  Serial.println("Connected");
  //showSSID(ssid);
  return true;
}

void setupDateTime() {
  Serial.println("Setting time");
  DateTime.setTimeZone("NZST-12NZDT,M9.5.0,M4.1.0/3");
  DateTime.setServer("nz.pool.ntp.org");
  DateTime.begin(15000);
  if (!DateTime.isTimeValid()) {
    Serial.println("Failed to get time from server.");
  }
  else
  {
    Serial.println("Time set from NTP server");
  }
}


void initOTA() {
  // Init OTA
  // Port defaults to 8266
  ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  ArduinoOTA.setHostname("car-charger");

  ArduinoOTA.onStart([]() {
    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    //showReceiveProgram();
  });
  ArduinoOTA.onEnd([]() {
    //
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    //
  });
  ArduinoOTA.onError([](ota_error_t error) {
    //showOTAError(error);
  });
  ArduinoOTA.begin();
}

void debounce()
{
  if (_triggered > 0) {
    _triggered++;
    if (_triggered > 2)
    {
      _triggered = 0;
    }
  }
}

void setState()
{
  int hr = DateTime.getParts().getHours();

  // On from 11PM till 9AM
  if (hr > 22 || hr < 9)
  {
    // Even if we're in BOOST mode and hr > 21, then switch back to normal mode
    _state = STATE_ON;
  }
  else
  {
    if (_state != STATE_BOOST)
    {
      _state = STATE_OFF;
    }
  }

  if (_state > STATE_OFF)
  {
    digitalWrite(_relayOutputPin, HIGH);
  }
  else
  {
    digitalWrite(_relayOutputPin, LOW);
  }
}


void drawConnecting() {
  if (_progressRadius == 0)
  {
    drawWiFiIcon(55, 55);
    _progressRadius = 10;
  }
  // Blanking from last scan
  tft.drawCircle(64, 64, _progressRadius, ST7735_BLACK);

  _progressRadius += 1;

  tft.drawCircle(64, 64, _progressRadius, ConvertRGB(0, 0, 250));
  tft.drawCircle(64, 64, _progressRadius + 1, ConvertRGB(0, 0, 200));
  tft.drawCircle(64, 64, _progressRadius + 2, ConvertRGB(0, 0, 150));
  tft.drawCircle(64, 64, _progressRadius + 3, ConvertRGB(0, 0, 100));
  tft.drawCircle(64, 64, _progressRadius + 4, ConvertRGB(0, 0, 50));
  if (_progressRadius > 100) {
    _progressRadius = 10;
  }
}

int ConvertRGB( byte R, byte G, byte B)
{
  return ( ((R & 0xF8) << 8) | ((G & 0xFC) << 3) | (B >> 3) );
}

void drawWiFiIcon(int startx, int starty) {
  for (int y = 0; y < 18; y++)
  {
    for (int x = 0; x < 18; x++)
    {
      int idx = y * 18 + x;
      tft.drawPixel(x + startx, y + starty, wifi_icon[idx]);
    }
  }
}

void drawBorder() {
  int colour = getStateColour();
  tft.drawRoundRect(0, 0, 128, 128, 5, colour);
  tft.drawRoundRect(1, 1, 126, 126, 5, colour);
  tft.drawRoundRect(2, 2, 124, 124, 5, colour);
  tft.drawRoundRect(3, 3, 122, 122, 5, colour);
  tft.drawRoundRect(4, 4, 120, 120, 5, colour);
  tft.drawRoundRect(5, 5, 118, 118, 5, colour);
}

void drawWiFiState()
{
  drawWiFiIcon(15, 100);
  tft.setCursor(40, 105);
  tft.setTextSize(1);
  tft.print(ssid);
}

void drawText()
{
  static int lastState = -1;
  tft.setCursor(33, 20);
  tft.setTextColor(ST7735_YELLOW, ST7735_BLACK);
  tft.setTextFont(1);
  tft.println(DateTime.format(DateFormatter::DATE_ONLY).c_str());
  tft.setTextFont(4);
  tft.setCursor(16, 40);
  tft.println(DateTime.format(DateFormatter::TIME_ONLY).c_str());
  tft.setTextColor(getStateColour(), ST7735_BLACK);

  if (lastState != _state)
  {
    tft.fillRect(5, 70, 118, 20, ST7735_BLACK);
    if (_state == STATE_OFF)
    {
      tft.setCursor(40, 70);
      tft.println("OFF");
    }
    else if (_state == STATE_ON)
    {
      tft.setCursor(44, 70);
      tft.println("ON");
    }
    else
    {
      tft.setCursor(22, 70);
      tft.println("BOOST");
    }
    lastState = _state;
  }
}

int getStateColour() {
  int colour = 0;
  if (_state == STATE_OFF)
  {
    colour =  ST7735_BLUE;
  }
  else if (_state == STATE_ON)
  {
    colour =  ST7735_GREEN;
  }
  else
  {
    colour =  ST7735_RED;
  }
  return colour;
}
