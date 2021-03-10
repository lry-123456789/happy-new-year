#define _CRT_SECURE_NO_WARNINGS
#pragma once
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
#include<corecrt.h>

#pragma once

// 包括 SDKDDKVer.h 将定义可用的最高版本的 Windows 平台。

// 如果要为以前的 Windows 平台生成应用程序，请包括 WinSDKVer.h，并将
// 将 _WIN32_WINNT 宏设置为要支持的平台，然后再包括 SDKDDKVer.h。

#include <SDKDDKVer.h>
//此处为#include<targetver.h>
#include <stdio.h>
#include <tchar.h>
//此处为#include<stdafx.h>


// TODO:  在此处引用程序需要的其他头文件
#include<atlimage.h> 
#include<stdio.h>
#include<graphics.h>   //图形界面库头文件
#include<math.h>       //计算圆形的轨迹坐标
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
//#include 包含头文件
//#pragma comment（lib."文件名称"）  包含库文件

constexpr auto WND_WIDTH = 1000;
constexpr auto WND_HEIGHT = 600;
constexpr auto PI = 3.141592653589793238;
constexpr auto NUM = 14;

/***********结构****************/
struct JET  //烟花弹
{
	int x, y;      //发射点坐标
	int hx, hy;    //最高点坐标  爆炸坐标
	int height;    //高度  最高点y 发射点y的差值
	bool isshoot;  //是否发射状态

	DWORD t1, t2, dt;   //保存时间  时间可以用来描述发射速度
	IMAGE img[2];       //保存烟花一明一暗的图片
	byte n : 1;         //保存烟花弹的明暗状态  位段
	//字节为单位 int 4 char 1 n一个位 0-1
}jet[NUM];    //结构体数组14  img这个数组

struct FIRE
{
	int r;
	int max_r;
	int x, y;
	int cen_x, cen_y;
	int width, height;
	int xy[240][240];
	bool show;
	bool draw;
	DWORD t1, t2, dt;
}fire[NUM];
void database1(int a);
void database2(int a);
void database3(int i);
void database4(int a);
void database5(int a);
void welcome1(int b);
void welcome();
void init(int i);
void loadimages();
void choice(DWORD& t1);
void shoot();
void Show(DWORD* pMem);
void delay(int a);
void readme(int a);
void info(int a);
void scan_file(int a);

int main(int agrv, char* agrc[])
{
	readme(1);
	int ii;
	FILE* f1 = fopen("readme.txt", "a");
	if (f1 != NULL)
	{
		fflush(f1);
		//fclose(f1);
		//free(f1);
		//f1 = NULL;
	}
	//res 1.wav
	PlaySound(L"sound.dll", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
	//mp3播放
	//mciSendString(L"open 1.mp3 alias bkmusic", NULL, 0, NULL);
	//mciSendString(L"play bkmusic repeat", NULL, 0, NULL);
	//准备加载1.gif
			//?????????
			//还未找到加载1.gif的方法
			//?????????
	//播放1.gif结束
	welcome1(1);			 //测试时使用
	scan_file(1);          //测试时使用，
	int i;
	int j;
	j = 0;
	for (i = 0; i < 37; i++)
	{
			database1(i);			//测试时使用
			Sleep(1000);
			system("cls");
	}
	initgraph(WND_WIDTH, WND_HEIGHT);       //init初始化  graph图形界面 窗口
	srand((unsigned int)time(NULL));
	DWORD t1 = timeGetTime();
	DWORD* pMem = GetImageBuffer();
	//第一个界面
	welcome();
	//database4(1);
	//初始化
	for (int i = 0; i < NUM; i++)
	{
		init(i);
	}

	loadimages();
	BeginBatchDraw();
	while (!_kbhit())
	{
		Sleep(10);
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//fprintf(f1, "%d\n", i);
				int px1 = rand() % 1000;
				int py1 = rand() % 600;
				if (py1 < 599)
				{
					pMem[py1 * 1000 + px1] = pMem[py1 * 1000 + px1 + 1] = BLACK;
				}
				//fprintf(f1, "x=%d", px1);
				//fprintf(f1, "y=%d", py1);
			}
		}
		choice(t1);
		shoot();
		Show(pMem);
		EndBatchDraw();
	}
	return 0;
}

