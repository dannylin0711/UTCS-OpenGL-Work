//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <math.h>
#include <stdio.h>

#define PI acos(-1)
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
static bool singleMode = true;
static bool flag = true;
static int count = 0;
double translateX = 0.0;
double translateY = 0.0;
double translateZ = 0.0;
double scaleX = 1.0;
double scaleY = 1.0;
double scaleZ = 1.0;
double rotateX = 0;
double rotateY = 0;
double rotateZ = 0;
double prev_rotateX = 0;
double prev_rotateY = 0;
double prev_rotateZ = 0;
double rad = PI/180.0 ;
float matrix[16];
float matrix_temp[16];
bool rotateFlag = true;

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
void drawAxis2(){
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(2.5,0.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.0,0,0.0);
    glVertex3f(0.0,2.5,0.0);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,2.5);
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

void colorCube(){
    polygon(0,3,2,1);
    polygon(2,3,7,6);
    polygon(0,4,7,3);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(0,1,5,4);

}








double rotateMatrixX[3][3] = {  {1,0,0},
                                {0,cos(rotateX*rad)-sin(rotateX*rad)},
                                {0,sin(rotateX*rad),cos(rotateX*rad)}
                            };
double rotateMatrixZ[3][3] = {  {cos(rotateZ*rad), -sin(rotateZ*rad),0},
                                {sin(rotateZ*rad),cos(rotateZ*rad),0},
                                {0,0,1}
                            };
double rotateMatrixY[3][3] = {  {cos(rotateY*rad), 0,sin(rotateY*rad)},
                                {0,1,0},
                                {-sin(rotateY*rad),0,cos(rotateY*rad)}
                            };
void MatrixMult(float *mat1, float *mat2, float *result)
{
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			result[i*4+j] = 0;
			for(int k=0; k<4; k++){
				result[i*4+j] += mat1[i*4+k]*mat2[k*4+j];
			}
		}
	}
}

void MatrixRotateX(float *mat, float angle){
	angle = angle/180*3.141592653589793238;
	float rot[] = {
		1,0,0,0,
		0,cos(angle),-sin(angle),0,
		0,sin(angle),cos(angle),0,
		0,0,0,1
	};
	float res[16];
	MatrixMult(rot,mat,res);
	for(int i=0; i<16; i++) mat[i] = res[i];
}

void MatrixRotateY(float *mat, float angle){
	angle = angle/180*3.141592653589793238;
	float rot[] = {
		cos(angle),0,sin(angle),0,
		0,1,0,0,
		-sin(angle),0,cos(angle),0,
		0,0,0,1
	};
	float res[16];
	MatrixMult(rot,mat,res);
	for(int i=0; i<16; i++) mat[i] = res[i];
}

void MatrixRotateZ(float *mat, float angle){
	angle = angle/180*3.141592653589793238;
	float rot[] = {
		cos(angle),-sin(angle),0,0,
		sin(angle),cos(angle),0,0,
		0,0,1,0,
		0,0,0,1
	};
	float res[16];
	MatrixMult(rot,mat,res);
	for(int i=0; i<16; i++) mat[i] = res[i];
}

void MatrixIdentity(float *mat)
{
	for(int i=0; i<16; i++) mat[i] = 0;
	for(int i=0; i<4; i++){
		mat[i*4+i] = 1;
	}
}
void MatrixCopy(float *src, float *dest){
	for(int i=0; i<16; i++) dest[i] = src[i];
}

