
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*牌的数据结构*/
typedef struct
{
	char face[4];
	int num;
}FACE;
/*建立返回牌结果的数据结构*/
typedef struct
{
	int result;    //点数
	int max;     //最大的那张牌
	int number;    //如果多张牌时返回
	int numberzhi;
}PAIRESULT;
/*建立总共纸牌初始函数*/
void inition(FACE zong[])
{
	int i;
	for (i = 1; i <= 4; i++)
	{
		strcpy(zong[i].face, "3");
		zong[i].num = 0;
	}
	for (i = 5; i <= 8; i++)
	{
		strcpy(zong[i].face, "4");
		zong[i].num = 1;
	}
	for (i = 9; i <= 12; i++)
	{
		strcpy(zong[i].face, "5");
		zong[i].num = 2;
	}
	for (i = 13; i <= 16; i++)
	{
		strcpy(zong[i].face, "6");
		zong[i].num = 3;
	}
	for (i = 17; i <= 20; i++)
	{
		strcpy(zong[i].face, "7");
		zong[i].num = 4;
	}
	for (i = 21; i <= 24; i++)
	{
		strcpy(zong[i].face, "8");
		zong[i].num = 5;
	}
	for (i = 25; i <= 28; i++)
	{
		strcpy(zong[i].face, "9");
		zong[i].num = 6;
	}
	for (i = 29; i <= 32; i++)
	{
		strcpy(zong[i].face, "10");
		zong[i].num = 7;
	}
	for (i = 33; i <= 36; i++)
	{
		strcpy(zong[i].face, "J");
		zong[i].num = 8;
	}
	for (i = 37; i <= 40; i++)
	{
		strcpy(zong[i].face, "Q");
		zong[i].num = 9;
	}
	for (i = 41; i <= 44; i++)
	{
		strcpy(zong[i].face, "K");
		zong[i].num = 10;
	}
	for (i = 45; i <= 48; i++)
	{
		strcpy(zong[i].face, "A");
		zong[i].num = 11;
	}
	for (i = 49; i <= 52; i++)
	{
		strcpy(zong[i].face, "2");
		zong[i].num = 12;
	}
}
/*建立输出函数*/
void output(int n, FACE zong[], int k)
{
	int i;
	printf("/n");
	if (k == 2)
		printf("这是玩家的牌/n");
	else
		printf("这是庄家的牌/n");
	for (i = 1; i <= n; i++)
		printf("%s ", zong[i].face);
	printf("/n");
}
/*建立洗牌函数*/
void xipai(FACE zong[])
{
	int i, j;
	long k;
	FACE temp;
	srand(time(NULL));
	for (k = 1; k<1000; k++)
	{
		i = 1 + rand() % 52;
		j = 1 + rand() % 52;
		temp = zong[i];
		zong[i] = zong[j];
		zong[j] = temp;
	}
}

/*建立发牌函数*/
void fapai(FACE zong[], FACE player1[], FACE player2[])
{
	int i = 1, c1 = 1, c2 = 1;
	for (i = 1; i <= 10;)
	{
		player1[c1++] = zong[i++];
		player2[c2++] = zong[i++];
	}
}
/*建立牌的排序函数*/
void paisort(FACE player[])
{
	FACE temp;
	int i, j;
	for (i = 0; i<4; i++)
		for (j = 1; j <= 4 - i; j++)
			if (player[j].num>player[j + 1].num)
			{
				temp = player[j];
				player[j] = player[j + 1];
				player[j + 1] = temp;
			}
}
/*建立只有三张非纸牌的函数*/
int san(int a2[])
{
	if ((a2[0] + a2[1] + a2[2]) % 10 == 0)//三张牌和为十的倍数时
		return 10;
	else   //没有牛时
	{
		/*以下是有两张牌和为10时*/
		if (a2[0] + a2[1] == 10)  return a2[2];
		if (a2[0] + a2[2] == 10)    return a2[1];
		if (a2[1] + a2[2] == 10)    return a2[0];
		else
			return 0;
	}
}