void database1(int b)
{
	FILE* f1 = fopen("readme.txt", "a");
	switch (b)
	{
		case 1:
		{
			printf("春");
			fprintf(f1, "春\n");
		}
		break;
		case 2:
		{
			printf("节");
			fprintf(f1, "节\n");
		}
		break;
		case 3:
		{
			printf("快");
			fprintf(f1, "快\n");
		}
		break;
		case 4:
		{
			printf("乐");
			fprintf(f1, "乐\n");
		}
		break;
		case 5:
		{
			printf("H");
			fprintf(f1, "H\n");
		}
		break;
		case 6:
		{
			printf("a");
			fprintf(f1, "a\n");
		}
		break;
		case 7:
		{
			printf("p");
			fprintf(f1, "p\n");
		}
		break;
		case 8:
		{
			printf("p");
			fprintf(f1, "p\n");
		}
		break;
		case 9:
		{
			printf("y");
			fprintf(f1, "y\n");
		}
		break;
		case 10:
		{
			printf(" ");
			fprintf(f1, " \n");
		}
		break;
		case 11:
		{
			printf("S");
			fprintf(f1, "S\n");
		}
		break;
		case 12:
		{
			printf("p");
			fprintf(f1, "p\n");
		}
		break;
		case 13:
		{
			printf("r");
			fprintf(f1, "r\n");
		}
		break;
		case 14:
		{
			printf("i");
			fprintf(f1, "i\n");
		}
		break;
		case 15:
		{
			printf("n");
			fprintf(f1, "n\n");
		}
		break;
		case 16:
		{
			printf("g");
			fprintf(f1, "g\n");
		}
		break;
		case 17:
		{
			printf(" ");
			fprintf(f1, " \n");
		}
		break;
		case 18:
		{
			printf("F");
			fprintf(f1, "F\n");
		}
		break;
		case 19:
		{
			printf("e");
			fprintf(f1, "e\n");
		}
		break;
		case 20:
		{
			printf("s");
			fprintf(f1, "s\n");
		}
		break;
		case 21:
		{
			printf("t");
			fprintf(f1, "t\n");
		}
		break;
		case 22:
		{
			printf("i");
			fprintf(f1, "i\n");
		}
		break;
		case 23:
		{
			printf("v");
			fprintf(f1, "v\n");
		}
		break;
		case 24:
		{
			printf("a");
			fprintf(f1, "a\n");
		}
		break;
		case 25:
		{
			printf("l");
			fprintf(f1, "l\n");
		}
		break;
		case 26:
		{
			printf("春节快乐");
			fprintf(f1, "春节快乐\n");
		}
		break;
		case 27:
		{
			printf("Happy");
			fprintf(f1, "Happy\n");
		}
		break;
		case 28:
		{
			printf("Spring");
			fprintf(f1, "Spring\n");
		}
		break;
		case 29:
		{
			printf("Festival");
			fprintf(f1, "Festival\n");
		}
		break;
		case 30:
		{
			printf("春节快乐\n");
			printf("Happy Spring Festival\n");
			fprintf(f1, "春节快乐\n");
			fprintf(f1, "Happy Spring Festival\n");
		}
		break;
		case 31:
		{
			database2(31);
			fprintf(f1,"                      ■■                          \n");
			fprintf(f1,"                      ■■                          \n");
			fprintf(f1,"                      ■■                          \n");
			fprintf(f1,"    ■■■■■■■■■■■■■■■■■■■■■      \n");
			fprintf(f1,"    ■■■■■■■■■■■■■■■■■■■■■      \n");
			fprintf(f1,"                    ■■                            \n");
			fprintf(f1,"                    ■■                            \n");
			fprintf(f1,"      ■■■■■■■■■■■■■■■■■■■        \n");
			fprintf(f1,"      ■■■■■■■■■■■■■■■■■■■        \n");
			fprintf(f1,"                  ■■                              \n");
			fprintf(f1,"                ■■■                              \n");
			fprintf(f1,"  ■■■■■■■■■■■■■■■■■■■■■■■    \n");
			fprintf(f1,"  ■■■■■■■■■■■■■■■■■■■■■■■    \n");
			fprintf(f1,"            ■■■            ■■■                \n");
			fprintf(f1,"          ■■■                ■■■              \n");
			fprintf(f1,"      ■■■■                  ■■■■            \n");
			fprintf(f1,"    ■■■■■■■■■■■■■■■■■■■■        \n");
			fprintf(f1,"■■■■  ■■                    ■■■■■■■    \n");
			fprintf(f1,"■■■    ■■                    ■■    ■■■    \n");
			fprintf(f1,"  ■      ■■■■■■■■■■■■■■              \n");
			fprintf(f1,"          ■■■■■■■■■■■■■■              \n");
			fprintf(f1,"          ■■                    ■■              \n");
			fprintf(f1,"          ■■                    ■■              \n");
			fprintf(f1,"          ■■                    ■■              \n");
			fprintf(f1,"          ■■■■■■■■■■■■■■              \n");
			fprintf(f1,"          ■■■■■■■■■■■■■■              \n");
		}
		break;
		case 32:
		{
			database2(32);
			fprintf(f1,"                ■■          ■■                \n");
			fprintf(f1,"                ■■          ■■                \n");
			fprintf(f1,"                ■■          ■■                \n");
			fprintf(f1,"■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			fprintf(f1,"■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			fprintf(f1,"                ■■          ■■                \n");
			fprintf(f1,"                ■■          ■■                \n");
			fprintf(f1,"                ■■          ■■                \n");
			fprintf(f1,"                ■■          ■■                \n");
			fprintf(f1,"                                                  \n");
			fprintf(f1,"  ■■■■■■■■■■■■■■■■■■■■■■    \n");
			fprintf(f1,"  ■■■■■■■■■■■■■■■■■■■■■■    \n");
			fprintf(f1,"                  ■■                    ■■    \n");
			fprintf(f1,"                  ■■                    ■■    \n");
			fprintf(f1,"                  ■■                    ■■    \n");
			fprintf(f1,"                  ■■                    ■■    \n");
			fprintf(f1,"                  ■■                    ■■    \n");
			fprintf(f1,"                  ■■                    ■■    \n");
			fprintf(f1,"                  ■■                    ■■    \n");
			fprintf(f1,"                  ■■                ■■■■    \n");
			fprintf(f1,"                  ■■              ■■■■      \n");
			fprintf(f1,"                  ■■              ■■■        \n");
			fprintf(f1,"                  ■■                            \n");
			fprintf(f1,"                  ■■                            \n");
			fprintf(f1,"                  ■■                            \n");
			fprintf(f1,"                  ■■                            \n");
		}
		break;
		case 33:
		{
			database2(33);
			fprintf(f1,"        ■■                  ■■                \n");
			fprintf(f1,"        ■■                  ■■                \n");
			fprintf(f1,"        ■■                  ■■                \n");
			fprintf(f1,"        ■■                  ■■                \n");
			fprintf(f1,"        ■■          ■■■■■■■■■■■      \n");
			fprintf(f1,"        ■■          ■■■■■■■■■■■■    \n");
			fprintf(f1,"  ■■  ■■  ■■            ■■      ■■      \n");
			fprintf(f1,"  ■■  ■■    ■■          ■■      ■■      \n");
			fprintf(f1,"■■    ■■    ■■          ■■      ■■      \n");
			fprintf(f1,"■■    ■■    ■■■        ■■      ■■      \n");
			fprintf(f1,"■■    ■■                  ■■      ■■      \n");
			fprintf(f1,"■■    ■■                  ■■      ■■      \n");
			fprintf(f1,"■■    ■■                  ■■      ■■■    \n");
			fprintf(f1,"        ■■      ■■■■■■■■■■■■■■■■\n");
			fprintf(f1,"        ■■      ■■■■■■■■■        ■■■\n");
			fprintf(f1,"        ■■                  ■■■              \n");
			fprintf(f1,"        ■■                ■■■■              \n");
			fprintf(f1,"        ■■                ■■  ■■            \n");
			fprintf(f1,"        ■■              ■■    ■■            \n");
			fprintf(f1,"        ■■              ■■      ■■          \n");
			fprintf(f1,"        ■■            ■■        ■■■        \n");
			fprintf(f1,"        ■■          ■■■          ■■■      \n");
			fprintf(f1,"        ■■        ■■■              ■■■■  \n");
			fprintf(f1,"        ■■      ■■■■                ■■■■\n");
			fprintf(f1,"        ■■      ■■■                    ■■  \n");
			fprintf(f1,"        ■■        ■                            \n");
		}
		break;
		case 34:
		{
			database2(34);
			fprintf(f1,"                                    ■■          \n");
			fprintf(f1,"        ■■  ■■■■■■■■■■■■■■        \n");
			fprintf(f1,"      ■■■■■■■■■■■■■■■■■■■      \n");
			fprintf(f1,"      ■■■                                      \n");
			fprintf(f1,"      ■■                                        \n");
			fprintf(f1,"      ■■              ■■                      \n");
			fprintf(f1,"      ■■              ■■                      \n");
			fprintf(f1,"      ■■              ■■                      \n");
			fprintf(f1,"      ■■              ■■                      \n");
			fprintf(f1,"    ■■■              ■■                      \n");
			fprintf(f1,"    ■■■              ■■                      \n");
			fprintf(f1,"    ■■■■■■■■■■■■■■■■■■■■■    \n");
			fprintf(f1,"    ■■■■            ■■■              ■    \n");
			fprintf(f1,"                        ■■                      \n");
			fprintf(f1,"                        ■■                      \n");
			fprintf(f1,"            ■          ■■                      \n");
			fprintf(f1,"          ■■■■      ■■      ■■■          \n");
			fprintf(f1,"          ■■■        ■■      ■■■■        \n");
			fprintf(f1,"        ■■■          ■■        ■■■■      \n");
			fprintf(f1,"      ■■■            ■■          ■■■■    \n");
			fprintf(f1,"    ■■■              ■■            ■■■■  \n");
			fprintf(f1,"  ■■■                ■■                      \n");
			fprintf(f1,"  ■■■                ■■                      \n");
			fprintf(f1,"                  ■■■■■                      \n");
			fprintf(f1,"                    ■■■■                      \n");
			fprintf(f1,"                    ■■                          \n");
		}
		break;
		case 35:
		{
			database2(35);
			fprintf(f1,"happy spring festival!");
		}
		break;
	}
	fclose(f1);
}

void database2(int a)
{
	switch (a)
	{
		case 31:
		{
		  //printf("■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("                      ■■                          \n");
			printf("                      ■■                          \n");
			printf("                      ■■                          \n");
			printf("    ■■■■■■■■■■■■■■■■■■■■■      \n");
			printf("    ■■■■■■■■■■■■■■■■■■■■■      \n");
			printf("                    ■■                            \n");
			printf("                    ■■                            \n");
			printf("      ■■■■■■■■■■■■■■■■■■■        \n");
			printf("      ■■■■■■■■■■■■■■■■■■■        \n");
			printf("                  ■■                              \n");
			printf("                ■■■                              \n");
			printf("  ■■■■■■■■■■■■■■■■■■■■■■■    \n");
			printf("  ■■■■■■■■■■■■■■■■■■■■■■■    \n");
			printf("            ■■■            ■■■                \n");
			printf("          ■■■                ■■■              \n");
			printf("      ■■■■                  ■■■■            \n");
			printf("    ■■■■■■■■■■■■■■■■■■■■        \n");
			printf("■■■■  ■■                    ■■■■■■■    \n");
			printf("■■■    ■■                    ■■    ■■■    \n");
			printf("  ■      ■■■■■■■■■■■■■■              \n");
			printf("          ■■■■■■■■■■■■■■              \n");
			printf("          ■■                    ■■              \n");
			printf("          ■■                    ■■              \n");
			printf("          ■■                    ■■              \n");
			printf("          ■■■■■■■■■■■■■■              \n");
			printf("          ■■■■■■■■■■■■■■              \n");
		}
		break;
		case 32:
		{
		  //printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("                ■■          ■■                \n");
			printf("                ■■          ■■                \n");
			printf("                ■■          ■■                \n");
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("                ■■          ■■                \n");
			printf("                ■■          ■■                \n");
			printf("                ■■          ■■                \n");
			printf("                ■■          ■■                \n");
			printf("                                                  \n");
			printf("  ■■■■■■■■■■■■■■■■■■■■■■    \n");
			printf("  ■■■■■■■■■■■■■■■■■■■■■■    \n");
			printf("                  ■■                    ■■    \n");
			printf("                  ■■                    ■■    \n");
			printf("                  ■■                    ■■    \n");
			printf("                  ■■                    ■■    \n");
			printf("                  ■■                    ■■    \n");
			printf("                  ■■                    ■■    \n");
			printf("                  ■■                    ■■    \n");
			printf("                  ■■                ■■■■    \n");
			printf("                  ■■              ■■■■      \n");
			printf("                  ■■              ■■■        \n");
			printf("                  ■■                            \n");
			printf("                  ■■                            \n");
			printf("                  ■■                            \n");
			printf("                  ■■                            \n");
		}
		break;
		case 33:
		{
			//printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("        ■■                  ■■                \n");
			printf("        ■■                  ■■                \n");
			printf("        ■■                  ■■                \n");
			printf("        ■■                  ■■                \n");
			printf("        ■■          ■■■■■■■■■■■      \n");
			printf("        ■■          ■■■■■■■■■■■■    \n");
			printf("  ■■  ■■  ■■            ■■      ■■      \n");
			printf("  ■■  ■■    ■■          ■■      ■■      \n");
			printf("■■    ■■    ■■          ■■      ■■      \n");
			printf("■■    ■■    ■■■        ■■      ■■      \n");
			printf("■■    ■■                  ■■      ■■      \n");
			printf("■■    ■■                  ■■      ■■      \n");
			printf("■■    ■■                  ■■      ■■■    \n");
			printf("        ■■      ■■■■■■■■■■■■■■■■\n");
			printf("        ■■      ■■■■■■■■■        ■■■\n");
			printf("        ■■                  ■■■              \n");
			printf("        ■■                ■■■■              \n");
			printf("        ■■                ■■  ■■            \n");
			printf("        ■■              ■■    ■■            \n");
			printf("        ■■              ■■      ■■          \n");
			printf("        ■■            ■■        ■■■        \n");
			printf("        ■■          ■■■          ■■■      \n");
			printf("        ■■        ■■■              ■■■■  \n");
			printf("        ■■      ■■■■                ■■■■\n");
			printf("        ■■      ■■■                    ■■  \n");
			printf("        ■■        ■                            \n");
		}
		break;
		case 34:
		{
			//不用                                             不用 
		  //printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("                                    ■■          \n");
			printf("        ■■  ■■■■■■■■■■■■■■        \n");
			printf("      ■■■■■■■■■■■■■■■■■■■      \n");
			printf("      ■■■                                      \n");
			printf("      ■■                                        \n");
			printf("      ■■              ■■                      \n");
			printf("      ■■              ■■                      \n");
			printf("      ■■              ■■                      \n");
			printf("      ■■              ■■                      \n");
			printf("    ■■■              ■■                      \n");
			printf("    ■■■              ■■                      \n");
			printf("    ■■■■■■■■■■■■■■■■■■■■■    \n");
			printf("    ■■■■            ■■■              ■    \n");
			printf("                        ■■                      \n");
			printf("                        ■■                      \n");
			printf("            ■          ■■                      \n");
			printf("          ■■■■      ■■      ■■■          \n");
			printf("          ■■■        ■■      ■■■■        \n");
			printf("        ■■■          ■■        ■■■■      \n");
			printf("      ■■■            ■■          ■■■■    \n");
			printf("    ■■■              ■■            ■■■■  \n");
			printf("  ■■■                ■■                      \n");
			printf("  ■■■                ■■                      \n");
			printf("                  ■■■■■                      \n");
			printf("                    ■■■■                      \n");
			printf("                    ■■                          \n");
		}
		break;
		case 35:
		{
			printf("happy spring festival!");
		}
		break;
		case 36:
		{
			printf("凡是过往，皆为序章；长路浩荡，未来可期");
		}
		break;
	}
}

void database3(int i)
{
	FILE* f100 = fopen("readme.txt", "a");
	if (i == 1)
	{
		printf("正在加载sound.dll");
		fprintf(f100, "正在加载sound.dll");
	}
	if (i == 2)
	{
		printf("正在加载ntdll.dll");
		fprintf(f100, "正在加载ntdll.dll");
	}
	if (i == 3)
	{
		printf("正在加载kernel32.dll");
		fprintf(f100, "正在加载kernel32.dll");
	}
	if (i == 4)
	{
		printf("正在加载Kernel32.dll");
		fprintf(f100, "正在加载Kernel32.dll");
	}
	if (i == 5)
	{
		printf("正在加载user32.dll");
		fprintf(f100, "正在加载user32.dll");
	}
	if (i == 6)
	{
		printf("正在加载win32u.dll");
		fprintf(f100, "正在加载win32u.dll");
	}
	if (i == 7)
	{
		printf("正在加载gdi32.dll");
		fprintf(f100, "正在加载gdi32.dll");
	}
	if (i == 8)
	{
		printf("正在加载gdi32full.dll");
		fprintf(f100, "正在加载gdi32full.dll");
	}
	if (i == 9)
	{
		printf("正在加载msvcp_win.dll");
		fprintf(f100, "正在加载msvcp_win.dll");
	}
	if (i == 10)
	{
		printf("正在加载ucrtbase.dll");
		fprintf(f100, "正在加载ucrtbase.dll");
	}
	if (i == 11)
	{
		printf("正在加载shell32.dll");
		fprintf(f100, "正在加载shell32.dll");
	}
	if (i == 12)
	{
		printf("正在加载ole32.dll");
		fprintf(f100, "正在加载ole32.dll");
	}
	if (i == 13)
	{
		printf("正在加载rpcrt4.dll");
		fprintf(f100, "正在加载rpcrt4.dll");
	}
	if (i == 14)
	{
		printf("正在加载combase.dll");
		fprintf(f100, "正在加载combase.dll");
	}
	if (i == 15)
	{
		printf("正在加载GpiPlus.dll");
		fprintf(f100, "正在加载GpiPlus.dll");
	}
	if (i == 16)
	{
		printf("正在加载msvcrt.dll");
		fprintf(f100, "正在加载msvcrt.dll");
	}
	if (i == 17)
	{
		printf("正在加载winmm.dll");
		fprintf(f100, "正在加载winmm.dll");
	}
	if (i == 18)
	{
		printf("正在加载vcruntime140d.dll");
		fprintf(f100, "正在加载vcruntime140d.dll");
	}
	if (i == 19)
	{
		printf("正在加载ucrtbased.dll");
		fprintf(f100, "正在加载ucrtbased.dll");
	}
	if (i == 20)
	{
		printf("正在加载imm32.dll");
		fprintf(f100, "正在加载imm32.dll");
	}
	if (i == 21)
	{
		printf("正在加载kernel.appcore.dll");
		fprintf(f100, "正在加载kernel.appercore.dll");
	}
	if (i == 22)
	{
		printf("正在加载bcryptprimitives.dll");
		fprintf(f100, "正在加载bcryptprimitives.dll");
	}
	if (i == 23)
	{
		printf("正在加载uxtheme.dll");
		fprintf(f100, "正在加载uxtheme.dll");
	}
	if (i == 24)
	{
		printf("正在加载msctf.dll");
		fprintf(f100, "正在加载msctf.dll");
	}
	if (i == 25)
	{
		printf("正在加载oleaaut32.dll");
		fprintf(f100, "正在加载oleaaut32.dll");
	}
	if (i == 26)
	{
		printf("正在加载sechost.dll");
		fprintf(f100, "正在加载sechost.dll");
	}
	if (i == 27)
	{
		printf("正在加载winmmbase.dll");
		fprintf(f100, "正在加载winmmbase.dll");
	}
	if (i == 28)
	{
		printf("正在加载MMDevAPI.dll");
		fprintf(f100, "正在加载MMDevAPI.dll");
	}
	if (i == 29)
	{
		printf("正在加载SHCore.dll");
		fprintf(f100, "正在加载SHCore.dll");
	}
	if (i == 30)
	{
		printf("正在加载devobj.dll");
		fprintf(f100, "正在加载devobj.dll");
	}
	if (i == 31)
	{
		printf("正在加载cfgmgr32.dll");
		fprintf(f100, "正在加载vcfgmgr32.dll");
	}
	if (i == 32)
	{
		printf("正在加载wdmaud.drv");
		fprintf(f100, "正在加载wdmaud.drv");
	}
	if (i == 33)
	{
		printf("正在加载ksuser.dll");
		fprintf(f100, "正在加载ksuser.dll");
	}
	if (i == 34)
	{
		printf("正在加载avrt.dll");
		fprintf(f100, "正在加载avrt.dll");
	}
	if (i == 35)
	{
		printf("正在加载AudioSes.dll");
		fprintf(f100, "正在加载AudioSes.dll");
	}
	if (i == 36)
	{
		printf("正在加载advapi32.dll");
		fprintf(f100, "正在加载advapi32.dll");
	}
	if (i == 37)
	{
		printf("正在加载poweprof.dll");
		fprintf(f100, "正在加载poweprof.dll");
	}
	if (i == 38)
	{
		printf("正在加载umpdc.dll");
		fprintf(f100, "正在加载umpdc.dll");
	}
	if (i == 39)
	{
		printf("正在加载msacm32.drv");
		fprintf(f100, "正在加载msacm32.drv");
	}
	if (i == 40)
	{
		printf("正在加载msacm32.dll");
		fprintf(f100, "正在加载msacm32.dll");
	}
	if (i == 41)
	{
		printf("正在加载midimap.dll");
		fprintf(f100, "正在加载midimap.dll");
	}
	if (i == 42)
	{
		printf("正在加载clbcatq.dll");
		fprintf(f100, "正在加载clbcaq.dll");
	}
	if (i == 43)
	{
		printf("正在加载TextInputFramework.dll");
		fprintf(f100, "正在加载TextInputFramework.dll");
	}
	if (i == 44)
	{
		printf("正在加载CoreMessage.dll");
		fprintf(f100, "正在加载CoreMessage.dll");
	}
	if (i == 45)
	{
		printf("正在加载CoreUIComponents.dll");
		fprintf(f100, "正在加载CoreComponments.dll");
	}
	if (i == 46)
	{
		printf("正在加载ws2_32.dll");
		fprintf(f100, "正在加载ws2_32.dll");
	}
	if (i == 47)
	{
		printf("正在加载ntmarta.dll");
		fprintf(f100, "正在加载ntmarta.dll");
	}
	if (i == 48)
	{
		printf("正在加载WinTypes.dll");
		fprintf(f100, "正在加载WinTypes.dll");
	}
	if (i == 49)
	{
		printf("正在加载TextShaping.dll");
		fprintf(f100, "正在加载TextShaping.dll");
	}
	if (i == 50)
	{
		printf("正在加载WindowsCodecs.dll");
		fprintf(f100, "正在加载WindowsCodecs.dll");
	}
	if (i == 51)
	{
		printf("正在加载bcrypt.dll");
		fprintf(f100, "正在加载bcrypt.dll");
	}
	else if(i>51&&i<80)
	{
		printf("正在校验文件......");
		fprintf(f100, "正在校验文件......");
	}
	if (i >= 80)
	{
		printf("正在检查文件是否存在错误：进度：%d%c", (i - 79) * 100 / 20, '%');
		fprintf(f100, "正在检查文件是否存在错误：进度%d%c", (i - 79) * 100 / 20, '%');
	}
	if (f100 != NULL)
	{
		//free(f100);
		//f100 = NULL;
		fflush(f100);
	}
}



void welcome1(int a)
{
	int i;
	int j;
	FILE* f1 = fopen("readme.txt", "a");
	for (i = 0; i < 100; i++)
	{
		database3(i);
		for (j = 0; j < 20; j++)
		{
			printf("\n");
			fprintf(f1, "\n");
		}
		printf("                                        this program is powered by lry\n");
		printf("                                         all rights reserved 2020~2021\n");
		printf("                                          begin to start this project\n");
		printf("                                              rate of progress:%d%c\n", i, '%');
		printf("                                                 powered by --%c%c%c%c%c%c",0xc1,0xf5,0xc8,0xca,0xd3,0xee);
		fprintf(f1,"                                        this program is powered by lry\n");
		fprintf(f1, "                                         all rights reserved 2020~2021\n");
		fprintf(f1, "                                          begin to start this project\n");
		fprintf(f1, "                                              rate of progress:%d%c\n", i, '%');
		fprintf(f1, "                                                 powered by --%c%c%c%c%c%c", 0xc1, 0xf5, 0xc8, 0xca, 0xd3, 0xee);
		system("cls");
	}
}
void welcome()
{
	settextcolor(YELLOW);

	for (int i = 0; i < 50; i++)
	{
		//圆心（500,300） 半径150  60个均匀点的x,y
		int x = 500 + int(150 * sin(PI * 2 * i / 60));
		int y = 300 + int(150 * cos(PI * 2 * i / 60));
		cleardevice();
		settextstyle(i, 0, L"微软雅黑");
		outtextxy(x - 100, y - 150, L"凡是过往");     //在指定的位置去输出字符
		outtextxy(x, y - 100, L"皆为序章");
		Sleep(25);
	}

	//_getch();   //接收字符 不回显 直接接收
	Sleep(2000);
	cleardevice();
	settextstyle(25, 0, L"宋体");
	outtextxy(400, 150, L"长路浩荡");
	outtextxy(400, 200, L"未来可期");
	//outtextxy(400, 250, L"长路浩荡");
	//outtextxy(400, 300, L"未来可期");
	//outtextxy(400, 350, L"5");
	//outtextxy(560, 400, L"---6");

	Sleep(3000);
	//_getch();
}

void init(int i)
{
	int r[14] = { 120,120,155,123,130,147,138,138,130,135,140,132,155,160 };
	int x[14] = { 120,120,110,117,110,93,102,102,110,105,100,108,110,132 };
	int y[14] = { 120,120,85,118,120,105,103,110,110,120,1201,04,85,145 };

	fire[i].x = 0;
	fire[i].y = 0;
	fire[i].width = 240;
	fire[i].height = 240;
	fire[i].max_r = r[i];
	fire[i].cen_x = x[i];
	fire[i].cen_y = y[i];
	fire[i].show = false;
	fire[i].dt = 5;
	fire[i].t1 = timeGetTime();
	fire[i].r = 0;


	//初始化  烟花弹
	jet[i].x = 0;
	jet[i].y = 0;
	jet[i].hx = 0;
	jet[i].hy = 0;
	jet[i].height = 0;
	jet[i].t1 = timeGetTime();   //获取系统时间
	jet[i].dt = rand() % 10;   //0-9的随机时间
	jet[i].n = 0;
	jet[i].isshoot = false;
}

void loadimages()
{
	IMAGE fm, gm;
	loadimage(&fm, L"flower.dll", 3120, 240);
	for (int i = 0; i < NUM; i++)
	{
		SetWorkingImage(&fm);
		getimage(&gm, i * 240, 0, 240, 240);
		SetWorkingImage(&gm);

		for (int a = 0; a < 240; a++)
		{
			for (int b = 0; b < 240; b++)
			{
				fire[i].xy[a][b] = getpixel(a, b);
			}
		}
	}

	IMAGE jetimg;
	loadimage(&jetimg, L"shoot.dll", 200, 50);

	//set设置 working正在工作的 image图片
	SetWorkingImage(&jetimg);

	for (int i = 0; i < NUM; i++)
	{
		int n = rand() % 5;   //0-4的随机数

		getimage(&jet[i].img[0], n * 20, 0, 20, 50);
		getimage(&jet[i].img[1], (n + 5) * 20, 0, 20, 50);
	}
	SetWorkingImage(NULL);
}

void choice(DWORD& t1)
{
	DWORD t2 = timeGetTime();
	if (t2 - t1 >= 2)   //2ms产生一个烟花弹
	{
		int n = rand() % 200;     //0-199
		if (n < NUM && jet[n].isshoot == false && fire[n].show == false)
		{
			//重置烟花弹
			jet[n].x = rand() % (WND_WIDTH - 20);
			jet[n].y = rand() % 100 + 400;   //450-549
			jet[n].hx = jet[n].x;
			jet[n].hy = rand() % 400;        //0-399
			jet[n].height = jet[n].y - jet[n].hy;
			jet[n].isshoot = true;
			//n
			putimage(jet[n].x, jet[n].y, &jet[n].img[jet[n].n]);
		}
		t1 = t2;
	}
}

void shoot()
{
	for (int i = 0; i < NUM; i++)
	{
		jet[i].t2 = timeGetTime();
		if (jet[i].t2 - jet[i].t1 > jet[i].dt && jet[i].isshoot == true)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n]);

			if (jet[i].hy < jet[i].y)
			{
				jet[i].n++;  //0-1  明暗交替
				jet[i].y -= 5;
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n]);

			if (jet[i].y <= jet[i].hy)
			{
				fire[i].y = jet[i].hy;
				fire[i].x = jet[i].hx;
				fire[i].show = true;
				jet[i].isshoot = false;
			}
			jet[i].t1 = jet[i].t2;
		}
	}
}

