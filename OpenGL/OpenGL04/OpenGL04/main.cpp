#include <OpenGL/glut.h>

int WindowPositionX = 100;  //��������E�B���h�E�ʒu��X���W
int WindowPositionY = 100;  //��������E�B���h�E�ʒu��Y���W
int WindowWidth = 512;    //��������E�B���h�E�̕�
int WindowHeight = 512;    //��������E�B���h�E�̍���
char WindowTitle[] = "���E�̎n�܂�";  //�E�B���h�E�̃^�C�g��

//----------------------------------------------------
// �����̂̒�`
//----------------------------------------------------
GLdouble vertex[][3] = {
  { 0.0, 0.0, 0.0 },
  { 2.0, 0.0, 0.0 },
  { 2.0, 2.0, 0.0 },
  { 0.0, 2.0, 0.0 },
  { 0.0, 0.0, 30.0 },
  { 2.0, 0.0, 30.0 },
  { 2.0, 2.0, 30.0 },
  { 0.0, 2.0, 30.0 }
};
int face[][4] = {//�ʂ̒�`
  { 0, 1, 2, 3 },
  { 1, 5, 6, 2 },
  { 5, 4, 7, 6 },
  { 4, 0, 3, 7 },
  { 4, 5, 1, 0 },
  { 3, 2, 6, 7 }
};
GLdouble normal[][3] = {//�ʂ̖@���x�N�g��
  { 0.0, 0.0,-1.0 },
  { 1.0, 0.0, 0.0 },
  { 0.0, 0.0, 1.0 },
  {-1.0, 0.0, 0.0 },
  { 0.0,-1.0, 0.0 },
  { 0.0, 1.0, 0.0 }
};
//----------------------------------------------------
// ���������̒�`
//----------------------------------------------------
struct MaterialStruct {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess;
};
//jade(�Ő�)
MaterialStruct ms_jade = {
  {0.135,     0.2225,   0.1575,   1.0},
  {0.54,      0.89,     0.63,     1.0},
  {0.316228,  0.316228, 0.316228, 1.0},
  12.8 };
//ruby(���r�[)
MaterialStruct ms_ruby = {
  {0.1745,   0.01175,  0.01175,   1.0},
  {0.61424,  0.04136,  0.04136,   1.0},
  {0.727811, 0.626959, 0.626959,  1.0},
  76.8 };
//----------------------------------------------------
// �F�̒�`�̒�`
//----------------------------------------------------
GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 }; //�ԐF
GLfloat green[] = { 0.2, 0.8, 0.2, 1.0 };//�ΐF
GLfloat blue[] = { 0.2, 0.2, 0.8, 1.0 };//�F
GLfloat yellow[] = { 0.8, 0.8, 0.2, 1.0 };//���F
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };//���F
GLfloat shininess = 30.0;//����̋���
//-----------------------------------------

