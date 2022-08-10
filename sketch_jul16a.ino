#include "Adafruit_MCP23017.h"
#include <SPI.h>                                        //libraries
#include <SD.h>
#include<Wire.h>
#include<LiquidCrystal.h>

byte c, t, i,input,input1,f;
int d,q;
byte  x, y = 0;                                         //initialize variables

byte buffer1[8], buffer2[8], buffer3[8], buffer4[8], buffer5[8], buffer6[8], buffer7[8], buffer8[8], buffer9[8],
     buffer10[8], buffer11[8], buffer12[8], buffer13[8], buffer14[8], buffer15[8], buffer16[8],cat[8];            //arrays to store masterdata

Adafruit_MCP23017 mcp1, mcp2, mcp3, mcp4, mcp5, mcp6, mcp7, mcp8;         //initialize all mcp objects.
File myFile;



const int rs = 7, en = 8, d5 = 2, d4 = 3, d3= 4, d2= 5;     //digital pins used for lcd.
LiquidCrystal lcd(rs, en, d5, d4, d3, d2);


//-------------------------------------------setup-------------------------------------------------------------------------------
void setup()
{
#define newharness A0 
#define restart A1                    
#define testing A2                   //1x4 keypad connections to arduino.
#define master A3



  int addr1 = 0x00;
  int addr2 = 0x01;                 //addresses.
  int addr3 = 0x02;
  int addr4 = 0x03;
  int addr5 = 0x04;
  int addr6 = 0x05;
  int addr7 = 0x06;
  int addr8 = 0x07;

  Wire.begin();  
  Serial.begin(9600);
  lcd.begin(16, 2);

  mcp1.begin(addr1);
  mcp2.begin(addr2);
  mcp3.begin(addr3);
  mcp4.begin(addr4);
  mcp5.begin(addr5);
  mcp6.begin(addr6);
  mcp7.begin(addr7);
  mcp8.begin(addr8);


  while (!Serial) { }                             //check spi commnication .
 
 lcd.setCursor(0,0);
 lcd.print(F("Initializing SD"));
 delay(1000);
  if (!SD.begin(10))
  {
  lcd.setCursor(0,1);
  lcd.print(F("SD card failed"));
   delay(1000);
    while (1);
  }
  lcd.setCursor(0,1);
  lcd.print(F("SD Initiated"));
   delay(1500);
//delay(500);
lcd.clear();


   pinMode(master,INPUT_PULLUP);                    // setkeypad pins as input
   pinMode(testing,INPUT_PULLUP);
   pinMode(restart,INPUT_PULLUP);
   pinMode(newharness,INPUT_PULLUP);


lcd.print(F("Press a key"));
l2:                                                           //l2 label

while(1)                                                      //continiusly run until key press detected.
{
int master1=digitalRead(master);
if(master1==1)
{
 byte v=0;
}

if(master1==0)
{
lcd.clear();
byte  v=1;
goto  l1;
}

  
  
  int testing1=digitalRead(testing);
  if(testing1==1)
{
 
}
if(testing1==0)
{
  lcd.clear();
  lcd.setCursor(0,0);
lcd.print(F("test key pressed"));
  delay(200);
  lcd.setCursor(0,1);
lcd.print(F("Start testing"));
delay(500);
loop();
}
 int restart1=digitalRead(restart);

if(restart1==1)
{
 
}
if(restart1==0)
{
   lcd.clear();
   lcd.setCursor(0,0);
lcd.print(F("R key pressed"));
delay(200);
lcd.setCursor(0,1);
//lcd.print(F("Start testing again"));
lcd.print(F("testing again"));
delay(500);
loop();
}

int newharness1=digitalRead(newharness);
if(newharness1==1)
{
}

if(newharness1==0)
{
lcd.setCursor(0,0);
lcd.print(F("NH key pressed"));
// lcd.setCursor(0,1);
//lcd.print(F("harness connected"));
SD.remove("51.txt");
SD.remove("52.txt");
SD.remove("53.txt");
SD.remove("54.txt");
SD.remove("55.txt");
SD.remove("56.txt");                           //remove previous files in sd card to store new data in them.
SD.remove("57.txt");
SD.remove("58.txt");
delay(800);
lcd.clear();
lcd.setCursor(0,0);
//lcd.print(F("data of previous harness removed"));
lcd.print(F("data removed"));
 lcd.setCursor(0,1);
lcd.print(F("store new data"));
  delay(800);
goto l2;
}

}

l1:                                                                   //l1 label.                                                              
if(byte v=1)

{
  lcd.setCursor(0,0);  
lcd.print(F("M key pressed"));
  lcd.setCursor(0,1);
lcd.print(F("storing MD"));
delay(800);
 
//____________________________________________________________________________________________________________________________________
 myFile = SD.open("51.txt", FILE_WRITE);                  
  if (myFile)                                                            // if the file opened okay, write to it:
  {
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print(F("Storingto 51.txt"));
  for(byte i =0;i<16;i++)
 {
    mcp1.pinMode(i, OUTPUT);
    mcp1.digitalWrite(i, LOW);

 all();

mcp1.pinMode(i, OUTPUT);
mcp1.digitalWrite(i, HIGH);

 }
     myFile.close();
      lcd.setCursor(0,1);
      delay(200);
    lcd.print(F("done."));
      delay(500);
  }
  else
  {
     lcd.setCursor(0,1);
    lcd.print(F("E toopen 51.txt"));                    // if the file didn't open, print an error:
  }
 
//__________________________________________________________________________________________________________________________________
    myFile = SD.open("52.txt", FILE_WRITE);

  if (myFile)
  {
    lcd.clear();
     lcd.setCursor(0,0);
    lcd.print(F("Storingto 52.txt"));
   
   for(byte i =0;i<16;i++)
 {
    mcp2.pinMode(i, OUTPUT);
    mcp2.digitalWrite(i, LOW);
    all();
    mcp2.pinMode(i, OUTPUT);
    mcp2.digitalWrite(i, HIGH);
 }

    myFile.close();
     lcd.setCursor(0,1);
       delay(200);
   lcd.print(F("done."));
     delay(500);
  }
  else
  {
     lcd.setCursor(0,1);
    lcd.print(F("E to open 42.txt"));
  }
//_____________________________________________________________________________________________________________________________________________________
 myFile = SD.open("53.txt", FILE_WRITE);

  if (myFile)
  {
    lcd.clear();
      lcd.setCursor(0,0);
lcd.print(F("Storingto 43.txt"));
     for(byte i =0;i<16;i++)
 {
    mcp3.pinMode(i, OUTPUT);
    mcp3.digitalWrite(i, LOW);
    all();
    mcp3.pinMode(i, OUTPUT);
    mcp3.digitalWrite(i, HIGH);
     }

 myFile.close();
 lcd.setCursor(0,1);
   delay(200);
lcd.print(F("done."));
    delay(500);
  }
  else
  {
     lcd.setCursor(0,1);
    lcd.print(F("E to open 41.txt"));
  }
//_____________________________________________________________________________________________________________________________________________________
 
    myFile = SD.open("54.txt", FILE_WRITE);

  if (myFile)
  { 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Storingto 44.txt"));  
    
   for(byte i =0;i<16;i++)
 {
    mcp4.pinMode(i, OUTPUT);
    mcp4.digitalWrite(i, LOW);
 all();
   mcp4.pinMode(i, OUTPUT);
    mcp4.digitalWrite(i, HIGH);
     }
myFile.close();
 lcd.setCursor(0,1);
   delay(200);
lcd.print(F("done."));
    delay(500);
  }
  else
  {
   lcd.setCursor(0,1);
    lcd.print(F("E to open 41.txt"));
  }

//_____________________________________________________________________________________________________________________________________________________
   
        myFile = SD.open("55.txt", FILE_WRITE);

  if (myFile)
  {
    lcd.clear();
     lcd.setCursor(0,0);
    lcd.print(F("Storingto 45.txt"));
     
    for(byte i =0;i<16;i++)
 {
    mcp5.pinMode(i, OUTPUT);
    mcp5.digitalWrite(i, LOW);
 all();
    mcp5.pinMode(i, OUTPUT);
    mcp5.digitalWrite(i, HIGH);
     }
       myFile.close();
        lcd.setCursor(0,1);
          delay(200);
    lcd.print(F("done."));
       delay(500);
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print(F("E to open 41.txt"));
  }
//_____________________________________________________________________________________________________________________________________________________
   
myFile = SD.open("56.txt", FILE_WRITE);
if (myFile)
{
  lcd.clear();
   lcd.setCursor(0,0);
    lcd.print(F("Storingto 46.txt"));
 
    for(byte i =0;i<16;i++)
 {
    mcp6.pinMode(i, OUTPUT);
    mcp6.digitalWrite(i, LOW);
all();
    mcp6.pinMode(i, OUTPUT);
    mcp6.digitalWrite(i, HIGH);
     }
       myFile.close();
        lcd.setCursor(0,1);
          delay(200);
    lcd.print(F("done."));
       delay(500);
  }
  else
  {
     lcd.setCursor(0,1);
    lcd.print(F("E to open 41.txt"));
  }
//_____________________________________________________________________________________________________________________________________________________
   
        myFile = SD.open("57.txt", FILE_WRITE);

  if (myFile) {
     lcd.clear();
     lcd.setCursor(0,0);
    lcd.print(F("Storingto 47.txt"));
     
    for(byte i =0;i<16;i++)
 {
    mcp7.pinMode(i, OUTPUT);
    mcp7.digitalWrite(i, LOW);
all();
mcp7.pinMode(i, OUTPUT);
    mcp7.digitalWrite(i, HIGH);
     }

       myFile.close();
        lcd.setCursor(0,1);
          delay(200);
    lcd.print(F("done."));
        delay(500);
  }
  else
  {
     lcd.setCursor(0,1);
    lcd.print(F("E to open 47.txt"));
  }
//_____________________________________________________________________________________________________________________________________________________
myFile = SD.open("58.txt", FILE_WRITE);

  if (myFile) {
    lcd.clear();
     lcd.setCursor(0,0);
    lcd.print(F("Storingto 48.txt"));
     
   for(byte i =0;i<16;i++)
 {
    mcp8.pinMode(i, OUTPUT);
    mcp8.digitalWrite(i, LOW);
all();
mcp8.pinMode(i, OUTPUT);
mcp8.digitalWrite(i, HIGH);
     }
 
       myFile.close();
        lcd.setCursor(0,1);
          delay(200);
    lcd.print(F("done."));
        delay(500);
  }
  else
  {
     lcd.setCursor(0,1);
    lcd.print(F("E to open 41.txt"));
  }
//_____________________________________________________________________________________________________________________________________________________
 lcd.clear();
 lcd.setCursor(0,0);
lcd.print(F("MD stored"));
 lcd.setCursor(0,1);
 lcd.print(F("press next key"));
 delay(500);
 }
 
 goto l2;  
}
//--------------end of setup----------------------------------------------------------------



