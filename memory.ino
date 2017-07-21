void store_imu()
{
  read_imu();
  if(abs(yaw-l_value)>1 )//&& yaw<200 && yaw>-200)
  {
    Serial.println("store_imu");
     imuval[index]=yaw;
    l_value=yaw;
    Serial.print(imuval[index]);// raw unmapped yaw
    index++;
    time2=millis();
     timedif[index]=(time2-time1);
     time1=time2;
    Serial.print("--->");
    Serial.println(timedif[index]);
    
  }
}

void recall()
{
  for(int i=0;i<index;i++)
  {
    if(i==1)
     continue;
    Serial.print(imuval[i]);// raw unmapped yaw
    Serial.print("--->");
    Serial.println(timedif[i]);
    /*mapwheels(imuval[i]);
   delay(timedif[i+1]);*/
    imu_init=imuval[i];
       read_imu();
    while(abs(imu_init-yaw)>5)
    {
      /*Attain the yaw +of imuval[i]*/
      /*
       * 1. Read the current yaw
       * 2. Map it w.r.t. the initial to attain initial.
       * 3. Map the speed of the wheels using the mapped yaw value
       */
       Serial.print("ArrayVal : ");Serial.print(imuval[i]);
       read_imu();
       Serial.print("  ----  ");
       Serial.print(yaw);
       IMU_setup();
       Serial.println(String("---map---")+String(mapyaw)+String("   "));
       mapwheels(mapyaw);
    } 
    /*
  analogWrite(pwm1,0);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm2,0);
  digitalWrite(dir2,LOW);
delay(2000);
    */
    for(int j=millis();millis()-j<timedif[i-1];)
    {
  analogWrite(pwm1,maxspeed);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm2,maxspeed);
  digitalWrite(dir2,LOW);
    }
  }
}
