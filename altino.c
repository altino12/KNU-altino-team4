#include "Altino.h"
#include <stdio.h>

SensorData sdata; //센서를 이용하기 위한 선언


int main() {

	Open(szPort); // 블루투스 연결



	while (1) {

		Sendbuf[21] = 10;
		sdata = Sensor(1); // 센서값을 부르기 위한 함수

		if (sdata.IRSensor[2] > 16) { // [2]번 센서와 벽의 거리가 약 3CM정도 보다 가까우면 좌회전


			Steering(1); //좌회전

			Go(290, 290); //뒷바퀴 속도 290,290

		}

		if (sdata.IRSensor[2] <= 16 && sdata.IRSensor[2] > 8) { // [2]번 센서와 벽의 거리가 약 3~5CM일경우 직진


			Steering(2); //전진

			Go(290, 290); //뒷바퀴 속도 290,290

		}

		if (sdata.IRSensor[2] <= 8) { // [2]번 센서와 벽의 거리가 약 5CM일경우 벽에 붙기 위해 우회전


			Steering(3); //우회전

			Go(290, 290); // 뒷바퀴 속도 290,290

		}

		if (sdata.IRSensor[4] >= 600) { // 알티노 주행의 종료 조건 IR [4번] 센서를 손으로 잡는다.

			break;
		}


	}

Close(); //알티노와의 연결을 끊는다.

return 0;

}
