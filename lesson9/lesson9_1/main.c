/*
*******************************************************************************
*                     ���ְ��ֽ���ѧ51��Ƭ��(C���԰�)��
*                    ���� KST-51 ��Ƭ�������� ʾ��Դ����
*
*         (c) ��Ȩ���� 2014 ��ɳ̲������/�廪��ѧ������ ��������Ȩ��
*                 ��ȡ������������ʣ�http://www.kingst.org
*
* �ļ�����main.c
* ��  ������9�� ������������Ļ���ʾ��
* �汾�ţ�v1.0.0
* ��  ע���������9��9.3.3��
*******************************************************************************
*/

#include <reg52.h>

unsigned char code BeatCode[8] = {  //����������Ķ�Ӧ��IO���ƴ���
    0xE, 0xC, 0xD, 0x9, 0xB, 0x3, 0x7, 0x6
};

void delay();

void main()
{
    unsigned char tmp;  //����һ����ʱ����
    unsigned char index = 0;  //��������������
    
	while (1)
    {
        tmp = P1;                    //��tmp��P1�ڵ�ǰֵ�ݴ�
        tmp = tmp & 0xF0;            //��&���������4λ
        tmp = tmp | BeatCode[index]; //��|�����ѽ��Ĵ���д����4λ
        P1  = tmp;                   //�ѵ�4λ�Ľ��Ĵ���͸�4λ��ԭֵ�ͻ�P1
        index++;                     //���������������
        index = index & 0x07;        //��&����ʵ�ֵ�8����
        delay();                     //��ʱ2ms����2msִ��һ��
    }
}
/* ������ʱ��������ʱԼ2ms */
void delay()
{
    unsigned int i = 200;
	
    while (i--);
}