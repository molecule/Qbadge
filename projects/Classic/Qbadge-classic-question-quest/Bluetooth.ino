/**
 * Parse the string setn by the BLE, and call the correct function based on input.
 */
void displayBasedOnInput(String response) {
  if (response.length() > 0) {
    if (response == String("QCOM")) {
      questionsAnswered |= QUESTION_MASK_ONE;
      callFunction(1);
    }
    else if (response == String("30")) {
      questionsAnswered |= QUESTION_MASK_TWO;
      callFunction(2);
    }
    else if (response == String("CDMA")) {
      questionsAnswered |= QUESTION_MASK_THREE;
      callFunction(3);
    }
    else if (response == String("COMMUNITY")) {
      questionsAnswered |= QUESTION_MASK_FOUR;
      callFunction(4);
    }
    else if (response == String("COUNTERCLOCKWISE")) {
      questionsAnswered |= QUESTION_MASK_SIX;
      //ChaseFlip goes clockwise...lol
      callFunction(6);
    }
    else if (response == String("FIBONACCI")) {
      questionsAnswered |= QUESTION_MASK_FIVE;
      callFunction(5);
    }
    else if (response == String("14")) {
      questionsAnswered |= QUESTION_MASK_SEVEN;
      callFunction(7);
    }
    else if (response == String("-39083")) {
      questionsAnswered |= QUESTION_MASK_EIGHT;
      callFunction(8);
    }
    else if (response == String("54")) {
      questionsAnswered |= QUESTION_MASK_NINE;
      callFunction(9);
    }
    else if (response == String("TRUE")) {
      questionsAnswered |= QUESTION_MASK_TEN;
      callFunction(10);
    }
    else if (response == String("MULTIPLY")) {
      questionsAnswered |= QUESTION_MASK_ELEVEN;
      callFunction(11);
    }
    else if (response == String("YIPPEE")) {
      questionsAnswered |= QUESTION_MASK_TWELVE;
      callFunction(12);
    }
    else if (response == String("MOLLENKOPF")) {
      questionsAnswered |= QUESTION_MASK_THIRTEEN;
      callFunction(13);
    }
    else if (response == String("QUALCOMM")) {
      questionsAnswered |= QUESTION_MASK_FOURTEEN;
      // rainbow
      callFunction(14);
    }
    else if (response == String("NEGATIVE")) {
      questionsAnswered |= QUESTION_MASK_FIFTEEN;
      callFunction(15);
    } 
    else if (response == String("U")) {
      questionsAnswered |= QUESTION_MASK_SIXTEEN;
      callFunction(16);
    }
    else if (response == String("SAN DIEGO")) {
      questionsAnswered |= QUESTION_MASK_SEVENTEEN;
      callFunction(17);
    } 
    else if (response == String("LOW ENERGY")) {
      questionsAnswered |= QUESTION_MASK_EIGHTEEN;
      callFunction(18);
    }
    else {
      callFunction(99);
    }
    callFunction(0);
    reportCorrectQuestions();
    //bluetoothbluetoothSerial.println(readString);
  }
}

/**
 * Read the data from the BLE, breaking on '\n' and '\r' characters.
 */
String readFromBluetooth() {
  String readString = "";
  
  while (Serial.available()) {
    delay(10);  //small delay to allow input buffer to fill

    char c = Serial.read();  //gets one byte from serial buffer
    if (c == '.') {
      break;
    }
    readString += c;
  } 
  return readString;
}