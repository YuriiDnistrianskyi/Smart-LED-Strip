#ifndef RBGCOMMAND_H
#define RBGCOMMAND_H

#include "pins.H"

void RBGcommand(uint32_t valueColor, uint32_t valuePower) {
    if (valueColor == 0) {
      // None
      analogWrite(ledPinRed, 0);
      analogWrite(ledPinGreen, 0);
      analogWrite(ledPinBlue, 0);
    } else if (valueColor < 146) {
      // R
      analogWrite(ledPinRed, valuePower);
      analogWrite(ledPinGreen, 0);
      analogWrite(ledPinBlue, 0);
    } else if(valueColor >= 146 && valueColor < 292) {
      // G
      analogWrite(ledPinRed, 0);
      analogWrite(ledPinGreen, valuePower);
      analogWrite(ledPinBlue, 0);
    } else if(valueColor >= 292 && valueColor < 438){
      // B
      analogWrite(ledPinRed, 0);
      analogWrite(ledPinGreen, 0);
      analogWrite(ledPinBlue, valuePower);
    } else if(valueColor >= 438 && valueColor < 584){
      // RG
      analogWrite(ledPinRed, valuePower);
      analogWrite(ledPinGreen, valuePower);
      analogWrite(ledPinBlue, 0);
    } else if(valueColor >= 584 && valueColor < 730){
      // RB
      analogWrite(ledPinRed, valuePower);
      analogWrite(ledPinGreen, 0);
      analogWrite(ledPinBlue, valuePower);
    } else if(valueColor >= 730 && valueColor < 876){
      // GB
      analogWrite(ledPinRed, 0);
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
