
#include<DS1307RTC.h>
#include <DS1307.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <DS1307RTC.h>
#include <Arduino.h>
#include "DS1307.h"
#include <Eeprom24Cxx.h>
#include "Wire.h"   
#include "I2CKeyPad.h"
#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
SoftwareSerial esp (6,7);
#define RST_PIN         8
#define SS_PIN          10
LiquidCrystal_I2C lcd(0x27, 16, 2); // địa chỉ i2c của lcd là 0x27, 16 dòng 2 cột
RTC_DS1307 rtc;
DS1307 clock;
uint8_t index;
// khởi tạo danh sách card và số mã thẻ ban đầu là 1, Mode = 0;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

long last = millis();
const uint8_t KEYPAD_ADDRESS = 0x20;
I2CKeyPad keyPad(KEYPAD_ADDRESS);
int kiemtra1;
char keys[] = "123A456B789C*0#DNF";  // N = NoKey, F = Fail
int Num_Key = 0, Dem_Pass = 0;
int startaddrcard = 2; 
int addrendaddrcard = 1000;  
int startaddrpass = 1010; // địa chỉ bắt đầu của mảng char mật khẩu
int addrnumkey = 1009; // địa chỉ lưu số kí tự trong mật khẩu
//int startaddrcardmaspass = 150; // địa chỉ bắt đầu của mảng char mật khẩu
//int addrcardmasnumkey = 1020; // địa chỉ lưu số kí tự trong mật khẩu
int  ktra ;
int menu = 4;
int demtong = 0;

int Mode = 0, n = 0, k;
uint32_t m;
int time1 = 0, time2 = 0, time3 = 0;
char c[6], d[6];
byte chuoi[16];
int ID;
int dulieu = 0;
char chedomocua=0;
int suco=0;
String chuoithe;
int UID[4], i;
void ThemThe();
void XoaThe();
void DoiMatKhau();
MFRC522 mfrc522(SS_PIN, RST_PIN);

void Out()
{
  lcd.clear();
  demtong = 0; 
  Mode = 0;
  Time();   
}


void MaHoaString()
{
  chuoithe="";
  
  for(int i=0;i<4;i++)
  {
    chuoithe+=(String)UID[i];
    }
  Serial.println(chuoithe);
}
void  MaHoa()
 {
   ID=0;
  int m=25;
  for(int i=0;i<4;i++)
  {
    ID+=UID[i]*m;
    m-=3;
    }
    Serial.print("Ma the sau khi ma hoa: ");
    Serial.println(ID);
   
  }
int quetthe(long thoigian)
{
  Serial.println("BAT dau quet the : ");
  long l = millis();
  while(1)
  {

     while ( ! mfrc522.PICC_IsNewCardPresent()) 
  { 
    if(millis() - l >thoigian)
    return 0 ;
  }
while ( ! mfrc522.PICC_ReadCardSerial()) 
  {  
    
    if(millis() - l > thoigian)
    return 0 ;
  }
    
    for (byte i = 0; i < mfrc522.uid.size; i++) 
  { 
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
       
    UID[i] = mfrc522.uid.uidByte[i];
    
    Serial.print(UID[i]); 
  }
   MaHoa();
   MaHoaString();
    mfrc522.PICC_HaltA();  
  mfrc522.PCD_StopCrypto1();
  return 1;
    
   }
  }


void uint32_tToByte()
{
 
  esp.println(chuoithe);
  Serial.println("DA gui");
  Serial.println(chuoithe);
    Bao();
 
}
int Check_Key(int diachibatdau , int diachisokitu)  //(startaddrpass, addrnumkey
{
  char a[AVR_EEPROM.read_1_byte(diachisokitu) - 1];
  while (Num_Key < AVR_EEPROM.read_1_byte(diachisokitu))
  {
    index = keyPad.getKey();
    if (keys[index] != 'N' && keys[index] != 'F')
    {

      lcd.print(keys[index]);
      lcd.setCursor((4 + Num_Key), 1);
      delay(100);
      lcd.print("*");
      delay(150);
      a[Num_Key++] = keys[index];
    }
  }
  Num_Key = 0;
  int j;
  k = 0;
  for (j = diachibatdau; j < diachibatdau + AVR_EEPROM.read_1_byte(diachisokitu); j++) //  diachisokitu la nội dung ô 1010 // diachibatdau là ô 100
  {

    if (AVR_EEPROM.read_1_byte(j) != a[k] - 48)
    {

      return 0;
    }

    k++;
  }

  return 1;
}
void Time()
{
  DateTime now = rtc.now();
  lcd.setCursor(4, 1);
  if (now.hour() <= 9)
  {
    lcd.print("0");
    lcd.print(now.hour());
  }
  else {
    lcd.print(now.hour());
  }
  lcd.print(':');
  if (now.minute() <= 9)
  {
    lcd.print("0");
    lcd.print(now.minute());
  }
  else {
    lcd.print(now.minute());
  }
  lcd.print(':');
  if (now.second() <= 9)
  {
    lcd.print("0");
    lcd.print(now.second());
  }
  else {
    lcd.print(now.second());
  }
  lcd.print("   ");

  lcd.setCursor(2, 0);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  lcd.print(",");
  if (now.day() <= 9)
  {
    lcd.print("0");
    lcd.print(now.day());
  }
  else {
    lcd.print(now.day());
  }
  lcd.print('/');
  if (now.month() <= 9)
  {
    lcd.print("0");
    lcd.print(now.month());
  }
  else {
    lcd.print(now.month());
  }
  lcd.print('/');
  if (now.year() <= 9)
  {
    lcd.print("0");
    lcd.print(now.year());
  }
  else {
    lcd.print(now.year());
  }
  ;

}

