
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include<time.h>
void *currentfont;
float p=36,q=20;
int i,count;
char t[2];
clock_t  start,end;
int flag=0,df=10;

void box()
{
     
	glColor3f(0.8,0.8,0.1);
	glPointSize(35);
	glBegin(GL_POINTS);
	glVertex2f(p,q);
	glEnd();


}
void box1()
{
     
	glColor3f(1.0,0.0,0.0);
	glPointSize(35);
	glBegin(GL_POINTS);
	glVertex2f(36,20);
	glEnd();
}


void box2()
{
     
	glColor3f(0.1,0.5,0.5);
	glPointSize(35);
	glBegin(GL_POINTS);
	glVertex2f(161,125);
	glEnd();

}

void setFont(void *font)
{
	currentfont=font;
}


void drawstring(float x,float y,float z,char *string)
{
	    char *c;
	glRasterPos3f(x,y,z);
 
	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,1.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}


void frontscreen(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,0);
  	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstring(40,100,0,"PROJECT PARTNERS");
	drawstring(40,90,0,"1.NIDHI S YELI");
	drawstring(40,80,0,"2.RESHMA ROOHI K");
	drawstring(100,90,0,"4JN15CS054");
	drawstring(100,80,0,"4JN15CS077");

	glColor3f(1,1,0);
	drawstring(40,60,0,"PROJECT GUIDES");
	drawstring(40,50,0,"SUSHMA R.B");
	setFont(GLUT_BITMAP_8_BY_13);
	drawstring(65,50,0,"M.Tech");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstring(75,50,0,"Asst.Professor,CSE");
	drawstring(40,40,0,"NAMITHA M.V");
	setFont(GLUT_BITMAP_8_BY_13);
	drawstring(68,40,0,"M.Tech");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstring(79,40,0,"Asst.Professor,CSE");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,0);
	drawstring(30,135,0,"JAWAHARLAL NEHRU NATIONAL COLLEGE OF ENGINEERING,SHIMOGA ");
	glColor3f(0.8,0.6,0.8);
	drawstring(80,125,0,"CG MINI PROJECT");
	drawstring(80,122,0,"________________");

	glColor3f(1,0,1);
	drawstring(82,115,0,"MAZE RUNNER");


	glColor3f(1,0,1);
	drawstring(130,5,0,"Press ENTER to continue");

	glFlush();
}



void winscreen()
{
setFont(GLUT_BITMAP_HELVETICA_18);
glColor3f(0,1,0);
drawstring(65,100,0," YOU HAVE SUCCEEDED IN FINDING OUT THE PATH");

setFont(GLUT_BITMAP_HELVETICA_18);
glColor3f(1,0,1);
drawstring(90,120,0,"CONGRATS!!!");

setFont(GLUT_BITMAP_HELVETICA_18);
glColor3f(1,1,1);
drawstring(35,60,0,"* PRESS ESC TO GO TO MAIN MENU");

setFont(GLUT_BITMAP_HELVETICA_18);
glColor3f(1,1,1);
drawstring(35,45,0,"* PRESS 1 TO RESTART THE GAME");

glEnd();
glFlush();
}


void startscreen()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(1,0,0.5);
drawstring(80,120,0,"WELCOME TO MAZE RUNNER");

setFont(GLUT_BITMAP_HELVETICA_18);
glColor3f(1,0.5,0.5);
drawstring(50,100,0,"1.NEW GAME");

setFont(GLUT_BITMAP_HELVETICA_18);
glColor3f(1,0.5,0.5);
drawstring(50,80,0,"2.INSTRUCTIONS");

setFont(GLUT_BITMAP_HELVETICA_18);
glColor3f(1,0.5,0.5);
drawstring(50,60,0,"3.QUIT");

glEnd();
glFlush();
}



