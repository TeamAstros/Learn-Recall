void store_imu()
{
  read_imu();
  if(abs(yaw-l_value)>2)
  {
    Serial.println("store_imu");
    imuval[index]=yaw;
    l_value=yaw;
    index++;
    time2=millis();
     timedif[index]=(time2-time1);
     time1=time2;
  }
}

void recall()
{
  for(int i=0;i<index;i++)
  {
    Serial.print(imuval[i]);// raw unmapped yaw
    Serial.print("--->");
    Serial.println(timedif[i]);
    /*mapwheels(imuval[i]);
   delay(timedif[i+1]);*/

    for(long j=millis();millis()-j<=timedif[i+1];)
    {
      /*Attain the yaw of imuval[i]*/
      /*
       * 1. Read the current yaw
       * 2. Map it w.r.t. the initial to attain initial.
       * 3. Map the speed of the wheels using the mapped yaw value
       */
       Serial.print("ArrayVal : ");Serial.print(imuval[i]);
       read_imu();
       IMU_setup();
       mapwheels(mapyaw);
    }
    imu_init = imuval[i+1];
  }
}