void MatrixTranspose(float *mat)
{
	float temp;
	for(int i=0; i<4; i++){
		for(int j=i+1; j<4; j++){
			temp = mat[i*4+j];
			mat[i*4+j] = mat[j*4+i];
			mat[j*4+i] = temp;
		}
	}
}
void rotateSpecial(){
    float trans[16];
	float temp[16];

	MatrixIdentity(temp);

    MatrixRotateX(temp, 360-prev_rotateX);

    MatrixRotateY(temp, 360-prev_rotateY);

    MatrixRotateZ(temp, 360-prev_rotateZ);
	MatrixMult(matrix,temp,trans);
	MatrixCopy(trans,matrix);
	MatrixTranspose(trans);
    glMultMatrixf(trans);
}
void rotate(){
    float trans[16];
	float temp[16];

	MatrixIdentity(temp);
    if(rotateFlag){
        if(prev_rotateX-rotateX)
            MatrixRotateX(temp, rotateX-prev_rotateX);
	    if(prev_rotateY-rotateY)
            MatrixRotateY(temp, rotateY-prev_rotateY);
        if(prev_rotateZ-rotateZ)
            MatrixRotateZ(temp, rotateZ-prev_rotateZ);
	    MatrixMult(matrix,temp,trans);
	    MatrixCopy(trans,matrix);
	    MatrixTranspose(trans);


        prev_rotateX = rotateX;
        prev_rotateY = rotateY;
        prev_rotateZ = rotateZ;

        glMultMatrixf(trans);
    }else{
        rotateFlag = true;

    }

}





void __fastcall TForm1::init(TObject *Sender){
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.1,0.1,0.1,1.0);
        MatrixIdentity(matrix);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::graphicDraw(TObject *Sender){

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4,4,-4,4,-7.0,7.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if(!singleMode){
        glPushMatrix();

        glViewport(0,0,GLBox1->Width/2,GLBox1->Height/2);

        drawAxis();
        glTranslated(translateX,translateY,translateZ);
        rotate();
        glScaled(scaleX,scaleY,scaleZ);

        drawAxis2();
        colorCube();
        //divideAndDraw(v[0],v[1],v[2],v[3],abs(count));

        glPopMatrix();

        glViewport(0,GLBox1->Height/2,GLBox1->Width/2,GLBox1->Height/2);
        glPushMatrix();
        gluLookAt(0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0);
        drawAxis();
        glTranslated(translateX,translateY,translateZ);
        rotate();
        glScaled(scaleX,scaleY,scaleZ);

        drawAxis2();
        colorCube();

        //divideAndDraw(v[0],v[1],v[2],v[3],abs(count));
        glPopMatrix();
        glViewport(GLBox1->Width/2,0,GLBox1->Width/2,GLBox1->Height/2);
        glPushMatrix();
        gluLookAt(1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0);
        drawAxis();
        glTranslated(translateX,translateY,translateZ);
        rotate();
        glScaled(scaleX,scaleY,scaleZ);

        drawAxis2();
        colorCube();

        //divideAndDraw(v[0],v[1],v[2],v[3],abs(count));

        glPopMatrix();

        glViewport(GLBox1->Width/2,GLBox1->Height/2,GLBox1->Width/2,GLBox1->Height/2);
        glPushMatrix();

        gluLookAt(1,1,1,0.0,0.0,0.0,0.0,1.0,0.0);
        drawAxis();
        glTranslated(translateX,translateY,translateZ);
        rotate();
        glScaled(scaleX,scaleY,scaleZ);


        drawAxis2();
        colorCube();

        //divideAndDraw(v[0],v[1],v[2],v[3],abs(count));

        glPopMatrix();
    }else{
        glViewport(0,0,GLBox1->Width,GLBox1->Height);
        glPushMatrix();


        gluLookAt(1,1,1,0.0,0.0,0.0,0.0,1.0,0.0);
        drawAxis();

        glTranslated(translateX,translateY,translateZ);
        rotate();
        glScaled(scaleX,scaleY,scaleZ);

        drawAxis2();
        colorCube();
        //rotateSpecial();
        //glGetDoublev (GL_MODELVIEW_MATRIX, matrix);

        //divideAndDraw(v[0],v[1],v[2],v[3],abs(count));

        glPopMatrix();
    }
     glFlush();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    GLBox1->Invalidate();
    /*
    if(flag){
        count++;
        if(count>=8)
            flag = !flag;
    }else{
        count--;
        if(count<=0)
            flag = !flag ;
    }*/
}
//---------------------------------------------------------------------------






