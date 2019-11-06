#include <stdio.h>
#define leapyear(year) ((year)%4==0 && ( (year)%100!=0 || (year)%400==0 )) //윤년판정매크로

int main(void)
{
	int year, month; // 연도와 월을 저장할 변수
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // 각 달의 총일 수 (첫번째 수는 제외) 
	int lastyear, day, i; printf("몇년 몇월의 달력을 출력하시겠습니까?: ");
	scanf_s("%d %d", &year, &month); if (month == 2 && leapyear(year)) // 해당년도가 윤년이면, 2월은 총 29일 
		totalday[2] = 29;

	lastyear = year - 1; // 작년 말까지 진행된 요일을 계산하기 위해 lastyear를 선언 
	day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7;
	/* lastyear : 1년은 365일, 1년이 지날때마다 요일이 한번 늘어난다
	 (365를 7로 나누면 1이기 때문) +(lastyear/4)-(lastyear/100)+(lastyear/400) : 윤년의 다음연도는 요일이 두번 늘어므로,
	 lastyear까지 있던 모든 윤년을 더한다 +1 : 1년 1월 1일은 일요일이 아니라 월요일이므로 1을 더한다 (0년은 없다) %7 :
	 요일은 7가지 이므로, 앞의 계산값을 7로 나눈 나머지가 year년 1월의 첫요일 뜻한다
	 나머지값에 따라 0:일요일, 1:월요일, 2:화요일, 3:수요일, 4:목요일, 5:금요일, 6:토요일 */

	for (i = 1; i < month; i++) // year년 month월 직전까지의 총 일 수를 구하기 위한 for문 
		day += totalday[i];
	day %= 7; // year년 month월 1일의 시작 요일 
	printf("\n %d년 %d일\n", year, month); // year년 month월 타이틀 출력 
	printf("\n 일 월 화 수 목 금 토"); // 요일 리스트 출력 

	for (i = -day; i < totalday[month]; i++) {
		if ((i + day) % 7 == 0) // 출력될 차례가 일요일이면, 개행 
			printf("\n"); if (i < 0) // month월 1일이 출력되기 이전의 날짜는 공백으로 채움 
			printf(" "); else // 날짜 출력 
			printf("%4d", i + 1);
	}

	printf("\n\n");

	return 0;
}