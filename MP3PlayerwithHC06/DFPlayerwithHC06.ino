/*
 * MP3 Player with DFPlayer Mini, Bluetooth (HC-05) Module
 * Made by Darkhost (darkhost225@gmail.com)
 * Required Library : SoftwareSerial, DFRobotDFPlayerMini
 * Last Update : 2018.06.22
 * Bluetooth RX - 8 / TX - 9
 * DFPlayer RX - 11 / TX - 12
 * Serial Speed 115200 / DFPlayer Serial Speed 9600 / Bluetooth Serial Speed 19200
 */

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// RX, TX Setting
#define BT_RX 8
#define BT_TX 9
#define DF_RX 11
#define DF_TX 12

// Module Setting
SoftwareSerial BT(BT_TX, BT_RX);
SoftwareSerial DF(DF_TX, DF_RX);
DFRobotDFPlayerMini DFPlayer;

// Variable
String rstring;

void setup() {
  Serial.begin(115200);
  Serial.println("MP3 Player with Bluetooth (HC-05) Module");
  Serial.println("Made by Darkhost (darkhost225@gmail.com)");
  DF.begin(9600);
  
  if(!DFPlayer.begin(DF)) {
    Serial.println("Can't load DFPlayer.");
    while(true);
  }
  
  Serial.println("DFPlayer Loaded.");
  DFPlayer.volume(15);

  BT.begin(19200);
}

void loop() {
  delay(1000);
  if(BT.available()) {
    rstring = BT.readString();
    Serial.println(rstring);
    if(rstring == "play") {
      DFPlayer.play(1);
    }
    if(rstring == "next") {
      DFPlayer.next();
    }
    if(rstring == "pause") {
      DFPlayer.pause();
    }
  }
}
