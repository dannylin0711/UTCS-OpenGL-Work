//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLCtrl"
#pragma resource "*.dfm"
TForm1 *Form1;
typedef float point[3];

point v[]={{0.0,0.0,1.0},
           {0.0,0.942809,-0.333333},
           {-0.816497,-0.471405,-0.333333},
           {0.816497,-0.471405,-0.333333}};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

static bool flag = true;
static int count = 0;
/*
GLfloat vertices[][3] = {
{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},
{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},
{1.0,1.0,1.0},{-1.0,1.0,1.0}
};

GLfloat colors[][3] = {
{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},
{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},
{1.0,1.0,1.0},{0.0,1.0,1.0}
};  */

void triangle(point a, point b, point c){

     glVertex3fv(a);
     glVertex3fv(b);
     glVertex3fv(c);

}


void drawTetra(point a,point b,point c,point d){
    glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.0,0.0);
            triangle(a,b,c);
        glColor3f(0.0,0.0,1.0);
            triangle(a,d,c);
        glColor3f(1.0,1.0,1.0);
            triangle(b,c,d);
        glColor3f(0.0,1.0,0.0);
            triangle(a,b,d);
    glEnd();
}

void drawAxis(){
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-5.0,0.0,0.0);
    glVertex3f(5.0,0.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.0,-5.0,0.0);
    glVertex3f(0.0,5.0,0.0);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.0,-5.0);
    glVertex3f(0.0,0.0,5.0);
    glEnd();
}
/*
void polygon(int a,int b, int c, int d){
    glBegin(GL_POLYGON);
        glColor3fv(colors[a]);
        glVertex3fv(vertices[a]);
        glColor3fv(colors[b]);
        glVertex3fv(vertices[b]);
        glColor3fv(colors[c]);
        glVertex3fv(vertices[c]);
        glColor3fv(colors[d]);
        glVertex3fv(vertices[d]);
    glEnd();
}    */

void divideAndDraw(point a,point b, point c ,point d ,int times){
    point mid[6];
    int j;
    if(times>0){
        for(j = 0;j < 3;j++) mid[0][j] = (a[j]+b[j])/2;
        for(j = 0;j < 3;j++) mid[1][j] = (a[j]+c[j])/2;
        for(j = 0;j < 3;j++) mid[2][j] = (a[j]+d[j])/2;
        for(j = 0;j < 3;j++) mid[3][j] = (b[j]+c[j])/2;
        for(j = 0;j < 3;j++) mid[4][j] = (c[j]+d[j])/2;
        for(j = 0;j < 3;j++) mid[5][j] = (b[j]+d[j])/2;

        divideAndDraw(a,mid[0],mid[1],mid[2],times-1);
        divideAndDraw(mid[0],b,mid[3],mid[5],times-1);
        divideAndDraw(mid[1],mid[3],c,mid[4],times-1);
        divideAndDraw(mid[2],mid[5],mid[4],d,times-1);
    }else{
        drawTetra(a,b,c,d);
    }
}
/*
void colorCube(){
    polygon(0,3,2,1);
    polygon(2,3,7,6);
    polygon(0,4,7,3);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(0,1,5,4);

}    */

void __fastcall TForm1::init(TObject *Sender){
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.1,0.1,0.1,1.0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::graphicDraw(TObject *Sender){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2,2,-2,2,-2.0,2.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glViewport(0,0,GLBox1->Width/2,GLBox1->Height/2);
    //colorCube();
    divideAndDraw(v[0],v[1],v[2],v[3],abs(count));
    drawAxis();

    glViewport(0,GLBox1->Height/2,GLBox1->Width/2,GLBox1->Height/2);
    glPushMatrix();
    gluLookAt(0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0);
    //colorCube();
    drawAxis();
    divideAndDraw(v[0],v[1],v[2],v[3],abs(count));
    glPopMatrix();

    glViewport(GLBox1->Width/2,0,GLBox1->Width/2,GLBox1->Height/2);
    glPushMatrix();
    gluLookAt(1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0);
    //colorCube();
    drawAxis();
    divideAndDraw(v[0],v[1],v[2],v[3],abs(count));
    glPopMatrix();

    glViewport(GLBox1->Width/2,GLBox1->Height/2,GLBox1->Width/2,GLBox1->Height/2);
    glPushMatrix();
    gluLookAt(1,1,1,0.0,0.0,0.0,0.0,1.0,0.0);
    //colorCube();
    drawAxis();
    divideAndDraw(v[0],v[1],v[2],v[3],abs(count));
    glFlush();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    GLBox1->Invalidate();

    if(flag){
        count++;
        if(count>=8)
            flag = !flag;
    }else{
        count--;
        if(count<=0)
            flag = !flag ;
    }
}
//---------------------------------------------------------------------------