void Show(DWORD* pMem)
{
	int drt[16] = { 5,5,5,5,5,6,25,25,25,25,25,55,55,55,55,55 };    //dt

	for (int i = 0; i < NUM; i++)
	{
		fire[i].t2 = timeGetTime();

		if (fire[i].t2 - fire[i].t1 > fire[i].dt && fire[i].show == true)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;
				fire[i].dt = drt[fire[i].r / 10];
				fire[i].draw = true;
			}

			if (fire[i].r >= fire[i].max_r - 1)
			{
				fire[i].draw = false;
				init(i);
			}
			fire[i].t1 = fire[i].t2;
		}

		if (fire[i].draw)
		{
			for (double a = 0; a <= 6.28; a += 0.01)
			{
				int x1 = (int)(fire[i].cen_x + fire[i].r * cos(a));
				int y1 = (int)(fire[i].cen_y + fire[i].r * sin(a));

				if (x1 > 0 && x1 < fire[i].width && y1>0 && y1 < fire[i].height)
				{
					int b = fire[i].xy[x1][y1] & 0xff;
					int g = (fire[i].xy[x1][y1] >> 8) & 0xff;
					int r = (fire[i].xy[x1][y1] >> 16);
					int xx = (int)(fire[i].x + fire[i].r * cos(a));
					int yy = (int)(fire[i].y + fire[i].r * sin(a));

					if (r > 0x20 && g > 0x20 && b > 0x20 && xx > 0 && xx < 1000 && yy < 600 && yy>0)
					{
						pMem[yy * 1000 + xx] = BGR(fire[i].xy[x1][y1]);
					}
				}
			}
			fire[i].draw = true;
		}
	}

}