void mcp1A()
{
  Wire.beginTransmission(0x20);
  Wire.write(0x12);                              //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x20, 1);                     //request 1 byte
Read();
}
//---------------------------------------------------------------------------------------------
void mcp1B()
{
  Wire.beginTransmission(0x20);
  Wire.write(0x13);                               //for port b
  Wire.endTransmission();

  Wire.requestFrom(0x20, 1);                     //request 1 byte
Read();
}
//---------------------------------------------------------------------------------------------
void mcp2A()
{
  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  Wire.endTransmission();

  Wire.requestFrom(0x21, 1);
Read();
}
//---------------------------------------------------------------------------------------------
void mcp2B()
{
  Wire.beginTransmission(0x21);
  Wire.write(0x13);
  Wire.endTransmission();

  Wire.requestFrom(0x21, 1);
 Read();
}
//---------------------------------------------------------------------------------------------
void mcp3A()
{
  Wire.beginTransmission(0x22);
  Wire.write(0x12);  
  Wire.endTransmission();

  Wire.requestFrom(0x22, 1);
Read();
}
//---------------------------------------------------------------------------------------------
void mcp3B()
{
  Wire.beginTransmission(0x22);
  Wire.write(0x13);
  Wire.endTransmission();

  Wire.requestFrom(0x22, 1);
  Read();
}

