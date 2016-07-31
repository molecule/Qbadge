// uint8_t badge_id_me = 0x86; // 7 bits 135
// Serial.println("AT+DEVNAME=Molly Nicholas");
const int yes = 1;
const int no = 0;
uint32_t myAnswers() {
    uint32_t myIRCode = 0;
    uint32_t Answer = 0;
    // 1 for 'Yes' and a 0 for a 'No'

    // Have you been to Texas before?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<17);

    // Have you participated in a hackathon before?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<16);

    // Have you ever won an award?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<15);

    // Have you played with an Arduino or a microcontroller before this conference?
    Answer = no;
    myIRCode = myIRCode + (Answer<<14);

    // Do you play any musical instruments?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<13);

    // Is this your first time at GHC?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<12);

    // Are you a member of any professional organizations?
    Answer = no;
    myIRCode = myIRCode + (Answer<<11);

    // Did you get more than 7 hours of sleep last night
    Answer = yes;
    myIRCode = myIRCode + (Answer<<10);

    // Are you the first person in your family to attend college?
    Answer = no;
    myIRCode = myIRCode + (Answer<<9);

    // Do you work with or study software engineering?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<8);

    // Do you work with or study hardware engineering?
    Answer = no;
    myIRCode = myIRCode + (Answer<<7);

    // Have you ever used a 3D printer?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<6);

    // Did you ever switch majors?
    Answer = no;
    myIRCode = myIRCode + (Answer<<5);

    // Have you ever been published?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<4);

    // Does your mobile phone use a Qualcomm chip?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<3);

    // Are you a robot?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<2);

    // Do you use a smartwatch?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<1);

    // Do you like to travel?
    Answer = yes;
    myIRCode = myIRCode + (Answer<<0);

    return myIRCode;
}