void instruction()
{
	glBegin(GL_LINES);
	glVertex2f(80,122);
	glVertex2f(110,122);
	glEnd();
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,1,1);
drawstring(80,125,0,"INSTRUCTIONS:");
glColor3f(0.2,0.5,0.5);
drawstring(50,100,0,"* IN THIS GAME YOU ARE SUPPOSED TO REACH THE DESTINATION");
glColor3f(0.2,0.5,0.5);
drawstring(50,80,0,"* USE THE ARROW KEYS TO MOVE");
glColor3f(0.2,0.5,0.5);
drawstring(50,60,0,"* IF YOU FIND THE PROPPER PATH IN 30 SECONDS YOU WIN ");


setFont(GLUT_BITMAP_HELVETICA_18);
glColor3f(0,0,1);
drawstring(120,30,0,"PRESS ESC TO GO BACK TO MAIN MENU");

glEnd();


glFlush();
}


void timeover()
{
 glClear(GL_COLOR_BUFFER_BIT);
 setFont(GLUT_BITMAP_HELVETICA_18);
 glColor3f(1.0,0,0);
drawstring(90,110,0,"TIMEOVER");
 glColor3f(0,1,0);
 drawstring(80,90,0,"YOU HAVE LOST THE GAME");
 drawstring(80,70,0,"BETTER LUCK NEXT TIME");
 drawstring(120,40,0,"* PRESS ESC TO GO TO MAIN MENU");
 drawstring(120,32,0,"* PRESS 1 TO RESTART THE GAME");
 glFlush();
}


void idle()
{
  if(df==1)
  {
    end=clock();
    count=(end-start)/CLOCKS_PER_SEC;
    if(count==30)
    {
       df=4;
    }
	else
	if((count<30) &&  ((p>=157 && p<=165) && (q>=121 && q<=129)))
	{
		df=5;
	}
  }

   glutPostRedisplay();
}