int Check_Card(int id, int a, int b)
{

  lcd.clear();
  int i;
  for (i = b; i <= AVR_EEPROM.read_2_byte(a); i += 2)
  {
    if (AVR_EEPROM.read_2_byte(i) == id)
    {
      return 1;
    }
  }
  return 0;
}

void Delete_Card(int a, int  b, int  c)
{
  int i, j, h = 1;
  if (a == AVR_EEPROM.read_2_byte(b) )
  {
    lcd.clear();
    lcd.print(" KHONG THE XOA");
    delay(500);
    lcd.clear();
    return;
  }
  
  for (i = b + 2; i <= AVR_EEPROM.read_2_byte(c); i += 2)  // b=150 , c 1000
  {

    if (AVR_EEPROM.read_2_byte(i) == a)
    {
      for (j = i; j < AVR_EEPROM.read_2_byte(c); j += 2)
      {
        AVR_EEPROM.write_2_byte(j, AVR_EEPROM.read_2_byte(j + 2) );
      }
      AVR_EEPROM.write_2_byte(c, (AVR_EEPROM.read_2_byte(c) - 2));
      h = 0;
      break;
    }
  }
  if (h == 1)
  {
    lcd.clear();
    lcd.print("THE KO TON TAI");
    delay(500);
  }
}

void SPAM(int c)
{
  if (c == 0)
  {
    digitalWrite(A1, 1);
    delay(100);
    digitalWrite(A1, 0);
  }
  else
  {
    digitalWrite(A1, 1);
    digitalWrite(A0, 1);
    delay(1000);
    digitalWrite(A1, 0);
    digitalWrite(A0, 0);
  }


}


unsigned int Gia_tri_moi;
void setup1()
{
  TCCR1A = 0;
  TCCR1B = 0;
  // RESET lại 2 thanh ghi
  DDRB |= (1<< PB1);
  // Đầu ra PB0 là OUTPUT ( pin 8)

  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12) | (1 << WGM13);
  // chọn Fast PWM, chế độ chọn TOP_value tự do  ICR1
  TCCR1A |= (1 << COM1A1);
  // So sánh thường( none-inverting)

  TCCR1B |= (1 << CS11);
  // P_clock=16mhz/8=2mhz
  // mỗi P_clock bằng 1/2mhz= 0.5 us
  OCR1A = 1060;
  Gia_tri_moi = OCR1A;
  // Value=1060 , tương đương xung có độ rộng 1060*0.5us=530us (0.53ms)
  // Value=4820, tương đương xung có độ rộng 4820*0.5us=2410us (2,41ms)
  ICR1 = 40000;
  // xung răng cưa tràn sau 40000 P_clock, tương đương (20ms)
}
void Bao()
{
  digitalWrite(A1, 1);
    delay(100);
    digitalWrite(A1, 0);
 }
void set(unsigned int x)
{
  if (Gia_tri_moi != x) {
    OCR1A = x;
    Gia_tri_moi = OCR1A;
  }
  else {
    return; // thoát ngay
  }
  // x : 1060 - 4820
  //Độ rộng: 0.53ms - 2.41 ms
}

void setup ()
{
  Serial.begin(19200);
  esp.begin(19200);
  lcd.init();
  lcd.backlight();
   SPI.begin();    
    mfrc522.PCD_Init();
  pinMode(menu, INPUT_PULLUP);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT); 
}


