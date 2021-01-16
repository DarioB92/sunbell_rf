/* rfsend(n)
* 1 channel 1 up
* 2 channel 1 down
* 3 channel 1 stop
* 4 channel 2 up
* 5 channel 2 down
* 6 channel 2 stop
* 7 channel 3 up
* 8 channel 3 down
* 9 channel 3 stop
* 10 channel 4 up
* 11 channel 4 down
* 12 channel 4 stop
* 13 channel 1 automatic up
*/


#define RF_TX 2
#define RESEND 10

#include "custom_rf_auto.h"

int i,j=1;

void setup() {
  // put your setup code here, to run once:
  pinMode(RF_TX, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0; i<RESEND;i++){
    rfsend(j);
  }
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
  if(j>1)
    j=1;
  else
    j=2;
}
