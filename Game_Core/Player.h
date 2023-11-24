#pragma once
class Player {
protected:
    int i;
    int j;

public:
    Player(int initialI = 0, int initialJ = 0) : i(initialI), j(initialJ) {}

    void updatePosition(int newRow, int newCol) {
        i = newRow;
        j = newCol;
    }

    int Geti() {
        return i;
    }
    int Getj() {
        return j;
    }
    void Seti(int editedi) {
        i = editedi;
    }
    void Setj(int editedj) {
        j = editedj;
    }
};