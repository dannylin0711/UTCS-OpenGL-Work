//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLCtrl"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

GLfloat vertices[][3] = {
{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},
{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},
{1.0,1.0,1.0},{-1.0,1.0,1.0}
};

GLfloat colors[][3] = {
{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},
{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},
{1.0,1.0,1.0},{0.0,1.0,1.0}
};
void drawAxis(){
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(5.0,0.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,5.0,0.0);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,5.0);
    glEnd();
}
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
}

void colorCube(){
    polygon(0,3,2,1);
    polygon(2,3,7,6);
    polygon(0,4,7,3);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(0,1,5,4);

}

void __fastcall TForm1::init(TObject *Sender){
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.1,0.1,0.1,1.0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::graphicDraw(TObject *Sender){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,-5.0,5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    colorCube();
    
    glFlush();
}
//---------------------------------------------------------------------------