void specialkey(int key,int x,int y)
{
  switch(key)
  {


     case GLUT_KEY_UP:
		flag=0;
		if(q<125)
		if(!((p>=42&&p<=50)&&(q>=20&&q<=86))) //1

        if(!((p>=58&&p<=65)&&(q>=20&&q<=68)))  //2

        if(!((p>=72&&p<=80)&&(q>=20&&q<=50)))  //3

		if(!((p>=72&&p<=80)&&(q>=58&&q<=104))) //4

		if(!((p>=88&&p<=95)&&(q>=40&&q<=68)))  //5

		if(!((p>=87&&p<=95)&&(q>=104&&q<=121))) //6

		if(!((p>=103&&p<=110)&&(q>=42&&q<=68))) //7

		if(!((p>=100&&p<=110)&&(q>=111&&q<=125)))//8

		if(!((p>=117&&p<=125)&&(q>=58&&q<=86)))  //9

		if(!((p>=132&&p<=140)&&(q>=20&&q<=50)))  //10

		if(!((p>=132&&p<=140)&&(q>=58&&q<=104)))//11

		if(!((p>=147&&p<=155)&&(q>=20&&q<=50)))   //12

		if(!((p>=147&&p<=155)&&(q>=58&&q<=104)))  //13


       ///

        if(!((p>=42&&p<=65)&&(q>=20&&q<=33)))

        if(!((p>=42&&p<=65)&&(q>=75&&q<=86)))

		if(!((p>=58&&p<=80)&&(q>=55&&q<=68)))

		if(!((p>=42&&p<=140)&&(q>=90&&q<=104)))

        if(!((p>=42&&p<=125)&&(q>=110&&q<=122)))

		if(!((p>=72&&p<=125)&&(q>=20&&q<=33)))

		if(!((p>=72&&p<=95)&&(q>=40&&q<=46)))//7

		if(!((p>=87&&p<=125)&&(q>=75&&q<=86)))

		if(!((p>=103&&p<=155)&&(q>=40&&q<=48)))

		if(!((p>=117&&p<=140)&&(q>=55&&q<=68)))

		if(!((p>=133&&p<=165)&&(q>=110&&q<=122)))

		if(!((p>=147&&p<=165)&&(q>=55&&q<=68)))
			///



		q=q+5;
		glutPostRedisplay();
		break;



   case GLUT_KEY_DOWN:

	flag=0;
	    if(q>15)
	    if(!((p>=42&&p<=50)&&(q>=20&&q<=86))) //1

        if(!((p>=58&&p<=65)&&(q>=20&&q<=68)))  //2

        if(!((p>=72&&p<=80)&&(q>=20&&q<=50)))  //3

		if(!((p>=72&&p<=80)&&(q>=58&&q<=104))) //4

		if(!((p>=87&&p<=95)&&(q>=40&&q<=70)))  //5

		if(!((p>=87&&p<=95)&&(q>=104&&q<=121))) //6

		if(!((p>=103&&p<=110)&&(q>=42&&q<=70))) //7

		if(!((p>=100&&p<=110)&&(q>=111&&q<=125)))//8

		if(!((p>=117&&p<=125)&&(q>=58&&q<=86)))  //9

		if(!((p>=132&&p<=140)&&(q>=20&&q<=50)))  //10

		if(!((p>=132&&p<=140)&&(q>=58&&q<=104)))//11

		if(!((p>=147&&p<=155)&&(q>=22&&q<=50)))   //12

		if(!((p>=147&&p<=155)&&(q>=58&&q<=106)))  //13


			/////
		if(!((p>=42&&p<=65)&&(q>=22&&q<=36)))

        if(!((p>=42&&p<=65)&&(q>=78&&q<=90)))

		if(!((p>=58&&p<=80)&&(q>=60&&q<=70))) //60

		if(!((p>=42&&p<=140)&&(q>=96&&q<=106)))

        if(!((p>=42&&p<=125)&&(q>=113&&q<=125)))

		if(!((p>=72&&p<=125)&&(q>=22&&q<=35)))

		if(!((p>=72&&p<=95)&&(q>=43&&q<=51)))

		if(!((p>=87&&p<=125)&&(q>=78&&q<=91)))

		if(!((p>=103&&p<=155)&&(q>=43&&q<=50)))

		if(!((p>=117&&p<=140)&&(q>=60&&q<=70)))

		if(!((p>=133&&p<=165)&&(q>=113&&q<=125)))

		if(!((p>=147&&p<=165)&&(q>=60&&q<=70)))
			///
		q=q-5;
		glutPostRedisplay();
		break;




	case GLUT_KEY_RIGHT:
		flag=0;
		if(p<160)
		if(!((p>=40&&p<=65)&&(q>=23&&q<=33)))

        if(!((p>=40&&p<=65)&&(q>=76&&q<=86)))

		if(!((p>=55&&p<=80)&&(q>=58&&q<=68)))

		if(!((p>=40&&p<=140)&&(q>=94&&q<=104)))

        if(!((p>=40&&p<=125)&&(q>=111&&q<=122)))

		if(!((p>=70&&p<=125)&&(q>=23&&q<=33)))

		if(!((p>=72&&p<=95)&&(q>=44&&q<=46)))      // 7

		if(!((p>=85&&p<=125)&&(q>=76&&q<=86)))

		if(!((p>=100&&p<=155)&&(q>=43&&q<=48)))

		if(!((p>=117&&p<=140)&&(q>=58&&q<=68)))

		if(!((p>=130&&p<=160)&&(q>=111&&q<=122)))

		if(!((p>=147&&p<=160)&&(q>=58&&q<=68)))

			////

		if(!((p>=41&&p<=50)&&(q>=21&&q<=86))) //1

        if(!((p>=54&&p<=65)&&(q>=21&&q<=68)))  //2

        if(!((p>=70&&p<=80)&&(q>=21&&q<=48)))  //3

		if(!((p>=67&&p<=80)&&(q>=58&&q<=104))) //4

		if(!((p>=86&&p<=95)&&(q>=44&&q<=68)))  //5

		if(!((p>=85&&p<=95)&&(q>=104&&q<=121))) //6

		if(!((p>=100&&p<=110)&&(q>=21&&q<=68))) //7

		if(!((p>=100&&p<=110)&&(q>=111&&q<=125)))//8

		if(!((p>=114&&p<=125)&&(q>=58&&q<=86)))  //9

		if(!((p>=130&&p<=140)&&(q>=15&&q<=48)))  //10

		if(!((p>=130&&p<=140)&&(q>=58&&q<=104)))//11

		if(!((p>=145&&p<=155)&&(q>=21&&q<=48)))   //12

		if(!((p>=145&&p<=155)&&(q>=58&&q<=104)))  //13


			p=p+5;
         glutPostRedisplay();
		break;


	case GLUT_KEY_LEFT:
		flag=0;
		if(p>37)
		if(!((p>=43&&p<=63)&&(q>=23&&q<=33)))

        if(!((p>=43&&p<=68)&&(q>=76&&q<=86)))

		if(!((p>=55&&p<=78)&&(q>=58&&q<=68)))

		if(!((p>=43&&p<=138)&&(q>=94&&q<=104)))

        if(!((p>=43&&p<=128)&&(q>=111&&q<=122)))

		if(!((p>=72&&p<=126)&&(q>=23&&q<=33)))//6

		if(!((p>=72&&p<=93)&&(q>=44&&q<=46)))

		if(!((p>=85&&p<=123)&&(q>=76&&q<=86)))

		if(!((p>=103&&p<=153)&&(q>=42&&q<=48)))

		if(!((p>=117&&p<=138)&&(q>=58&&q<=68)))

		if(!((p>=133&&p<=158)&&(q>=111&&q<=122)))

		if(!((p>=147&&p<=158)&&(q>=58&&q<=68)))

			////

		if(!((p>=43&&p<=52)&&(q>=21&&q<=86))) //1

        if(!((p>=58&&p<=66)&&(q>=21&&q<=68)))  //2

        if(!((p>=72&&p<=83)&&(q>=21&&q<=48)))  //3

		if(!((p>=72&&p<=82)&&(q>=58&&q<=104))) //4

		if(!((p>=87&&p<=97)&&(q>=44&&q<=68)))  //5

		if(!((p>=88&&p<=97)&&(q>=104&&q<=121))) //6

		if(!((p>=103&&p<=113)&&(q>=21&&q<=68))) //7

		if(!((p>=103&&p<=113)&&(q>=111&&q<=125)))//8

		if(!((p>=117&&p<=126)&&(q>=58&&q<=86)))  //9

		if(!((p>=132&&p<=143)&&(q>=15&&q<=48)))  //10

		if(!((p>=132&&p<=143)&&(q>=58&&q<=104)))//11

		if(!((p>=147&&p<=158)&&(q>=21&&q<=48)))   //12

		if(!((p>=147&&p<=158)&&(q>=58&&q<=104)))  //13


			p=p-5;
         glutPostRedisplay();
		break;




    /*case GLUT_KEY_UP:
		flag=0;
		if(p==36&&q==20)
        if(p==36&&q<=124)
		q=q+5;
		glutPostRedisplay();
		break;*/
	/*case GLUT_KEY_RIGHT:
		flag=0;
		if(p==36&&q==20)
		if(p<=160&&20)
			p=p+5;
         glutPostRedisplay();
		break;*/
}

}


