/**
 * Set up the bluetooth module. Depending on the mode, we'll either
 * tell the BLE to start in "Data" mode, where it can pair with 
 * another device and listen for Strings, or "Beacon" mode where it
 * sends out its beacon information.
 * 
 */
void bluetoothSetup() {
  Serial.begin(9600);
  while(!Serial) {;}
  Serial.println("AT+DEVNAME=Station Ten");
  delay(500);
  if (mode == 0) {
    // Do nothing, default is to start up in DATA mode.
  } else  {
    char buffer[32];
    sprintf(buffer,"AT+QBEACON=%02X,%02X",badge_id_me, badge_id_you);
    Serial.println(buffer);
  }
}

/**
 * Read the data from the BLE, breaking on '\n' and '\r' characters.
 */
String readFromBluetooth() {
  String readString = "";
  
    while (Serial.available()) {
    delay(10);  //small delay to allow input buffer to fill

    char c = Serial.read(); //gets one byte from serial buffer
    if (c == '\n' || c == '\r') {
      break;
    }
    readString += c;
  } 
  return readString;
}

/**
 * Parse the string setn by the BLE, and call the correct function based on input.
 */
void displayBasedOnInput(String response) {
  if (response.length() > 0) {
    if(response==AT_COMMAND_RX_SUCCESSFUL) {
      chasePersist(strip.numPixels(), leaf_green);
      callFunction(0);
    } else if(response==AT_COMMAND_RX_FAILED) {
      chasePersist(strip.numPixels(), white);
      callFunction(0);
    } else if(response==AT_CONNECTION_ESTABLISHED) {
      chasePersist(strip.numPixels(), purple);
      callFunction(0);
    } else if (response.indexOf("LED") >= 0) {
        int index = response.indexOf("LED");
        response.remove(index, 3);
        for (int i = 0; i < questions.size(); i++) {
          if (questions.valueAt(i) == response.toInt()) {
            // LEDs are indexed starting from 0. But because of the
            // masking to get the correct questions, we index the 
            // questions from 1. So to translate from question to LED index
            // we subtract zero here.
            sparkleOneFadeToBlack(response.toInt()-1);
          }
        }
        reportCorrectQuestions();
        return;
    } else if (questions.contains(response)) {
        uint32_t questionNumber = questions[response];
        questionsAnswered |= QUESTION_MASK_MAP[questionNumber];
        callFunction(questionNumber);
        callFunction(0);
        reportCorrectQuestions();
    }
    /*
    else if (response == String("1 1 3 3 13 13") || response == String("11331313")) {
      questionsAnswered |= QUESTION_MASK_TWO;
      callFunction(2);
    }
    else if (response == String("CDMA")) {
      questionsAnswered |= QUESTION_MASK_THREE;
      callFunction(3);
    }
    else if (response == String("3")) {
      questionsAnswered |= QUESTION_MASK_FOUR;
      callFunction(4);
    }
    else if (response == String("LOW ENERGY")) {
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
    else if (response == String("40320")) {
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
    else if (response == String("STATIC")) {
      questionsAnswered |= QUESTION_MASK_SIXTEEN;
      callFunction(16);
    }
    else if (response == String("A")) {
      questionsAnswered |= QUESTION_MASK_SEVENTEEN;
      callFunction(17);
    } 
    else if (response == String("TRUE")) {
      questionsAnswered |= QUESTION_MASK_EIGHTEEN;
      callFunction(18);
    } else if (response.indexOf("LED") >= 0) {
      int index = response.indexOf("LED");
      response.remove(index, 3);
      sparkleOneFadeToBlack(response.toInt());
      reportCorrectQuestions();
      return;
    }
    */
    else {
      callFunction(99);
    }
    //callFunction(0);
    //reportCorrectQuestions();
    //bluetoothbluetoothSerial.println(readString);
  }
}
