//#include<SoftwareSerial.h>
//SoftwareSerial saber(2,3);

#define push 22

int imu_init ;//= 123 ; //Set initial value here

int time1=millis();
int time2;
int timedif[1000];
int yaw,mapyaw,imuval[1000],index=0;
int l_value=0;
int flag=0;
String val;
int speed1=0,speed2=0;
int maxspeed=40;

void setup()
{
Serial.begin(115200);
Serial3.begin(57600);
Serial1.begin(9600);   

pinMode(push,INPUT_PULLUP);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
/*
analogWrite(pwm1,100);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm2,100);
  digitalWrite(dir2,LOW);
  delay(3000);
  */
}

void loop()
{ 
//  read_imu();
//  Serial.println(yaw);
//  Serial.print(" ");
//  Serial.println(mapyaw);
  if(!digitalRead(push)) // Button pressed
  {
    Serial.println("push main hai");
    time1=millis();
    flag++;
    while(!digitalRead(push));
  }
  if(flag==1)
  {
   digitalWrite(13,HIGH);
   store_imu();
    
  }
  else if(flag==2)
  {
    digitalWrite(13,LOW);
    Serial.println("recall");
    delay(3000);
    recall();
    flag=-999;
  }
  else 
  {
    //int z=0;
//   saber.write((int)0);
//analogWrite(3,0);
Serial1.write(0);
   }
}