void delay(int a)
{
	while (a)
	{
		a--;
	}
}

void readme(int a)				//由于技术原因，暂时不会启用这一段代码
{
	int i;
	for (i = 10;i > 0;i--)
	{
		info(i);
	}
	delay(5000);
	FILE* fp=fopen("readme.txt","a");
	FILE* fp1=fopen("readme.txt","a");
	char data;
	printf("this line of code is for text,这可能需要一段时间");
	Sleep(1000);
	if (fp == NULL)
	{
		FILE* fp2 = fopen("readme.txt", "a");
		fprintf(fp2, "\n");
		printf("there are no such files,creating...");
		Sleep(5000);
		system("cls");
		fprintf(fp2, "运行本程序需要以下的几个文件\n");
		fprintf(fp2, "1.sound.dll（如果该文件缺失，将无法播放背景音乐）\n");
		fprintf(fp2, "2.shoot.dll和flower.dll（如果这两个文件的任意一个缺失，将无法读取信息，使程序运行异常）");
		fprintf(fp2, "3.系统必要组件：\n");
		fprintf(fp2, "ntd.dll\nkernel32.dll\nKernelbase.dll\nuser32.dll\nwin32u.dll\ngdi32.dll\n");
		fprintf(fp2, "gdi32full.dll\nmsvcp_win.dll\nucrtbase.dll\nshell32.dll\nole32.dll\nrpcrt4.dll\n");
		fprintf(fp2, "combase.dll\nGdiPlus.dll\nmsvcrt.dll\nwinmm.dll\nvcruntime140d.dll\nucrtbased.dll\n");
		fprintf(fp2, "imm32,dll\nkernel.appcore.dll\nbcryptprimitives.dll\nuxtheme.dll\nmsctf.dll\n");
		fprintf(fp2, "oleaut32.dll\nsechost.dll\nwinmmbase.dll\nMMDevAPI.dll\nSHCore.dll\ndevobj.dll\n");
		fprintf(fp2, "ctgmgr32.dll\nwdmaud.drv\nksuser.dll\navrt.dll\nAudioSes.dll\nadvapi32.dll\n");
		fprintf(fp2, "powrprof.dll\numpdc.dll\nmsacm32.dll\nmidimap.dll\nclbcatq.dll\n");
		fprintf(fp2, "TextInputFramework.dll\nCoreMessaging.dll\nCoreUIComponents.dll\nws2_32.dll\nntmarta.dll\nWinTypes.dll\n");
		fprintf(fp2, "TextShaping.dll\nWindowsCodecs.dll\nbcrypt.dll\n");
		fprintf(fp2, "如果上述系统的必要组件缺失，请在微软的官网上下载微软常用运行库合集，以保证本程序的正常运行\n");
		Sleep(1000);
		printf("相关的说明文件已经创建完成，正在读取相关的使用说明文件");
		fclose(fp);
		fclose(fp2);
		if (fp1 == NULL)
		{
			printf("WARNING!!!!!!\n");
			printf("系统检测到您删除了相关的说明文件，或者是说明文件读取出现了异常，重新启动本程序或重启电脑或授予该程序读写信息的权限可能会解决相关问题。本程序将会在5秒内关闭。");
			fclose(fp);
			Sleep(5000);
			exit(0);
		}
		else if (fp1!= NULL)
		{
			system("cls");
			printf("系统已经检测到相关的文件，正在读取，请稍后......");
			Sleep(1000);
			system("cls");
			Sleep(5000);
			system("cls");
			printf("运行本程序需要以下的几个文件\n");
			printf("1.sound.dll（如果该文件缺失，将无法播放背景音乐）\n");
			printf("2.shoot.dll和flower.dll（如果这两个文件的任意一个缺失，将无法读取信息，使程序运行异常）");
			printf("3.系统必要组件：\n");
			printf("ntd.dll\nkernel32.dll\nKernelbase.dll\nuser32.dll\nwin32u.dll\ngdi32.dll\n");
			printf("gdi32full.dll\nmsvcp_win.dll\nucrtbase.dll\nshell32.dll\nole32.dll\nrpcrt4.dll\n");
			printf("combase.dll\nGdiPlus.dll\nmsvcrt.dll\nwinmm.dll\nvcruntime140d.dll\nucrtbased.dll\n");
			printf("imm32,dll\nkernel.appcore.dll\nbcryptprimitives.dll\nuxtheme.dll\nmsctf.dll\n");
			printf("oleaut32.dll\nsechost.dll\nwinmmbase.dll\nMMDevAPI.dll\nSHCore.dll\ndevobj.dll\n");
			printf("ctgmgr32.dll\nwdmaud.drv\nksuser.dll\navrt.dll\nAudioSes.dll\nadvapi32.dll\n");
			printf("powrprof.dll\numpdc.dll\nmsacm32.dll\nmidimap.dll\nclbcatq.dll\n");
			printf("TextInputFramework.dll\nCoreMessaging.dll\nCoreUIComponents.dll\nws2_32.dll\nntmarta.dll\nWinTypes.dll\n");
			printf("TextShaping.dll\nWindowsCodecs.dll\nbcrypt.dll\n");
			printf("如果上述系统的必要组件缺失，请在微软的官网上下载微软常用运行库合集，以保证本程序的正常运行\n");
			fclose(fp1);
		}
	}
	else if (fp1!= NULL)
	{
		remove("readme.txt");
		fprintf(fp1, "运行本程序需要以下的几个文件\n");
		fprintf(fp1, "1.sound.dll（如果该文件缺失，将无法播放背景音乐）\n");
		fprintf(fp1, "2.shoot.dll和flower.dll（如果这两个文件的任意一个缺失，将无法读取信息，使程序运行异常）");
		fprintf(fp1, "3.系统必要组件：\n");
		fprintf(fp1, "ntd.dll\nkernel32.dll\nKernelbase.dll\nuser32.dll\nwin32u.dll\ngdi32.dll\n");
		fprintf(fp1, "gdi32full.dll\nmsvcp_win.dll\nucrtbase.dll\nshell32.dll\nole32.dll\nrpcrt4.dll\n");
		fprintf(fp1, "combase.dll\nGdiPlus.dll\nmsvcrt.dll\nwinmm.dll\nvcruntime140d.dll\nucrtbased.dll\n");
		fprintf(fp1, "imm32,dll\nkernel.appcore.dll\nbcryptprimitives.dll\nuxtheme.dll\nmsctf.dll\n");
		fprintf(fp1, "oleaut32.dll\nsechost.dll\nwinmmbase.dll\nMMDevAPI.dll\nSHCore.dll\ndevobj.dll\n");
		fprintf(fp1, "ctgmgr32.dll\nwdmaud.drv\nksuser.dll\navrt.dll\nAudioSes.dll\nadvapi32.dll\n");
		fprintf(fp1, "powrprof.dll\numpdc.dll\nmsacm32.dll\nmidimap.dll\nclbcatq.dll\n");
		fprintf(fp1, "TextInputFramework.dll\nCoreMessaging.dll\nCoreUIComponents.dll\nws2_32.dll\nntmarta.dll\nWinTypes.dll\n");
		fprintf(fp1, "TextShaping.dll\nWindowsCodecs.dll\nbcrypt.dll\n");
		fprintf(fp1, "如果上述系统的必要组件缺失，请在微软的官网上下载微软常用运行库合集，以保证本程序的正常运行\n");
		fscanf_s(fp1, "%c", &data);
		printf("%c", data);
		printf("\n");
		fclose(fp);
		fclose(fp1);
	}
}

