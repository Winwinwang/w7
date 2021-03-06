//include library
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Define Variables
#define OLED_MOSI   11 //D1
#define OLED_CLK   12 //D0
#define OLED_DC    9 //DC
#define OLED_CS    8 //CS
#define OLED_RESET 10 //RES
const int buttonPin = A0;
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

int buttonState =0;

void text(){
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(30,10);
  display.print("HELLO!");
  display.display();
};
static const unsigned char PROGMEM Logo[]={
  0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,
  0x00,0x00,0x3f,0x00,0x01,0xfe,0x00,0x00,
  0x00,0x00,0xff,0x80,0x03,0xff,0x00,0x00,
  0x00,0x01,0xff,0xc0,0x03,0xff,0x80,0x00,
  0x00,0x01,0xff,0xc0,0x07,0xff,0x80,0x00,
  0x00,0x03,0xff,0xc0,0x07,0xff,0xc0,0x00,
  0x00,0x03,0xff,0xe0,0x07,0xff,0xc0,0x00,
  0x00,0x03,0xff,0xef,0xff,0xff,0xc0,0x00,
  0x00,0x03,0xff,0xf7,0xff,0xff,0xc0,0x00,
  0x00,0x07,0xff,0xe3,0xc7,0xff,0xc0,0x00,
  0x00,0x03,0xff,0xc9,0x13,0xff,0x80,0x00,
  0x00,0x01,0xff,0xd0,0x09,0xff,0x80,0x00,
  0x00,0x01,0xff,0x80,0x01,0xff,0x00,0x00,
  0x00,0x00,0x7f,0x80,0x01,0xf4,0x00,0x00,
  0x00,0x00,0x03,0x88,0x51,0xc0,0x00,0x00,
  0x00,0x00,0x03,0x08,0x49,0xe0,0x00,0x00,
  0x00,0x00,0x07,0x88,0x80,0xe0,0x00,0x00,
  0x00,0x00,0x07,0x8a,0xe9,0xe0,0x00,0x00,
  0x00,0x00,0x07,0x8f,0x79,0xe0,0x00,0x00,
  0x00,0x00,0x07,0x8f,0x71,0xe0,0x00,0x00,
  0x00,0x00,0x03,0xc7,0xe3,0xe0,0x00,0x00,
  0x00,0x00,0x03,0x87,0xf0,0x60,0x00,0x00,
  0x00,0x00,0x02,0xc6,0xf1,0xa0,0x00,0x00,
  0x00,0x00,0x07,0xc7,0xe1,0xa0,0x00,0x00,
  0x00,0x00,0x02,0x41,0x42,0x60,0x00,0x00,
  0x00,0x00,0x02,0x30,0x04,0x40,0x00,0x00,
  0x00,0x00,0x01,0x0f,0xb8,0xc0,0x00,0x00,
  0x00,0x00,0x00,0xe7,0xff,0x00,0x00,0x00,
  0x00,0x00,0x00,0x3c,0x3e,0x00,0x00,0x00,
  0x00,0x00,0x00,0x0f,0xf8,0x00,0x00,0x00,
  0x00,0x00,0x00,0x07,0xa0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,
  
};

void pic(){
  display.clearDisplay();
  display.drawBitmap(23,0,Logo,64,32,WHITE);
  display.display();
};
void setup() {
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH);
  Serial.begin(9600);
  //pinMode(Light_PIN,INPUT);
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextWrap(false);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW){
    text();
    }
  else{
    pic();
    }
}
