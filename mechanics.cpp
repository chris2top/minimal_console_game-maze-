#include <string>
#include <iostream>
#include "../include/mechanics.h"

std::pair<int, int> detect_player(std::vector<std::string> line)
{
    int x_coord = 0;
    int y_coord = 0;
    for (auto content : line)
    {
        for (auto content2 : content)
        {
            if (content2 == 'P')
            {
                int player_x = x_coord;
                int player_y = y_coord;
                return std::pair<int, int> (player_x, player_y);
            }
            x_coord++;
        }
        x_coord = 0;
        y_coord++;
    }
    return std::pair<int, int> (-1, -1);
}

std::pair<int, int> detect_gate(std::vector<std::string> line)
{
    int x_coord = 0;
    int y_coord = 0;
    for (auto content : line)
    {
        for (auto content2 : content)
        {
            if (content2 == 'G')
            {
                int gate_x = x_coord;
                int gate_y = y_coord;
                return std::pair<int, int> (gate_x, gate_y);
            }
            x_coord++;
        }
        x_coord = 0;
        y_coord++;
    }
    return std::pair<int, int> (-1, -1);
}

std::vector<std::pair<int, int>> detect_coin(std::vector<std::string> line)
{
    int x_coord = 0;
    int y_coord = 0;
    std::vector<std::pair<int, int>> coin_list;

    for (auto content : line)
    {
        for (auto content2 : content)
        {
            if (content2 == 'C')
            {
                int coin_x = x_coord;
                int coin_y = y_coord;
                coin_list.push_back(std::pair<int, int>(coin_x, coin_y));
            }
            x_coord++;
        }
        x_coord = 0;
        y_coord++;
    }
    return coin_list;
}

std::pair<bool, std::vector<std::string>> check_next_position(std::pair<int, int> curr_coord,
                                          std::string inp, std::vector<std::string> level)
{
    if (inp == "w")
    {
        if (level[curr_coord.second - 1][curr_coord.first] != '#')
        {
            level[curr_coord.second][curr_coord.first] = '.';
            level[curr_coord.second - 1][curr_coord.first] = 'P';
            return std::make_pair(false, level);
        }
        else
            return std::make_pair(true, level);
    }

    else if (inp =="a")
    {
        if (level[curr_coord.second][curr_coord.first - 1] != '#')
        {
            level[curr_coord.second][curr_coord.first] = '.';
            level[curr_coord.second][curr_coord.first - 1] = 'P';
            return std::make_pair(false, level);
        }
        else
            return std::make_pair(true, level);
    }

    else if (inp == "s")
    {
        if (level[curr_coord.second + 1][curr_coord.first] != '#')
        {
            level[curr_coord.second][curr_coord.first] = '.';
            level[curr_coord.second + 1][curr_coord.first] = 'P';
            return std::make_pair(false, level);
        }
        else
            return std::make_pair(true, level);
    }

    else if (inp == "d")
    {
        if (level[curr_coord.second][curr_coord.first + 1] != '#')
        {
            level[curr_coord.second][curr_coord.first] = '.';
            level[curr_coord.second][curr_coord.first + 1] = 'P';
            return std::make_pair(false, level);
        }
        else
            return std::make_pair(true, level);
    }

    else
    {
        std::cout << "wrong input" << std::endl;
        return std::make_pair(true, level);
    }
}

bool player_on_gate(std::pair<int, int> gate, std::pair<int, int> player)
{
    if (player == gate)
        return false;
    else
        return true;
}

int coins(std::pair<int, int> player, std::vector<std::pair<int, int>> coin_list)
{
    for (auto content : coin_list)
        if (player == content)
            return 1;
    return 0;
}