void info(int a)
{
	printf("----------------------------------------informination-------------------------------------------\n");
	printf("Application:		新年快乐.exe\n");
	printf("version    :		1.0.1\n");
	printf("last update:		2021.1.11\n");
	printf("Host       :        LAPTOP-VIVL9BEE\n");
	printf("creater    :        LRY\n");
	printf("tag        :        Windows_visual_studio_x86_release\n");
	printf("cmd        :        NULL\n");
	printf("eabi       :        amd_R5_32bit_or_higher_vision\n");
	printf("sound.dll  :        SHA256: 0524F3ACEDE0045633DA441AA4A76FB32740E34ACFAF56AEFAAF7B80B5BEF8B5\n");
	printf("shoot.dll  :        SHA256: B907C1CDE39454371F5F65ADDB863485A15780D4CEFD25DECFE6DF71290A0A61\n");
	printf("flower.dll :        SHA256: 5016AA8836638F453A561DC6674AD51F4A353C4FE6F30702CA9205A1331635A6\n");
	printf("platform   :        Windows 20H2\n");
	printf("all rights reserved 2020~2021 ---powered by lry\n");
	printf("this informination will be closed after %d sceonds\n", a);
	printf("if you are the first time using this program,please look at readme.txt\n");
	printf("----------------------------------------information-----------------------------------------------\n");
	printf("these below things are necessary for this program.\n");
	printf("first: sound.dll if this file has been lost ,there could be no sound in this program.\n");
	printf("second:shoot.dll and flower.dll if these have been lost ,the program will be abnormal.\n");
	printf("third :necessary for the Windows operating system,and will be used for this program.\n");
	printf("ntd.dll  kernel32.dll  Kernelbase.dll  users32.dll  win32u.dll  gdi32.dll  gdi32full.dll  WindowsCodecs.dll\n");
	printf("msvcp_win.dll  ucrtbase.dll  shell32.dll  ole32.dll  rpcrt4.dll  combase.dll  GdiPlus.dll  bcrypt.dll\n");
	printf("msvcrt.dll  winmm.dll  vcrtuntime140d.dll  ucrtbased.dll  imm32.dll  kernel.appcore.dll  bcrtptprimitives.dll\n");
	printf("uxtheme.dll  msctf.dll  oleaut32.dll  sechost.dll  winmmbase.dll  MMDevAPI.dll  SHCore.dll  devobj.dll\n");
	printf("ctrmgr32.dll  wdmaud.drv  ksuser.dll  avrt.dll  AudioSes.dll  advapi32.dll  TextInputFramework.dll\n");
	printf("CoreMessaging.dll  CoreaUIComponents.dll  ws2_32.dll  ntmarta.dll  WinTypes.dll  TextShaping.dll\n");
	printf("if you can't find these files in your computer ,please go to Microsoft for help,or download 微软常用运行库合集\n");
	printf("these information will be closed after %d sceonds----powered by lry\n", a);
	printf("if this program get something wrong,please restart this program.");
	Sleep(1000);
	system("cls");
	FILE* f1 = fopen("readme.txt", "a");
	fprintf(f1,"程序已经成功启动\n");
	fprintf(f1, "下面输出程序输出信息\n");
	fprintf(f1, "----------------------------------------informination-------------------------------------------\n");
	fprintf(f1, "Application:		新年快乐.exe\n");
	fprintf(f1, "version    :		1.0.1\n");
	fprintf(f1, "last update:		2021.1.11\n");
	fprintf(f1, "Host       :       LAPTOP-VIVL9BEE\n");
	fprintf(f1, "creater    :       LRY\n");
	fprintf(f1, "tag        :        Windows_visual_studio_x86_release\n");
	fprintf(f1, "cmd        :        NULL\n");
	fprintf(f1, "eabi       :        amd_R5_32bit_or_higher_vision\n");
	fprintf(f1, "sound.dll  :        SHA256: 0524F3ACEDE0045633DA441AA4A76FB32740E34ACFAF56AEFAAF7B80B5BEF8B5\n");
	fprintf(f1, "shoot.dll  :        SHA256: B907C1CDE39454371F5F65ADDB863485A15780D4CEFD25DECFE6DF71290A0A61\n");
	fprintf(f1, "flower.dll :        SHA256: 5016AA8836638F453A561DC6674AD51F4A353C4FE6F30702CA9205A1331635A6\n");
	fprintf(f1, "platform   :        Windows 20H2\n");
	fprintf(f1, "all rights reserved 2020~2021 ---powered by lry\n");
	fprintf(f1, "this informination will be closed after % d sceonds\n", a);
	fprintf(f1, "if you are the first time using this program,please look at readme.txt\n");
	fprintf(f1, "----------------------------------------information-----------------------------------------------\n");
	fprintf(f1, "first: sound.dll if this file has been lost ,there could be no sound in this program.\n");
	fprintf(f1, "second:shoot.dll and flower.dll if these have been lost ,the program will be abnormal.\n");
	fprintf(f1, "third :necessary for the Windows operating system,and will be used for this program.\n");
	fprintf(f1, "ntd.dll  kernel32.dll  Kernelbase.dll  users32.dll  win32u.dll  gdi32.dll  gdi32full.dll  WindowsCodecs.dll\n");
	fprintf(f1, "msvcp_win.dll  ucrtbase.dll  shell32.dll  ole32.dll  rpcrt4.dll  combase.dll  GdiPlus.dll  bcrypt.dll\n");
	fprintf(f1, "msvcrt.dll  winmm.dll  vcrtuntime140d.dll  ucrtbased.dll  imm32.dll  kernel.appcore.dll  bcrtptprimitives.dll\n");
	fprintf(f1, "uxtheme.dll  msctf.dll  oleaut32.dll  sechost.dll  winmmbase.dll  MMDevAPI.dll  SHCore.dll  devobj.dll\n");
	fprintf(f1, "ctrmgr32.dll  wdmaud.drv  ksuser.dll  avrt.dll  AudioSes.dll  advapi32.dll  TextInputFramework.dll\n");
	fprintf(f1, "CoreMessaging.dll  CoreaUIComponents.dll  ws2_32.dll  ntmarta.dll  WinTypes.dll  TextShaping.dll\n");
	fprintf(f1, "if you can't find these files in your computer ,please go to Microsoft for help,or download 微软常用运行库合集\n");
	fprintf(f1, "these information will be closed after %d sceonds----powered by lry\n", a);
	fprintf(f1, "if this program get something wrong,please restart this program.\n");
	fflush(f1);
	fclose(f1);
}