void display()
{
glClear(GL_COLOR_BUFFER_BIT);

if(df==10)
     frontscreen();
else if(df==0)
      startscreen();
else if(df==1)
{

box1();
box();
box2();
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(1,0,1);
drawstring(30,140,0,"Press q to quit");

setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(1,1,1);
drawstring(15,15,0,"START");

setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(1,1,1);
drawstring(175,125,0,"END");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0,0.0,0.0);
		drawstring(167,100,0,"TIME REMAINING : ");
		glColor3f(1,0,0);
		sprintf(t,"%d",30-count);
        drawstring(177,92,0,t);

glColor3f(1.0,1.0,1.0);
glLineWidth(50.0);
glBegin(GL_LINES);
 glVertex2i(30,134.6);
 glVertex2i(30,10);
 glVertex2i(30,10);
 glVertex2i(165,10);
 glVertex2i(165,10);
 glVertex2i(165,134.6);
 glVertex2i(165,132);
 glVertex2i(165,134.6);
  glVertex2i(165,134.6);
 glVertex2i(30,134.6);

 glVertex2i(60,81.2);
 glVertex2i(45,81.2);

 glVertex2i(45,81.2);
 glVertex2i(45,27.8);
 
 glVertex2i(45,27.8);
 glVertex2i(60,27.8);

 glVertex2i(60,27.8);
 glVertex2i(60,63.4);

 glVertex2i(60,63.4);
 glVertex2i(75,63.4);

 glVertex2i(75,63.4);
 glVertex2i(75,99);

 glVertex2i(45,99);
 glVertex2i(135,99);

 glVertex2i(135,99);
 glVertex2i(135,63.4);
 
 glVertex2i(135,63.4);
 glVertex2i(120,63.4);
 
 glVertex2i(120,63.4);
 glVertex2i(120,81.2);
 
 glVertex2i(120,81.2);
 glVertex2i(90,81.2);  //
 
 glVertex2i(90,63.4);
 glVertex2i(90,45.6);
 
 glVertex2i(90,45.6);
 glVertex2i(75,45.6);
 
 glVertex2i(75,45.6);
 glVertex2i(75,27.8);
 
 glVertex2i(75,27.8);
 glVertex2i(120,27.8);
 
 glVertex2i(105,63.4);
 glVertex2i(105,27.8);
 
 glVertex2i(105,45.6);
 glVertex2i(150,45.6);

 glVertex2i(150,45.6);
 glVertex2i(150,27.8);
 
 glVertex2i(135,45.6);
 glVertex2i(135,10);//

 glVertex2i(150,99);
 glVertex2i(150,63.4);
 
 glVertex2i(150,63.4);
 glVertex2i(165,63.4);//
 
 glVertex2i(105,134.6);
 glVertex2i(105,116.8);//
 
 glVertex2i(45,116.8);
 glVertex2i(120,116.8);//

 glVertex2i(90,116.8);
 glVertex2i(90,99);//
 
 glVertex2i(135,116.8);
 glVertex2i(165,116.8);
 glutPostRedisplay();

 if(p==161 && q==125)
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(1,0,1);
drawstring(75,80,0,"you win");

 }
 else if(df==2)
	 instruction();
 else if(df==3)
	 exit(1);
 else if(df==4)
 {
    timeover();
 }
 else if(df==5)
	 winscreen();

  
 


glEnd();
glFlush();
}


void keyboard(unsigned char key,int x,int y)
{

if(df==10 && key==13)
df=0;

    else if((df==0 || df==4 || df==5)&& key=='1')
   {
     df=1;
     start=clock();
	 glutPostRedisplay();
   }
  else if(df==0 && key=='2')
   df=2;
  else if(df==0 && key=='3')
   df=3;
  else if(key==27)
   {	df=0;
	}
	if((key=='0' || key=='1')&& (df==4||df==1))
  {
   p=36.0;
   q=20.0;
  }
  glutPostRedisplay ();
}


void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,200.0,0.0,150.0);
}



void main(int argc,char**argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(1250,650);
glutCreateWindow("MAZE RUNNER");
glutDisplayFunc(display);
glutIdleFunc(idle);
glutSpecialFunc(specialkey);
glutKeyboardFunc(keyboard);
init();
glutMainLoop();

}