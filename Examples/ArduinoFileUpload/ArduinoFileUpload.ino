//Arduino Uno with Matrix Orbital GLK19264A-7T-1U PCB Reev2.0 (I2C Mode) and BBC (Breadboard Cable)
//Created by Clark, 22/09/2014
//support@matrixorbital.ca 
//www.matrixorbital.ca/appnotes

#include <Wire.h>
#include <stdlib.h>
#include "glk_arduino.h"

#define I2C_Address 0x28  //Define default 8bit I2C address of 0x50 >> 1 for 7bit Arduino

unsigned int bitmap_id = 2;  //Bitmap file index
byte bitmap_data[] = { 5, 4, 80, 34, 224 };  //Width, height, plus three bytes smiley face data
unsigned long bitmap_size = 5;  //Size of bitmap file
char* error_message;

void setup(){
  Wire.begin();  //Setup I2C bus and serial reporting
  delay(1000);
  Serial.begin(19200);
  setReportingMode(0);  //Transmit via i2c port rather than serial
  char* message = "Uploading Image...";
  clearScreen();
  writeMessage(message, strlen(message));
  boolean success = UploadEightPointOneBitmap(bitmap_id, bitmap_size);
  if(success == true){
    error_message = "<- Displaying Image Here";
    Serial.print("Upload Successful!");
  }
  else{
    error_message = "Error Uploading Image!";
    Serial.print("Upload Error!");
  }
  delay(2000);
}

void loop(){  //Main loop
  clearScreen();
  DrawEightPointOneBitmap(bitmap_id, 1, 1);
  setCursorCoordinates(10, 0);
  writeMessage(error_message, strlen(error_message));
  delay(2000);
}

boolean UploadEightPointOneBitmap(unsigned int id, unsigned long file_size){  //Upload protocol for firmware revision 8.1 and higher only
  byte command[] = { GLK_CMD_BYTE, GLK_BITMAP_UPLOAD_FILE, (byte)(id), (byte)(id >> 8), (byte)(file_size), (byte)(file_size >> 8), (byte)(file_size >> 16), (byte)(file_size >> 24) };
  i2cWriteBytes(command, sizeof(command));  //Bitmap upload command
  byte size_response = i2cReadByte();  
  if (size_response != 1){  //Check that file will fit
    Serial.print(size_response);
    Serial.print("Size Error!");
    return false;
  }
  //Begin upload protocol (non-Xmodem)
  unsigned long i;
  for (i = 0; i < file_size; i++){
    Serial.print("Byte: ");
    Serial.print(i);
    byte data[] = { bitmap_data[i] };
    Serial.print("Writing: ");
    Serial.print(data[0]);
    i2cWriteBytes(data, 1);  //Write one data byte
    byte data_response = i2cReadByte();
    Serial.print("Response: ");
    Serial.print(data_response);
    if (data_response == data[0]){  //Check echo from display
      byte ack[] = { 1 };
      i2cWriteBytes(ack, 1);   //Confirm echo matches transmitted data
    }
    else{
      byte nack[] = { 8 };
      i2cWriteBytes(nack, 1);   //Abort upload for display and host if echo does not match
      Serial.print("Data Error!");
      return false;
    }
  }
  return true;
}

void DrawEightPointOneBitmap(unsigned int id, byte x, byte y){  //Drawing protocol for firmware revision 8.1 and higher only
  byte command[] = { GLK_CMD_BYTE, GLK_BITMAP_DRAW_FROM_MEM, (byte)(id), (byte)(id >> 8), x, y };  //Little Endian protocol
  i2cWriteBytes(command, sizeof(command));  //Draw command 
}

void clearScreen(){
  byte command[] = { GLK_CMD_BYTE, GLK_TXT_CLS };
  i2cWriteBytes(command, sizeof(command));
}

void setReportingMode(byte mode){
  byte command[] = { GLK_CMD_BYTE, GLK_COM_PROTO, mode };
  i2cWriteBytes(command, sizeof(command));
}

void setCursorCoordinates(byte x, byte y){
  byte command[] = {GLK_CMD_BYTE, GLK_TXT_CURS_COORD, x, y};
  i2cWriteBytes(command, sizeof(command));
}

void writeMessage(char* data, byte length){
  i2cWriteString(data, length);
}

void i2cWriteBytes(byte* data, byte length){  //Simple transmission of bytes, used for commands
  Wire.beginTransmission(GLK_I2C_ADDR);
  for(int i = 0; i < length; i++){
    Wire.write(data[i]);
    delay(10);  //Delay between bytes to ensure proper communication, 10ms works well with the Uno
  }
  Wire.endTransmission();
  delay(50);  //Delay after transaction, avoids accidentally reading data transmitted from the host
}

void i2cWriteString(char* data, byte length){  //Simple transmission of text strings
  Wire.beginTransmission(GLK_I2C_ADDR);
  for(int i = 0; i < length; i++){
    Wire.write(data[i]);
    delay(10);
  }
  Wire.endTransmission();
  delay(50);
}

byte i2cReadByte(){  //Wait for one byte to be available over i2c and read it
  while(Wire.available()<1){
  Wire.requestFrom(I2C_Address, 1);
  }
  return(Wire.read());
}
