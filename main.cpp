
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <GL/glu.h>



using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1600,900), "SFML OpenGL");
    Texture back;
    back.loadFromFile("resources/1.jpg");
    Sprite background(back);

    GLuint texture = 0;
    {
        Image image;
        image.loadFromFile("resources/2.jpg");
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.getSize().x, image.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    }
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClearDepth(1.f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f,1.f,1.f,500.f);

    Clock clock1;

    while(window.isOpen()){
        Event event1;
        while(window.pollEvent(event1)){
            if(event1.type==Event::Closed){
                window.close();
            }
        }
        float time = clock1.getElapsedTime().asSeconds()*100;
        float size = 20.f;

        window.pushGLStates();
        window.draw(background);
        window.popGLStates();

        glClear(GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0,0,-100);
        glRotatef(time, 50,50,0);

        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);

            glTexCoord2f(0, 0); glVertex3d(-size, -size, -size);
            glTexCoord2f(1, 0); glVertex3d(size, -size, -size);
            glTexCoord2f(1, 1); glVertex3d(size, size, -size);
            glTexCoord2f(0, 1); glVertex3d(-size, size, -size);

            glTexCoord2f(0, 0); glVertex3d(size, -size, size);
            glTexCoord2f(1, 0); glVertex3d(-size, -size, size);
            glTexCoord2f(1, 1); glVertex3d(-size, size, size);
            glTexCoord2f(0, 1); glVertex3d(size, size, size);

            glTexCoord2f(0, 0); glVertex3d(-size, -size, size);
            glTexCoord2f(1, 0); glVertex3d(-size, -size, -size);
            glTexCoord2f(1, 1); glVertex3d(-size, size, -size);
            glTexCoord2f(0, 1); glVertex3d(-size, size, size);

            glTexCoord2f(0, 0); glVertex3d(size, -size, -size);
            glTexCoord2f(1, 0); glVertex3d(size, -size, size);
            glTexCoord2f(1, 1); glVertex3d(size, size, size);
            glTexCoord2f(0, 1); glVertex3d(size, size, -size);

            glTexCoord2f(0, 0); glVertex3d(-size, -size, size);
            glTexCoord2f(1, 0); glVertex3d(size, -size, size);
            glTexCoord2f(1, 1); glVertex3d(size, -size, -size);
            glTexCoord2f(0, 1); glVertex3d(-size, -size, -size);

            glTexCoord2f(0, 0); glVertex3d(-size, size, -size);
            glTexCoord2f(1, 0); glVertex3d(size, size, -size);
            glTexCoord2f(1, 1); glVertex3d(size, size, size);
            glTexCoord2f(0, 1); glVertex3d(-size, size, size);


        glEnd();

        window.display();

    }

    glDeleteTextures(1, &texture);



    return 0;
}