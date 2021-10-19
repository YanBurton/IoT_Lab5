#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
FASTLED_USING_NAMESPACE

#define DATA_PIN            5
#define NUM_LEDS            39
#define MAX_POWER_MILLIAMPS 500
#define LED_TYPE            WS2812B
#define COLOR_ORDER         GRB

//Input pins
int potPin0 = 0;
int potPin1 = 1;
int potPin2 = 3;

//Variables to store analog input
int red = 0;
int green = 0;
int blue = 0;

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  delay(3000);
  FastLED.addLeds<LED_TYPE,DATA_PIN,GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //setting up LEDs
  FastLED.setMaxPowerInVoltsAndMilliamps( 5, MAX_POWER_MILLIAMPS);
  FastLED.clear(); //clear colours
  fill_solid(leds, NUM_LEDS, CRGB(0,0,0)); //set colour values to nothing
  FastLED.show(); //show colour values on LEDs
}

void loop() {
  int red = analogRead(potPin0) / 4;
  int green = analogRead(potPin1) / 4;
  int blue = analogRead(potPin2) / 4;
  //Serial.println("red: " + red); //for testing purposes
  //Serial.println("green: " + green); //for testing purposes
  //Serial.println("blue: " + blue); //for testing purposes
  fill_solid(leds, NUM_LEDS, CRGB(red,green,blue));
  FastLED.show();
  //delay(1000); //for testing purposes

}
