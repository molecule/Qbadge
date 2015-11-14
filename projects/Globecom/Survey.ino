// uint8_t badge_id_me = 0x86; // 7 bits 135
// Serial.println("AT+DEVNAME=Molly Nicholas");
const int yes = 1;
const int no = 0;
uint32_t myAnswers() {
    uint32_t myIRCode = 0;
    uint32_t Answer = 0;
    // 1 for 'Yes' and a 0 for a 'No'

    // Are you interested in 5G?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<17);

    // Are you interested in P2P/D2D?
    Answer = no;
    myIRCode = myIRCode + (Answer<<16);

    // Are you interested in M2M/IoT?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<15);

    // Are you interested in Green Communications?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<14);

    // Are you interested in Smart Grid?
    Answer = no;
    myIRCode = myIRCode + (Answer<<13);

    // Are you interested in Wireless Charging?
    Answer = no;
    myIRCode = myIRCode + (Answer<<12);

    // Are you interested in Smart Health?
    Answer = no;
    myIRCode = myIRCode + (Answer<<11);

    // Are you interested in Cloud Computing?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<10);

    // Are you interested in Automotive?
    Answer = no;
    myIRCode = myIRCode + (Answer<<9);

    // Are you interested in Software Defined Networks?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<8);

    // Are you interested in Small Cells?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<7);

    // Are you interested in LTE-U/LAA?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<6);


    /******** END SURVEY ********/

    return myIRCode;
}