//---------------------------------------------------------------------------------------------
void mcp4A()
{
  Wire.beginTransmission(0x23);
  Wire.write(0x12);  
  Wire.endTransmission();

  Wire.requestFrom(0x23, 1);
  Read();
}

//---------------------------------------------------------------------------------------------
void mcp4B()
{
  Wire.beginTransmission(0x23);
  Wire.write(0x13);  
  Wire.endTransmission();

  Wire.requestFrom(0x23, 1);
Read();
}
//---------------------------------------------------------------------------------------------
void mcp5A()
{
  Wire.beginTransmission(0x24);
  Wire.write(0x12);  
  Wire.endTransmission();

  Wire.requestFrom(0x24, 1);
Read();
}
//---------------------------------------------------------------------------------------------
void mcp5B()
{
  Wire.beginTransmission(0x24);
  Wire.write(0x13);  
  Wire.endTransmission();

  Wire.requestFrom(0x24, 1);
Read();
}
//---------------------------------------------------------------------------------------------
void mcp6A()
{
  Wire.beginTransmission(0x25);
  Wire.write(0x12);  
  Wire.endTransmission();

  Wire.requestFrom(0x25, 1);
Read();
}
//---------------------------------------------------------------------------------------------
void mcp6B()
{
  Wire.beginTransmission(0x25);
  Wire.write(0x13);  
  Wire.endTransmission();

  Wire.requestFrom(0x25, 1);
Read();
}
//---------------------------------------------------------------------------------------------
void mcp7A()
{
  Wire.beginTransmission(0x26);
  Wire.write(0x12);  
  Wire.endTransmission();

  Wire.requestFrom(0x26, 1);
Read();
}
//---------------------------------------------------------------------------------------------
void mcp7B()
{
  Wire.beginTransmission(0x26);
  Wire.write(0x13);  
  Wire.endTransmission();

  Wire.requestFrom(0x26, 1);
Read();
}
//---------------------------------------------------------------------------------------------
void mcp8A()
{
  Wire.beginTransmission(0x27);
  Wire.write(0x12);  
  Wire.endTransmission();

  Wire.requestFrom(0x27, 1);
Read();
}
//---------------------------------------------------------------------------------------------
void mcp8B()
{
  Wire.beginTransmission(0x27);
  Wire.write(0x13);  
  Wire.endTransmission();

  Wire.requestFrom(0x27, 1);
  Read();
}
 
