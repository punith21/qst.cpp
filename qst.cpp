#include<GL/glut.h>
//#include<stdlib.h>
#include<GL/glu.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
GLfloat v[][8][3]={{{-1.5,-1.5,-1.0},{-1.3,-1.5,-1.0},{-1.3,-1.3,-1.0},{-1.5,-1.3,-1.0},{-1.6,-1.6,1.0},{-1.4,-1.6,1.0},{-1.4,-1.4,1.0},{-1.6,-1.4,1.0}} , {{-1.3,-1.5,-1.0},{-1.1,-1.5,-1.0},{-1.1,-1.3,-1.0},{-1.3,-1.3,-1.0},{-1.4,-1.6,1.0},{-1.2,-1.6,1.0},{-1.2,-1.4,1.0},{-1.4,-1.4,1.0}} , {{-1.1,-1.5,-1.0},{-0.9,-1.5,-1.0},{-0.9,-1.3,-1.0},{-1.1,-1.3,-1.0},{-1.2,-1.6,1.0},{-1.0,-1.6,1.0},{-1.0,-1.4,1.0},{-1.2,-1.4,1.0}} , {{-1.5,-1.3,-1.0},{-1.3,-1.3,-1.0},{-1.3,-1.1,-1.0},{-1.5,-1.1,-1.0},{-1.6,-1.4,1.0},{-1.4,-1.4,1.0},{-1.4,-1.2,1.0},{-1.6,-1.2,1.0}} , {{-1.3,-1.3,-1.0},{-1.1,-1.3,-1.0},{-1.1,-1.1,-1.0},{-1.3,-1.1,-1.0},{-1.4,-1.4,1.0},{-1.2,-1.4,1.0},{-1.2,-1.2,1.0},{-1.4,-1.2,1.0}} , {{-1.1,-1.3,-1.0},{-0.9,-1.3,-1.0},{-0.9,-1.1,-1.0},{-1.1,-1.1,-1.0},{-1.2,-1.4,1.0},{-1.0,-1.4,1.0},{-1.0,-1.2,1.0},{-1.2,-1.2,1.0}} , {{-1.5,-1.1,-1.0},{-1.3,-1.1,-1.0},{-1.3,-0.9,-1.0},{-1.5,-0.9,-1.0},{-1.6,-1.2,1.0},{-1.4,-1.2,1.0},{-1.4,-1.0,1.0},{-1.6,-1.0,1.0}} , {{-1.3,-1.1,-1.0},{-1.1,-1.1,-1.0},{-1.1,-0.9,-1.0},{-1.3,-0.9,-1.0},{-1.4,-1.2,1.0},{-1.2,-1.2,1.0},{-1.2,-1.0,1.0},{-1.4,-1.0,1.0}} , {{-1.1,-1.1,-1.0},{-0.9,-1.1,-1.0},{-0.9,-0.9,-1.0},{-1.1,-0.9,-1.0},{-1.2,-1.2,1.0},{-1.0,-1.2,1.0},{-1.0,-1.0,1.0},{-1.2,-1.0,1.0}}};
GLfloat colors[][3]={{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0},{1.0,0.0,1.0},{0.0,1.0,1.0}};
GLfloat st[][3]={{1.8,-1.5,-1.0},{2.0,-1.5,-1.0},{2.0,0.9,-1.0},{1.8,0.9,-1.0},{1.7,-1.6,1.0},{1.9,-1.6,1.0},{1.9,0.8,1.0},{1.7,0.8,1.0}};
GLint i,h,m,k,n=5;
GLfloat tempv[8][3];
GLint tos=-1,maxsize=5,g=-1,f=0,ch,fr=-1,r=-1;
GLfloat tempst=-1.5,sttos=-1.9;
GLfloat stcube[9][8][3];
GLint pu=0,po=0,in=0,l,o,rear,node=0;
GLfloat tx=0.0,ty=1.0,stfr=-1.5,str=-1.4;
int out=0;
void polygon(int a,int b,int c,int d,int i)
{ 
 glBegin(GL_POLYGON);
 glColor3fv(colors[a]);
 glVertex3fv(v[i][a]);
 glColor3fv(colors[b]);
 glVertex3fv(v[i][b]);
 glColor3fv(colors[c]);
 glVertex3fv(v[i][c]);
 glColor3fv(colors[d]);
 glVertex3fv(v[i][d]);
 glFlush();
 glEnd();
}
void colorcube()
{
 polygon(0,3,2,1,i);
 polygon(2,3,7,6,i);
 polygon(0,4,7,3,i);
 polygon(1,2,6,5,i);
 polygon(4,5,6,7,i);
 polygon(0,1,5,4,i);
}
void stack(int a,int b,int c,int d)
{
 
 glBegin(GL_POLYGON);
 glColor3f(1.0,1.0,1.0);
 glVertex3fv(st[a]);
 glColor3fv(colors[b]);
 glVertex3fv(st[b]);
 glColor3f(1.0,1.0,1.0);
 glVertex3fv(st[c]);
 glColor3fv(colors[d]);
 glVertex3fv(st[d]);
 glFlush();
 glEnd();
}
void stackcube()
{
 stack(0,3,2,1);
 stack(2,3,7,6);
 stack(0,4,7,3);
 stack(1,2,6,5);
 stack(4,5,6,7);
 stack(0,1,5,4);
}
void resultpolygon(int a,int b,int c,int d)
{
 glBegin(GL_POLYGON);
 glColor3fv(colors[a]);
 glVertex3fv(tempv[a]);
 glColor3fv(colors[b]);
 glVertex3fv(tempv[b]);
 glColor3fv(colors[c]);
 glVertex3fv(tempv[c]);
 glColor3fv(colors[d]);
 glVertex3fv(tempv[d]);
 glFlush();
 glEnd();
}
void resultcolorcube()
{
 resultpolygon(0,3,2,1);
 resultpolygon(2,3,7,6);
 resultpolygon(0,4,7,3);
 resultpolygon(1,2,6,5);
 resultpolygon(4,5,6,7);
 resultpolygon(0,1,5,4);
}
void stackpolygon(int a,int b,int c,int d,int f)
{
 
 glBegin(GL_POLYGON);
 glColor3fv(colors[a]);
 glVertex3fv(stcube[f][a]);
 glColor3fv(colors[b]);
 glVertex3fv(stcube[f][b]);
 glColor3fv(colors[c]);
 glVertex3fv(stcube[f][c]);
 glColor3fv(colors[d]);
 glVertex3fv(stcube[f][d]);
 glFlush();
 glEnd();
}
void stackcolorcube()
{
 stackpolygon(0,3,2,1,f);
 stackpolygon(2,3,7,6,f);
 stackpolygon(0,4,7,3,f);
 stackpolygon(1,2,6,5,f);
 stackpolygon(4,5,6,7,f);
 stackpolygon(0,1,5,4,f);
}
void init()
{
	glClearColor(0.1,0.1,0.1,1.0);
	gluOrtho2D(0.0,599.0,0.0,599.0);
}
void text(char str[])
{
 int i;
 for(i=0;i<strlen(str);i++) 
 {
	 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
 }
}
void form1()
{
 glColor3f(0.8,0.2,0.7);
 glRasterPos3f(-1.08,1.6,-1.0);
 text("GRAPHICAL  IMPLEMENTATION");
 glRasterPos3f(-0.12,1.4,-1.0);
 text("OF");
 glRasterPos3f(-0.66,1.2,-1.0);
 text("DATA STRUCTURES");
 glRasterPos3f(-0.53,1.0,-1.0);
 text("USING OPENGL");
 glColor3f(0.8,0.2,0.7);
 glRasterPos3f(1.4,-1.92,-1.0);
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'P');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'r');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'e');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'s');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'s');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,' ');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'n');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'/');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'N');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,' ');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'t');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'o');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,' ');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'c');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'o');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'n');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'t');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'i');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'n');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'u');
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'e');
 
 glRasterPos3f(-0.45,-1.3,-1.0);
 text("Under the guidance of : ");
 glRasterPos3f(-2.5,-1.5,-1.0);
 text(" Lohitesh Kumar N");
 glColor3f(0.8,0.2,0.7);
 glRasterPos3f(-2.5,-1.7,-1.0);
 text("Asst prof.Dept.of C.S.E.,");
 glRasterPos3f(1.6,-1.5,-1.0);
 text("Mahesh N");
 glColor3f(0.8,0.2,0.7);
 glRasterPos3f(1.6,-1.7,-1.0);
 text("Asst prof.Dept.of C.S.E.,");
 glRasterPos3f(-1.28,-0.6,-1.0);
 text("Department of Computer Science and Engineering ");
 glRasterPos3f(-1.28,-0.8,-1.0);
 text("Channabasaveshwara Institute of Engineering and Technology");
 glRasterPos3f(-0.47,0.7,-1.0);
 text("Submitted by : ");
 glRasterPos3f(-0.47,0.0,-1.0);
 text("Kumaraswamy A T");
 glRasterPos3f(-0.47,0.2,-1.0);
 text("[1cg11cs122]");
