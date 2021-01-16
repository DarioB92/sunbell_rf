/* rfsend(n)
* N   MEANING
* 1   channel 1 automatic-up
* 2   channel 1 automatic-down
* 3   channel 1 fine-up
* 4   channel 1 fine-down
* 5   channel 1 stop
* 6   channel 2 automatic-up
* 7   channel 2 automatic-down
* 8   channel 2 fine-up
* 9   channel 2 fine-down
* 10  channel 2 stop
* 11  channel 3 automatic-up
* 12  channel 3 automatic-down
* 13  channel 3 fine-up
* 14  channel 3 fine-down
* 15  channel 3 stop
* 16  channel 4 automatic-up
* 17  channel 4 automatic-down
* 18  channel 4 fine-up
* 19  channel 4 fine-down
* 20  channel 4 stop
*/

//define rf transmitter pin
#define RF_TX 2

//define needed channels
#define RF_CHANNEL1
#define RF_CHANNEL2
#define RF_CHANNEL3
#define RF_CHANNEL4

//define if you need only automatic up/down
#define RF_MINIMAL

//include the library
#include "custom_rf_complete.h"

#define RESEND 20

void setup() {
  //set rf transmitter pin as output
  pinMode(RF_TX, OUTPUT);
  //led go brrrr
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //will send the code RESEND times (original 5)
  for(int i=0; i<RESEND;i++){
    rfsend(2); //channel 1 down!!!
  }
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
}
