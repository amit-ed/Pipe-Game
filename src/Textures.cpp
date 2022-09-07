#include "Textures.h" 
#pragma once
//----------------------------------------------------------------------------
//set textures for all object in the game once
Textures::Textures()
{
    m_Font.loadFromFile("Love America.ttf");//setting one font
    std::vector<std::string>names[] =
    {
        {"pipe.png","pipe2.png"}
        ,{"tap.png","tap.png"}
        ,{"Curvedpipe.png","Curvedpipe2.png"}
        ,{"destination.png","destination.png"}
        ,{"WINNER.png"}
        ,{"three.png","three2.png"}
        ,{"background.jpg"}
        ,{"lvlup.jpg"}
    };
   
    sf::Texture* pic;
    for (int i = 0; i <Number_of_textures; i++) {
        for (int j = 0; j <names[i].size(); j++) {
            pic = new sf::Texture;
            pic->loadFromFile(names[i][j]);
            m_all_textures[i].push_back(pic);
        }
    }
}
//----------------------------------------------------------------------------
Textures& Textures::instance() {
    static Textures all_S;
    return all_S;
}
//----------------------------------------------------------------------------
Textures::~Textures()
{
    for (int i = 0; i < m_all_textures->size(); i++)
    {
        m_all_textures[i].clear();
    }
    m_all_textures->clear();
}
//----------------------------------------------------------------------------