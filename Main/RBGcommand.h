#ifndef RBGCOMMAND_H
#define RBGCOMMAND_H

#include "pins.H"

void RBGcommand(uint32_t valueColor, uint32_t valuePower) {
    analogWrite(ledPinRed, 0);
    analogWrite(ledPinGreen, 0);
    analogWrite(ledPinBlue, 0);
  
    if (valueColor < 146) {
      // R
      analogWrite(ledPinRed, valuePower);
    } else if(valueColor >= 146 && valueColor < 292) {
      // G
      analogWrite(ledPinGreen, valuePower);
    } else if(valueColor >= 292 && valueColor < 438){
      // B
      analogWrite(ledPinBlue, valuePower);
    } else if(valueColor >= 438 && valueColor < 584){
      // RG
      analogWrite(ledPinRed, valuePower);
      analogWrite(ledPinGreen, valuePower);
    } else if(valueColor >= 584 && valueColor < 730){
      // RB
      analogWrite(ledPinRed, valuePower);
      analogWrite(ledPinBlue, valuePower);
    } else if(valueColor >= 730 && valueColor < 876){
      // GB
      analogWrite(ledPinGreen, valuePower);
      analogWrite(ledPinBlue, valuePower);
    } else {
      // RGB
      analogWrite(ledPinRed, valuePower);
      analogWrite(ledPinGreen, valuePower);
      analogWrite(ledPinBlue, valuePower);
    }
}

#endif // RBGCOMMAND_H