void scan_file(int a)
{
	FILE* fp1 = fopen("sound.dll","rb");
	FILE* fp2 = fopen("shoot.dll", "rb");
	FILE* fp3 = fopen("flower.dll", "rb");
	FILE* f1 = fopen("readme.txt", "a");
	fprintf(f1, "正在校验sound.dll、shoot.dll、flower.dll文件是否存在");
	int t = 0;
	int i = 0;
	char k;
	if (fp1 == NULL)
	{
		t = t + 3;
	}
	if (fp2 == NULL)
	{
		t = t + 5;
	}
	if (fp3 == NULL)
	{
		t = t + 7;
	}
	if (t == 3)
	{
		printf("系统检测到缺失sound.dll文件，是否继续？\n是请按1，否请按2\n");
		fprintf(f1, "系统检测到缺失sound.dll文件，是否继续？\n是请按1，否请按2\n");
		scanf_s("%d", &i);
		fprintf(f1, "您做出的选择是%d", i);
		if (i == 1)
		{
			printf("系统开始重新执行代码\n");
			fprintf(f1, "系统开始重新执行代码\n");
			Sleep(1000);
			system("cls");
		}
		else if (i == 2)
		{
			printf("系统将在2秒后退出.");
			fprintf(f1, "系统将在2秒后退出");
			Sleep(2000);
			exit(0);
		}
		else if ((i != 1) && (i != 2))
		{
			printf("输入错误，正在退出本程序");
			fprintf(f1, "输入错误，正在退出本程序");
			printf("错误代码：0x%d", i);
			fprintf(f1, "错误代码：0x%d", i);
			exit(0);
		}
	}
	if (t == 5)
	{
		printf("系统检测到缺失shoot.dll文件，是否继续？\n是请按1，否请按2\n");
		fprintf(f1, "系统检测到缺失shoot.dll文件，是否继续？\n是请按1，否请按2\n");
		scanf_s("%d", &i);
		fprintf(f1, "您所作出的选择为%d", i);
		if (i == 1)
		{
			printf("系统开始重新执行代码\n");
			fprintf(f1, "系统开始重新执行代码\n");
			Sleep(1000);
			system("cls");
		}
		else if (i == 2)
		{
			printf("系统将在2秒后退出");
			fprintf(f1, "系统将在2秒后退出");
			Sleep(2000);
			exit(0);
		}
		else if ((i != 1) && (i != 2))
		{
			printf("输入错误，正在退出本程序");
			fprintf(f1, "输入错误，正在退出本程序");
			printf("错误代码：0x%d", i);
			fprintf(f1, "错误代码：0x%d",i);
			exit(0);
		}
	}
	if (t == 7)
	{
		printf("系统检测到缺失flower.dll文件，是否继续？\n是请按1，否请按2\n");
		fprintf(f1, "系统检测到缺失fower.dll文件，是否继续？\n是请按1，否请按2\n");
		scanf_s("%d", &i);
		fprintf(f1, "您所作出的选择为%d", i);
		if (i == 1)
		{
			printf("系统开始重新执行代码\n");
			fprintf(f1, "系统开始重新执行代码\n");
			Sleep(1000);
			system("cls");
		}
		else if (i == 2)
		{
			printf("系统将在2秒后退出.");
			fprintf(f1, "系统将在2秒后退出");
			Sleep(2000);
			exit(0);
		}
		else if ((i != 1) && (i != 2))
		{
			printf("输入错误，正在退出本程序");
			fprintf(f1, "输入错误，正在退出本程序");
			printf("错误代码：0x%d",i);
			fprintf(f1, "错误代码：0x%d", i);
			exit(0);
		}
	}
	if (t == 8)
	{
		printf("系统检测到缺失sound.dll文件和shoot.dll文件，是否继续？\n是请按1，否请按2\n");
		fprintf(f1, "系统检测到缺失sound.dll文件和shoot.dll文件，时候继续？\n是请按1，否请按2\n");
		scanf_s("%d", &i);
		fprintf(f1, "您所作出的选择为%d", i);
		if (i == 1)
		{
			printf("系统开始重新执行代码\n");
			fprintf(f1, "系统开始重新执行代码\n");
			Sleep(1000);
			system("cls");
		}
		else if (i == 2)
		{
			printf("系统将在2秒后退出.");
			fprintf(f1, "系统将在2秒后退出");
			Sleep(2000);
			exit(0);
		}
		else if ((i != 1) && (i != 2))
		{
			printf("输入错误，正在退出本程序");
			fprintf(f1, "输入错误，正在退出本程序");
			printf("错误代码：0x%d", i);
			fprintf(f1, "错误代码：0x%d", i);
			exit(0);
		}
	}
	if (t == 10)
	{
		printf("系统检测到缺失sound.dll文件和flower.dll文件，是否继续？\n是请按1，否请按2\n");
		fprintf(f1, "系统检测到缺失sound.dll文件和flower.dll文件，是否继续？\n是请按1，否请按2\n");
		scanf_s("%d", &i);
		fprintf(f1, "您所做出的选择为%d", i);
		if (i == 1)
		{
			printf("系统开始重新执行代码\n");
			fprintf(f1, "系统开始重新执行代码\n");
			Sleep(1000);
			system("cls");
		}
		else if (i == 2)
		{
			printf("系统将在2秒后退出.");
			fprintf(f1, "系统将在2秒后退出");
			Sleep(2000);
			exit(0);
		}
		else if ((i != 1) && (i != 2))
		{
			printf("输入错误，正在退出本程序");
			fprintf(f1, "输入错误，正在退出本程序");
			printf("错误代码：0x%d", i);
			fprintf(f1, "错误代码：0x%d", i);
			exit(0);
		}
	}
	if (t == 12)
	{
		printf("系统检测到缺失shoot.dll文件和flower.dll文件，是否继续？\n是请按1，否请按2\n");
		fprintf(f1, "系统检测到缺失shoot.dll文件和flower.dll文件，是否继续？\n是请按1，否请按2\n");
		scanf_s("%d", &i);
		fprintf(f1, "您所作出的选择为%d", i);
		if (i == 1)
		{
			printf("系统开始重新执行代码\n");
			fprintf(f1, "系统开始重新执行代码\n");
			Sleep(1000);
			system("cls");
		}
		else if (i == 2)
		{
			printf("系统将在2秒后退出.");
			fprintf(f1, "系统将在2秒后退出");
			Sleep(2000);
			exit(0);
		}
		else if ((i != 1) && (i != 2))
		{
			printf("输入错误，正在退出本程序");
			fprintf(f1, "输入错误，正在退出本程序");
			printf("错误代码：0x%d", i);
			fprintf(f1, "错误代码：0x%d", i);
			exit(0);
		}
	}
	if (t == 15)
	{
		printf("系统检测到缺失sound.dll文件、shoot.dll文件、flower.dll文件，是否继续？\n是请按1，否请按2\n");
		fprintf(f1, "系统检测到缺失sound.dll文件、shoot.dll文件、flower.dll文件,是否继续？\n是请按1，否请按2\n");
		scanf_s("%d", &i);
		fprintf(f1, "您所做出的选择为%d", i);
		if (i == 1)
		{
			printf("系统开始重新执行代码\n");
			fprintf(f1, "系统开始重新执行代码\n");
			Sleep(1000);
			system("cls");
		}
		else if (i == 2)
		{
			printf("系统将在2秒后退出.");
			fprintf(f1, "系统将在2秒后退出");
			Sleep(2000);
			exit(1);
		}
		else if ((i != 1) && (i != 2))
		{
			printf("输入错误，正在退出本程序");
			fprintf(f1, "输入错误，正在退出本程序");
			printf("错误代码：0x%d", i);
			fprintf(f1, "错误代码：0x%d", i);
			exit(0);
		}
	}
	else if (t == 0)
	{
		printf("系统检测到文件正常，即将启动主程序\n");
		fprintf(f1, "系统检测到文件正常，即将启动主程序\n");
		Sleep(1000);
		system("cls");
	}
	else if ((t != 0) && (t != 3) && (t != 5) && (t != 7) && (t != 8) && (t != 10) && (t != 12) && (t != 15))
	{
		printf("本程序出现了未知错误，错误代码为0x%d", t);
		fprintf(f1, "本程序出现了未知错误，错误代码为0x%d", t);
		printf("\n重新启动本程序可能会解决本问题");
		fprintf(f1, "\n重新启动本程序可能会解决本问题");
		printf("\n本程序正在退出，请稍后......");
		fprintf(f1, "\n本程序正在退出，请稍后......");
		Sleep(1000);
		exit(1);
	}
}
