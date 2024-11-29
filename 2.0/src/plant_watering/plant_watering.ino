
// CONNECTIONS:
// DS1302 CLK/SCLK --> 9
// DS1302 DAT/IO --> 8
// DS1302 RST/CE --> 10
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND

#include <RtcDS1302.h>

ThreeWire myWire(8,9,10); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

const int pumpPins[] = {3, 5, 6};

const int miliseconds = 5000;

void pump(int pin, unsigned long time) { // pump function 

    digitalWrite(pin, HIGH); //pump on
    delay(time);
    digitalWrite(pin, LOW); //pump off
    return 0;
  }
  
void water_plants(int pumpTime){

     for (int i = 0; i < 3; i++) {
      pump(pumpPins[i], pumpTime); //pumps will work after each other  
    }
    return 0;
  }

void printDateTime(const RtcDateTime& dt)
{
    char datestring[26];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.print(datestring);
}


void setup() {

  Serial.begin(57600);

  
    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);

    Rtc.Begin();

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    printDateTime(compiled);
    Serial.println();

    if (!Rtc.IsDateTimeValid()) 
    {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing

        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (Rtc.GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) 
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }
    else if (now > compiled) 
    {
        Serial.println("RTC is newer than compile time. (this is expected)");
    }
    else if (now == compiled) 
    {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }
  
  for (int i = 0; i < sizeof(pumpPins) / sizeof(pumpPins[0]); i++) {
    pinMode(pumpPins[i], OUTPUT);// pin setup for pumps
  }


  
}

void loop() {
   RtcDateTime now = Rtc.GetDateTime();

    printDateTime(now);
    Serial.println();

    // Execute task at 10:16 AM
    if (now.Hour() == 10 && now.Minute() == 17) 
    {
        water_plants(miliseconds);
        delay(2000);
        water_plants(miliseconds);
        delay(60000); // Prevent multiple executions in the same minute
    }

    if (!now.IsValid())
    {
        Serial.println("RTC lost confidence in the DateTime!");
    }

    delay(30000); // Check every 30 seconds
}
