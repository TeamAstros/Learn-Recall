void store_imu()
{
  if(abs(mapyaw-l_value)>2)
  {
    Serial.println("store_imu");
    imuval[index]=mapyaw;
    l_value=mapyaw;
    // timedif[index]=(time2-time1);
    index++;
    time2=millis();
    //  int m=time2-time1;
    // Serial.println(m);
     timedif[index]=(time2-time1);
     time1=time2;
  }
}

void recall()
{
  for(int i=0;i<index;i++)
  {
    Serial.print(imuval[i]);
    Serial.print("--->");
    Serial.println(timedif[i]);
    mapwheels(imuval[i]);
   delay(timedif[i+1]);
  }
}

