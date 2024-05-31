//לחיצה על כפתור אדום מדליקה נורה אדומה
// לחיצה נוספת - מכבה אותה
// כפתור ירוק משפיע באותה צורה על נורה ירוקה

#define NUMBER_OF_LEDS 2

#define BTN_pin 2
#define LedR 4
#define LedG 5

unsigned long current_time;
unsigned long LastPressTime;

int  LedsPin[NUMBER_OF_LEDS]={LedR,LedG};
bool LedIsOn[NUMBER_OF_LEDS];
void setup() {
  Serial.begin(9600);
  pinMode(BTN_pin,INPUT_PULLUP);
  for(int k = 0; k<NUMBER_OF_LEDS; k++){
    pinMode(LedsPin[k],OUTPUT);
    TurnLedOFF(k);
  }

  LastPressTime=millis();
}

int CurrBtn;
int LastBtn;
void loop() {
  CurrBtn=digitalRead(BTN_pin);

  if((CurrBtn == LOW) && (LastBtn == HIGH)&&(millis() - LastPressTime > 50)){
    LastPressTime=millis();
    ToggleLed(0);
  }
 

 LastBtn=CurrBtn;

}
void ToggleLed(int chnl){
  if(LedIsOn[chnl]){
    TurnLedOFF(chnl);
  } else {
    TurnLedOn(chnl);
  }
}
void TurnLedOn(int chnl){
  LedIsOn[chnl] = true;
  digitalWrite(LedsPin[chnl],HIGH);
}
void TurnLedOFF(int chnl){
  LedIsOn[chnl]=false;
  digitalWrite(LedsPin[chnl],LOW);
}









