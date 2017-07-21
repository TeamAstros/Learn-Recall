int imu_init ;//= 123 ; //Set initial value here

#define push 22
#define dir1 26
#define dir2 28
#define pwm1 3
#define pwm2 4

int time1=millis();
int time2;
int timedif[1000];
int yaw,mapyaw,imuval[1000],index=0;
int l_value=0;
int flag=0;
String val;
int speed1=0,speed2=0;
int maxspeed=40;

void setup() {
Serial.begin(115200);
Serial3.begin(57600);

pinMode(22,INPUT_PULLUP);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);
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
   store_imu(); 
  }
  else if(flag==2)
  {
    Serial.println("recall");
    delay(3000);
    recall();
    flag=-999;
  }
  else 
  {
    analogWrite(pwm1,0);
    digitalWrite(dir1,HIGH);
    analogWrite(pwm2,0);
    digitalWrite(dir2,LOW);
  }
}
