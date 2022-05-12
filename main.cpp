#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <windef.h>
#include <winuser.h>
#include <wingdi.h>


using namespace std;
using namespace sf;

int main()
{
        RenderWindow win(VideoMode::getDesktopMode(),"Hello SFML",Style::Fullscreen); //создаем полноэкранный режим

        Image myAs,myAs2,myKn,myKn2,ar,hp,port,play,title,exit,ctitle,play2,mons,oruzh,oruzh2,mons2,mech,playP,exitP; //задаем имя картинки
    HDC hDCScreen =  GetDC(NULL);
    double sx = GetDeviceCaps(hDCScreen,  HORZRES);
    double sy = GetDeviceCaps(hDCScreen,  VERTRES);
    ReleaseDC(NULL, hDCScreen);

        myAs.loadFromFile("Assasin2.png");
        myAs.createMaskFromColor(Color(255,255,255));  //присваиваем картинку

        myAs2.loadFromFile("Assasin3.png");
        myAs2.createMaskFromColor(Color(255,255,255));

        myKn.loadFromFile("Knight.png");
        myKn.createMaskFromColor(Color(255,255,255));

        myKn2.loadFromFile("Knight2.png");
        myKn2.createMaskFromColor(Color(255,255,255));

        title.loadFromFile("Title.png");
        title.createMaskFromColor(Color(255,255,255));

        ctitle.loadFromFile("ChTitle.png");
        ctitle.createMaskFromColor(Color(255,255,255));

        ar.loadFromFile("Arm.png");
        ar.createMaskFromColor(Color(255,255,255));

        hp.loadFromFile("HP.png");
        hp.createMaskFromColor(Color(255,255,255));

        mons.loadFromFile("monster.png");
        mons.createMaskFromColor(Color(255,255,255));

        mons2.loadFromFile("mmonster.png");
        mons2.createMaskFromColor(Color(255,255,255));
        ///Color::White
        port.loadFromFile("portal.png");
        port.createMaskFromColor(Color(255,255,255));

        play.loadFromFile("ButPlay.png");
        play.createMaskFromColor(Color(255,255,255));

        playP.loadFromFile("ButPlay2.png");
        playP.createMaskFromColor(Color(255,255,255));

        play2.loadFromFile("Play.png");
        play2.createMaskFromColor(Color(255,255,255));

        exit.loadFromFile("ButExit.png");
        exit.createMaskFromColor(Color(255,255,255));

        exitP.loadFromFile("ButExit2.png");
        exitP.createMaskFromColor(Color(255,255,255));

        oruzh.loadFromFile("lightY.png");
        oruzh.createMaskFromColor(Color(255,255,255));

        oruzh2.loadFromFile("lightY2.png");
        oruzh2.createMaskFromColor(Color(255,255,255));

        Texture Mytex;
        Mytex.loadFromImage(myAs);   //задаем текстуры ассасина
        Texture Mytex2;
        Mytex2.loadFromImage(myAs2);
        Sprite Myspr;
        Myspr.setTexture(Mytex);
        Myspr.setScale(2,2);
        Myspr.setPosition(550,345);
        Vector2f p2(Myspr.getGlobalBounds().width/2,Myspr.getGlobalBounds().height/2);
        bool Left=false,Right=false,Up=false,Down=false,Escape=false,Space=false,Mouse=false,razbl=false,zabl=false,razabl=false,rzabl=false,nestena=true,pisr=true,pisl=false,sim=true,sim2=false;   //создаем переменные типа bool

        Texture Kn;
        Kn.loadFromImage(myKn);
        Texture Kn2;
        Kn2.loadFromImage(myKn2);  //задаем текстуры рыцаря
        Sprite Knspr;
        Knspr.setTexture(Kn);
        Knspr.setScale(2,2);
        Knspr.setPosition(550,345);
        Vector2f p3(Knspr.getGlobalBounds().width/2,Knspr.getGlobalBounds().height/2);

        Texture mon;
        mon.loadFromImage(mons);
        Texture mmonster;
        mmonster.loadFromImage(mons2);  //задаем текстуры монстра
        Sprite monspr;
        monspr.setTexture(mon);
        monspr.setScale(2,2);
        monspr.setPosition(400,600);
        Vector2f p4(monspr.getGlobalBounds().width/2,monspr.getGlobalBounds().height/2);

        Texture MyNE;
        MyNE.loadFromImage(title);  //задаем текстуры начального экрана
        Sprite SprNE;
        SprNE.setTexture(MyNE);
        SprNE.setScale(sx/1366,sy/768);
        Vector2f p5(SprNE.getGlobalBounds().width/2,SprNE.getGlobalBounds().height/2);

        Texture Choose;
        Choose.loadFromImage(ctitle);   //задаем текстуры экрана выбора
        Sprite SprCh;
        SprCh.setTexture(Choose);
        SprCh.setScale(sx/1366,sy/768);
        Vector2f p6(SprCh.getGlobalBounds().width/2,SprCh.getGlobalBounds().height/2);

        Texture Myar;
        Myar.loadFromImage(ar);   //задаем текстуры  щитов
        Sprite sprar;
        sprar.setTexture(Myar);
        sprar.setPosition(5,36);
        Vector2f p7(sprar.getGlobalBounds().width/2,sprar.getGlobalBounds().height/2);

        Sprite sprar2;
        sprar2.setTexture(Myar);
        sprar2.setPosition(40,36);
        Vector2f p8(sprar2.getGlobalBounds().width/2,sprar2.getGlobalBounds().height/2);

        Sprite sprar3;
        sprar3.setTexture(Myar);
        sprar3.setPosition(75,36);
        Vector2f p9(sprar3.getGlobalBounds().width/2,sprar3.getGlobalBounds().height/2);

        Sprite sprar4;
        sprar4.setTexture(Myar);
        sprar4.setPosition(110,36);
        Vector2f p10(sprar4.getGlobalBounds().width/2,sprar4.getGlobalBounds().height/2);

        Sprite sprar5;
        sprar5.setTexture(Myar);
        sprar5.setPosition(145,36);
        Vector2f p11(sprar5.getGlobalBounds().width/2,sprar5.getGlobalBounds().height/2);

        Texture Myhp;
        Myhp.loadFromImage(hp);   //задаем текстуры  жизней
        Sprite sprhp1;
        sprhp1.setTexture(Myhp);
        sprhp1.setPosition(4,4);
        Vector2f p12(sprhp1.getGlobalBounds().width/2,sprhp1.getGlobalBounds().height/2);

        Sprite sprhp2;
        sprhp2.setTexture(Myhp);
        sprhp2.setPosition(38,4);
        Vector2f p13(sprhp2.getGlobalBounds().width/2,sprhp2.getGlobalBounds().height/2);

        Sprite sprhp3;
        sprhp3.setTexture(Myhp);
        sprhp3.setPosition(72,4);
        Vector2f p14(sprhp3.getGlobalBounds().width/2,sprhp3.getGlobalBounds().height/2);

        Sprite sprhp4;
        sprhp4.setTexture(Myhp);
        sprhp4.setPosition(106,4);
        Vector2f p15(sprhp4.getGlobalBounds().width/2,sprhp4.getGlobalBounds().height/2);

        Sprite sprhp5;
        sprhp5.setTexture(Myhp);
        sprhp5.setPosition(140,4);
        Vector2f p16(sprhp5.getGlobalBounds().width/2,sprhp5.getGlobalBounds().height/2);

        Sprite sprhp6;
        sprhp6.setTexture(Myhp);
        sprhp6.setPosition(174,4);
        Vector2f p22(sprhp6.getGlobalBounds().width/2,sprhp6.getGlobalBounds().height/2);

        Texture Myport;
        Myport.loadFromImage(port);  //задаем текстуры  портала
        Sprite sprport;
        sprport.setTexture(Myport);
        sprport.setScale(1.5,1.5);
        sprport.setPosition(400,570);
        Vector2f p17(sprport.getGlobalBounds().width/2,sprport.getGlobalBounds().height/2);

        Texture ButP;
        ButP.loadFromImage(play);  //задаем текстуры кнопки играть
        Texture ButP2;
        ButP2.loadFromImage(playP);
        Sprite sprplay;
        sprplay.setTexture(ButP);
        sprplay.setPosition(599*sx/1366,357*sy/768);
        sprplay.setScale(sx/1366,sy/768);
        Vector2f p18(sprplay.getGlobalBounds().width/2,sprplay.getGlobalBounds().height/2);

        Texture Bplay;
        Bplay.loadFromImage(play2);  //задаем текстуры кнопки play
        Sprite play1;
        play1.setTexture(Bplay);
        play1.setPosition(269*sx/1366,638*sy/768);
        play1.setScale(sx*2/1366,sy*2/768);
        Vector2f p19(play1.getGlobalBounds().width/2,play1.getGlobalBounds().height/2);

        Sprite play3;
        play3.setTexture(Bplay);
        play3.setPosition(979*sx/1366,638*sy/768);
        play3.setScale(sx*2/1366,sy*2/768);
        Vector2f p20(play3.getGlobalBounds().width/2,play3.getGlobalBounds().height/2);

        Texture ButE;
        ButE.loadFromImage(exit);  //задаем текстуры кнопки выход
        Texture ButE2;
        ButE2.loadFromImage(exitP);
        Sprite sprexit;
        sprexit.setTexture(ButE);
        sprexit.setPosition(599*sx/1366,448*sy/768);
        sprexit.setScale(sx/1366,sy/768);
        Vector2f p21(sprexit.getGlobalBounds().width/2,sprexit.getGlobalBounds().height/2);

        Texture Orughie;
        Orughie.loadFromImage(oruzh);   //задаем текстуры оружия
        Texture Orughie2;
        Orughie2.loadFromImage(oruzh2);
        Sprite Oruzhka;
        Oruzhka.setTexture(Orughie2);
        Oruzhka.setScale(2,2);
        Oruzhka.setOrigin(1,1);
        Oruzhka.setPosition(590,375);
        Vector2f p23(Oruzhka.getGlobalBounds().width/2,Oruzhka.getGlobalBounds().height/2);

        Clock timer; //создание таймера

        while (win.isOpen())   //комманды которые выполняются пока окно открыто
        {
            monspr.rotate(1);  //вращение монстра
            Time deltaTime=timer.getElapsedTime();   //таймер тикает
            timer.restart(); //рестарт таймера
            Event event;  //создаем событие с именем event
            while(win.pollEvent(event))   //пока выполняется событие
            {
                if (event.type==Event::Closed)  //если поступает сигнал, что окно закрывается мы его закрываем
                {
                    win.close();
                }
                if (event.type==Event::KeyPressed) //если посупил сигнал, что клавиша нажата
                {
                    switch(event.key.code) //узнаем какая клавиша нажата
                    {
                        case Keyboard::Up: //клавиша вверх нажата
                            Up=true;
                            break;
                        case Keyboard::Down: //клавиша вниз нажата
                            Down=true;
                            break;
                        case Keyboard::Left: //клавиша влево нажата
                            Left=true;
                            break;
                        case Keyboard::Right: //клавиша вправо нажата
                            Right=true;
                            break;
                        case Keyboard::W: //клавиша вверх нажата
                            Up=true;
                            break;
                        case Keyboard::S: //клавиша вниз нажата
                            Down=true;
                            break;
                        case Keyboard::A: //клавиша влево нажата
                            Left=true;
                            break;
                        case Keyboard::D: //клавиша вправо нажата
                            Right=true;
                            break;
                        case Keyboard::Escape: //клавиша esc нажата
                            Escape=true;
                            break;
                        case Keyboard::Space: //клавиша пробел нажата
                            Space=true;
                            break;

                    }
                }
                if (event.type==Event::KeyReleased) //если поступил сигнал, что клавиша отжата
                {
                    switch(event.key.code) //какая клавиша отжата
                    {
                        case Keyboard::W: //клавиша вверх отжата
                            Up=false;
                            break;
                        case Keyboard::S: //клавиша вниз отжата
                            Down=false;
                            break;
                        case Keyboard::A: //клавиша влево отжата
                            Left=false;
                            break;
                        case Keyboard::D: //клавиша вправо отжата
                            Right=false;
                            break;
                        case Keyboard::Up: //клавиша вверх отжата
                            Up=false;
                            break;
                        case Keyboard::Down: //клавиша вниз отжата
                            Down=false;
                            break;
                        case Keyboard::Left: //клавиша влево отжата
                            Left=false;
                            break;
                        case Keyboard::Right: //клавиша вправо отжата
                            Right=false;
                            break;
                        case Keyboard::Escape: //клавиша esc отжата
                            Escape=false;
                            break;
                        case Keyboard::Space: //клавиша пробел отжата
                            Space=false;
                            break;
                    }
                }
                if(sprplay.getGlobalBounds().contains(Mouse::getPosition().x,Mouse::getPosition().y)) //если кнопка играть соединяется с курсором мыши
                {
                    sprplay.setTexture(ButP2);
                } else {
                    sprplay.setTexture(ButP);
                }
                if(sprexit.getGlobalBounds().contains(Mouse::getPosition().x,Mouse::getPosition().y)) //если кнопка играть соединяется с курсором мыши
                {
                    sprexit.setTexture(ButE2);
                } else {
                    sprexit.setTexture(ButE);
                }
                if (event.type==Event::MouseButtonPressed) //если кнопка мыши нажата
                {
                    if(sprplay.getGlobalBounds().contains(Mouse::getPosition().x,Mouse::getPosition().y)) //если кнопка играть соединяется с курсором мыши
                    {
                        Mouse=true;
                        razbl=true;
                        sprexit.setPosition(5000,5000);
                        sprplay.setPosition(5000,5000);
                    }
                    else if(sprexit.getGlobalBounds().contains(Mouse::getPosition().x,Mouse::getPosition().y)) //если кнопка выхода соединяется с курсором мыши
                    {
                        zabl=true;
                    }
                    if(play1.getGlobalBounds().contains(Mouse::getPosition().x,Mouse::getPosition().y)) //если кнопка выбора №1 соединяется с курсором мыши
                    {
                        razabl=true;
                        play1.setPosition(5000,5000);
                        play3.setPosition(5000,5000);
                    }
                    else if(play3.getGlobalBounds().contains(Mouse::getPosition().x,Mouse::getPosition().y)) //если кнопка выбора №2 соединяется с курсором мыши
                    {
                        rzabl=true;
                        play1.setPosition(5000,5000);
                        play3.setPosition(5000,5000);
                    }
                }
                if(sprport.getGlobalBounds().intersects(Myspr.getGlobalBounds())&&Space) //если портал пересекается с героем и пробел нажат
                {
                    win.clear(Color::Green);
                    cout<<"You have won the game!!!"<<endl;
                    win.close();
                }
                if(sprport.getGlobalBounds().intersects(Knspr.getGlobalBounds())&&Space) //если портал пересекается с героем и пробел нажат
                {
                    win.clear(Color::Green);
                    cout<<"You have won the game!!!"<<endl;
                    win.close();
                }
                if(monspr.getGlobalBounds().intersects(Knspr.getGlobalBounds())) //если монстр пересекается с героем
                {
                    Knspr.setPosition(550,345);
                    Knspr.setTexture(Kn);
                    Oruzhka.setPosition(555,375);
                }
                if(monspr.getGlobalBounds().intersects(Myspr.getGlobalBounds())) //если монстр пересекается с героем
                {
                    Myspr.setPosition(550,345);
                    Myspr.setTexture(Mytex);
                    Oruzhka.setPosition(555,375);
                }
                if(monspr.getGlobalBounds().intersects(Oruzhka.getGlobalBounds())&&Space) //если монстр пересекается с оружием
                {
                    monspr.setTexture(mmonster);
                    monspr.setPosition(5000,5000);
                }
            }

            if(Escape)  //если нажат esc
            {
                win.close();
            }
            double x=Mouse::getPosition().x;
            double y=Mouse::getPosition().y;
            win.clear(Color::White);
            win.draw(SprNE);
            win.draw(sprplay);
            win.draw(sprexit);
            double angle = atan2(Oruzhka.getPosition().x - x,Oruzhka.getPosition().y - y)*(180/3.1416);
            double angle2 = atan2(-Oruzhka.getPosition().x + x,Oruzhka.getPosition().y - y)*(180/3.1416);
            if(razbl==true) //если переменная является правдой(true)
            {
                win.clear(Color::White);
                win.draw(SprCh);
                win.draw(play1);
                win.draw(play3);
                if(razabl==true) //если переменная является правдой
                {
                    win.clear(Color::White);
                    monspr.rotate(1.2);
                    win.draw(sprport);
                    win.draw(sprar);
                    win.draw(monspr);
                    win.draw(sprar2);
                    win.draw(sprar3);
                    win.draw(sprar4);
                    win.draw(sprhp1);
                    win.draw(sprhp2);
                    win.draw(sprhp3);
                    win.draw(sprhp4);
                    win.draw(Myspr);
                    win.draw(Oruzhka);
                    if(pisr)
                    {
                        Oruzhka.setRotation(-angle - 90);
                    }
                    if(pisl)
                    {
                        Oruzhka.setRotation(angle2+90);
                    }
                    if(Up&&Myspr.getPosition().y>5)
                    {
                        Myspr.move(0,-150 * deltaTime.asSeconds());
                        Oruzhka.move(0,-150 * deltaTime.asSeconds());
                    }
                    if(Down&&Myspr.getPosition().y<sy-50)
                    {
                        Myspr.move(0,150 * deltaTime.asSeconds());
                        Oruzhka.move(0,150 * deltaTime.asSeconds());
                    }
                    if(Left&&Myspr.getPosition().x>0)
                    {
                        Myspr.move(-150 * deltaTime.asSeconds(),0);
                        Myspr.setTexture(Mytex2);
                        Oruzhka.setTexture(Orughie);
                        Oruzhka.setOrigin(25,5);
                        if(sim)
                        {
                            Oruzhka.move(-37,0);
                            sim=false;
                        }
                        Oruzhka.move(-150 * deltaTime.asSeconds(),0);
                        sim2=true;
                        pisl=true;
                        pisr=false;

                    }
                    if(Right&&Myspr.getPosition().x<sx-50)
                    {
                        Myspr.move(150 * deltaTime.asSeconds(),0);
                        Myspr.setTexture(Mytex);
                        Oruzhka.setTexture(Orughie2);
                        Oruzhka.setOrigin(0,0);
                        Oruzhka.setRotation(-angle - 90);
                        if(sim2)
                        {
                            Oruzhka.move(37,0);
                            sim2=false;
                        }

                        Oruzhka.move(150 * deltaTime.asSeconds(),0);
                        sim=true;
                        pisr=true;
                        pisl=false;
                    }
                }

                if(rzabl==true)
                {
                    win.clear(Color::White);
                    win.draw(sprport);
                    win.draw(monspr);
                    win.draw(sprhp1);
                    win.draw(sprhp2);
                    win.draw(sprhp3);
                    win.draw(sprhp4);
                    win.draw(sprhp5);
                    win.draw(sprhp6);
                    win.draw(sprar);
                    win.draw(sprar2);
                    win.draw(sprar3);
                    win.draw(sprar4);
                    win.draw(sprar5);
                    win.draw(Knspr);
                    win.draw(Oruzhka);
                    if(pisr)
                    {
                        Oruzhka.setRotation(-angle - 90);
                    }
                    if(pisl)
                    {
                        Oruzhka.setRotation(angle2+90);
                    }
                    if(Up&&Knspr.getPosition().y>5)
                    {
                        Knspr.move(0,-90 * deltaTime.asSeconds());
                        Oruzhka.move(0,-90 * deltaTime.asSeconds());
                    }
                    if(Down&&Knspr.getPosition().y<sy-50)
                    {
                        Knspr.move(0,90 * deltaTime.asSeconds());
                        Oruzhka.move(0,90 * deltaTime.asSeconds());
                    }
                    if(Left&&Knspr.getPosition().x>0)
                    {
                        Knspr.move(-90 * deltaTime.asSeconds(),0);
                        Knspr.setTexture(Kn2);
                        Oruzhka.setTexture(Orughie);
                        Oruzhka.setOrigin(25,5);
                        if(sim)
                        {
                            Oruzhka.move(-37,0);
                            sim=false;
                        }
                        Oruzhka.move(-90 * deltaTime.asSeconds(),0);
                        sim2=true;
                        pisl=true;
                        pisr=false;

                    }
                    if(Right&&Knspr.getPosition().x<sx-50)
                    {
                        Knspr.move(90 * deltaTime.asSeconds(),0);
                        Knspr.setTexture(Kn);
                        Oruzhka.setTexture(Orughie2);
                        Oruzhka.setOrigin(1,1);
                        Oruzhka.setRotation(-angle - 90);
                        if(sim2)
                        {
                            Oruzhka.move(37,0);
                            sim2=false;
                        }

                        Oruzhka.move(90 * deltaTime.asSeconds(),0);
                        sim=true;
                        pisr=true;
                        pisl=false;
                    }
                }
            }
            else if(sprexit.getGlobalBounds().contains(Mouse::getPosition().x,Mouse::getPosition().y)&&Mouse)
            {
                zabl=true;
            }
            if(zabl==true)
            {
                win.close();
            }
            win.display();

        }
        return 0;
}
