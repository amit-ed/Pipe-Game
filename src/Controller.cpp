#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(Board_Height + 350, Board_Width + 150), "Pipe 2.1"), 
        m_Bg(*Textures::instance().get_Textures(6)[0]), m_lvlup(*Textures::instance().get_Textures(7)[0])
{
    m_Objects = m_board.get_map();
    m_graph = Graph();
    m_destinations = m_board.get_dests();
    for (int i = 0; i < m_Objects.size(); i++)
    {
        for (int j = 0; j < m_Objects[i].size(); j++)
        {
            m_graph.addEdge(m_Objects[i][j].get(), m_Objects[i][j].get());
            get_vertex(i, j);
        }
    }
    m_graph.WaterFlow();
 }
//===============================================================
Controller::~Controller()
{
    for (auto x : m_Objects)
    {
        x.clear();
    }
    m_destinations.clear();
}
//===============================================================
//main loop run the all game
void Controller::run()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        print_objects();
        m_window.display();
        handle_event();
        m_graph.WaterFlow();
        check_lvl();
    }
}
//===============================================================================
/*
print all tiles
*/
void Controller::print_objects() {//not const because m_tap.draw cant be const
    m_window.draw(m_Bg);
    for (int i = 0; i < m_Objects.size(); i++)
        for (int j = 0; j < m_Objects[i].size(); j++)
            m_Objects[i][j]->Draw(m_window);
    m_tap.Draw(m_window);
}

//================================================================================

/// <summary>
/// handle events like pressing the mouse or X to close the game
/// </summary>
void Controller::handle_event()
{
    sf::Event event;
    while ( m_window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                m_window.close();
                break;
            }
            break;

        case sf::Event::MouseButtonReleased:
        {

            auto location = m_window.mapPixelToCoords(
                { event.mouseButton.x, event.mouseButton.y });//set loction to know where we pressed on the screen
           
            switch (event.mouseButton.button)
            {
            case sf::Mouse::Button::Left:
                handleClick(location,true);
                break;
            case sf::Mouse::Button::Right:
                handleClick(location, false);
                break;
            }
            break;
        }
        };
    }
}

//====================================================================
///if we clicked on the mouse so check if we clicked on one of the object of the game 
void Controller::handleClick(const sf::Vector2f& location,bool dir)
{  
    for (int i = 0; i < m_Objects.size(); i++)
    {
        for (int j = 0; j < m_Objects[i].size(); j++) 
        {
            if (m_Objects[i][j]->Contain(location))
            {
                ++m_tap;
                if (dynamic_cast<Rotatable*>(m_Objects[i][j].get()))
                {
                    
                    for (auto x : m_Objects)
                    {
                        for (auto y : x)
                        {
                            y.get()->disconnect();//disconnect all object from water
                        }
                    }
                    
                   
                  
                    dynamic_cast<Rotatable*>(m_Objects[i][j].get())->Rotate(dir);
                    get_vertex(i, j);//
                    return;
                }
            }
        }
    }
}
//====================================================================
///set list OF NEIGHBORES
void Controller::get_vertex(int i,int j)
{
    list<Object*> temp;
    temp.push_back(m_Objects[i][j].get());
    if (j < m_Objects[0].size()-1)
    {
        if (m_Objects[i][j]->get_right_edge() && m_Objects[i][j + 1]->get_left_edge()) {
            temp.push_back(m_Objects[i][j + 1].get());
            m_graph.addEdge(m_Objects[i][j + 1].get(), m_Objects[i][j].get());
        }
        else m_graph.deleteEdge(m_Objects[i][j + 1].get(), m_Objects[i][j].get());
    }
    if (j >  0)
    {
        if (m_Objects[i][j]->get_left_edge() && m_Objects[i][j - 1]->get_right_edge()) {
            temp.push_back(m_Objects[i][j - 1].get());
            m_graph.addEdge(m_Objects[i][j - 1].get(), m_Objects[i][j].get());
        }
        else m_graph.deleteEdge(m_Objects[i][j - 1].get(), m_Objects[i][j].get());
    }
    if (i < m_Objects.size()-1)
    {
        if (m_Objects[i][j]->get_down_edge() && m_Objects[i+1][j]->get_up_edge()) {
            temp.push_back(m_Objects[i + 1][j].get());
            m_graph.addEdge(m_Objects[i + 1][j].get(), m_Objects[i][j].get());
        }
        else m_graph.deleteEdge(m_Objects[i + 1][j].get(), m_Objects[i][j].get());
    }
    if (i > 0)
    {
        if (m_Objects[i][j]->get_up_edge() && m_Objects[i-1][j]->get_down_edge()) {
            temp.push_back(m_Objects[i - 1][j].get());
            m_graph.addEdge(m_Objects[i - 1][j].get(), m_Objects[i][j].get());
        }
        else m_graph.deleteEdge(m_Objects[i-1][j].get(), m_Objects[i][j].get());
    }
    m_graph.replaceEdge(m_Objects[i][j].get(), temp);
}
//==================================================================
//check if we finished the current LVL
void Controller::check_lvl()
{
    for (auto x : m_destinations)
    {
        if (!m_Objects[x.x][x.y]->is_connected())
            return;
    }
    if (!m_board.rebuild_Map())
    {  
        Quit_Game(4);
        return;
    }
    print_objects();
    m_window.display();
    m_tap.reset();
    std::this_thread::sleep_for(std::chrono::milliseconds(700));//delay from presenting the finished LVL
    m_window.clear();

    m_window.draw(m_lvlup);
    m_window.display();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    m_destinations.clear();
    m_Objects = m_board.get_map();//new map
    m_graph = Graph();
    m_destinations = m_board.get_dests();
    for (int i = 0; i < m_Objects.size(); i++)//build new neighbors list for each vertex
    {
        for (int j = 0; j < m_Objects[i].size(); j++)
        {
            m_graph.addEdge(m_Objects[i][j].get(), m_Objects[i][j].get());
            get_vertex(i, j);
        }
    }
    m_graph.WaterFlow();
}
//==========================================================================
//quit game and present WINNER screen
void Controller::Quit_Game(int pic_num)
{
    
    print_objects();
    m_window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(700));//delay from presenting the finished LVL
    m_window.clear();
    sf::Sprite game_over;
    game_over.setTexture(*Textures::instance().get_Textures(pic_num)[0]);
    m_window.draw(game_over);
  
    m_window.display();
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
            break;
        }
    }
}
//=============================================================