void loop()
{

  

  if(digitalRead(menu)==0)
  {
    delay(50);
    if(digitalRead(menu)==0)
   {
    while(digitalRead(menu)==0);
    if(Mode==0)
    {
      Mode=1;
    }
    else
    {
       Mode=0;
     }
    }
    }
  
  if (Mode == 0)
  {
   
    Time();// HIỆN GIỜ
    
    if (esp.available()) // ktra xem dũ liệu từ esp32 qua kh
    {
      
      Bao(); // có dữ liệu
      
     dulieu=esp.read();
     
    if(dulieu==5)
    {
      chedomocua=1;
      dulieu==0;
      }
      else if (dulieu==6)

      {
        chedomocua=0;
        dulieu==0;
       }
      
      else if (dulieu==1)
      {
      // digitalWrite(A0,1);
        
        setup1();
        set(3500); // 125 độ
        delay(2000);
          // digitalWrite(A0,0);
            set(1060);
            dulieu = 0;
            
        }
          else if(dulieu==2)
          {
            DoiMatKhau();
            dulieu=0;
           }
          else if(dulieu==3)
            {
              ThemThe();
            dulieu=0;
            }
            else if (dulieu==4)
            {
            XoaThe();
            dulieu=0;
             }
             else
             {
              XoaTheoThuTu(dulieu/7);
             }
             
        }  
      }
       
    if(Mode==1)
    {
      int ktra1,Dem_Card=0,Dem_Pass=0;
       while (Dem_Card<2)
          {  
          lcd.clear() ;      
            lcd.print(">QUET THE ");

            if (quetthe(5000) == 0)

            {
              Out();
              break;
            }

            if (Check_Card(ID, addrendaddrcard , startaddrcard ) == 1)
            {
              ktra1 = 0;
              delay(500);
              
              while (Dem_Pass < 2)
              {
               if(chedomocua==1)
               {
                  lcd.clear();
                  Dem_Pass = 0;
                  lcd.clear();
                  lcd.print(" MAT KHAU DUNG");
                  lcd.setCursor( 0, 1);
                  lcd.print(" WELCOM!!!");
                  uint32_tToByte();
                   
                  setup1();
                  set(3500); // 90 độ
                  delay(2000);
                  set(1060); // 0 độ
                  lcd.clear();
                  kiemtra1 == 1;
                  break;
                  ktra = 1;
                }

                lcd.clear();
                lcd.print(">NHAP MAT KHAU");
                lcd.setCursor(4, 1);

                if (Check_Key(startaddrpass, addrnumkey) == 1)
                {

                  lcd.clear();
                  Dem_Pass = 0;
                  lcd.clear();
                  lcd.print(" MAT KHAU DUNG");
                  lcd.setCursor( 0, 1);
                  lcd.print(" WELCOM!!!");
                  uint32_tToByte();
                  
                  setup1();
                  set(3500); // 90 độ
                  delay(2000);
                  set(1060); // 0 độ
                  lcd.clear();
                  kiemtra1 == 1;
                  break;
                  ktra = 1;
                }

                else
                {
                  SPAM(0);
                  Dem_Pass++;
                  lcd.clear();
                  if (Dem_Pass > 1)
                  {
                    if (AVR_EEPROM.read_2_byte(startaddrcard) == ID) // startaddrcard = 150
                    {

                      Dem_Pass = 9;
                      kiemtra1 = 1;
                      ktra1 = 1;
                      break;
                    }
                    else
                    {
                      Delete_Card(ID, startaddrcard, addrendaddrcard);
                     
                      kiemtra1 = 1;
                      Dem_Pass = 9;
                      ktra1 = 1;
                      break;
                      
                    }
                  }
                }
              }
              if( Dem_Pass == 9) // phat hienj spam
              {
                esp.println("spam");
                 Serial.print("DA gui: ");
                 Serial.println("spam");
                 Dem_Pass =0;
                SPAM(1);
                Out();  
                }
                Dem_Card=3;
            }
            else // ma the sai
            {
              SPAM(0);
              Dem_Card++;

              if (Dem_Card > 1)
              {
                SPAM(1);
                Dem_Card = 9;
                esp.println("spam");
                 Serial.print("DA gui: ");
                 Serial.println("spam");
                Out();
                break;
              }
            }           
          }  
     }   
}
void DoiMatKhau()
{
Dem_Pass=0;
 while (Dem_Pass < 2)
              {
                  lcd.clear();
                  lcd.print(">MAT KHAU MOI");
                  lcd.setCursor(4, 1);
                  m = 0;
                  while (m < 6)
                  {

                    index = keyPad.getKey();
                    if (keys[index] != 'N' && keys[index] != 'F')
                    {
                      lcd.print(keys[index]);
                      lcd.setCursor((4 + m), 1);
                      delay(100);
                      lcd.print("*");
                      delay(150);
                      c[m++] = keys[index];
                    }

                  }
                  delay(100);

                  m = 0;
                  lcd.clear();
                  lcd.print(">XAC NHAN LAI");
                  lcd.setCursor(4, 1);

                  while (m < 6)
                  {

                    index = keyPad.getKey();
                    if (keys[index] != 'N' && keys[index] != 'F')
                    {
                      lcd.print(keys[index]);
                      lcd.setCursor((4 + m), 1);
                      delay(100);
                      lcd.print("*");
                      delay(150);
                      d[m++] = keys[index];
                    }
                  }
                  n = 0;
                  ktra=0;

                  for (k = 0; k < 6; k++)
                  {
                    if (c[k] != d[k])
                    {

                      n = 1;
                      lcd.clear();
                      lcd.print("KHONG TRUNG KHOP");
                      SPAM(0);
                      delay(1000);
                      lcd.clear();
                      ktra = 2;
                     
                      break;
                    }
                  }
                  if (n == 0)
                  {
                    k = 0;

                    for (m = startaddrpass; m < startaddrpass + 6; m++)
                    {

                      if (AVR_EEPROM.read_1_byte(m) != (c[k]) - 48)
                      {
                        ktra = 1;
                        lcd.clear();
                        lcd.print("  HOAN THANH"); 
                        delay(1000);
                        for (k = 0; k < 6; k++)
                        {

                          AVR_EEPROM.write_1_byte(1010 + k, c[k] - 48);
                        }
                          Dem_Pass=3;
                        break;
                      }
                      k++;
                      
                    }


                  }
                  if (ktra == 0)
                  {

                    lcd.clear();
                    lcd.print("PASS MOI GIONG");
                    lcd.setCursor(0, 1);
                    lcd.print("    PASS CU");
                    SPAM(0);
                    delay(1000);
                    lcd.clear();
                   
                  }
              }
 }
  void XoaThe()
  {
      if (startaddrcard == AVR_EEPROM.read_2_byte(addrendaddrcard)) // 
          {

            lcd.clear();
            lcd.print(" DANH SACH THE");
            lcd.setCursor(1, 1);
            lcd.print("PHU DA TRONG");
            SPAM(0);
            delay(1000);
            Out();

          }
          else
          {
            while (1)
            {
              if (startaddrcard == AVR_EEPROM.read_2_byte(addrendaddrcard))
              {

                lcd.clear();
                lcd.print(" DANH SACH THE");
                lcd.setCursor(1, 1);
                lcd.print("PHU DA TRONG");
                SPAM(0);
                delay(1000);
                Out();
                break;
              }
                    n = 0;
                    lcd.clear();
                    lcd.print("QUET THE CAN XOA ");
                    if (quetthe(6000) == 0)

                    {                  
                      Out();
                      break;
                    }
                    lcd.clear();
                    lcd.print("DANG XOA....");
                    Delete_Card(ID, startaddrcard, addrendaddrcard);
                    lcd.print("     OK.");
                    delay(1000);
                    
                    lcd.clear();  
                  }  
  }
  }
  
  void ThemThe()
  {
    while(1)
   {
                  lcd.clear();
                  lcd.print("QUET THE DE THEM");
                  if (quetthe(6000) == 0)

                  {
                    Out();
                    break;
                  }
                  lcd.clear();
                  lcd.print("DANG THEM....");
                  ktra = 1;
                  for (k = startaddrcard; k <= AVR_EEPROM.read_2_byte(addrendaddrcard); k += 2)
                  {
                    if (ID == AVR_EEPROM.read_2_byte(k))
                    {
                      lcd.clear();
                      lcd.print("THE DA TON TAI");
                      delay(1000);
                      lcd.clear();                      
                      ktra = 0;
                      break;
                    }
                  }
                  if (ktra == 1)
                  {
                    AVR_EEPROM.write_2_byte(AVR_EEPROM.read_2_byte(addrendaddrcard) + 2, ID);
                    AVR_EEPROM.write_2_byte(addrendaddrcard, AVR_EEPROM.read_2_byte(addrendaddrcard) + 2 );           
                    delay(1000);
                    ktra = 0;
                  }
                  lcd.clear();
                  lcd.print("     OK.");               
                   
    }
  }
  void XoaTheoThuTu(int thutu)
  {
 if(startaddrcard + 2*thutu >  AVR_EEPROM.read_2_byte(addrendaddrcard))
          {
            lcd.clear();
            lcd.print("   THU TU THE  ");
            lcd.setCursor(1, 1);
            lcd.print(" KHONG TON TAI");
            SPAM(0);
            delay(1000);
            Out();
            }
          else
          {
            if( startaddrcard + 2*thutu ==    AVR_EEPROM.read_2_byte(addrendaddrcard))
            {
                AVR_EEPROM.write_2_byte(addrendaddrcard, (AVR_EEPROM.read_2_byte(addrendaddrcard) - 2));
             } 
             else
           {
      for (int i = startaddrcard + 2*thutu;i <= AVR_EEPROM.read_2_byte(addrendaddrcard);i+=2)
        {
        AVR_EEPROM.write_2_byte(i, AVR_EEPROM.read_2_byte(i + 2) );
        }
         AVR_EEPROM.write_2_byte(addrendaddrcard, (AVR_EEPROM.read_2_byte(addrendaddrcard) - 2));
          }
  }
  }
  