//---------------------------------------------------------------------------------------------

void all()
{
 
mcp1A();
mcp1B();
mcp2A();
mcp2B();
mcp3A();
mcp3B();
mcp4A();
mcp4B();
mcp5A();
mcp5B();
mcp6A();
mcp6B();
mcp7A();
mcp7B();
mcp8A();
mcp8B();
}
//---------------------------------------------------------------------------------------------------------------------------
void Read()
{
 
  if (Wire.available());
  {
    input = Wire.read();
  }
f=input;
zeropad();
}

//-------------------------------------------------------------------------------------------------------------------------
void zeropad()
{
    for(byte m=0;m<8;m++)
  {
    byte h=bitRead(f,(7-m));
    myFile.print(h);
  }
   myFile.println();
   
}

//--------------------------start of loop------------------------------------------------------------------------------------------------
void loop()                                          
{

  q=1;
 for( i =0;i<16;i++)
 {
      mcp1.pinMode(i, OUTPUT);
    mcp1.digitalWrite(i, LOW);                                          //mcp1
       lcd.clear();
       lcd.setCursor(0,0);
        delay(500);
       lcd.print(i);
     lcd.print(F(" is Source  "));
     delay(500);
     
  sdcard();
ball();
if(c!=0)
{
  i--;
}
 
else
{
  //lcd.clear();
  delay(300);
  lcd.setCursor(0,1);
  lcd.print(F("No error found"));
   // lcd.setCursor(0,1);
    //  lcd.print(F("for source= "));
    //lcd.print(i);
    delay(500);
    mcp1.pinMode(i, OUTPUT);
    mcp1.digitalWrite(i, HIGH);
}

 }


 if(c==0)
 {
  q=2;
 for( i =0;i<16;i++)
 {
    mcp2.pinMode(i, OUTPUT);
    mcp2.digitalWrite(i, LOW);                                            //mcp2
     lcd.setCursor(0,0);
    delay(500);
    lcd.print(i+16);
     lcd.print(F("is Source  "));
     delay(500);

     sdcard();
ball();
if(c!=0)
{
  i--;
}
else
{
  //lcd.clear();
    delay(300);
     lcd.setCursor(0,1);
 lcd.print(F("No error found"));
//    lcd.setCursor(0,1);
//      lcd.print(F("for source= "));
//    lcd.print(i+16);
    delay(1000); 
   mcp2.pinMode(i, OUTPUT);
    mcp2.digitalWrite(i, HIGH);
}
 }
 }




 
 if(c==0)
 {
  q=3;
 for( i =0;i<16;i++)
 {
 
    mcp3.pinMode(i, OUTPUT);
    mcp3.digitalWrite(i, LOW);                            //mcp3
     lcd.setCursor(0,0);
        delay(500);
    lcd.print(i+32);
     lcd.print(F("is Source  "));
     delay(500);

     sdcard();
ball();
if(c!=0)
{
  i--;
}
else{
     lcd.clear();
     delay(300);
  lcd.setCursor(0,1);
  lcd.print(F("No error found"));
//    lcd.setCursor(0,1);
//      lcd.print(F("for source= "));
//     lcd.print(i+32);
      delay(1000); 
   mcp3.pinMode(i, OUTPUT);
    mcp3.digitalWrite(i, HIGH);
}
 }
 }




 
 if(c==0)
 {
    q=4;
 for( i =0;i<16;i++)
 {

    mcp4.pinMode(i, OUTPUT);                                    //mcp4
    mcp4.digitalWrite(i, LOW);
     lcd.setCursor(0,0);
        delay(500);
    lcd.print(i+48);
     lcd.print(F("is Source  "));
     delay(500);

      sdcard();
ball();
if(c!=0)
{
  i--;
}
else{
    lcd.clear();
       delay(300);
  lcd.setCursor(0,1);
  lcd.print(F("No error found"));
//    lcd.setCursor(0,1);
//      lcd.print(F("for source= "));
//     lcd.print(i+48);
      delay(1000); 
   mcp4.pinMode(i, OUTPUT);
    mcp4.digitalWrite(i, HIGH);
}
 }
 }




 
 if(c==0)
 {
  q=5;
 for( i =0;i<16;i++)
 {
 
    mcp5.pinMode(i, OUTPUT);                                  //mcp5
    mcp5.digitalWrite(i, LOW);
     lcd.setCursor(0,0);
        delay(500);
    lcd.print(i+64);
     lcd.print(F("is Source"));
     delay(500);

     sdcard();
ball();
if(c!=0)
{
  i--;
}
else{
     lcd.clear();
     delay(300);
   lcd.setCursor(0,1);
  lcd.print(F("No error found"));
//    lcd.setCursor(0,1);
//      lcd.print(F("for source= "));
//     lcd.print(i+64);
     delay(1000);
   mcp5.pinMode(i, OUTPUT);
    mcp5.digitalWrite(i, HIGH);
}
 }
 }





 
 if(c==0)
 {
  q=6;
 for(i =0;i<16;i++)
 {
    mcp6.pinMode(i, OUTPUT);
    mcp6.digitalWrite(i, LOW);                                          //mcp6
     lcd.setCursor(0,0);
        delay(500);
    lcd.print(i+80);
  lcd.print(F("is Source  "));
     delay(500);

     sdcard();
ball();
if(c!=0)
{
  i--;
}
else{
     lcd.clear();
        delay(300);
   lcd.setCursor(0,1);
  lcd.print(F("No error found"));
//    lcd.setCursor(0,1);
//      lcd.print(F("for source= "));
//     lcd.print(i+80);
     delay(1000);
   mcp6.pinMode(i, OUTPUT);
    mcp6.digitalWrite(i, HIGH);
}
 }
 }






 
 if(c==0)
 {
  q=7;
 for( i =0;i<16;i++)
 {
    mcp7.pinMode(i, OUTPUT);                                        //mcp7
    mcp7.digitalWrite(i, LOW);
     lcd.setCursor(0,0);
        delay(500);
    lcd.print(i+96);
     lcd.print(F("is Source  "));
     delay(500);

     sdcard();
ball();
if(c!=0)
{
  i--;
}
else{
     lcd.clear();
    delay(300);
     lcd.setCursor(0,1);
  lcd.print(F("No error found"));
//    lcd.setCursor(0,1);
//      lcd.print(F("for source= "));
//     lcd.print(i+96);
     delay(1000);
   mcp7.pinMode(i, OUTPUT);
    mcp7.digitalWrite(i, HIGH);
}
 }
 }





 
 if(c==0)
 {
  q=8;
 for( i =0;i<16;i++)    
 {

    mcp8.pinMode(i, OUTPUT);                                          //mcp8
    mcp8.digitalWrite(i, LOW);
     lcd.setCursor(0,0);
        delay(500);
    lcd.print(i+112);
lcd.print(F("is Source  "));
     delay(500);

     sdcard();
ball();
if(c!=0)
{
  i--;
}
else{
     lcd.clear();
      delay(300);
  lcd.setCursor(0,1);
  lcd.print(F("No error found"));
//    lcd.setCursor(0,1);
//      lcd.print(F("for source= "));
//     lcd.print(i+112);
     delay(1000);
   mcp8.pinMode(i, OUTPUT);
    mcp8.digitalWrite(i, HIGH);
}
 }
 }

//--------------------------------------------------------------------------------------------------

if(c==0)
{
//error();
lcd.clear();
//lcd.print(F("no error found"));
lcd.print(F("ALL OK"));
delay(500);
setup();
exit(0);
}
}




