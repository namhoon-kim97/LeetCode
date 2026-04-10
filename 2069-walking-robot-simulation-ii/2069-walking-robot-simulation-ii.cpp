class Robot {
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w - 1) + 2 * (h - 1);
        pos = 0;
        moved = false;
    }

    void step(int num) {
        moved = true;
        pos = (pos + num) % perimeter;
    }

    vector<int> getPos() {
        if (pos < w) {
            return {pos, 0}; // Bottom edge
        } else if (pos < w + h - 1) {
            return {w - 1, pos - w + 1}; // Right edge
        } else if (pos < 2 * w + h - 2) {
            return {2 * w + h - 3 - pos, h - 1}; // Top edge
        } else {
            return {0, perimeter - pos}; // Left edge
        }
    }

    string getDir() {
        if (pos == 0)
            return moved ? "South" : "East";

        if (pos < w)
            return "East";
        if (pos < w + h - 1)
            return "North";
        if (pos < 2 * w + h - 2)
            return "West";

        return "South";
    }

private:
    int w, h;
    int perimeter;
    int pos;
    bool moved;
};