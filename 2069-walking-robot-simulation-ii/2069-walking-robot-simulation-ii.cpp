class Robot {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    enum class Direction { East = 0, North = 1, West = 2, South = 3 };

    Robot(int width, int height)
        : _x(0), _y(0), _w(width), _h(height), _dir(Direction::East) {}

    void step(int num) {
        int perimeter = 2 * (_w - 1) + 2 * (_h - 1);
        num %= perimeter;
        if (num == 0) {
            if (_x == 0 && _y == 0) {
                _dir = Direction::South;
            }
        }
        while (num) {
            int nx = _x + dx[static_cast<int>(_dir)];
            int ny = _y + dy[static_cast<int>(_dir)];
            if (nx < 0 || ny < 0 || nx >= _w || ny >= _h) {
                _dir = static_cast<Direction>((static_cast<int>(_dir) + 1) % 4);
                continue;
            }
            _x = nx;
            _y = ny;
            num--;
        }
    }

    vector<int> getPos() { return {_x, _y}; }

    string getDir() {
        string names[] = {"East", "North", "West", "South"};
        return names[static_cast<int>(_dir)];
    }

private:
    int _x;
    int _y;
    int _w;
    int _h;
    Direction _dir;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */