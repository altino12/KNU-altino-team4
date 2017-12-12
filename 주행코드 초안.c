#include "Altino.h"
#include <stdio.h>

SensorData sdata;

int main() {
	Open(szPort);
	while (1) {

		Sendbuf[21] = 10;
		sdata = Sensor(1);

		printf("IR1 : %d, IR2 : %d\n", sdata.IRSensor[0], sdata.IRSensor[1]);
		printf("IR3 : %d, IR4 : %d\n", sdata.IRSensor[2], sdata.IRSensor[3]);
		printf("IR5 : %d, IR6 : %d\n", sdata.IRSensor[4], sdata.IRSensor[5]);

		if (sdata.IRSensor[3]>20) {
                     
			Steering(1); //자회전
			Go(300, 300);
			delay(50);

			if (sdata.IRSensor[2]>20) {
                       
				Steering(1); //자회전
				Go(300, 300);
				delay(300);

			}

			if (sdata.IRSensor[2]>300) {

				Steering(3); //우회전
				Go(-300, -300);
				delay(700);

				Steering(2); //전진
				Go(300, 300);
				delay(50);
			}

			Sendbuf[21] = 10;
			sdata = Sensor(1);

		}

		if (sdata.IRSensor[3]<20) {

			Steering(2); //전진
			Go(300, 300);
			delay(50);

			if (sdata.IRSensor[2]>20) {

				Steering(1); //전진
				Go(300, 300);
				delay(300);

			}

			if (sdata.IRSensor[2]>300) {

				Steering(3); //우회전
				Go(-300, -300);
				delay(700);

				Steering(2); //전진
				Go(300, 300);
				delay(50);
			}
		}
	}
}