/*建立有四张非花牌时的函数*/
int si(int a[])
{
	if ((a[0] + a[1] + a[2]) % 10 == 0)   //其中有三张牌和为10的倍数时
		return a[3];
	if ((a[0] + a[1] + a[3]) % 10 == 0)
		return a[2];
	if ((a[0] + a[2] + a[3]) % 10 == 0)
		return a[1];
	if ((a[3] + a[1] + a[2]) % 10 == 0)
		return a[0];
	/*以下是有两张牌和为1*/
	else
	{
		if (a[0] + a[1] == 10 && a[2] + a[3] == 10)
			return 10;
		if (a[0] + a[1] == 10 && a[2] + a[3] != 10)
			return (a[2] + a[3]) % 10;
		if (a[0] + a[2] == 10 && a[1] + a[3] == 10)
			return 10;
		if (a[0] + a[2] == 10 && a[1] + a[3] != 10)
			return (a[1] + a[3]) % 10;
		if (a[0] + a[3] == 10 && a[2] + a[1] == 10)
			return 10;
		if (a[0] + a[3] == 10 && a[2] + a[1] != 10)
			return (a[2] + a[1]) % 10;
		if (a[1] + a[2] == 10 && a[0] + a[3] == 10)
			return 10;
		if (a[1] + a[2] == 10 && a[0] + a[3] != 10)
			return (a[0] + a[3]) % 10;
		if (a[1] + a[3] == 10 && a[0] + a[2] == 10)
			return 10;
		if (a[1] + a[3] == 10 && a[0] + a[2] != 10)
			return (a[2] + a[0]) % 10;
		if (a[2] + a[3] == 10 && a[0] + a[1] == 10)
			return 10;
		if (a[2] + a[3] == 10 && a[0] + a[1] != 10)
			return (a[0] + a[1]) % 10;
		/*若无法凑出十时，点为零*/
		else
			return 0;
	}
}
/*若无张牌都为非花牌，即五张非花牌时,若要有点数，必须用三张牌来凑点数*/
int wu(int a[])
{
	if ((a[0] + a[1] + a[2]) % 10 == 0 && a[3] + a[4] == 10)
		return 10;
	if ((a[0] + a[1] + a[2]) % 10 == 0 && a[3] + a[4] != 10)
		return (a[3] + a[4]) % 10;

	if ((a[0] + a[1] + a[3]) % 10 == 0 && a[2] + a[4] == 10)
		return 10;
	if ((a[0] + a[1] + a[3]) % 10 == 0 && a[2] + a[4] != 10)
		return (a[2] + a[4]) % 10;

	if ((a[0] + a[1] + a[4]) % 10 == 0 && a[2] + a[3] == 10)
		return 10;
	if ((a[0] + a[1] + a[4]) % 10 == 0 && a[2] + a[3] != 10)
		return (a[2] + a[3]) % 10;

	if ((a[0] + a[2] + a[3]) % 10 == 0 && a[1] + a[4] == 10)
		return 10;
	if ((a[0] + a[2] + a[3]) % 10 == 0 && a[1] + a[4] != 10)
		return (a[1] + a[4]) % 10;

	if ((a[0] + a[2] + a[4]) % 10 == 0 && a[1] + a[3] == 10)
		return 10;
	if ((a[0] + a[2] + a[4]) % 10 == 0 && a[1] + a[3] != 10)
		return (a[1] + a[3]) % 10;

	if ((a[0] + a[4] + a[3]) % 10 == 0 && a[2] + a[1] == 10)
		return 10;
	if ((a[0] + a[4] + a[3]) % 10 == 0 && a[2] + a[1] != 10)
		return (a[2] + a[1]) % 10;

	if ((a[2] + a[1] + a[3]) % 10 == 0 && a[4] + a[0] == 10)
		return 10;
	if ((a[2] + a[1] + a[3]) % 10 == 0 && a[0] + a[4] != 10)
		return (a[0] + a[4]) % 10;

	if ((a[2] + a[1] + a[4]) % 10 == 0 && a[0] + a[3] == 10)
		return 10;
	if ((a[2] + a[1] + a[4]) % 10 == 0 && a[0] + a[3] != 10)
		return (a[0] + a[3]) % 10;

	if ((a[4] + a[1] + a[3]) % 10 == 0 && a[2] + a[0] == 10)
		return 10;
	if ((a[4] + a[1] + a[3]) % 10 == 0 && a[2] + a[0] != 10)
		return (a[2] + a[0]) % 10;

	if ((a[2] + a[4] + a[3]) % 10 == 0 && a[0] + a[1] == 10)
		return 10;
	if ((a[2] + a[4] + a[3]) % 10 == 0 && a[0] + a[1] != 10)
		return (a[0] + a[1]) % 10;
	else
		return 0;
}
/*建立求最大值的函数*/
int searchmaxpai(FACE player[])
{
	int a[7] = { 0 }, i, max;
	for (i = 1; i <= 5; i++)
	{
		if (player[i].num >= 11)
			a[i] = player[i].num - 13;
		else
			a[i] = player[i].num;
	}
	for (max = a[1], i = 1; i <= 5; i++)
		if (max<a[i])
			max = a[i];
	return max;
}
/*建立计算有几张重复牌的函数*/
void countrepeat(int a[], int n, int b[])
{
	int k[5] = { 0 }, i = 0, j = 0, temp = 0;
	for (i = 0; i<n; i++)
	{
		temp = a[i];
		for (j = 0; j<n; j++)
			if (temp == a[j])
				k[i]++;
	}
	for (i = 0; i<n; i++)
	{
		if (k[i] >= 3)
		{
			b[0] = k[i];   //b[0]存储重复数目
			b[1] = a[i];
			break;//b[1]存储对应的值
		}

	}
}
/*建立计算牌的点数的函数，这是游戏的核心算法*/
PAIRESULT jisuan(FACE player[], PAIRESULT finalresult)
{
	int a1[5] = { 0 }, c1 = 0;//用于存储10，J,Q,K的花牌表示的值
	int a[2] = { -1,-1 };
	int a2[5] = { 0 }, c2 = 0; //用于存储非花牌表示的值
	int i;
	for (i = 1; i <= 5; i++)  //总共5次
	{
		if (player[i].num >= 7 && player[i].num <= 10)  //如果是花牌时
			a1[c1++] = player[i].num + 3;
		else
			if (player[i].num >= 0 && player[i].num <= 6)//如果是3-9时
				a2[c2++] = player[i].num + 3;
			else
				a2[c2++] = player[i].num - 10;  //如果是A或2时
	} //完成对牌的分类存储
	  /*以下对非花牌进行计算点数*/
	switch (c2)
	{
	case 0: finalresult.result = 10; break; //都是花牌时
	case 1: finalresult.result = a2[0]; break;  //只有一张非花牌时
												/*只有二张非零牌时*/
	case 2: {if (a2[0] + a2[1] == 10)
		finalresult.result = 10;
			else
				finalresult.result = (a2[0] + a2[1]) % 10;
	}break;
		/*以下是由三张非花牌时*/
	case 3: finalresult.result = san(a2); break;
		/*以下是四张非花牌时*/
	case 4: finalresult.result = si(a2); break;
		/*以下是五张非花牌时*/
	case 5: finalresult.result = wu(a2); break;
	}
	finalresult.max = searchmaxpai(player);       //最大牌的值，便于点数相同时比较大小
												  /*以下对有可能有的多张牌进行处理,存储最多的牌*/
	if (c1 >= 3)
	{
		countrepeat(a1, c1, a);
		if (a[0] >= 3)
		{
			finalresult.number = a[0] + 1;   //如果是花牌有多张时倍数更大
			finalresult.numberzhi = a[1];
		}
	}
	else
		if (c2 >= 3)
		{
			countrepeat(a2, c2, a);
			if (a[0] >= 3)
			{
				finalresult.number = a[0];
				finalresult.numberzhi = a[1];
			}
		}
		else
			finalresult.number = finalresult.numberzhi = -1;
	return finalresult;
}
PAIRESULT build()
{
	PAIRESULT final;
	final.max = -1,
		final.number = -1;
	final.result = final.numberzhi = -1;
	return final;
}
/*建立牌的比较函数，a[0]总金钱，a[1]表示押金*/
int  compare(PAIRESULT final1, PAIRESULT final2, int a[])
{
	int t = a[0];
	/*做如下规定，四张相同牌，20，三张相同牌15倍，五张即四张花牌时25被*/
	/*相同牌时庄家牌大*/
	switch (final1.number)
	{
	case 5: {if (final2.number == 5 && final1.numberzhi >= final2.numberzhi)
	{
		a[0] = a[0] - a[1] * 25;
		break;
	}
			if (final2.number == 5 && final1.numberzhi<final2.numberzhi)
			{
				a[0] = a[0] + a[1] * 25;
				break;
			}
			else
			{
				a[0] = a[0] - a[1] * 25;
				break;
			}
	};
	case 4: { if (final2.number == 5)
	{
		a[0] = a[0] + a[1] * 25;
		break;
	}
			if (final2.number == 4 && final1.numberzhi >= final2.numberzhi)
			{
				a[0] = a[0] - a[1] * 20;
				break;
			}
			if (final2.number == 4 && final1.numberzhi<final2.numberzhi)
			{
				a[0] = a[0] + a[1] * 20;
				break;
			}
			else
			{
				a[0] = a[0] - a[1] * 20;
				break;
			}
	}
	case 3: {   if (final2.number == 5)
	{
		a[0] = a[0] + a[1] * 25;
		break;
	}
			if (final2.number == 4)
			{
				a[0] = a[0] + a[1] * 20;
				break;
			}
			if (final2.number == 3 && final1.numberzhi<final2.numberzhi)
			{
				a[0] = a[0] + a[1] * 15;
				break;
			}
			else
			{
				a[0] = a[0] - a[1] * 15;
				break;
			}
	};
	case -1: {
		if (final2.number == 5)
		{
			a[0] = a[0] + a[1] * 25;
			break;
		}
		if (final2.number == 4)
		{
			a[0] = a[0] + a[1] * 20;
			break;
		}
		if (final2.number == 3)
		{
			a[0] = a[0] + a[1] * 15;
			break;
		}
		if (final1.result>final2.result)//庄家牌大时
		{
			if (final1.result == 10)
			{
				a[0] = a[0] - a[1] * 3;
				break;
			}
			if (final1.result >= 7 && final1.result <= 9)
			{
				a[0] = a[0] - a[1] * 2;
				break;
			}
			if (final1.result<7)
			{
				a[0] = a[0] - a[1];
				break;
			}
		}
		else
			if (final1.result<final2.result)//玩家牌大时
			{
				if (final2.result == 10)
				{
					a[0] = a[0] + a[1] * 3;
					break;
				}
				if (final2.result >= 7 && final2.result <= 9)
				{
					a[0] = a[0] + a[1] * 2;
					break;
				}
				if (final2.result<7)
				{
					a[0] = a[0] + a[1];
					break;
				}
			}
			else
			{
				if (final1.result == 10 && final1.max >= final2.max)
				{
					a[0] = a[0] - a[1] * 3;
					break;
				}
				if (final1.result == 10 && final1.max<final2.max)
				{
					a[0] = a[0] + a[1] * 3;
					break;
				}
				if (final1.result >= 7 && final1.result <= 9 && final1.max >= final2.max)
				{
					a[0] = a[0] - a[1] * 2;
					break;
				}
				if (final1.result >= 7 && final1.result <= 9 && final1.max<final2.max)
				{
					a[0] = a[0] + a[1] * 2;
					break;
				}
				if (final1.result<7 && final1.max >= final2.max)
				{
					a[0] = a[0] - a[1];
					break;
				}
				if (final1.result<7 && final1.max<final2.max)
				{
					a[0] = a[0] + a[1];
					break;
				}
			}
	}
	}
	return a[0] - t;
}
void menu()
{
	printf("/t/t/t欢迎来到“欢乐斗牛”游戏/n");
	printf("请按数字键选择/n");
	printf("/t1:开始游戏/n");
	printf("/t2:游戏规则/n");
	printf("/t3:离开游戏/n");
}
/*建立游戏规则函数*/
void instruction()
{
	printf("/t斗牛也属于纸牌游戏，该游戏中游戏为庄家，你为玩家./n");
	printf("/t游戏开始时系统送你100游戏币，输完时游戏结束.");
	printf("/t规则简要如下:/n");
	printf("/t每人有五张牌，比较点数，点数大者胜。计算点数时10、J、Q、/n");
	printf("/tK为花牌，用非花牌计算点数，若五张牌中没有一张花牌，任意用/n");
	printf("/t其中三张凑成10的倍数，如果不能，则点数为零，如果能凑成，用/n");
	printf("/t另外两张之和除以十，余数为点数。若有花牌时，可以用其中两张/n");
	printf("/t或三张牌凑成10的倍数，如果能，结果为其余牌之和除以10的余数/n");
	printf("/t（余数为零点数为10）。不能时，点数为零。当点数相同时，以牌/n");
	printf("/t面值大者胜./n");
	printf("/t0-6点倍率为1，7-9点倍率为2，10点倍率为3/n");
	printf("/t三张相同面值的非花牌，倍率15，四张20/n");
	printf("/t三张相同面值的花牌，倍率20，四张25/n");
	printf("/t赌博有害家庭健康，该游戏仅供娱乐/n");
}
int main()
{
	FACE zong[52];//总共的48张纸牌
	PAIRESULT final1 = build(), final2 = build();//牌的结果
	FACE player1[5], player2[5];  //用于存储两个玩家的牌,player1是庄家，player2是玩家
	inition(zong);
	int flag, a[2] = { 100,0 }, count = 1, defen;
	char ch;
	/*以下是游戏菜单*/
	menu();
	scanf("%d", &flag);
	while (flag<1 || flag>3)
	{
		printf("数字输入错误，请重新输入/n");
		scanf("%d", flag);
	}
	while (flag != 1)
	{
		if (flag == 3)
			exit(0);
		else
			if (flag == 2)
			{
				instruction();
				menu();
				scanf("%d", &flag);
			}
	}
	if (flag == 1)
	{
		printf("/t/t现在开始游戏/n");
		printf("/t/t系统先送你100游戏币，当游戏币不大于零时游戏结束/n");
		while (1)
		{
			printf("/t/t/t/t第%d局/n", count);
			printf("请下注(1-10游戏币),目前你的游戏币为%d/n", a[0]);
			while (1)
			{
				scanf(" %d", &a[1]);
				if (a[1]>0 && a[1] <= 10)
					break;
				else
					printf("输入数据范围不对，请重新选择/n");
			}
			xipai(zong);  //洗牌
			fapai(zong, player1, player2);  //发牌
			paisort(player1);  output(5, player1, 1);  //庄家的牌，先排序在现实牌
			paisort(player2);   output(5, player2, 2);  //玩家的牌，先排序在显现牌
			final1 = jisuan(player1, final1);    //计算点数
			final2 = jisuan(player2, final2);   //计算点数
			defen = compare(final1, final2, a);
			if (final1.number >= 3 && final1.numberzhi >= 11)
				printf("/t庄家有%d张牌相同/n", (final1.number - 1));
			else
				if (final1.number >= 3 && final1.numberzhi<11)
					printf("/t庄家有%d张牌相同/n", final1.number);
				else
					printf("/t庄家牌的点数: %d/n", final1.result);

			if (final2.number >= 3 && final2.numberzhi >= 11)
				printf("恭喜你，你有%d张牌相同/n", (final2.number - 1));
			else
				if (final2.number >= 3 && final2.numberzhi<11)
					printf("恭喜你，你有%d张牌相同/n", final2.number);
				else
					if (final2.result == 10)
						printf("/t/t你牛了，牛气冲天/n");
					else
						if (final2.result >= 7 && final2.result <= 9)
							printf("/t/t你进套了，点数:%d/n", final2.result);
						else
							printf("/t/t你的点数：%d/n", final2.result);
			if (defen>0)
				printf("/t本局你胜，得分:%d/n", defen);
			else
				if (defen == 0)
					printf("/t本局平局/n");
				else
					printf("/t本局你输了，再接再厉,得分:%d/n", defen);
			printf("/t/t/t/t总游戏币：%d/n", a[0]);
			if (a[0] <= 0)
				break;
			else
			{
				printf("/t/t继续C(continue)/t/t退出游戏E(end)/n");
				scanf(" %c", &ch);
				if (ch == 'e')
					break;
				else
				{
					count++;
					final1 = final2 = build();
				}

			}
		}
	}
	if (a[0] == 100)
		printf("/t游戏结果平局/n");
	else
		if (a[0]>100)
			printf("/t恭喜你，你赢的游戏币%d/n", a[0] - 100);
		else
			printf("/t再接再厉,你输了游戏币%d/n", 100 - a[0]);
	return 0;
}

