
void mapwheels(int my_yaw)
{   
  if(my_yaw>=0)
  {
 
    speed1 = map(my_yaw,0,(maxspeed/2),maxspeed-1,0);
    speed2 = maxspeed;
  
 }

  if(my_yaw<0)
  {
 
    speed1 = maxspeed;
    speed2 = map(my_yaw,-1,-(maxspeed/2),maxspeed-1,0);
  }
 /* Serial.print(" MappedYaw : ");Serial.print(my_yaw);
  Serial.print(" Speed1 ");Serial.print(speed1);
  Serial.print(" Speed2 ");Serial.print(speed2);
   Serial.print("==== ");
  */
  runwheels();
}


void runwheels()
{
  if(speed1<0)
   speed1=0;
   if(speed2<0)
   speed2=0; 
   int aspeed1=map(speed1,0,maxspeed,64,32);
   int aspeed2=map(speed2,0,maxspeed,192,160);
  Serial1.write(aspeed1);
  Serial1.write(aspeed2);
 /*
  Serial.print(" ASpeed1 ");Serial.print(aspeed1);
  Serial.print(" ASpeed2 ");Serial.println(aspeed2);
*/
}
