#include <GoPiGo3.h>   // for GoPiGo3
#include <stdio.h>     // for printf
#include <unistd.h>    // for usleep
#include <signal.h>    // for catching exit signals
 

#define NO_LIMIT_SPEED 1000

GoPiGo3 GPG; 

void exit_signal_handler(int signo);

int main(){
	
	signal(SIGINT, exit_signal_handler); // register the exit function for Ctrl+C
	
	GPG.detect();

	printf("\n**** GoPiGo3 Robot Constants:\n");
	printf(" - WHEEL_DIAMETER: %.3f mm\n", GPG.WHEEL_DIAMETER);
	printf(" - WHEEL_BASE_WIDTH: %.3f mm\n", GPG.WHEEL_BASE_WIDTH);
	printf(" - ENCODER_TICKS_PER_ROTATION: %d\n", GPG.ENCODER_TICKS_PER_ROTATION);
	printf(" - MOTOR_GEAR_RATIO: %d\n", GPG.MOTOR_GEAR_RATIO);

	bool keepLooping = true;
        printf("\n****");
	printf("\n        fwd w ");
	printf("\n left  a  spin s   d  right");
	printf("\n            bkwd x ");
        printf("\n****");
	printf("\n\nCmd: (q to exit): ");

	// GPG.set_motor_limits(MOTOR_LEFT,0,300);
	// GPG.set_motor_limits(MOTOR_RIGHT,0,300);
	GPG.set_motor_limits(MOTOR_LEFT,0,0);
	GPG.set_motor_limits(MOTOR_RIGHT,0,0);

	do{
		system("stty raw");
		char c = getchar();
                system("stty cooked");
                printf("\n");
		printf("\nCmd: (q to exit): ");

		switch(c){
			case 'w':  // forward
				GPG.set_motor_dps(MOTOR_LEFT + MOTOR_RIGHT, NO_LIMIT_SPEED);
				break;
			case 'x' :    // backward
				GPG.set_motor_dps(MOTOR_LEFT + MOTOR_RIGHT, NO_LIMIT_SPEED * -1);
				break;
			case 'd' :    // right turn
				GPG.set_motor_dps(MOTOR_LEFT, NO_LIMIT_SPEED);
				GPG.set_motor_dps(MOTOR_RIGHT, 0);
				break;
			case 'a' :     // left turn
				GPG.set_motor_dps(MOTOR_LEFT, 0);
				GPG.set_motor_dps(MOTOR_RIGHT, NO_LIMIT_SPEED);
				break;
			case 'q' :     // quit
				GPG.set_motor_dps(MOTOR_LEFT + MOTOR_RIGHT, 0);
				keepLooping = false;
				break;
			case ' ' :  // stop
				GPG.set_motor_dps(MOTOR_LEFT + MOTOR_RIGHT, 0);
				break;
			case 's' :  // spin
				GPG.set_motor_dps(MOTOR_LEFT, (int)(NO_LIMIT_SPEED/2) );
				GPG.set_motor_dps(MOTOR_RIGHT, (int)(-NO_LIMIT_SPEED/2) );
				break;
		}
	} while (keepLooping);
	system("stty cooked");
        printf("\n");
}


void exit_signal_handler(int signo){
	  if(signo == SIGINT){
         GPG.reset_all();    // Reset everything so there are no run-away motors
         exit(-2);
	  }
}
