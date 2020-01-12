/* 
**  Connect the ESP8266 unit to an existing WiFi access point
*/
#include <ESP8266WiFi.h>

//const char* ssid = "TESLA";
//const char* password = "tesla18!";
const char* ssid = "Honor 9 Lite_FAB1";
const char* password = "spacex19";

// Define web server port
WiFiServer server(80);
// define L298N pins
int leftMotorForward = 2;    
int rightMotorForward = 15;  
int leftMotorBackward = 0;   
int rightMotorBackward = 13;  

int rightMotorENB = 14; 
int leftMotorENB = 12;


void setup() {
  // put your setup code here, to run once:

  /* setp wifi config */
  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);

  Serial.print("Authenticating to wifi... : ");
  Serial.print(ssid);

  // wait until connection made to WiFi
  while(WiFi.status() != WL_CONNECTED){
    delay(250);
    Serial.print(".");
  }

  Serial.print("Athentication success...");
  Serial.println();
  Serial.print("Ip addr : ");
  Serial.print( WiFi.localIP());
  Serial.println();

  pinMode(leftMotorForward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT); 
  pinMode(leftMotorBackward, OUTPUT);  
  pinMode(rightMotorBackward, OUTPUT);

  pinMode(leftMotorENB, OUTPUT); 
  pinMode(rightMotorENB, OUTPUT);

  digitalWrite(leftMotorENB,LOW);
  digitalWrite(rightMotorENB,LOW);
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(leftMotorBackward,LOW);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(rightMotorBackward,LOW);

  server.begin();
  /* initialize digital pin LED_BUILTIN as an output. */ 
  pinMode(LED_BUILTIN, OUTPUT);

   
  
  
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  
  // put your main code here, to run repeatedly:

  // check if someone is connected
  WiFiClient client = server.available();
  if(!client){
    return;
  }

  // read which button was pressed from Web Page
  String request = client.readStringUntil('\r');

  // power up led's based on button input
  if(request.indexOf("/forward=1") != -1){
    digitalWrite(leftMotorENB,HIGH);
    digitalWrite(rightMotorENB,HIGH);
    digitalWrite(leftMotorForward,LOW);
    digitalWrite(rightMotorForward,LOW);
    digitalWrite(leftMotorBackward,HIGH);
    digitalWrite(rightMotorBackward,HIGH);
  }

  if(request.indexOf("/reverse=1") != -1){
    
    digitalWrite(leftMotorENB,HIGH);
    digitalWrite(rightMotorENB,HIGH);
    digitalWrite(leftMotorBackward,LOW);
    digitalWrite(rightMotorBackward,LOW);
    digitalWrite(leftMotorForward,HIGH);
    digitalWrite(rightMotorForward,HIGH);

    digitalWrite(LED_BUILTIN, HIGH);
  }

  if(request.indexOf("/stop=1") != -1){
    digitalWrite(leftMotorENB,LOW);
    digitalWrite(rightMotorENB,LOW);
    digitalWrite(leftMotorForward,LOW);
    digitalWrite(leftMotorBackward,LOW);
    digitalWrite(rightMotorForward,LOW);
    digitalWrite(rightMotorBackward,LOW);
  }

  if(request.indexOf("/left=1") != -1){
    digitalWrite(leftMotorENB,HIGH);
    digitalWrite(rightMotorENB,HIGH); 
    digitalWrite(leftMotorForward,HIGH);
    digitalWrite(rightMotorForward,HIGH);
    digitalWrite(rightMotorBackward,LOW);
    digitalWrite(leftMotorBackward,HIGH);
  }

  if(request.indexOf("/right=1") != -1){
    digitalWrite(leftMotorENB,HIGH);
    digitalWrite(rightMotorENB,HIGH);
    digitalWrite(leftMotorForward,HIGH);
    digitalWrite(rightMotorForward,HIGH);
    digitalWrite(rightMotorBackward,HIGH);
    digitalWrite(leftMotorBackward,LOW);
  }

  // create a web page
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  
  client.println("<style>");
  client.println("body {background-color: #ACAEAD;}"); // bg-color
  client.println("@media only screen and (max-width: 600px) {");
  client.println("body { background-color: lightblue; }");
  client.println(".ph-btn{");
  client.println(" font-size:16px;");
  client.println(" padding:4px 6px;");
  client.println("}");
  client.println("}");
  client.println("</style>");

  client.println("<h3><b>IOT 2 Wheel Drive</b></h3>");
  client.println("<br><br>");

  client.println(" <a href=\"/forward=1\"\"><button class=\"ph-btn\">FORWARD</button></a>");
  client.println(" <a href=\"/reverse=1\"\"><button class=\"ph-btn\">REVERSE</button></a>");
  client.println("<br>");
  client.println(" <a href=\"/left=1\"\"><button class=\"ph-btn\">LEFT</button></a>");
  client.println(" <a href=\"/right=1\"\"><button class=\"ph-btn\">RIGHT</button></a>");
  client.println("<br>");
  client.println(" <a href=\"/stop=1\"\"><button class=\"ph-btn\">STOP</button></a>");
  
  client.println("</html>");

  delay(10);
}
