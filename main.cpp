/*********************************************************************************
SCY202 ICE 02 - Actuation: Ex 2 Template
Name:
Date:

Pseudo-Code:

	Inlcude mbed.h, Motor.h, platform/mbed_thread.h libraries
	Declare Serial port to PC
	Declare Motor object
	Declare potentiomater and joystick
	Define timers t and tlog for control and data logging
	Define all other variables

	Initialize Motor speed to zero
    	Ask user for control frequency, stored in freq
    	Check that the user entered correct frequency, if not, ask again
	Initialize t and tlog

	while(true)
		Read the potentiometer and convert to duty cyle
		Set the speed of the Motor based on duty cycle
		Print tlog and duty cycle 
		if (Joystick is pressed)
			Break while loop
		end-if
		Wait for 1/freq - t seconds
		reset timer t
	end-while
	Set the speed of Motor back to zero
**********************************************************************************/
 
/********************************"Pre-Processors" ********************************/
#include "mbed.h"                    //Include mbed library (Pin and C/C++ API)
#include "Motor.h"                   //Do not forget to import Motor library (Motor API)
#include "platform/mbed_thread.h"

//[Insert] Declare serial port object to pc
//[Insert] Declare motor object
//[Insert] Declare Analog and digital inputs 

Timer t;        //Timer to regulate control sequence
Timer tlog;     //Timer to log data
float dt;       //A variable to regulate the time

//[Insert] Declare any variables you might use in the program
float freq = 5;   //Default frequency, to be changed by user
 
/************************** Beginning of Main Program *****************************/
int main()
{
    //[Insert] Set motor speed to zero (initialize motor)
    
    //[Insert] Ask user for control frequency and store value in freq
    //[Insert] Check that the user entered correct frequency, if not, ask again
    //Once we have a correct frequency
    float Ts = 1.0/freq; //Set period between executions (inverse of frequency)
    //[Insert] Provide instructions to user... like how to stop the program
    wait(2);     //Allow sometime in between (a time buffer)
    t.start();   //Initialize timers
    tlog.start();
    
    while(1) {
        //[Insert]Read the potentiometer and convert to duty cyle
        //[Insert]Set the speed of the motor based on duty cycle
        //[Insert]Print the time and dc values to TeraTerm, use tlog.read() to read the time
        //[Insert]Check if the joystick is being pressed
        //[Insert]Break from the while loop if the joystick is pressed down
        
        //**************The following piece of code regulates the frequency of execution
        //Should not be changed
        dt = Ts-t.read();
        t.stop();
        t.reset();
        if (dt > 0) {
            thread_sleep_for(1000*dt); 		//wait for delta t in milliseconds
        } 
        t.start();
        //*************End of piece of code that regulates frequency
    }
    //[Insert] Set the speed of the motor back to zero
}
/***************************** End of Main Program ******************************/