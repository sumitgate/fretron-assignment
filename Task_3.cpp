#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct Position {
    int a,b;
    bool operator<(const Position& other) const {
        return a == other.a ? b < other.b : a < other.a;
    }
};

struct State {
    Position pos;
    vector<Position> path;
    set<Position> killed;
    bool operator<(const State& other) const {
        return pos < other.pos;
    }
};

vector<Position> gNextPositions(Position pos, const set<Position>& soldiers) {
    vector<Position> nextPositions;
    for (int i = pos.b + 1; i <= 8; ++i) {
        Position next = { pos.a, i };
        if (soldiers.count(next)) {
            nextPositions.push_back(next);
            break;
        }
    }
    for (int i = pos.a + 1; i <= 8; ++i) {
        Position next = { i, pos.b };
        if (soldiers.count(next)) {
            nextPositions.push_back(next);
            break;
        }
    }
    return nextPositions;
}

void findPaths(Position castle, set<Position> soldiers) {
    queue<State> q;
    q.push({ castle, { castle }, {} });

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.killed.size() == soldiers.size()) {
            for (const auto& pos : current.path) {
                cout << "(" << pos.a << "," << pos.b << ") ";
            }
            cout << endl;
            continue;
        }

        vector<Position> nextPositions = gNextPositions(current.pos, soldiers);
        for (const auto& next : nextPositions) {
            if (current.killed.count(next)) continue;
            State newState = current;
            newState.pos = next;
            newState.path.push_back(next);
            newState.killed.insert(next);
            q.push(newState);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of soldiers: ";
    cin >> n;

    set<Position> soldiers;
    for (int i = 0; i < n; ++i) {
        Position soldier;
        cout << "Enter coordinates for soldier " << i + 1 << ": ";
        cin >> soldier.a >> soldier.b;
        soldiers.insert(soldier);
    }

    Position castle;
    cout << "Enter the coordinates for your 'special' castle: ";
    cin >> castle.a >> castle.b;

    cout << "Paths for the 'special_castle':\n";
    findPaths(castle, soldiers);

    return 0;
}
