#include <SoftwareSerial.h>
#include <CytronEZMP3.h>
#include <Cytron_G15Shield.h>
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN   9    // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 3
#define G15_1 1
#define G15_2 2
#define LED 13


Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
Cytron_G15Shield g15(2, 3, 8); // SoftwareSerial: Rx, Tx and Control pin
CytronEZMP3 mp3;


int counter = 0;
int state = 0;
int lastState = 0;

void pattern (int counter);

void setup() {
  
  pinMode(7, INPUT);
  pinMode(12, OUTPUT);

  digitalWrite(12, HIGH);
  Serial.begin(9600);


  /* Servo Setting */
  g15.begin(19200);
  g15.exitWheelMode(G15_1);
  g15.exitWheelMode(G15_2);

  g15.setLED(G15_1, ON);
  g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
  g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
  
  g15.setLED(G15_2, ON);
  g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
  g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg


  /* MP3 Setting */
  if(!mp3.begin(10, 11))
  {
    Serial.println("Init failed");
    while(1);
  }
  mp3.setVolume(50);


  /* NeoPixel Setting */
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  counter = 0;
}


void loop() {
  
   state = digitalRead(7);
   Serial.println(digitalRead(7));
   
  if(state != lastState){
    if(state == HIGH){
     counter++;
     Serial.print("Counter:");
     Serial.println(counter);
      
        if(counter >= 11){
          counter = 1;
          }
          
     pattern(counter);

      }
      else{
      Serial.println("OFF");
      }
     delay(50);
  }
  
  lastState = state;

}


