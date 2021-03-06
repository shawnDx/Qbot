#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// if there is error include linefollow.h

#ifndef display_h
    #define display_h

    // If using software SPI (the default case):
    #define OLED_MOSI   9
    #define OLED_CLK   10
    #define OLED_DC    11
    #define OLED_CS    12
    #define OLED_RESET 13
    Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

    /* Uncomment this block to use hardware SPI
    #define OLED_DC     6
    #define OLED_CS     7
    #define OLED_RESET  8
    Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);
    */

    #define NUMFLAKES 10
    #define XPOS 0
    #define YPOS 1
    #define DELTAY 2

    #define LOGO16_GLCD_HEIGHT 16 
    #define LOGO16_GLCD_WIDTH  16 
    static const unsigned char PROGMEM logo16_glcd_bmp[] =
    { B00000000, B11000000,
    B00000001, B11000000,
    B00000001, B11000000,
    B00000011, B11100000,
    B11110011, B11100000,
    B11111110, B11111000,
    B01111110, B11111111,
    B00110011, B10011111,
    B00011111, B11111100,
    B00001101, B01110000,
    B00011011, B10100000,
    B00111111, B11100000,
    B00111111, B11110000,
    B01111100, B11110000,
    B01110000, B01110000,
    B00000000, B00110000 };

    #if (SSD1306_LCDHEIGHT != 64)
    #error("Height incorrect, please fix Adafruit_SSD1306.h!");
    #endif

    void dispalyInit(){

    display.begin(SSD1306_SWITCHCAPVCC);
    display.clearDisplay();
    display.display();
    }

    void displayTest(void){

        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);

        for(int i=0;i<50;i++){

            display.print(i);
            display.display();
            delay(1000);
        }

        display.clearDisplay();
    }

    void printValues (double value) {
        display.clearDisplay();
        display.setCursor(0,0);
        display.print(value,4);
        display.display();
    }

    void displayKp (void){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("Kp Value");
        display.print(" Base Val ");
        display.println(FULL_SPEED_Kp,4);
        display.display();
    }

    void displayKd (void){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("Kd Value");
        display.print("Base Val ");
        display.println(FULL_SPEED_Kd,4);
        display.display();
    }


     void displayWallKp (void){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("Kp Value");
        display.print(" Base Val ");
        display.println(WALL_FULL_SPEED_Kp,4);
        display.display();
    }

    void displayWallKd (void){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("Kd Value");
        display.print("Base Val ");
        display.println(WALL_FULL_SPEED_Kd,4);
        display.display();
    }


    void displayChangePID(void){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("1.Change Kp");
        display.println("2.Change Kd");
        display.display();
    }

    void displayMainMenu(void){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("1.Line Fllow");
        display.println("2.Solve maze");
        display.println("3.Wall Follow");
        display.println("4.Calibrate");
        display.display();
    }
    void displayLIneFllow(){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("1.Line Fllow");
        display.println("2.ChangPid");
        display.display();
    }

    void displayWallFllow(){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("1.Wall Fllow");
        display.println("2.ChangPid");
        display.display();
    }

       void displayText(String text){

        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println(text);
        display.display();
    }
#endif