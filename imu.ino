void read_imu()
{
  if(Serial3.available())
  {
   val=Serial3.readStringUntil('/');
   yaw=val.toInt();
   //IMU_setup();
  }
}
void IMU_setup()
{
  if(imu_init>=0)
    func();
  else if(imu_init<0)
    func2();
}

void func()
{ 
     if(yaw>=imu_init && yaw<=179)
    {
      mapyaw=map(yaw,imu_init,179,0,(179-imu_init));
    }
        
    else if(yaw>=-179&&yaw<=-179+imu_init)
    {
      mapyaw=map(yaw,-179,(-179+imu_init),(180-imu_init),179);
    }
        
    else if(yaw>=-179+imu_init && yaw<=0)
    {
      mapyaw=map(yaw,-179+imu_init,0,-179,-imu_init);
    }
    
    else if(yaw>=0&&yaw<=imu_init)
     
    {
      mapyaw=map(yaw,0,imu_init,-imu_init,0);
    }
  }

void func2()
{ 
        
    if(yaw<=0 && yaw>=imu_init)
    {
      mapyaw=map(yaw,imu_init,0,0,-imu_init);
    }
        
    else if(yaw<=imu_init && yaw>=-179)
    {
      mapyaw=map(yaw,imu_init,-179,0,-179-imu_init);
    }
        
    else if(yaw<=179 && yaw>=179+imu_init)
    {
      mapyaw=map(yaw,179,179+imu_init,-179-imu_init,-179);
    }
    
    else if(yaw<=179+imu_init && yaw>=0)
     
    {
     mapyaw=map(yaw,179+imu_init,0,179,-imu_init);
    }
}

