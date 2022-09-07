#include <vector>
#include <string>
#include <iostream>
#include "macros.h"
#include <SFML/Graphics.hpp>
#pragma once
//all the texture are created with singelton ,static object .
//----------------------------------------------------------------------------
class Textures {

    //--------------public--------functions-----------------------//
public:
    static Textures& instance();
    //gets requested sound from sound member
    const std::vector<sf::Texture*>& get_Textures(int type_E) const { return (m_all_textures[type_E]); }
    const sf::Font& get_Font() const { return m_Font; }
    //--------------private--------functions-----------------------//
private:
    Textures();//constractor for static member
    ~Textures();
    std::vector<sf::Texture*>m_all_textures[Number_of_textures];
    sf::Font m_Font;
};
//----------------------------------------------------------------------------