void __fastcall TForm1::XRotateScrollBarChange(TObject *Sender)
{
    XRotateAmount->Caption = XRotateScrollBar->Position;
    rotateX = XRotateScrollBar->Position;

    GLBox1->Invalidate();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::YRotateScrollBarChange(TObject *Sender)
{
    YRotateAmount->Caption = YRotateScrollBar->Position;
    rotateY = YRotateScrollBar->Position;

    GLBox1->Invalidate();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZRotateScrollBarChange(TObject *Sender)
{
    ZRotateAmount->Caption = ZRotateScrollBar->Position;
    rotateZ = ZRotateScrollBar->Position;

    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::XMoveScrollBarChange(TObject *Sender)
{
    XMoveAmount->Caption = XMoveScrollBar->Position;
    translateX = (double)XMoveScrollBar->Position/100.0;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::YMoveScrollBarChange(TObject *Sender)
{
    YMoveAmount->Caption = YMoveScrollBar->Position;
    translateY = (double)YMoveScrollBar->Position/100.0;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZMoveScrollBarChange(TObject *Sender)
{
    ZMoveAmount->Caption = ZMoveScrollBar->Position;
    translateZ = (double)ZMoveScrollBar->Position/100.0;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::XScaleScrollBarChange(TObject *Sender)
{
    if(!ScaleCheckBox->Checked){
        XScaleAmount->Caption = XScaleScrollBar->Position;
        scaleX = (double)XScaleScrollBar->Position/100.0;
    }else{
        XScaleAmount->Caption = XScaleScrollBar->Position;
        YScaleAmount->Caption = XScaleScrollBar->Position;
        ZScaleAmount->Caption = XScaleScrollBar->Position;
        //YScaleScrollBar->Position = XScaleScrollBar->Position;
        //ZScaleScrollBar->Position = XScaleScrollBar->Position;
        scaleZ = scaleY = scaleX = (double)XScaleScrollBar->Position/100.0;
    }
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::YScaleScrollBarChange(TObject *Sender)
{
    YScaleAmount->Caption = YScaleScrollBar->Position;
    scaleY = (double)YScaleScrollBar->Position/100.0;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZScaleScrollBarChange(TObject *Sender)
{
    ZScaleAmount->Caption = ZScaleScrollBar->Position;
    scaleZ = (double)ZScaleScrollBar->Position/100.0;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetRotateButtonClick(TObject *Sender)
{
    rotateSpecial();
    prev_rotateX = 0;
    prev_rotateY = 0;
    prev_rotateZ = 0;

    rotateFlag = false;
    XRotateScrollBar->Position = 0;
    YRotateScrollBar->Position = 0;
    ZRotateScrollBar->Position = 0;
    rotateX = 0;
    rotateY = 0;
    rotateZ = 0;
    MatrixIdentity(matrix);
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetMoveButtonClick(TObject *Sender)
{
    XMoveScrollBar->Position = 0;
    YMoveScrollBar->Position = 0;
    ZMoveScrollBar->Position = 0;
    XMoveScrollBarChange(Sender);
    YMoveScrollBarChange(Sender);
    ZMoveScrollBarChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetScaleGroupClick(TObject *Sender)
{
    XScaleScrollBar->Position = 100;
    YScaleScrollBar->Position = 100;
    ZScaleScrollBar->Position = 100;
    XScaleScrollBarChange(Sender);
    YScaleScrollBarChange(Sender);
    ZScaleScrollBarChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChangeSingleMode(TObject *Sender)
{
    singleMode = true;
    GLBox1->Invalidate();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChangeMultiMode(TObject *Sender)
{
    singleMode = false;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::checkScale(TObject *Sender)
{
    if(ScaleCheckBox->Checked){
        YScaleScrollBar->Enabled = false;
        ZScaleScrollBar->Enabled = false;
        int temp = XScaleScrollBar->Position;
        //YScaleScrollBar->Position = temp;
        //ZScaleScrollBar->Position = temp;
        scaleZ = scaleY = scaleX;
        YScaleAmount->Caption = temp;
        ZScaleAmount->Caption = temp;
    }else{
        YScaleScrollBar->Enabled = true;
        ZScaleScrollBar->Enabled = true;
        YScaleAmount->Caption = YScaleScrollBar->Position;
        ZScaleAmount->Caption = ZScaleScrollBar->Position;
        scaleY = (double)YScaleScrollBar->Position/100.0;
        scaleZ = (double)ZScaleScrollBar->Position/100.0;
    }
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

