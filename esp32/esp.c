/*#define MODEM_RX 16
#define MODEM_TX 1
#define SIM800A Serial2
#include <SoftwareSerial.h>
*/
#include <SoftwareSerial.h>
SoftwareSerial SIM800A (32,33);
SoftwareSerial esp(26,27);
#include <String.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "web.h"
#include <WebServer.h>
#include <string.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

              /*Includes ESP8266WiFi.h and WiFiClientSecure.h, just have these two libraries downloaded before*/      /*Library file for Google Sheets, has to be used after Wi-Fi Client Secure declaration, here everything is in Trigger_WIFI.h, so using it after Trigger_WIFI.h*/ 

/**********Google Sheets Definations***********/                                                            /*Here No_of_Parameters decides how many parameters you want to send it to Google Sheets at once, change it according to your needs*/
/*********************************************/
const char * ssid = "Hihi";
const char * password = "07062002";

//const char * ssid = "Android";
//const char * password = "12345678";
String GOOGLE_SCRIPT_ID ="AKfycbxQnXckZjN-JhnWhTJAGXX2dWDnMqJABTJLcdc4FvD5_scRQkc2-akgrlITq2b6RzIu";
  int dulieu;                       
WebServer server (80);
void SendWebPage(); // hàm gửi dữ liệu lên web
void  ConnectWifi (); // hàm connecwifi chế độ kết nối wifi ngoài
void  Send_Data(); // 
long last = millis();
long last1 = millis();
long last2 = millis();
  String param;

 float h;
  float t;
  int danggoi=0;
   String a;
   String b;
   String DataSendWeb = ""; // chuỗi dữ liệu thông tin thẻ gửi lên web
int dem=0;
    void  SendMessage(int c) {
  if (c==1)
  {
   
       SIM800A.println("AT");
       
       SIM800A.println("AT+CMGS=\"+84392908655\"\r");
       
       delay(300);
       SIM800A.println("nhiet do qua cao");
       delay(300);
       SIM800A.println((char)26);
       Serial.println("Hoan thanh");
    }
    else if(c==0)
    {
      SIM800A.println("AT");
       SIM800A.println("AT+CMGS=\"+84392908655\"\r");
       delay(300);
       SIM800A.println(WiFi.localIP());
       delay(300);
       SIM800A.println((char)26);
       Serial.println("Hoan thanh");
      
      }
      else if(c==2)
      {
        
       SIM800A.println("AT");
       SIM800A.println("AT+CMGS=\"+84392908655\"\r");
       delay(300);
       SIM800A.println("Co truong hop dot nhap");
       delay(300);
       SIM800A.println((char)26);
       Serial.println("Hoan thanh");
        
        }
  }
    
    
      void GOI()
      {
        danggoi=1;
        SIM800A.println("AT");
        SIM800A.println("ATD0392908655;"); 
        Serial.println ("Goi.......");
        delay(20000);
        last2=millis();
      
     
      }

   void NhanTinNhan()
  {

     Serial.println("DA Nhan ");
    String response = SIM800A.readString();
  Serial.println(response);
         a=response.substring(50,response.length()-1);
          Serial.println(a);
         b=response.substring(10,21);
          Serial.println(b);
          if(b.indexOf("84392908655") >= 0)
          {
            if(response.indexOf("MOCUA")>=0)
            {
            Serial.println("Gui du lieu mo cua");
            gui(1);
            }
            else if(response.indexOf("IP")>=0)
            {
            SendMessage(0);
            }
            
          }
          else
          {
            Serial.println("khong dung mo cua");
            }
    }
   
void XulyText1()
{
  String text1 = server.arg("name1");
  int dulieugui=text1.toInt();
  dulieugui*=7; 
  if(dulieugui!=0)
  {
   gui(dulieugui);
  }
}
void  Send_Data()
{
   server.send(200,"text/html",String(DataSendWeb));
  
 }
void SendWebPage()
{
  server.send(200,"text/html",webpage );
} 
 void gui(int dulieu)
 {
   if(millis()-last>500)
   {
      esp.write(dulieu);
 
     Serial.print("da gui du lieu: ");
     
       Serial.println(dulieu);
       last=millis();
   }
  }
 void  Connect_Wifi()
 {
      WiFi.mode(WIFI_STA);
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  Serial.println(ssid);
   while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("CONNECTED !!!");   
  Serial.println("Connect WiFi");
 Serial.print("Address IP ESP: ");
 Serial.println(WiFi.localIP());
  }
void setup()
{
  last=millis();
  SIM800A.begin(19200);
  esp.begin(19200);
  Serial.begin(19200);   
server.on("/Update",[]{
    Send_Data();
  });
  
  server.on("/mocua",[]{
   gui(1);
  });
  server.on("/doimatkhau",[]{
   gui(2);
  });
  server.on("/themthe",[]{
   gui(3);
  });
  server.on("/xoathe",[]{
   gui(4);
  });
    server.on("/1lop",[]{
    gui(5);
    });
    server.on("/2lop",[]{
    gui(6);
  });
  server.on("/Text1", [] {
    XulyText1();
  });
  SIM800A.println("AT+CPMS=\"SM\",\"SM\",\"SM\""); // Chọn bộ nhớ lưu trữ
  delay(1000);

  SIM800A.println("AT+CNMI=1,2,0,0,0"); // Cấu hình module để thông báo khi có tin nhắn mới
  delay(1000);
  SIM800A.println("AT+CMGF=1");
  Connect_Wifi();
  server.begin();
  Serial.println("Sever Start!!!!");
 server.on("/",[]{
    SendWebPage();
  });
 
   }

 void write_to_google_sheet(String params) // gửi string paramas lên gg sheet
 {
  HTTPClient http;
  String url = "https://script.google.com/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?" + params;
  //Serial.print(url);
  Serial.println("Postring GPS data to Google Sheet");
  //---------------------------------------------------------------------
  //starts posting data to google sheet
  http.begin(url.c_str());
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  int httpCode = http.GET();
  Serial.print("HTTP Status Code: ");
  Serial.println(httpCode);
  //---------------------------------------------------------------------
  //getting response from google sheet
  String payload;
  if (httpCode > 0) {
    payload = http.getString();
    Serial.println("Payload: " + payload);
  }
 // else
 // {
  //  write_to_google_sheet(param);
  // }
  //---------------------------------------------------------------------
  http.end();
} 

void loop()
 {

 if((danggoi==1 )&&(millis()-last2>30000))
 {
  danggoi=0;
    SIM800A.println("ATH");
  }
server.handleClient();
 if (esp.available()) 
  {



   
      String mathe=esp.readStringUntil('\n') ;
      if(mathe.indexOf("spam") >= 0)
      {
       GOI();
     SendMessage(2) ;
       }
       else{
      Serial.print("đã nhan: ");
      Serial.println(mathe);
 //String moi="999";
 param  = "latitude="+mathe;
  write_to_google_sheet(param); 
       }
 }
 if(SIM800A.available())
    {  
      NhanTinNhan();
      
     }
}
    
 
   
  
  
  