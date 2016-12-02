#ifndef MECHANICS_H_INCLUDED
#define MECHANICS_H_INCLUDED

#include <vector>
#include <string>

std::pair<int, int> detect_player(std::vector<std::string> line);
std::pair<int, int> detect_gate(std::vector<std::string> line);
std::vector<std::pair<int, int>> detect_coin(std::vector<std::string> line);
std::pair<bool, std::vector<std::string>> check_next_position(std::pair<int, int> curr_coord, std::string inp, std::vector<std::string> level);
bool player_on_gate(std::pair<int, int> gate, std::pair<int, int> player);
int coins(std::pair<int, int> player, std::vector<std::pair<int, int>> coin_list);

#endif // MECHANICS_H_INCLUDED
