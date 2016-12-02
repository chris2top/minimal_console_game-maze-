#include <iostream>
#include <vector>
#include "../include/file_utility.h"
#include "../include/mechanics.h"

using namespace std;

int main() {
    int coin_counter = 0;
    bool run = true;
    bool repeat = false;
    string inp;
    vector<string> level = file_content("levels/level1.lvl");
    pair<int, int> gate = detect_gate(level);
    vector<pair<int, int>> coin = detect_coin(level);

    do
    {
        pair<int, int> ret = detect_player(level);
        do
        {
            for(auto item : level)
                cout << item << endl;
            run = player_on_gate(gate, ret);
            coin_counter += coins(ret, coin);

            cout << "Coins: " << coin_counter << endl;
            cin >> inp;

            if (inp == "q")
                break;
            else
            {
            repeat = check_next_position(ret, inp, level).first;
            level = check_next_position(ret, inp, level).second;

            cout << "\033[2J\033[1;1H"; //löscht Screen und spring auf erste Stelle
            }
        } while (repeat == true);
        if (inp == "q")
            break;
    } while(run == true);
    if (inp != "q")

        cout << "Herzlichen Glückwunsch Sie haben das Level geschafft!" << endl;
}
