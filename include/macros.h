#pragma once
#include <SFML/Graphics.hpp>
constexpr auto Number_of_textures = 8;
constexpr auto STARTING_X = 50;
constexpr auto STARTING_Y = 100;

constexpr auto sourceU = 'U';
constexpr auto sourceD = 'D';
constexpr auto sourceL = 'L';
constexpr auto sourceR = 'R';
constexpr auto destU = 'u';
constexpr auto destD = 'd';
constexpr auto destL = 'l';
constexpr auto destR = 'r';
constexpr auto pipeR = '-';
constexpr auto pipeL = '|';
constexpr auto CurvedL = ')';
constexpr auto CurvedR = '(';
constexpr auto CurvedD = '%';
constexpr auto CurvedU = '^';
constexpr auto threeU = 'G';
constexpr auto threeD = 'P';
constexpr auto threeL = '3';
constexpr auto threeR = 'Q';

constexpr auto Connected = 1;
constexpr auto Disconnected = 0;

constexpr auto Board_Height = 600;
constexpr auto Board_Width = 600;