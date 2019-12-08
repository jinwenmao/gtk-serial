/*
 * author: wide288
 * copyleft
 * for you YangQi and my mom Happy every day!
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include     <stdio.h>      /*标准输入输出定义*/
#include     <stdlib.h>     /*标准函数库定义*/
#include     <unistd.h>     /*Unix标准函数定义*/
#include     <sys/types.h>  /**/
#include     <sys/stat.h>   /**/
#include     <fcntl.h>      /*文件控制定义*/
#include     <termios.h>    /*PPSIX终端控制定义*/
#include     <errno.h>      /*错误号定义*/
#include "callbacks.h"
#include "interface.h"
#include "support.h"

extern GtkWidget *textview1;
extern GtkWidget *textview2;
extern GtkTextBuffer *buffer1;
extern GtkTextBuffer *buffer2;
int com_n = 0x00;	//选择端口标志数, 0=>com1, 1=>com2
int data_n = 0x01;	//数据位 0=> 7 ,1=> 8
int stop_n = 0x00;	//停止位 0=>1 ,1=>2
int par_n = 0x00;	//校验位 0=>n ,1=>奇, 2=>偶
int fd;
gboolean flag_com = TRUE;

//声明函数
void set_speed(int fd, int speed);
int set_parity(int fd,int databits,int stopbits,int parity);
int open_com(gchar *dev);
void read_com(int devfd);	//读串口

void read_com(int devfd)
{
	gchar buff[512];
	gchar nread;
	GtkTextIter end;

	while(flag_com)
	{
		g_usleep(4);
		gdk_threads_enter();
		gtk_text_buffer_get_end_iter(buffer1, &end);
		while((nread = read(fd,buff,512))>0)	//向接收文本框传数据
		{
			gtk_text_buffer_insert(buffer1, &end, buff, -1);
//printf(":%d\n", nread);
//buff[nread+1] = '\0';
//printf(":\n%s\n", buff);
		}
		gdk_threads_leave();
	}
}

/*
设置速率
*/
void set_speed(int fd, int speed)
{
	int i;
	int status;
	struct termios opt;
	int speed_arr[] = {B38400,B19200,B9600,B4800,B2400,B1200,B300,B38400,B19200,B9600,B4800,B2400,B1200,B300};
	int name_arr[] = {38400,19200,9600,4800,2400,1200,300,38400,19200,9600,4800,2400,1200,300};

	tcgetattr(fd, &opt);
	for(i=0; i<sizeof(speed_arr)/sizeof(int); i++)
	{
		if(speed == name_arr[i])
		{
			tcflush(fd, TCIOFLUSH);
			cfsetispeed(&opt, speed_arr[i]);
			cfsetospeed(&opt, speed_arr[i]);
			status = tcsetattr(fd, TCSANOW, &opt);
			if(status != 0)
			{
				perror("tcsetattr fd\n");
				return;
			}
			tcflush(fd, TCIOFLUSH);
		}
	}
}

/**
*@brief   设置串口数据位，停止位和效验位
*@param  fd     类型  int  打开的串口文件句柄
*@param  databits 类型  int 数据位   取值 为 7 或者8
*@param  stopbits 类型  int 停止位   取值为 1 或者2
*@param  parity  类型  int  效验类型 取值为N,E,O,,S
*/
int set_parity(int fd,int databits,int stopbits,int parity)
{ 
	struct termios options; 
	if  ( tcgetattr( fd,&options)  !=  0) { 
		perror("SetupSerial 1");     
		return(FALSE);  
	}
	options.c_cflag &= ~CSIZE; 
	switch (databits) /*设置数据位数*/
	{   
	case 0://7
		options.c_cflag |= CS7; 
		break;
	case 1://8
		options.c_cflag |= CS8;
		break;   
	default:    
		fprintf(stderr,"Unsupported data size\n"); return (FALSE);  
	}
switch (parity) 
{   
	case 0:    
		options.c_cflag &= ~PARENB;   /* Clear parity enable */
		options.c_iflag &= ~INPCK;     /* Enable parity checking */ 
		break;  
	case 1:     
		options.c_cflag |= (PARODD | PARENB); /* 设置为奇效验*/  
		options.c_iflag |= INPCK;             /* Disnable parity checking */ 
		break;  
	case 2:  
		options.c_cflag |= PARENB;     /* Enable parity */    
		options.c_cflag &= ~PARODD;   /* 转换为偶效验*/     
		options.c_iflag |= INPCK;       /* Disnable parity checking */
		break;
	case 3:  /*as no parity*/   
	    options.c_cflag &= ~PARENB;
		options.c_cflag &= ~CSTOPB;break;  
	default:   
		fprintf(stderr,"Unsupported parity\n");    
		return (FALSE);  
	}  
/* 设置停止位*/  
switch (stopbits)
{   
	case 0:    //1
		options.c_cflag &= ~CSTOPB;  
		break;  
	case 1:    //2
		options.c_cflag |= CSTOPB;  
	   break;
	default:    
		 fprintf(stderr,"Unsupported stop bits\n");  
		 return (FALSE); 
} 
/* Set input parity option */ 
if (parity != 'n')   
	options.c_iflag |= INPCK; 
tcflush(fd,TCIFLUSH);
options.c_cc[VTIME] = 150; /* 设置超时15 seconds*/   
options.c_cc[VMIN] = 0; /* Update the options and do it NOW */
if (tcsetattr(fd,TCSANOW,&options) != 0)   
{ 
	perror("SetupSerial 3");   
	return (FALSE);  
} 
return (TRUE);  
}