void pattern (int counter)
{
  switch(counter){
    
    case 1:  
    if(digitalRead(7) == HIGH){
      
        colorWipe(strip.Color(255, 0, 0), 30);
        mp3.playTrack(1);
    
        /* Controlling G15 with ID 1 and ID 2*/
    
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 150);
        g15.setPosAngle(G15_2, 50); 
        
        delay(600);
            
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 150);
        g15.setPosAngle(G15_1, 160); 
    
        delay(950);
    
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 150);
        g15.setPosAngle(G15_1, 250); 
    
        delay(600);
    
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 150);
        g15.setPosAngle(G15_2, 10);
    
    }else{
      
        colorWipe(strip.Color(0, 0, 0), 1);
        mp3.pause();

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg

    }

          
    case 2: 
    if(digitalRead(7) == HIGH){

        colorWipe(strip.Color(0, 255, 0), 150);
        mp3.playTrack(2);
    
        /* Controlling G15 with ID 1 and ID 2*/
    
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 50); 
        
        delay(300);
            
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 300);
        g15.setPosAngle(G15_1, 160); 
    
        delay(800);
    
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 300);
        g15.setPosAngle(G15_1, 250); 
    
        delay(300);
    
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 10);



        delay(1000);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 50); 
        
        delay(2000);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 10);

    }else{
       
        colorWipe(strip.Color(0, 0, 0), 1);
        mp3.pause();
      
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg
    }


    case 3: 
    if(digitalRead(7) == HIGH){

        colorWipe(strip.Color(0, 0, 255), 150);
        mp3.playTrack(3);
    
        /* Controlling G15 with ID 1 and ID 2*/

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 50); 
        
        delay(200);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 10);
         
        delay(200);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 60); 
        
        delay(200);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 10);
         
        delay(200);

         
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 50); 
        
        delay(400);
            
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 300);
        g15.setPosAngle(G15_1, 160); 
    
        delay(800);
    
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 300);
        g15.setPosAngle(G15_1, 250); 
    
        delay(300);
    
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 10);

    }else{
       
        colorWipe(strip.Color(0, 0, 0), 1);
        mp3.pause();

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg
    }


    case 4:  
    if(digitalRead(7) == HIGH){

        theaterChase(strip.Color(127, 127, 127), 50);
        mp3.playTrack(1);
    
        /* Controlling G15 with ID 1 and ID 2*/
    
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 50); 
        
        delay(600);
            
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 50);
        g15.setPosAngle(G15_1, 190); 
    
        delay(950);

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 50);
        g15.setPosAngle(G15_1, 210); 
    
        delay(800);
        
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 50);
        g15.setPosAngle(G15_1, 190); 
    
        delay(500);
        
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 50);
        g15.setPosAngle(G15_1, 158); 
    
        delay(1200);
    
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 300);
        g15.setPosAngle(G15_1, 250); 
    
        delay(2000);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 10);

        delay(1000);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 300);
        g15.setPosAngle(G15_2, 50); 
        
        delay(1000);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 50);
        g15.setPosAngle(G15_2, 10);

        delay(300);

    
    }else{
      
        colorWipe(strip.Color(0, 0, 0), 1);
        mp3.pause();
      
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg

    }


    case 5:  
    if(digitalRead(7) == HIGH){

        theaterChase(strip.Color(127,   0,   0), 50);
        mp3.playTrack(1);
    
        /* Controlling G15 with ID 1 and ID 2*/
    
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 80);
        g15.setPosAngle(G15_2, 30); 
        
        delay(300);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 80);
        g15.setPosAngle(G15_2, 40); 
        
        delay(900);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 80);
        g15.setPosAngle(G15_2, 50); 
        
        delay(900);

        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 150);
        g15.setPosAngle(G15_2, 10); 
        
        delay(2000);
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 150);
        g15.setPosAngle(G15_2, 50); 
        
        delay(600);

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 70);
        g15.setPosAngle(G15_1, 200); 
    
        delay(800);

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 700);
        g15.setPosAngle(G15_1, 170); 
    
        delay(800);

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 70);
        g15.setPosAngle(G15_1, 158); 
    
        delay(1000);
    
        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 150);
        g15.setPosAngle(G15_1, 250); 
    
        delay(600);
    
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 150);
        g15.setPosAngle(G15_2, 10);

        delay(600);
    
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 50);
        g15.setPosAngle(G15_2, 30);
        
        delay(600);
    
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 20);
        g15.setPosAngle(G15_2, 10);
    
    }else{

        colorWipe(strip.Color(0, 0, 0), 1);
        mp3.pause();

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg

    }


    case 6:
    if(digitalRead(7) == HIGH){

        //colorWipe(strip.Color(0, 0, 85), 150);
        mp3.playTrack(1);
    
        /* Controlling G15 with ID 1 and ID 2*/
    

    
    }else{

        colorWipe(strip.Color(0, 0, 0), 1);
        mp3.pause();

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg

    }
    
    case 7:
    if(digitalRead(7) == HIGH){

        //colorWipe(strip.Color(0, 160, 0), 150);
        mp3.playTrack(1);
    
        /* Controlling G15 with ID 1 and ID 2*/
    

    
    }else{

        colorWipe(strip.Color(0, 0, 0), 1);
        mp3.pause();

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg

    }
    
    case 8:
    if(digitalRead(7) == HIGH){

        //theaterChaseRainbow(50);
        mp3.playTrack(1);
    
        /* Controlling G15 with ID 1 and ID 2*/
    

    
    }else{

        colorWipe(strip.Color(0, 0, 0), 1);
        mp3.pause();

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg

    }
    
    case 9:
    if(digitalRead(7) == HIGH){

        //colorWipe(strip.Color(127, 127, 127), 150);
        mp3.playTrack(1);
    
        /* Controlling G15 with ID 1 and ID 2*/
    

    
    }else{

        colorWipe(strip.Color(0, 0, 0), 1);
        mp3.pause();

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg

    }

    case 10:
    if(digitalRead(7) == HIGH){

        //rainbowCycle(80);
        mp3.playTrack(1);
    
        /* Controlling G15 with ID 1 and ID 2*/
    

    
    }else{

        colorWipe(strip.Color(0, 0, 0), 1);
        mp3.pause();

        g15.setLED(G15_1, ON);
        g15.setSpeed(G15_1, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
        
        g15.setLED(G15_2, ON);
        g15.setSpeed(G15_2, 250); // Set G15 (ID = 1) speed to 250, 
        g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg

    }



    
 
    default: 
    colorWipe(strip.Color(0, 0, 0), 1);
    mp3.pause();
     
    /* Controlling G15 with ID 1*/
    g15.setLED(G15_1, OFF);
    g15.setSpeed(G15_1, 300); // Set G15 (ID = 1) speed to 250, 
    g15.setPosAngle(G15_1, 250); // Set G15 (ID = 1) position to 250 deg
 
    delay(800);
      
    g15.setLED(G15_2, OFF);
    g15.setSpeed(G15_2, 300); // Set G15 (ID = 1) speed to 150, 
    g15.setPosAngle(G15_2, 10); // Set G15 (ID = 1) position to 10 deg

    
    }
    

 }


 // Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<5; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 6; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


