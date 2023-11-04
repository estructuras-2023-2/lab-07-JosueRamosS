#include <vector>
#include <queue>
using namespace std;

vector<int> Torneo(vector<int> abilities, int n, int k) {
    queue<int> queue;

    int i = 2;
    while (i < abilities.size()) {
        queue.push(abilities[i]);
        i++;
    }

    int games_won = 0;
    int current_player = abilities[0];
    int challenging_player = abilities[1];

    vector<int> output(2);

    int game = 1;
    do {
        if (current_player > challenging_player) {
            games_won++;
            output = {challenging_player, current_player};
            queue.push(challenging_player);
        } else {
            games_won = 1;
            output = {current_player, challenging_player};
            queue.push(current_player);
            current_player = challenging_player;
        }
        // If the player won n games, they go to the end
        if (games_won == n) {
            queue.push(current_player);
            current_player = queue.front();
            queue.pop();
            games_won = 0;
        }
        challenging_player = queue.front();
        queue.pop();
        game++;
    } while (game <= k);

    return output;
}