/*
打开串口
*/
int open_com(gchar *dev)
{
	int fd = open(dev, O_RDWR);
	if( -1 == fd)
	{
		perror("串口没打开\n");	//最好写到label里，或出现对话框
		return -1;
	}
	else return fd;
}

void
on_comboboxentry1_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
//选择端口
	com_n = gtk_combo_box_get_active(combobox);
}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//打开串口
	gchar *str_com = "/dev/ttyS0";
	GtkTextIter end;

	if(com_n == 0)
		str_com = "/dev/ttyS0";
	else if(com_n == 1)
		str_com = "/dev/ttyS1";
printf("test(open com):%s\n",str_com);
	fd = open_com(str_com);
	if(fd < 0) return;
	set_speed(fd,9600);
	if (set_parity(fd,data_n, stop_n, par_n) == FALSE)  {
		printf("设置波特率失败\n");
		exit (0);
	}
	g_thread_create(read_com, fd, FALSE, NULL);
	printf("test :ok\n");
}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//关闭串口
	flag_com = FALSE;
	close(fd);
printf("test(close com):\n");
}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//清空发送文本框
GtkTextIter start, end;
gtk_text_buffer_get_start_iter(buffer2, &start);
gtk_text_buffer_get_end_iter(buffer2, &end);
gtk_text_buffer_delete(buffer2, &start, &end);
/*	gchar *str = "\0";
      GtkWidget *w = NULL;
	gpointer tv2;
      w = gtk_widget_get_toplevel(GTK_WIDGET(button));
      if (GTK_WIDGET_TOPLEVEL (w))
      {
		tv2 = g_object_get_data (GTK_OBJECT(w), "textview2");
            if (tv2 != NULL)
            {
      	      gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv2)), str, strlen(str));
            }
      }*/
}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//接收文本框进制互换(十六《--》十)

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//清空接收文本框
GtkTextIter start, end;
gtk_text_buffer_get_start_iter(buffer1, &start);
gtk_text_buffer_get_end_iter(buffer1, &end);
gtk_text_buffer_delete(buffer1, &start, &end);
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//发送文本
	GtkTextIter start, end;
	gchar *buff;

	gtk_text_buffer_get_start_iter(buffer2, &start);
	gtk_text_buffer_get_end_iter(buffer2, &end);
	buff = gtk_text_buffer_get_text(buffer2, &start, &end, TRUE);
	printf("send text:%s\n",buff);
	write(fd, buff, sizeof(buff));
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//发送文本框进制互换

}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//退出程序
//此函数成功
	gtk_main_quit();
//	return FALSE;
}

gboolean hex2shi(GString *str_hex, GString *str_shi)
{

}

gboolean shi2hex(gchar *str_shi, gchar *str_hex)
{

}

void
on_comboboxentry2_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
//数据位 7,8
	data_n = gtk_combo_box_get_active(combobox);
}


void
on_comboboxentry4_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
//校验位
	par_n = gtk_combo_box_get_active(combobox);
}


void
on_comboboxentry3_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
//停止位
	stop_n = gtk_combo_box_get_active(combobox);
}

