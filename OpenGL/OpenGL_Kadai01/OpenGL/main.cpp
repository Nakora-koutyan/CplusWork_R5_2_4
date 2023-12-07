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

    gluPerspective(30.0, (double)WindowWidth / (double)WindowHeight, 0.1, 1000.0); //�������e�@�̎��̐�gluPerspactive(th, w/h, near, far);

    gluLookAt(
        0.0, -100.0, 50.0, // ���_�̈ʒux,y,z;
        0.0, 100.0, 0.0,   // ���E�̒��S�ʒu�̎Q�Ɠ_���Wx,y,z
        0.0, 0.0, 1.0);  //���E�̏�����̃x�N�g��x,y,z
}
//----------------------------------------------------
// �`��̊֐�
//----------------------------------------------------
void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�o�b�t�@�̏���

    //��
    glPushMatrix();
    glColor3d(1.0, 0.0, 0.0); //�F�̐ݒ�
    glTranslated(0.0, 10.0, 20.0);//���s�ړ��l�̐ݒ�
    glutSolidSphere(4.0, 20, 20);//�����F(���a, Z���܂��̕�����, Z���ɉ�����������)
    glPopMatrix();

    //������
    glPushMatrix();
    glColor3d(0.0, 1.0, 0.0);//�F�̐ݒ�
    glTranslated(-20.0, 0.0, 20.0);//���s�ړ��l�̐ݒ�
    glutSolidCube(10.0);//�����F(��ӂ̒���)
    glPopMatrix();

    //�~��
    glPushMatrix();
    glColor3d(0.0, 0.0, 1.0);//�F�̐ݒ�
    glTranslated(20.0, 100.0, 0.0);//���s�ړ��l�̐ݒ�
    glutSolidCone(5.0, 10.0, 20, 20);//�����F(���a, ����, Z���܂��̕�����, Z���ɉ�����������)
    glPopMatrix();

    //������
    glPushMatrix();
    glColor3d(0.0, 1.0, 1.0);//�F�̐ݒ�
    glTranslated(30.0, 50.0, 0.0);//���s�ړ��l�̐ݒ�
    glBegin(GL_QUADS);
    for (int j = 0; j < 6; ++j) {
        for (int i = 0; i < 4; ++i) {
            //12�s�ڂœǂݍ��񂾏������ɐ}�`���\�z
            glVertex3dv(vertex[face[j][i]]);
        }
    }
    glEnd();
    glPopMatrix();

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