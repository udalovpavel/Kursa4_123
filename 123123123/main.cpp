#include <SFML/Graphics.hpp>

using namespace sf;




int main()
{
    int i, j, temp; // задание типов данных
    int b[5]; 
    bool flag;
    int a[5], post = 0, n;
    srand(time(0));
    for (int i = 0; i < 5; i++) { a[i] = rand() % 5; } // гереация массива 
    while (true) { // удаление одинаковых элементов
        flag = true;
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 5; j++)
            {
                if (a[i] == a[j])
                {
                    a[i] = rand() % 5;
                    flag = false;
                }
            }
        if (flag)
            break;
    }
    for (i = 0; i < 5; i++) // копирование массива
        b[i] = a[i];



    sf::Font font; // установка шрифта в программе
    if (!font.loadFromFile("arialmt.ttf"))
    {
        //=(
    }
    RenderWindow window(VideoMode(800, 800), L"Новый проект", Style::Default); // создание окна

    window.setVerticalSyncEnabled(true); // установка вертикальной синзронизации по умлочанию

    RectangleShape robot(sf::Vector2f(100, 50)); // создание робота
    CircleShape item_1(50); // создание кругов
    CircleShape item_2(50);
    CircleShape item_3(50);
    CircleShape item_4(50);
    CircleShape item_5(50);
    robot.setPosition(350, 600); // установка позиции робота на экране
    //   int random = rand() % 10;
    item_1.setPosition(80, 100); // установка позиции кругов на экране
    item_2.setPosition(200, 100);
    item_3.setPosition(320, 100);
    item_5.setPosition(560, 100);
    item_4.setPosition(440, 100);
    robot.setFillColor(Color::Magenta);

    sf::Text text_1; // создание цифр
    text_1.setFont(font); // шрифт текста
    text_1.setString(std::to_string(b[0])); // значение текста
    text_1.setCharacterSize(24); // размер текста 
    text_1.setFillColor(Color::Black); // цвет текста
    text_1.setStyle(Text::Bold); // стиль текста

    sf::Text text_2;
    text_2.setFont(font);
    text_2.setString(std::to_string(b[1]));
    text_2.setCharacterSize(24);
    text_2.setFillColor(Color::Black);
    text_2.setStyle(Text::Bold);

    sf::Text text_3;
    text_3.setFont(font);
    text_3.setString(std::to_string(b[2]));
    text_3.setCharacterSize(24);
    text_3.setFillColor(Color::Black);
    text_3.setStyle(Text::Bold);

    sf::Text text_4;
    text_4.setFont(font);
    text_4.setString(std::to_string(b[3]));
    text_4.setCharacterSize(24);
    text_4.setFillColor(Color::Black);
    text_4.setStyle(Text::Bold);

    sf::Text text_5;
    text_5.setFont(font);
    text_5.setString(std::to_string(b[4]));
    text_5.setCharacterSize(24);
    text_5.setFillColor(Color::Black);
    text_5.setStyle(Text::Bold);

    int robot_y_pos, robot_x_pos;

    robot_y_pos = robot.getPosition().y; // позиция робота по у
    robot_x_pos = robot.getPosition().x; // позиция робота по х

    int speed = 5; // скорость робота
    bool sort = true;
    while (window.isOpen())
    {
        text_1.setPosition(item_1.getPosition().x + 42, item_1.getPosition().y + 35); //привязка цифры к кругу
        text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
        text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
        text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
        text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);

        if (sort){
        for (int q = 0; q < 5; q++)
            {
                switch (q)
                {
                case 0:
                    if (robot_x_pos < item_1.getPosition().x) // движение по х к первому кругу
                    {
                        while (robot_x_pos < item_1.getPosition().x)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                    } 

                    if (robot_x_pos > item_1.getPosition().x)
                    {
                        while (robot_x_pos > item_1.getPosition().x)
                        {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                    }

                    while (robot_y_pos > item_1.getPosition().y + 100)
                    {
                        robot_y_pos -= speed;
                        robot.setPosition(robot_x_pos, robot_y_pos);
                        window.clear(Color::Blue);
                        window.draw(robot);
                        window.draw(item_1);
                        window.draw(item_2);
                        window.draw(item_3);
                        window.draw(item_4);
                        window.draw(item_5);
                        window.draw(text_1);
                        window.draw(text_2);
                        window.draw(text_3);
                        window.draw(text_4);
                        window.draw(text_5);
                        window.display();
                    }
                    switch (b[q])
                    {
                    case 0:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_1.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_1.setPosition(item_1.getPosition().x + 42, item_1.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 1:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_1.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_1.setPosition(item_1.getPosition().x + 42, item_1.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 200)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_1.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_1.setPosition(item_1.getPosition().x + 42, item_1.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 2:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_1.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_1.setPosition(item_1.getPosition().x + 42, item_1.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 320)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_1.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_1.setPosition(item_1.getPosition().x + 42, item_1.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 3:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_1.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_1.setPosition(item_1.getPosition().x + 42, item_1.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 440)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_1.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_1.setPosition(item_1.getPosition().x + 42, item_1.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 4:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_1.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_1.setPosition(item_1.getPosition().x + 42, item_1.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 560)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_1.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_1.setPosition(item_1.getPosition().x + 42, item_1.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    }
                    break;
                case 1:
                    if (robot_x_pos < item_2.getPosition().x)
                    {
                        while (robot_x_pos < item_2.getPosition().x)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                    }

                    if (robot_x_pos > item_2.getPosition().x)
                    {
                        while (robot_x_pos > item_2.getPosition().x)
                        {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                    }

                    while (robot_y_pos > item_2.getPosition().y + 100)
                    {
                        robot_y_pos -= speed;
                        robot.setPosition(robot_x_pos, robot_y_pos);
                        window.clear(Color::Blue);
                        window.draw(robot);
                        window.draw(item_1);
                        window.draw(item_2);
                        window.draw(item_3);
                        window.draw(item_4);
                        window.draw(item_5);
                        window.draw(text_1);
                        window.draw(text_2);
                        window.draw(text_3);
                        window.draw(text_4);
                        window.draw(text_5);
                        window.display();
                    }

                    

                    switch (b[q])
                    {
                    case 0:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_2.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos > 80) {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_2.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 1:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_2.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 200)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_2.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 2:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_2.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 320)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_2.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 3:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_2.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 440)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_2.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 4:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_2.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 560)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_2.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_2.setPosition(item_2.getPosition().x + 42, item_2.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    }
                    break;
                case 2:
                    if (robot_x_pos < item_3.getPosition().x)
                    {
                        while (robot_x_pos < item_3.getPosition().x)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                    }

                    if (robot_x_pos > item_3.getPosition().x)
                    {
                        while (robot_x_pos > item_3.getPosition().x)
                        {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                    }

                    while (robot_y_pos > item_3.getPosition().y + 100)
                    {
                        robot_y_pos -= speed;
                        robot.setPosition(robot_x_pos, robot_y_pos);
                        window.clear(Color::Blue);
                        window.draw(robot);
                        window.draw(item_1);
                        window.draw(item_2);
                        window.draw(item_3);
                        window.draw(item_4);
                        window.draw(item_5);
                        window.draw(text_1);
                        window.draw(text_2);
                        window.draw(text_3);
                        window.draw(text_4);
                        window.draw(text_5);
                        window.display();
                    }
                    switch (b[q])
                    {
                    case 0:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos > 80) {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 1:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 200)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos > 200) {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 2:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 320)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 3:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 440)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 4:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 560)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_3.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_3.setPosition(item_3.getPosition().x + 42, item_3.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    }
                    break;
                case 3:
                    if (robot_x_pos < item_4.getPosition().x)
                    {
                        while (robot_x_pos < item_4.getPosition().x)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                    }

                    if (robot_x_pos > item_4.getPosition().x)
                    {
                        while (robot_x_pos > item_4.getPosition().x)
                        {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                    }

                    while (robot_y_pos > item_4.getPosition().y + 100)
                    {
                        robot_y_pos -= speed;
                        robot.setPosition(robot_x_pos, robot_y_pos);
                        window.clear(Color::Blue);
                        window.draw(robot);
                        window.draw(item_1);
                        window.draw(item_2);
                        window.draw(item_3);
                        window.draw(item_4);
                        window.draw(item_5);
                        window.draw(text_1);
                        window.draw(text_2);
                        window.draw(text_3);
                        window.draw(text_4);
                        window.draw(text_5);
                        window.display();
                    }
                    switch (b[q])
                    {
                    case 0:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos > 80) {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 1:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 200)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos > 200) {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 2:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 320)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos > 320) {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 3:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 440)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 4:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 560)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_4.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_4.setPosition(item_4.getPosition().x + 42, item_4.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    }
                    break;
                case 4:
                    if (robot_x_pos < item_5.getPosition().x)
                    {
                        while (robot_x_pos < item_5.getPosition().x)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                    }

                    if (robot_x_pos > item_5.getPosition().x)
                    {
                        while (robot_x_pos > item_5.getPosition().x)
                        {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                    }

                    while (robot_y_pos > item_5.getPosition().y + 100)
                    {
                        robot_y_pos -= speed;
                        robot.setPosition(robot_x_pos, robot_y_pos);
                        window.clear(Color::Blue);
                        window.draw(robot);
                        window.draw(item_1);
                        window.draw(item_2);
                        window.draw(item_3);
                        window.draw(item_4);
                        window.draw(item_5);
                        window.draw(text_1);
                        window.draw(text_2);
                        window.draw(text_3);
                        window.draw(text_4);
                        window.draw(text_5);
                        window.display();
                    }
                    switch (b[q])
                    {
                    case 0:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos > 80) {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 1:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3); 
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 200)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos > 200) {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 2:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 320)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos > 320) {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 3:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 440)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos > 440) {
                            robot_x_pos -= speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    case 4:
                        while (robot_y_pos < 600)
                        {
                            robot_y_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        while (robot_x_pos < 560)
                        {
                            robot_x_pos += speed;
                            robot.setPosition(robot_x_pos, robot_y_pos);
                            item_5.setPosition(robot_x_pos, robot_y_pos - 100);
                            text_5.setPosition(item_5.getPosition().x + 42, item_5.getPosition().y + 35);
                            window.clear(Color::Blue);
                            window.draw(robot);
                            window.draw(item_1);
                            window.draw(item_2);
                            window.draw(item_3);
                            window.draw(item_4);
                            window.draw(item_5);
                            window.draw(text_1);
                            window.draw(text_2);
                            window.draw(text_3);
                            window.draw(text_4);
                            window.draw(text_5);
                            window.display();
                        }
                        break;
                    }
                    break;
                }
            }
        }
        if (item_1.getPosition().y > 150)
            sort = false;
        Event event; // добавляет возможность закрыть программу
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed)
                window.close();
        } 

        window.clear(Color::Blue); // визуализация
        window.draw(robot); // вывод робота
        window.draw(item_1); // вывод кругов 
        window.draw(item_2);
        window.draw(item_3);
        window.draw(item_4);
        window.draw(item_5);
        window.draw(text_1); // вывод цифр
        window.draw(text_2);
        window.draw(text_3);
        window.draw(text_4);
        window.draw(text_5);
        window.display(); // отображение экрана


    }
    return 0;
}