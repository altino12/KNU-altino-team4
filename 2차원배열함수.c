#include <stdio.h>

int M[115][115]; // 궤적을 출력하기 위해 2차원 배열을 만들어 줌.

int x = 85; // 현재 위치 x
int y = 55; // 현재 위치 y

int main() {

	int i = 0; // 2차원 배열을 위해 i와 j를 선언함
	int j = 0;


	while (i <= 114) {


		while (j <= 114) { // 모든 2차월 배열을 흰 공간으로 채워줌


			M[i][j] = "□";

			j = j + 1; //j++;

		}

		j = 0;
		i = i + 1; //i++;

	}



	i = 0;
	j = 0; // i와 j값 초기화.

	while (i <= 114) { // 지금까지 2차원 배열에 기록했던 궤적들을 CMD 콘솔창에 출력 한다.


		while (j <= 114) {

			printf("%s", M[i][j]);


			j = j + 1; //j++;

		}
		printf("\n");
		j = 0;
		i = i + 1; //i++;

	}


}
