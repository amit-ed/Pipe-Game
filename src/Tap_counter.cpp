#include "Tap_counter.h";

Tap_counter::Tap_counter()
{
    m_text.setFont(Textures::instance().get_Font());
    m_text.setCharacterSize(35);
    m_text.setPosition(10, 10);
    m_text.setColor(sf::Color::Black);

}
//======================================================
//draw counter
void Tap_counter::Draw(sf::RenderWindow& window) {

    std::stringstream time;
    time << "Taps : " << "  " << std::to_string(m_taps);

    m_text.setString(time.str());
    window.draw(m_text);
}

//======================================================