//----------------------------------------------------
// �֐��v���g�^�C�v�i��ɌĂяo���֐����ƈ����̐錾�j
//----------------------------------------------------
void Initialize(void);
void Display(void);
void Ground(void);  //��n�̕`��
//----------------------------------------------------
// ���C���֐�
//----------------------------------------------------
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);//���̏�����
    glutInitWindowPosition(WindowPositionX, WindowPositionY);//�E�B���h�E�̈ʒu�̎w��
    glutInitWindowSize(WindowWidth, WindowHeight); //�E�B���h�E�T�C�Y�̎w��
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);//�f�B�X�v���C���[�h�̎w��
    glutCreateWindow(WindowTitle);  //�E�B���h�E�̍쐬
    glutDisplayFunc(Display); //�`�掞�ɌĂяo�����֐����w�肷��i�֐����FDisplay�j
    Initialize(); //�����ݒ�̊֐����Ăяo��
    glutMainLoop();
    return 0;
}
//----------------------------------------------------
// �����ݒ�̊֐�
//----------------------------------------------------
void Initialize(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0); //�w�i�F
    glEnable(GL_DEPTH_TEST);//�f�v�X�o�b�t�@���g�p�FglutInitDisplayMode() �� GLUT_DEPTH ���w�肷��

    //�����̐ݒ�--------------------------------------
    GLfloat light_position0[] = { -50.0, -50.0, 20.0, 1.0 }; //����0�̍��W
    glLightfv(GL_LIGHT0, GL_POSITION, light_position0); //����0��

    //�����ϊ��s��̐ݒ�------------------------------
    glMatrixMode(GL_PROJECTION);//�s�񃂁[�h�̐ݒ�iGL_PROJECTION : �����ϊ��s��̐ݒ�AGL_MODELVIEW�F���f���r���[�ϊ��s��j
    glLoadIdentity();//�s��̏�����
    gluPerspective(30.0, (double)WindowWidth / (double)WindowHeight, 0.1, 1000.0); //�������e�@�̎��̐�gluPerspactive(th, w/h, near, far);

    //���_�̐ݒ�------------------------------
    gluLookAt(
        0.0, -100.0, 50.0, // ���_�̈ʒux,y,z;
        0.0, 100.0, 0.0,   // ���E�̒��S�ʒu�̎Q�Ɠ_���Wx,y,z
        0.0, 0.0, 1.0);  //���E�̏�����̃x�N�g��x,y,z
   //----------------------------------------
}
//----------------------------------------------------
// �`��̊֐�
//----------------------------------------------------
void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�o�b�t�@�̏���

    //���f���r���[�ϊ��s��̐ݒ�--------------------------
    glMatrixMode(GL_MODELVIEW);//�s�񃂁[�h�̐ݒ�iGL_PROJECTION : �����ϊ��s��̐ݒ�AGL_MODELVIEW�F���f���r���[�ϊ��s��j
    glLoadIdentity();//�s��̏�����
    glViewport(0, 0, WindowWidth, WindowHeight);
    //----------------------------------------------

    //�A�eON-----------------------------
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);//����0�𗘗p
    //-----------------------------------

    //��
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, ms_ruby.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ms_ruby.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ms_ruby.specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, &ms_ruby.shininess);
    glTranslated(0.0, 10.0, 20.0);//���s�ړ��l�̐ݒ�
    glutSolidSphere(4.0, 20, 20);//�����F(���a, Z���܂��̕�����, Z���ɉ�����������)
    glPopMatrix();

    //������
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
    glTranslated(-20.0, 0.0, 20.0);//���s�ړ��l�̐ݒ�
    glutSolidCube(10.0);//�����F(��ӂ̒���)
    glPopMatrix();

    //�~��
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    glTranslated(20.0, 100.0, 0.0);//���s�ړ��l�̐ݒ�
    glutSolidCone(5.0, 10.0, 20, 20);//�����F(���a, ����, Z���܂��̕�����, Z���ɉ�����������)
    glPopMatrix();

    //������
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, ms_jade.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ms_jade.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ms_jade.specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, &ms_jade.shininess);
    glTranslated(30.0, 50.0, 0.0);//���s�ړ��l�̐ݒ�
    glBegin(GL_QUADS);
    for (int j = 0; j < 6; ++j) {
        glNormal3dv(normal[j]); //�@���x�N�g���̎w��
        for (int i = 0; i < 4; ++i) {
            glVertex3dv(vertex[face[j][i]]);
        }
    }
    glEnd();
    glPopMatrix();

    //�A�eOFF-----------------------------
    glDisable(GL_LIGHTING);
    //-----------------------------------

    Ground();

    glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)�Ń_�u���o�b�t�@�����O�𗘗p��
}
//----------------------------------------------------
// ��n�̕`��
//----------------------------------------------------
void Ground(void) {
    double ground_max_x = 300.0;
    double ground_max_y = 300.0;
    glColor3d(0.8, 0.8, 0.8);  // ��n�̐F
    glBegin(GL_LINES);
    for (double ly = -ground_max_y; ly <= ground_max_y; ly += 10.0) {
        glVertex3d(-ground_max_x, ly, 0);
        glVertex3d(ground_max_x, ly, 0);
    }
    for (double lx = -ground_max_x; lx <= ground_max_x; lx += 10.0) {
        glVertex3d(lx, ground_max_y, 0);
        glVertex3d(lx, -ground_max_y, 0);
    }
    glEnd();
}