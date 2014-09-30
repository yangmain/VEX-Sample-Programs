#pragma config(Sensor, in4,    light,               sensorReflection)
#pragma config(Sensor, dgtl11, bump,                sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |+++++++++++++++++++++++++++++++++++++++++++++++
Light Sensor Debug Stream for Graphing
- This program outputs the value of a VEX Ambient Light sensor 10x a second to the ROBOTC Debug Stream
  Debugger window, until a touch sensor is pressed. The data created by the program can be copied
  from the Debug Stream and pasted into Office Excel or OpenOffice Calc and graphed for analysis.
- The Debug Stream Debugger window can be found by selecting Window > Menu Level > Expert / Super User.
- This method will work for sampling data from any of the sensors!

[I/O Port]          [Name]              [Type]                  [Description]
Analog Port 4       light               Ambient Light Sensor    Top mounted sensor
Digital Port 11     bump                Bumper Switch           Top mounted sensor
----------------------------------------------------------------------------------------------------*/

task main()
{
  writeDebugStreamLine("Time \t Value");  //Write Categories to the Debug Stream
  clearTimer(T1);
  while(SensorValue[bump] == 0) //While the bump switch is released...
  {
    writeDebugStreamLine("%d \t %d", time1[T1], SensorValue[light]);  //Output the timestamp and sensor data...
    wait1Msec(100);                                                   //10x per second
  }
}