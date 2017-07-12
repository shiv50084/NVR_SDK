#ifndef _MOUSE_H_
#define _MOUSE_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/input.h>

struct mousedev_motion {
    int dx, dy, dz; 		//�����ƫ������dz��ʾ���ֵ�ֵ
    unsigned long buttons;	//ָʾ����״̬
							//bit0: �����״̬��0-->�޶��������ͷţ�1-->����
							//bit1: �Ҽ���״̬��0-->�޶��������ͷţ�1-->����
							//bit2: �м��״̬��0-->�޶��������ͷţ�1-->����
							//�жϰ��µĶ��������ϴ����״̬��ֵ���һ�£������ͬ���ҵ�ǰֵΪ1��ʾ���¸ü���
							//�ж��ͷŵĶ��������ϴ����״̬��ֵ���һ�£������ͬ���ҵ�ǰֵΪ0��ʾ�ͷŸü���
							//�϶����жϣ�������£��ƶ�������ͷŵĹ���
    unsigned short abs_x;	//x�ľ�������, [0, 1024]
    unsigned short abs_y;	//y�ľ�������, [0, 768]
};

struct mousedev_status {
	unsigned char status;
	unsigned short x,y,z;
};

#define	MOUSE_LEFT_DOWN		0x1
#define	MOUSE_RIGHT_DOWN	  0x2
#define	MOUSE_MID_DOWN		0x3
#define	MOUSE_LEFT_UP		0x4
#define	MOUSE_RIGHT_UP		0x5
#define	MOUSE_MID_UP		0x6
//#define	MOUSE_MOVE			0x7
#define	MOUSE_WHEEL_DOWN	0x8
#define	MOUSE_WHEEL_UP		0x9

#define DEV_MOUSE "/dev/input/mice"

#endif