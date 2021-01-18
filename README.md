# RF library for SunBell Curtrains

I have 4 Sunbell curtrains, and want to integrate them in my domotic system. 
They works on 433Mhz.
![](images/multisample.jpg)
Logic samples show this kind of encoding, I suppose Manchester.
![](images/singleframe.jpg)
Message is probably made up by :

||||||
| ------------ | ------------ | ------------ | ------------ | ------------ |
| Preamble | Transmitter address or sync | Target Id | Command | Checksum | 

After some attempts I decided to simply retransmit the sampled signal. 
I sampled, for each of the 4 channels:  
automatic up: will open the curtrain  
automatic down: will close the curtrain  
fine up: while pressed will slowly open the curtrain, or regulate inclination  
fine down: while pressed will slowly close the curtrain, or regulate inclination  
stop: will sto automatic up or automatic down. 

| To use the library it's needed to |  
|-----------------|---------------|  
| define RF_TX pin	| #define RX_TX 2 |  
| define the channel needed	|  #define CHANNELx |  
| (optional) define | #RF_MINIMAL to use only automatic up/down |

#rfsend(n)

|n |  MEANING
| ------------ | ------------ |
| 1 |  channel 1 automatic-up
| 2 | channel 1 automatic-down
 |3 |channel 1 fine-up
 |4 |  channel 1 fine-down
 |5 |  channel 1 stop
 |6 | channel 2 automatic-up
 |7 |  channel 2 automatic-down
 |8 |  channel 2 fine-up
 |9 |  channel 2 fine-down
 |10|  channel 2 stop
 |11|  channel 3 automatic-up
 |12| channel 3 automatic-down
 |13|  channel 3 fine-up
 |14| channel 3 fine-down
 |15|  channel 3 stop
 |16|  channel 4 automatic-up
 |17|  channel 4 automatic-down
 |18|  channel 4 fine-up
 |19|  channel 4 fine-down
 |20|  channel 4 stop


## Example
```c
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
    rfsend(2); //channel 1 automatic-down!!!
  }
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
}
```

### FAQ
1) Can I use for... Sure
2) Will work on my curtrains?
3) Yes, push both buttons on the reciever and send a command for the choosen channel.   N.B. this will exclude your remote
  
  To Radaelli, I'm really impressed, the quality of the PCB it's astonishing!