//------end of loop--------------------------------------------------------------------------------------
void setptt()
{
 byte array1[8]={0,1,2,3,4,5,6,7};
  for (byte j = 0; j < 8; j++)
  {
    byte mynum = bitRead(x, j);
    byte actualnum = bitRead(y, j);
    if (mynum != actualnum)
    {
    if(t==1  )
    {
       byte  r=j;
          lcd.setCursor(0,1);
         lcd.print(array1[r]);
         lcd.print(F(" pin is open"));
         

        break;
      }
      if(t==2  )
    {
       byte  r=j;
         lcd.setCursor(0,1);
         lcd.print(array1[r]+8);
         lcd.print(F(" pin is open"));
          
        break;
      }

          if(t==3  )
    {
       byte  r=j;
       lcd.setCursor(0,1);
         lcd.print(array1[r]+16);
         lcd.print(F(" pin is open"));
          

        break;
      }
             if(t==4 )
    {
       byte  r=j;
           lcd.setCursor(0,1);
         lcd.print(array1[r]+24);
         lcd.print(F(" pin is open"));
         

        break;
      }
                 if(t==5 )
    {
       byte  r=j;
       lcd.setCursor(0,1);
         lcd.print(array1[r]+32);
         lcd.print(F(" pin is open"));
         

        break;
      }
                     if(t==6 )
    {
       byte  r=j;
             lcd.setCursor(0,1);
         lcd.print(array1[r]+40);
         lcd.print(F(" pin is open"));
           
 
        break;
      }
                        if(t==7 )
    {
       byte  r=j;
             lcd.setCursor(0,1);
         lcd.print(array1[r]+48);
            lcd.print(F(" pin is open"));
 
        break;
      }
                           if(t==8 )
    {
       byte  r=j;
             lcd.setCursor(0,1);
         lcd.print(array1[r]+56);
         lcd.print(F(" pin is open"));
           
   
        break;
      }
                              if(t==9 )
    {
       byte  r=j;
          lcd.setCursor(0,1);
         lcd.print(array1[r]+64);
           lcd.print(F(" pin is open"));
           
   
        break;
      }
                                    if(t==10)
    {
       byte  r=j;
            lcd.setCursor(0,1); 
         lcd.print(array1[r]+72);
     lcd.print(F(" pin is open"));
         
   
        break;
      }


                                         if(t==11)
    {
       byte  r=j;
            lcd.setCursor(0,1);     
         lcd.print(array1[r]+80);
   lcd.print(F(" pin is open"));
     
        break;
      }


                                         if(t==12)
    {

       byte  r=j;
            lcd.setCursor(0,1);     
         lcd.print(array1[r]+88);
       lcd.print(F(" pin is open"));
            
           
           
     
        break;
      }

                                         if(t==13)
    {
       byte  r=j;
           lcd.setCursor(0,1);      
         lcd.print(array1[r]+96);
           lcd.print(F(" pin is open"));
           

        break;
      }

                                         if(t==14)
    {
       byte  r=j;
            lcd.setCursor(0,1);   
         lcd.print(array1[r]+104);  
         lcd.print(F(" pin is open"));
            
   
        break;
      }
                  if(t==15)
    {
       byte  r=j;
            lcd.setCursor(0,1);   
         lcd.print(array1[r]+112);
   lcd.print(F(" pin is open"));
            
     
        break;
      }
       if(t==16)
    {
       byte  r=j;
            lcd.setCursor(0,1);   
         lcd.print(array1[r]+120);
      lcd.print(F(" pin is open"));
        break;
      }
     
    }

  }
// delay(500);
}