glRasterPos3f(-0.47,0.4,-1.0);
 text("Yashas Y S");
 glRasterPos3f(-0.47,-0.2,1.0);
 text("[1cg11cs411]");
 glFlush();
 glEnd();
}
void form2()
{
 glColor3f(0.8,0.2,0.7);
 glRasterPos3f(-1.6,0.85,-1.0);
 text("1. Press 1 to goto Stack");
 glRasterPos3f(-1.8,1.45,-1.0);
 text("NAVIGATION OPTIONS");
 glRasterPos3f(-1.6,0.55,-1.0);
 text("2. Press 2 to goto Queue");
 glFlush();
 glRasterPos3f(-1.6,0.23,-1.0);
 text("3. Press 3 to goto Tree");
 glFlush();
 glRasterPos3f(-1.6,-0.05,-1.0);
 text("4. Press 4 to exit");
 glFlush();
 glColor3f(0.8,0.2,0.7);
 glRasterPos3f(-1.8,-0.65,-1.0);
 text("Press h/H to go to help");
 glFlush();
 glEnd();
}
void help()
{
 glColor3f(0.8,0.2,0.7);
 glRasterPos3f(-1.6,0.85,-1.0);
 text("Use mouse keys to operate in the output");
 glRasterPos3f(-1.4,0.55,-1.0);
 text("Right Button Click to open the Menu");
 glRasterPos3f(-1.4,0.23,-1.0);
 text("Left Button Click to select the option");
 glRasterPos3f(-1.6,-0.35,-1.0);
 text("Press m/M to go back");
 glFlush();
 glEnd();
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 if(out==0)
  form1();
 else if(out==1)
  form2();
 else if(out==2)
  help();
 else
 {
  if(ch==1)
  {
  glColor3f(0.8,0.2,0.7);
  if(sttos<-1.5)
   glRasterPos3f(1.45,sttos+0.4,1.0);
  else
   glRasterPos3f(1.45,sttos,1.0);
  text("tos>>");
  glFlush();
  for(i=0;i<=n;i++)
   colorcube();
  stackcube();
  resultcolorcube();
 for(f=0;f<=tos;f++)
  stackcolorcube();
  glColor3f(0.8,0.2,0.7);
  glRasterPos3f(1.7,-1.8,1.0);
  text("Stack");
  glFlush();
  if(tos==-1)
  {
   glColor3f(0.8,0.2,0.7);
   glRasterPos3f(-0.5,0.0,-1.0);
   text("Stack Empty");
   glFlush();
  }
  if(tos>=maxsize)
  {
   glColor3f(0.8,0.2,0.7);
   glRasterPos3f(-0.5,0.0,-1.0);
   text("Stack Full");
   glFlush();
  }
  glColor3f(0.8,0.2,0.7);
  glRasterPos3f(1.7,-1.8,1.0);
  text("Stack");
  glFlush(); 
 }
 else if(ch==2)
 {
  glColor3f(1.0,0.0,0.0);
  glRasterPos3f(1.38,stfr,1.0);
  text("front>>");
  glFlush();

  glColor3f(1.0,0.0,0.0);
  glRasterPos3f(1.4,str,1.0);
  text("rear>>");
  glFlush();

  glColor3f(0.8,0.2,0.7);
  glRasterPos3f(2.1,-0.2,1.0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'Q');
  glRasterPos3f(2.1,-0.35,1.0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'u');
  glRasterPos3f(2.1,-0.5,1.0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
  glRasterPos3f(2.1,-0.65,1.0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'u');
  glRasterPos3f(2.1,-0.8,1.0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
  glFlush();
  for(i=0;i<=n;i++)
   colorcube();
  stackcube();
  resultcolorcube();
 for(f=fr;f<=r;f++)
  stackcolorcube();
  if(r==-1)
  {
   glColor3f(0.8,0.2,0.7);
   glRasterPos3f(-0.5,0.0,-1.0);
   text("Queue Empty");
   glFlush();
  }
  if(r>=maxsize)
  {
   glColor3f(0.8,0.2,0.7);
   glRasterPos3f(-0.5,0.0,-1.0);
   text("Queue Full");
   glFlush();
  }
 }
 else if(ch==3)
 {
  glColor3f(0.8,0.2,0.7);
  glRasterPos3f(1.1,-1.8,1.0);
  text("Tree");
  glFlush();
  if(node==1)
  {
   glColor3f(0.8,0.2,0.7);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-1][0][0],stcube[node-1][0][1],1.0);
   glVertex3f(tx,ty,1.0);
   glFlush();
   glEnd();
  }
  if(node==2)
  {
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-2][0][0],stcube[node-2][0][1],1.0);
   glVertex3f(tx-1.0,ty,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-2][1][0],stcube[node-2][1][1],1.0);
   glVertex3f(tx,ty,1.0);
   glFlush();
   glEnd();
  }
  if(node==3)
  {
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-3][0][0],stcube[node-3][0][1],1.0);
   glVertex3f(tx+0.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-3][1][0],stcube[node-3][1][1],1.0);
   glVertex3f(tx+1.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-2][0][0],stcube[node-2][0][1],1.0);
   glVertex3f(tx,ty,1.0);
   glFlush();
   glEnd();
  }
  if(node==4)
  {
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-4][0][0],stcube[node-4][0][1],1.0);
   glVertex3f(tx-0.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-4][1][0],stcube[node-4][1][1],1.0);
   glVertex3f(tx+0.7,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-3][0][0],stcube[node-3][0][1],1.0);
   glVertex3f(tx-0.6,ty,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-3][1][0],stcube[node-3][1][1],1.0);
   glVertex3f(tx,ty,1.0);
   glFlush();
   glEnd();
  }
  if(node==5)
  {
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-5][0][0],stcube[node-5][0][1],1.0);
   glVertex3f(tx-0.7,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-5][1][0],stcube[node-5][1][1],1.0);
   glVertex3f(tx+0.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-4][0][0],stcube[node-4][0][1],1.0);
   glVertex3f(tx-1.0,ty,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-4][1][0],stcube[node-4][1][1],1.0);
   glVertex3f(tx-0.4,ty,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-3][0][0],stcube[node-3][0][1],1.0);
   glVertex3f(tx,ty,1.0);
   glFlush();
   glEnd();
  }
  if(node==6)
  {
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-6][0][0],stcube[node-6][0][1],1.0);
   glVertex3f(tx-1.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-6][1][0],stcube[node-6][1][1],1.0);
   glVertex3f(tx-0.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-5][0][0],stcube[node-5][0][1],1.0);
   glVertex3f(tx-1.6,ty,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-5][1][0],stcube[node-5][1][1],1.0);
   glVertex3f(tx-1.0,ty,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-4][0][0],stcube[node-4][0][1],1.0);
   glVertex3f(tx-0.6,ty,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-4][1][0],stcube[node-4][1][1],1.0);
   glVertex3f(tx,ty,1.0);
   glFlush();
   glEnd();
  }
  if(node==7)
  {
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-7][0][0],stcube[node-7][0][1],1.0);
   glVertex3f(tx+0.6,ty+1.4,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-7][1][0],stcube[node-7][1][1],1.0);
   glVertex3f(tx+1.6,ty+1.4,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-6][0][0],stcube[node-6][0][1],1.0);
   glVertex3f(tx+0.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-6][1][0],stcube[node-6][1][1],1.0);
   glVertex3f(tx+0.9,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-5][0][0],stcube[node-5][0][1],1.0);
   glVertex3f(tx+1.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-5][1][0],stcube[node-5][1][1],1.0);
   glVertex3f(tx+1.9,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-4][0][0],stcube[node-4][0][1],1.0);
   glVertex3f(tx,ty,1.0);
   glFlush();
   glEnd();
  }
  if(node==8)
  {
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-8][0][0],stcube[node-8][0][1],1.0);
   glVertex3f(tx,ty+1.4,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-8][1][0],stcube[node-8][1][1],1.0);
   glVertex3f(tx+1.0,ty+1.4,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-7][0][0],stcube[node-7][0][1],1.0);
   glVertex3f(tx-0.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-7][1][0],stcube[node-6][1][1],1.0);
   glVertex3f(tx+0.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-6][0][0],stcube[node-6][0][1],1.0);
   glVertex3f(tx+0.7,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-6][1][0],stcube[node-6][1][1],1.0);
   glVertex3f(tx+1.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-5][0][0],stcube[node-5][0][1],1.0);
   glVertex3f(tx-0.6,ty,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-5][1][0],stcube[node-5][1][1],1.0);
   glVertex3f(tx,ty,1.0);
   glFlush();
   glEnd();
  }
  if(node==9)
  {
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-9][0][0],stcube[node-9][0][1],1.0);
   glVertex3f(tx,ty+1.4,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-9][1][0],stcube[node-9][1][1],1.0);
   glVertex3f(tx+1.0,ty+1.4,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-8][0][0],stcube[node-8][0][1],1.0);
   glVertex3f(tx-0.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-8][1][0],stcube[node-8][1][1],1.0);
   glVertex3f(tx+0.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-7][0][0],stcube[node-7][0][1],1.0);
   glVertex3f(tx+0.7,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-7][1][0],stcube[node-7][1][1],1.0);
   glVertex3f(tx+1.3,ty+0.8,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-6][0][0],stcube[node-6][0][1],1.0);
   glVertex3f(tx-0.6,ty,1.0);
   glFlush();
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINES);
   glVertex3f(stcube[node-6][1][0],stcube[node-6][1][1],1.0);
   glVertex3f(tx,ty,1.0);
   glFlush();
   glEnd();
  }

  for(i=0;i<=n;i++)
   colorcube();
  for(f=0;f<node;f++)
  stackcolorcube();
  resultcolorcube();
 }
 glColor3f(0.5,0.6,0.8);
 glRasterPos3f(-0.5,1.45,-1.0);
 text("Press m/M to goto Main Menu");
 glFlush();
 }
 if(ch==4)
	 exit(0);
 glutSwapBuffers();

}
void myreshape(int w,int h)
{
 glViewport(0,0,w,h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 if(w<=h)
  glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
 else
  glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
 glMatrixMode(GL_MODELVIEW);
}
void push()
{
 if(tos<maxsize)
 {
  for(h=0;h<8;h++)
   for(m=0;m<3;m++)
    tempv[h][m]=v[i][h][m];
  n--;
  display();
  while(tempv[0][1]<=1.0)
  {
   for(k=0;k<8;k++)
    tempv[k][1]=tempv[k][1]+0.1;
   display();
  }
 while(tempv[0][0]<=st[0][0])
 {
  for(k=0;k<8;k++)
   tempv[k][0]=tempv[k][0]+0.1;
  display();
  }
 while(tempv[0][1]>tempst)
 {
  for(k=0;k<8;k++)
   tempv[k][1]=tempv[k][1]-0.1;
  display();
 }
  tos++;
  for(h=0;h<8;h++)
   for(m=0;m<3;m++)
    stcube[tos][h][m]=tempv[h][m];
  tempst+=0.4;
  sttos+=0.4;
  display();
 }
 else
 { 
  display();
 }
}
void pop()
{
 if(tos>=0)
 {
  for(h=0;h<8;h++)
   for(m=0;m<3;m++)
    tempv[h][m]=stcube[tos][h][m];
  tos--;
  display();
  while(tempv[0][1]<=1.0)
  {
   for(k=0;k<8;k++)
    tempv[k][1]=tempv[k][1]+0.1;
   display();
  }
  while(tempv[0][0]>v[i][0][0])
  {
   for(k=0;k<8;k++)
    tempv[k][0]=tempv[k][0]-0.1;
   display();
  }
  while(tempv[0][1]>v[i][0][1])
  {
   for(k=0;k<8;k++)
    tempv[k][1]=tempv[k][1]-0.1;
   display();
  }
  tempst-=0.4;
  display();
  sttos-=0.4;
  n++;
  display();
 }
 else
 {
  display();	
 }
}
void stack_menu(int id)
{
 switch(id)
 {
  case 1:i--;push();break;
  case 2:pop();break;
 case 4:exit(0);
	  break;
 }
}
void mymenu()
{
 glutCreateMenu(stack_menu);
 glutAddMenuEntry("Push",1);
 glutAddMenuEntry("Pop",2);
 glutAddMenuEntry("Exit",4);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void insert()
{
 if(r>=maxsize)
  display();
 else
 {
  for(h=0;h<8;h++)
   for(m=0;m<3;m++)
    tempv[h][m]=v[i][h][m];
  n--;
  display();
  while(tempv[0][1]<=1.0)
  {
   for(k=0;k<8;k++)
    tempv[k][1]=tempv[k][1]+0.1;
   display();
  }
 while(tempv[0][0]<=st[0][0])
 {
  for(k=0;k<8;k++)
   tempv[k][0]=tempv[k][0]+0.1;
  display();
 }
 while(tempv[0][1]>tempst)
 {
  for(k=0;k<8;k++)
   tempv[k][1]=tempv[k][1]-0.1;
  display(); 
 }
  tempst+=0.4;
  r++;
  for(h=0;h<8;h++)
   for(m=0;m<3;m++)
    stcube[r][h][m]=tempv[h][m];
  display();
  str+=0.4;
  if(r==maxsize)
   str-=0.4;
  if(fr==-1)
	  fr=0;
 }
}
void remove()
{
 if(fr==-1)
  display();
 else if(fr<=r)
 {
  for(h=0;h<8;h++)
   for(m=0;m<3;m++)
	tempv[h][m]=stcube[fr][h][m];
  fr++;
  display();
  stfr+=0.4;
  if(fr>r)
   stfr-=0.4;
  while(tempv[0][1]>-1.8)
  {
   for(k=0;k<8;k++)
	tempv[k][1]=tempv[k][1]-0.1;
   display();
  }
  while(tempv[0][0]>0.0)
  {
   for(k=0;k<8;k++)
	tempv[k][0]=tempv[k][0]-0.1;
   display();
  }
  while(tempv[0][1]<1.0)
  {
   for(k=0;k<8;k++)
	tempv[k][1]=tempv[k][1]+0.1;
   display();
  }
  while(tempv[0][0]>v[i][0][0])
  {
   for(k=0;k<8;k++)
	tempv[k][0]=tempv[k][0]-0.1;
   display();
  }
  while(tempv[0][1]>v[i][0][1])
  {
   for(k=0;k<8;k++)
	tempv[k][1]=tempv[k][1]-0.1;
   display();
  }
  if(fr>r)
  {
   fr=-1;
   r=-1;
   tempst=-1.5;
   str=-1.4;
   stfr=-1.5;
  }
  n++;
  display();
 } 
}
void queuemenu(int id)
{
 switch(id)
 {
  case 1:i--;insert();break;
  case 2:remove();break;
  case 4:break;exit(0);
 }
}
void myqmenu()
{
 glutCreateMenu(queuemenu);
 glutAddMenuEntry("Insert",1);
 glutAddMenuEntry("Remove",2);
 glutAddMenuEntry("Exit",4);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void tinsert()
{
 if((n>=0)&&(n<=8))
 {
  for(h=0;h<8;h++)
   for(m=0;m<3;m++)
    tempv[h][m]=v[i][h][m];
  n--;
  display();
  while(tempv[0][0]<tx)
  {
   for(k=0;k<8;k++)
    tempv[k][0]=tempv[k][0]+0.1;
   display();
  }
  while(tempv[0][1]<=ty)
  {
   for(k=0;k<8;k++)
    tempv[k][1]=tempv[k][1]+0.1;
   display();
  }
  if((node==0)||(node==2)||(node==6))   ty=ty-0.5;
  for(h=0;h<8;h++)
   for(m=0;m<3;m++)
    stcube[node][h][m]=tempv[h][m];
  node++;
  if((node==1)||(node==3)||(node==7))   ty=ty-0.2;
  if(node==1)   tx=tx-0.5;
  if(node==2)   tx=tx+1.0;
  if(node==3)   tx=tx-1.3;
  if(node==4)   tx=tx+0.6;
  if(node==5)   tx=tx+0.4;
  if(node==6)   tx=tx+0.6;
  if(node==7)   tx=tx-1.9;
  if(node==8)   tx=tx+0.6;
  display();
 }
}
void tremove()
{
 if(node>0)
 {
  node--;
  for(h=0;h<8;h++)
   for(m=0;m<3;m++)
    tempv[h][m]=stcube[node][h][m];
  if((node==0)||(node==2)||(node==6))   ty=ty+0.5;
  if((node==6)||(node==2)||(node==0))   ty=ty+0.2;
  if(node==7)   tx=tx-0.6;
  if(node==6)   tx=tx+1.9;
  if(node==5)   tx=tx-0.6;
  if(node==4)   tx=tx-0.4;
  if(node==3)   tx=tx-0.6;
  if(node==2)   tx=tx+1.3;
  if(node==1)   tx=tx-1.0;
  while(tempv[0][1]>v[i][0][1])
  {
   for(k=0;k<8;k++)
    tempv[k][1]=tempv[k][1]-0.1;
   display();
  }
  while(tempv[0][0]>v[i][0][0])
  {
   for(k=0;k<8;k++)
    tempv[k][0]=tempv[k][0]-0.1;
   display();
  }
  n++;  
  display();
 }
}

void treemenu(int id)
{
 switch(id)
 {
  case 1:i--;tinsert();break;
  case 2:tremove();break;
  case 4:exit(0);break;
 }
}
void mytmenu()
{
 glutCreateMenu(treemenu);
 glutAddMenuEntry("Insert",1);
 glutAddMenuEntry("Remove",2);
 glutAddMenuEntry("Exit",4);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void keyboard(unsigned char key,int x,int y)
{
 if(key=='n'||key=='N')
 {
  out=1;
  display();
 }
 if(key=='1')
 {
  out=3;
  ch=1;
  n=5;
  i=0;
  tos=-1;
  sttos=-1.9;
  tempst=-1.5;
  mymenu();
  display();
 }
 if(key=='2')
 {
  out=3;
  ch=2;
  n=5;
  i=0;
  r=fr=-1;
  stfr=-1.5;
  str=-1.4;
  tempst=-1.5;
  myqmenu();
  display();
 }
 if(key=='3')
 {
  out=3;
  ch=3;
  n=8;
  i=0;
  tx=0.0;
  ty=1.0;
  mytmenu();
  display();
 }
 if(key=='4')
 {
  exit(0);
 }
 if(key=='m'||key=='M')
 {
  out=1;
  display();
 }
 if(key=='h'||key=='H')
 {
  out=2;
  display();
 }
}
int main(int argc,char **argv)
{
  //glClearColor(0.0,0.0,0.0,0.0);
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
  glutInitWindowSize(600,600);
  glutCreateWindow("colorcube");
  init();
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(myreshape);
  glutDisplayFunc(display);
  glutMainLoop();
 return 0;
}
