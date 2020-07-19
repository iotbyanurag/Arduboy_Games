
#include <Arduboy.h>
#include "bitmaps.h"
#define JUMP_COORDINATE 35
//#include <Arduboy2.h>
// make an instance of arduboy used for many functions
Arduboy arduboy;
unsigned int BUTTON_PRESS_COUNTER = 0;
// make an ArdBitmap instance that will use the given the screen buffer and dimensions
//#define ARDBITMAP_SBUF arduboy.getBuffer()
////#include "Arduboy2Ext.h"
//#include <ArdBitmap.h>
//ArdBitmap<WIDTH, HEIGHT> ardbitmap;
//Arduboy2Ext arduboyNew;
// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  // initiate arduboy instance
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.clear();
  arduboy.drawSlowXYBitmap(0,0,TEAM_LOGO,128,54,1); // GAME LOGO IS DISPLAYED FOR 8 SECONDS.
   arduboy.display();
    delay(3000);
  
  Start_Game(); // GAME SCREEN IS DISPLAYED
}
// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
// statements written/ functions called in this loop are executed continuously, untill the microprocessor is switched off.
void loop(){
  // pause render until it's time for the next frame

   if (!(arduboy.nextFrame()))
    return;

     if(arduboy.pressed(RIGHT_BUTTON)){
    //digitalWrite(RED_LED, LOW); 
    delay(150);
    BUTTON_PRESS_COUNTER = BUTTON_PRESS_COUNTER+1;  // initial value of COUNTER was 0, now the value =1 
   }
   
   else if(arduboy.pressed(LEFT_BUTTON)){
    //digitalWrite(GREEN_LED, LOW);
     delay(150);
    BUTTON_PRESS_COUNTER = BUTTON_PRESS_COUNTER-1;
   }
       
     if (BUTTON_PRESS_COUNTER >2 ){
      BUTTON_PRESS_COUNTER = 0;
    }
    
    if( BUTTON_PRESS_COUNTER == 1){
    arduboy.clear();
   arduboy.drawSlowXYBitmap(0,0,BOY,128,41,1); 
     arduboy.drawSlowXYBitmap(38,47,ARROW,48,48,1); // arrow jumps to right on pressing the RIGHT BUTTON
     arduboy.display();
   }
   else if(BUTTON_PRESS_COUNTER == 2){
    arduboy.clear();
     arduboy.drawSlowXYBitmap(0,0,BOY,128,41,1); 
     arduboy.drawSlowXYBitmap(80,47,ARROW,48,48,1); // arrow jumps to right on pressing the RIGHT BUTTON
     arduboy.display();
   }
   else{
     arduboy.clear();  
     arduboy.drawSlowXYBitmap(0,0,BOY,128,41,1); 
     arduboy.drawSlowXYBitmap(0,47,ARROW,48,48,1); // arrow jumps to right on pressing the RIGHT BUTTON
     arduboy.display();
   }

    if((arduboy.pressed(B_BUTTON))){
      resetGame();  
  }
  // first we clear our screen to black
  if((arduboy.pressed(A_BUTTON))&&(BUTTON_PRESS_COUNTER==0)){
     arduboy.setRGBled(255,0,0);
  }
  else if ((arduboy.pressed(A_BUTTON))&&(BUTTON_PRESS_COUNTER==1)) {
    arduboy.setRGBled(0,0,0);
    digitalWrite(GREEN_LED,LOW);
    
  }
 else if ((arduboy.pressed(A_BUTTON))&&(BUTTON_PRESS_COUNTER==2)) {
    arduboy.setRGBled(0,0,0);
    digitalWrite(BLUE_LED,LOW);
    
  } 
}
void Start_Game(){
  // draw the three circle bitmap on the whole screen (128,4
    arduboy.drawSlowXYBitmap(0,0,BOY,128,41,1);
    arduboy.display();
    //Draw the arro at home position (0,47)
    arduboy.drawSlowXYBitmap(0,47,ARROW,48,48,1);
    arduboy.display();
}

void resetGame(){
   arduboy.setRGBled(0,0,0);
    arduboy.clear();
   arduboy.drawSlowXYBitmap(0,0,TRY_AGAIN,128,54,1); // GAME LOGO IS DISPLAYED FOR 8 SECONDS.
    arduboy.display();
   delay(2000);
}
