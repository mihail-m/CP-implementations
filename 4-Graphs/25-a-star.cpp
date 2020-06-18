#include <bits/stdc++.h>
using namespace std;

static const int MOD1 = 1000000000 + 7;
static const int MOD2 = 1000000000 + 9;

static const int MAX_SIZE = 1000000;
int powers1[MAX_SIZE];
int powers2[MAX_SIZE];

static const int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool time_left(time_t start_time, time_t work_time) {
    return clock() < start_time + work_time;
}

// N-puzzle state
struct state {
    vector<int> puzzle_state;
    int puzzle_size;

    pair<int, int> empty_cell;

    long long score;
    int moves_cnt;

    pair<int, int> hash;

    state(vector<int> arr, int mvs) {
        puzzle_state = arr;
        puzzle_size = sqrt(arr.size());
        moves_cnt = mvs;
        hash = {get_hash(powers1, MOD1), get_hash(powers2, MOD2)};

        evaluate();
    }

    int get_hash(int *powers, int mod) {
        long long res = 0;
        for (int i = 0; i < puzzle_state.size(); i++) {
            res = (res + (puzzle_state[i] * powers[i]) % mod) % mod;
        }
        return (int) res;
    }

    int evaluate() {
        score = dist_empty_cell();
        score += dist_all_cells();
        score += not_in_place();
    }

    int dist_empty_cell() {
        int index = 0;
        for (int row = 0; row < puzzle_size; row++) {
            for (int col = 0; col < puzzle_size; col++, index++) {
                if (puzzle_state[index] == 0) {
                    empty_cell = {row, col};
                    return dist_cell(row, col, puzzle_state.size() - 1);
                }
            }
        }
    }

    int dist_all_cells() {
        int ret = 0;

        int index = 0;
        for (int row = 0; row < puzzle_size; row++) {
            for (int col = 0; col < puzzle_size; col++, index++) {
                if (puzzle_state[index] == 0) {
                    continue;
                }

                ret += dist_cell(row, col, puzzle_state[index]);
            }
        }

        return ret;
    }

    int not_in_place() {
        int ret = 0;

        int index = 0;
        for (int row = 0; row < puzzle_size; row++) {
            for (int col = 0; col < puzzle_size; col++, index++) {
                if (puzzle_state[index] == 0) {
                    continue;
                }

                ret += (dist_cell(row, col, puzzle_state[index]) == 0) ? 0 : 1;
            }
        }

        return ret;
    }

    int dist_cell(int r, int c, int val) {
        int target_r = (val - 1) / puzzle_size;
        int target_c = (val - 1) % puzzle_size;

        return abs(target_r - r) + abs(target_c - c);
    }

    void print() {
        cout << score;

        for (int i = 0; i < puzzle_state.size(); i++) {
            if (i % puzzle_size == 0) {
                cout << "\n";
            }

            cout << puzzle_state[i] << " ";
        }
        cout << "\n";
    }

    bool operator<(const state& rhs) {
        return this->score > rhs.score;
    }
};

vector<state*> generate_new_states(set<state*>& states, set<pair<int, int>>& state_hashes) {
    vector<state*> generated_states;

    for (auto it = states.begin(); it != states.end(); it++) {
        state* current_state = *it;

        vector<int> current_arangement = current_state->puzzle_state;

        for (int i = 0; i < 4; i++) {
            int new_row = current_state->empty_cell.first + moves[i][0];
            int new_col = current_state->empty_cell.second + moves[i][1];

            if (new_row < 0 || new_row >= current_state->puzzle_size) {
                continue;
            }

            if (new_col < 0 || new_col >= current_state->puzzle_size) {
                continue;
            }

            int current_index = current_state->puzzle_size
                               * current_state->empty_cell.first 
                               + current_state->empty_cell.second;

            int new_index = current_state->puzzle_size 
                            * new_row
                            + new_col;

            swap(current_arangement[current_index], current_arangement[new_index]);

            state* new_state = new state(current_arangement, current_state->moves_cnt + 1);

            swap(current_arangement[current_index], current_arangement[new_index]);

            if (state_hashes.count(new_state->hash)) {
                delete new_state;
                continue;
            }

            generated_states.push_back(new_state);
            state_hashes.insert(new_state->hash);
        }
    }

    return generated_states;
}

void trim_states_set(set<state*>& states, int max_set_size) {
    while (states.size() > max_set_size) {
        state* temp = *(--states.end());
        states.erase(temp);
        delete temp;
    }
}

state a_star(state* start, time_t work_time, int max_set_size) {
    powers1[0] = powers2[0] = 1;
    for (int i = 1; i < start->puzzle_state.size(); i++) {
        powers1[i] = (powers1[i - 1] * 10) % MOD1;
        powers2[i] = (powers2[i - 1] * 10) % MOD2;
    }

    time_t start_time = clock();

    set<state*> states;
    states.insert(start);

    state best_state = *start;

    set<pair<int, int>> state_hashes;

    int depth = 0;
    while (states.size() > 0 && time_left(start_time, work_time)) {
        depth++;

        state* current_state = *states.begin();
        if (current_state->score < best_state.score) {
            best_state = *current_state;
        }

        vector<state*> new_states = generate_new_states(states, state_hashes);

        trim_states_set(states, 0);

        for(state* state: new_states) {
            states.insert(state);
        }

        trim_states_set(states, max_set_size);
    }

    cerr << "Depth: " << depth << "\n";
    cerr << "States considered: " << state_hashes.size() << "\n";

    trim_states_set(states, 0);

    return best_state;
}

state* input() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cell_i_j;
            cin >> cell_i_j;
            v.push_back(cell_i_j);
        }
    }

    state* start_state = new state(v, 0);
    return start_state;
}

void test() {
    a_star(input(), 30000, 512).print();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}

/*
Tests:
6
35 34 33 32 31 30
29 28 27 26 25 24
23 22 21 0 20 19
18 17 16 15 14 13
12 11 10 9 8 7
6 5 4 3 2 1

3
8 7 6
5 4 0
3 2 1
*/