//--------------------------end of setptt----------------------------------------------------------------------------------

void dog()
{
 byte sum=0;

for(byte g=0;g<8;g++)
{
  if(cat[g]==49)
  {
    cat[g]=1;
  }
  else
  {
    cat[g]=0;
  }
  sum=sum+(cat[g]<<(7-g));

}
//byte c=0;
c=(input1)^(sum);

if (c!= 0)
 {
   x = input1;
   y=sum;
setptt();
  }
  //delay(500);
 
return;
}


//------------------end of dog--------------------------------------------------------------------------------------------

//void error()
//{
//
//    lcd.print("No Error found.");
//    delay(250);
//    //exit(0);
//}

//-------------------end of error----------------------------------------------------------------------------------------------
void mcp1porta()
{
  t=1;
  Wire.beginTransmission(0x20);
  Wire.write(0x12);  
  Wire.endTransmission();

  Wire.requestFrom(0x20, 1);          //request one byte
  if (Wire.available());
  {
    input1 = Wire.read();         //test data mcp1 portA
                       
  }



for(byte u=0;u<8;u++)
{
cat[u]=buffer1[u];
}

dog();
}

//--------------------------------------------------------------------------------------------------------------------------------
void mcp1portb()
{
  if(c==0)
{
  t=2;
  Wire.beginTransmission(0x20);
  Wire.write(0x13);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x20, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();                //test data mcp1 portB

  }
 

for(byte u=0;u<8;u++)
{
cat[u]=buffer2[u];  
}

dog();
}
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp2porta()
{
if(c==0)
{
  t=3;
 Wire.beginTransmission(0x21);
  Wire.write(0x12);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x21, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();                  //test data mcp2 portA      
  }
 

for(byte u=0;u<8;u++)
{
cat[u]=buffer3[u];

}

dog();
}
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp2portb()
{
  if(c==0)
 {
  t=4;
 Wire.beginTransmission(0x21);
  Wire.write(0x13);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x21, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();                   //test data mcp2 portB  
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer4[u];  
}

dog();

 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp3porta()
{
  if(c==0)
{
  t=5;
Wire.beginTransmission(0x22);
  Wire.write(0x12);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x22, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();              //test data mcp3 portA                
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer5[u];  
}

dog();
}
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp3portb()
{
  if(c==0)
 {
  t=6;
Wire.beginTransmission(0x22);
  Wire.write(0x13);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x22, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();             //test data mcp3 portB                
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer6[u];  
}

dog();
 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp4porta()
{
  if(c==0)
 {
t=7;
Wire.beginTransmission(0x23);
  Wire.write(0x12);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x23, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();              //test data mcp4 portA                    
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer7[u];  
}

dog();
 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp4portb()
{
  if(c==0)
 {
  t=8;
Wire.beginTransmission(0x23);
  Wire.write(0x13);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x23, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();
                         //test data mcp4 portB
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer8[u];  
}

dog();
 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp5porta()
{
  if(c==0)
 {
t=9;
Wire.beginTransmission(0x24);
  Wire.write(0x12);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x24, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();                    
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer9[u];  
}

dog();
 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp5portb()
{
   if(c==0)
 {
  t=10;
  Wire.beginTransmission(0x24);
  Wire.write(0x13);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x24, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();      //test data portB
     
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer10[u];  
}

dog();
 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp6porta()
{
   if(c==0)
 {
  t=11;
  Wire.beginTransmission(0x25);
  Wire.write(0x12);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x25, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer11[u];  
}

dog();
 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp6portb()
{
  if(c==0)
 {
  t=12;
  Wire.beginTransmission(0x25);
  Wire.write(0x13);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x25, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer12[u];  
}

dog();
 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp7porta()
{
   if(c==0)
 {
  t=13;
 Wire.beginTransmission(0x26);
  Wire.write(0x12);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x26, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer13[u];  
}

dog();
 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp7portb()
{
   if(c==0)
 {
 t=14;
 Wire.beginTransmission(0x26);
  Wire.write(0x13);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x26, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer14[u];  
}

dog();

 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp8porta()
{
  if(c==0)
 {
 t=15;
 Wire.beginTransmission(0x27);
  Wire.write(0x12);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x27, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer15[u];  
}

dog();

 }
}
//--------------------------------------------------------------------------------------------------------------------------------
void mcp8portb()
{
  if(c==0)
 {
 t=16;
 Wire.beginTransmission(0x26);
  Wire.write(0x13);  //for port a
  Wire.endTransmission();

  Wire.requestFrom(0x27, 1);          //request one byte
  if (Wire.available());
  {
    input1= Wire.read();
  }
 

for( byte u=0;u<8;u++)
{
cat[u]=buffer16[u];  
}

dog();

 }
}

//--------------------------------------------------------------------------------------------------------------------------------

void sdcard()
{
 if(q==1)
  {
      myFile.close();
  myFile = SD.open("51.txt");
  if(myFile)
  {
    tree();
  myfilee();
  }
  else
  {
    lcd.clear();
    lcd.print(F("error opening 1.txt"));
  }
  }

 
     if(q==2)
  {
    myFile.close();
  myFile = SD.open("52.txt");
    if(myFile)
  {
    tree();
  myfilee();
  }
  else
  {
     lcd.clear();
    lcd.print(F("error opening 2.txt"));
  }
  }

if(q==3)
  {
    myFile.close();
  myFile = SD.open("53.txt");
   if(myFile)
  {
     tree();
 myfilee();
  }
  else
  {
     lcd.clear();
    lcd.print(F("error opening 3.txt"));
  }
  }

 
    if(q==4)
  {
     myFile.close();
  myFile = SD.open("54.txt");
   if(myFile)
   
  {
     tree();
  myfilee();
  }
  else
  {
     lcd.clear();
    lcd.print(F("error opening 4.txt"));
  }
  }


 
   if(q==5)
  {
     myFile.close();
  myFile = SD.open("55.txt");
    if(myFile)
     
  {
    tree();
  myfilee();
  }
  else
  {
     lcd.clear();
    lcd.print(F("error opening 5.txt"));
  }
  }
delay(200);
 
   if(q==6)
  {
     myFile.close();
  myFile = SD.open("56.txt");
   if(myFile)
   
  {
     tree();
  myfilee();
  }
  else
  {
     lcd.clear();
    lcd.print(F("error opening 6.txt"));
  }
  }

   if(q==7)
  {
     myFile.close();
  myFile = SD.open("57.txt");
    if(myFile)
   
  {
     tree();
  myfilee();
  }
  else
  {
     lcd.clear();
    lcd.print(F("error opening 7.txt"));
  }
  }

 
   if(q==8)
  {
     myFile.close();
  myFile = SD.open("58.txt");
   if(myFile)
  {
     tree();
  myfilee();
  }
  else
  {
     lcd.clear();
    lcd.print(F("error opening 8.txt"));
  }
  }
 return;
 
}

//---------------end of sdcard()--------------------------------------------------------------------------------------------

void myfilee()
{
 
   byte  a=0;
   // lcd.print("Masterdata1=");                                  //md1
 
    while (myFile.available() && (a < 8))
    {
      myFile.seek(a+d);
      delay(100);
      buffer1[a] = myFile.read();
      //Serial.write(buffer1[a]);
      a++;

      if(myFile.read()=='\n')
      {
     break;
      }
    }
      a=0;
      //lcd.print("Masterdata2=");                            //md2
        while (a < 8)
        {
        myFile.seek(a+10+d);
      buffer2[a] = myFile.read();
      //Serial.write(buffer2[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }
    }

      a=0;
      //lcd.print("Masterdata3=");                             //md3
        while (a < 8)
        {
        myFile.seek(a+20+d);
      buffer3[a] = myFile.read();
      //Serial.write(buffer3[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }

        }
     a=0;
     // lcd.print("Masterdata4=");                            //md4
        while (a < 8)
        {
        myFile.seek(a+30+d);
      buffer4[a] = myFile.read();
      //Serial.write(buffer4[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }

        }
         a=0;
     // lcd.print("Masterdata5=");                         //md5
        while (a < 8)
        {
        myFile.seek(a+40+d);
      buffer5[a] = myFile.read();
      //Serial.write(buffer5[a]);
     a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }


         a=0;
     // lcd.print("Masterdata6=");                         //md6
        while (a < 8)
        {
        myFile.seek(a+50+d);
      buffer6[a] = myFile.read();
      //Serial.write(buffer6[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }

         a=0;
   
    //  lcd.print("Masterdata7=");                        //md7
        while (a < 8)
        {
        myFile.seek(a+60+d);
      buffer7[a] = myFile.read();
      //Serial.write(buffer7[a]);
     a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }


 a=0;
   
   //  lcd.print("Masterdata8=");                       //md8
        while (a < 8)
        {
        myFile.seek(a+70+d);
      buffer8[a] = myFile.read();
      //Serial.write(buffer8[a]);
     a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }

         a=0;
   
      //lcd.print("Masterdata9=");                 //md9
        while (a < 8)
        {
        myFile.seek(a+80+d);
      buffer9[a] = myFile.read();
      //Serial.write(buffer9[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }



 a=0;
   
      //lcd.print("Masterdata10=");           //md10
        while (a < 8)
        {
        myFile.seek(a+90+d);
      buffer10[a] = myFile.read();
      //Serial.write(buffer10[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }


 a=0;
   
      //lcd.print("Masterdata11=");            //md11
        while (a < 8)
        {
        myFile.seek(a+100+d);
      buffer11[a] = myFile.read();
     // Serial.write(buffer11[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }

       
 a=0;
   
      //lcd.print("Masterdata12=");        //md12
        while (a < 8)
        {
        myFile.seek(a+110+d);
      buffer12[a] = myFile.read();
      //Serial.write(buffer12[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }


 a=0;
     // lcd.print();
      //lcd.print("Masterdata13=");        //md13
        while (a < 8)
        {
        myFile.seek(a+120+d);
      buffer13[a] = myFile.read();
      //Serial.write(buffer13[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }



 a=0;
   
      //lcd.print("Masterdata14=");        //md14
        while (a < 8)
        {
        myFile.seek(a+130+d);
      buffer14[a] = myFile.read();
      //Serial.write(buffer14[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }


         a=0;
   
      //lcd.print("Masterdata15=");        //md15
        while (a < 8)
        {
        myFile.seek(a+140+d);
      buffer15[a] = myFile.read();
      //Serial.write(buffer15[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }

         a=0;
   
      //lcd.print("Masterdata16=");        //md16
        while (a < 8)
        {
        myFile.seek(a+150+d);
      buffer16[a] = myFile.read();
      //Serial.write(buffer16[a]);
      a++;
       if(myFile.read()=='\n')
      {
        break;
      }
        }



      myFile.close();

  return;    
}

//-------------------end of myfilee--------------------------------------------------------------------------------------------------------------------------------

void ball()
{
mcp1porta();
mcp1portb();
mcp2porta();
mcp2portb();
mcp3porta();
mcp3portb();
mcp4porta();
mcp4portb();
mcp5porta();
mcp5portb();
mcp6porta();
mcp6portb();
mcp7porta();
mcp7portb();
mcp8porta();
mcp8portb();
}
//----------------------------------------end of ball------------------------------------------------------------------------------------------------------

void tree()
{
  if(i==0)
  {
    d=0;
  }
  if( i==1)
  {
    d=160;  
  }
   if(i==2 )
  {
    d=320;
  }
     if(i==3)
  {
    d=480;
   
  }
     if(i==4)
  {
    d=640;
  }
     if(i==5)
  {
    d=800;
  }
       if(i==6)
  {
    d=960;
  }
        if(i==7)
  {
    d=1120;  
  }
        if(i==8)
  {
    d=1280;
  }
          if(i==9)
  {
    d=1440;  
  }
           if(i==10)
  {
    d=1600;
  }
             if(i==11)
  {
    d=1760;
  }
             if(i==12)
  {
    d=1920;
  }
             if(i==13)
  {
    d=2080;
  }
             if(i==14)
  {
    d=2240;
  }
              if(i==15)
  {
    d=2400;  
  }
return;
}
//-----------------------end of tree-----------------------------------------------------------------------------------------------------

     
