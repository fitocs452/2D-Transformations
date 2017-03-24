int tree[4][2];
int trunk[5][2];
coordinate treeCenter;

int house[5][2];
int roof[4][2];
int window[5][2];
int door[5][2];
coordinate houseCenter;
double factorX, factorY;

coordinate tempPoint;

void initHouse();
void drawHouse();
void eraseHouse();
void houseTranslation(int direction);
void houseRotation();
void houseScale(int inOrOut);
void houseShear();

void initTree();
void drawTree();
void eraseTree();
void treeTranslation(int direction);
void treeRotation();
void treeScale(int inOrOut);
void treeShear(int direction);

void initTree() {
    // Tree vertices
    tree[0][0] = 500;
    tree[0][1] = 300;

    tree[1][0] = 600;
    tree[1][1] = 150;

    tree[2][0] = 700;
    tree[2][1] = 300;

    tree[3][0] = 500;
    tree[3][1] = 300;

    // Trunk vertices
    trunk[0][0] = 575;
    trunk[0][1] = 400;

    trunk[1][0] = 575;
    trunk[1][1] = 300;

    trunk[2][0] = 625;
    trunk[2][1] = 300;

    trunk[3][0] = 625;
    trunk[3][1] = 400;

    trunk[4][0] = 575;
    trunk[4][1] = 400;

    treeCenter.x = 600;
    treeCenter.y = 300;

    drawTree();
}

void drawTree() {
    scanline(tree,TRIANGLE, 48);
    scanline(trunk, SQUARE, 12);
}

void eraseTree() {
    scanline(tree, TRIANGLE, WHITE);
    scanline(trunk, SQUARE, WHITE);
}

void treeTranslation(int direction) {
    double factorX, factorY;
    int i;
    
    if(direction == MOVE_UP) {
        factorX = 0;
        factorY = -10;
    }

    if(direction == MOVE_DOWN) {
        factorX = 0;
        factorY = 10;
    }

    if(direction == MOVE_RIGHT) {
        factorX = 10;
        factorY = 0;
    }

    if(direction == MOVE_LEFT) {
        factorX = -10;
        factorY = 0;
    }

    for(i = 0; i < TRIANGLE; i++) {
        tempPoint.x = tree[i][0];
        tempPoint.y = tree[i][1];
        tempPoint.z = 1;

        tempPoint = translation(factorX, factorY, tempPoint);

        tree[i][0] = tempPoint.x;
        tree[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++) {
        tempPoint.x = trunk[i][0];
        tempPoint.y = trunk[i][1];
        tempPoint.z = 1;

        tempPoint = translation(factorX, factorY, tempPoint);

        trunk[i][0] = tempPoint.x;
        trunk[i][1] = tempPoint.y;
    }

    treeCenter = translation(factorX, factorY, treeCenter);
}

void treeRotation() {
    int i;

    for(i = 0; i < TRIANGLE; i++) {
        tempPoint.x = tree[i][0];
        tempPoint.y = tree[i][1];
        tempPoint.z = 1;

        tempPoint = rotation(tempPoint, treeCenter, 30);

        tree[i][0] = tempPoint.x;
        tree[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++) {
        tempPoint.x = trunk[i][0];
        tempPoint.y = trunk[i][1];
        tempPoint.z = 1;

        tempPoint = rotation(tempPoint, treeCenter, 30);

        trunk[i][0] = tempPoint.x;
        trunk[i][1] = tempPoint.y;
    }
}

void treeScale(int inOrOut) {
    int i;

    for(i = 0; i < TRIANGLE; i++) {
        tempPoint.x = tree[i][0];
        tempPoint.y = tree[i][1];
        tempPoint.z = 1;

        // zoom in
        if (inOrOut == IN) {
            tempPoint = scale(tempPoint, treeCenter, 0.9, 0.9);
        } else {
            tempPoint = scale(tempPoint, treeCenter, 1.1, 1.1);
        }

        tree[i][0] = tempPoint.x;
        tree[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++) {
        tempPoint.x = trunk[i][0];
        tempPoint.y = trunk[i][1];
        tempPoint.z = 1;

        // zoom in
        if (inOrOut == IN) {
            tempPoint = scale(tempPoint, treeCenter, 0.9, 0.9);
        } else {
            tempPoint = scale(tempPoint, treeCenter, 1.1, 1.1);
        }

        trunk[i][0] = tempPoint.x;
        trunk[i][1] = tempPoint.y;
    }
}

void treeShear(int direction) {
    int i;

    if(direction == MOVE_UP) {
        factorX = 0;
        factorY = 0.1;
    }

    if(direction == MOVE_DOWN) {
        factorX = 0;
        factorY = -0.1;
    }

    if(direction == MOVE_RIGHT) {
        factorX = 0.1;
        factorY = 0;
    }

    if(direction == MOVE_LEFT) {
        factorX = -0.1;
        factorY = 0;
    }

    for(i = 0; i < TRIANGLE; i++) {
        tempPoint.x = tree[i][0];
        tempPoint.y = tree[i][1];
        tempPoint.z = 1;

        tempPoint = shear(factorX, factorY, tempPoint, treeCenter);

        tree[i][0] = tempPoint.x;
        tree[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++) {
        tempPoint.x = trunk[i][0];
        tempPoint.y = trunk[i][1];
        tempPoint.z = 1;

        tempPoint = shear(factorX, factorY, tempPoint, treeCenter);

        trunk[i][0] = tempPoint.x;
        trunk[i][1] = tempPoint.y;
    }

    treeCenter = shear(factorX, factorY, treeCenter, treeCenter);
}

void initHouse(){

    // House vertices
    house[0][0] = 100;
    house[0][1] = 400;

    house[1][0] = 100;
    house[1][1] = 250;

    house[2][0] = 300;
    house[2][1] = 250;

    house[3][0] = 300;
    house[3][1] = 400;

    house[4][0] = 100;
    house[4][1] = 400;

    // Roof vertices
    roof[0][0] = 100;
    roof[0][1] = 250;

    roof[1][0] = 200;
    roof[1][1] = 100;

    roof[2][0] = 300;
    roof[2][1] = 250;

    roof[3][0] = 100;
    roof[3][1] = 250;

    // Door vertices
    door[0][0] = 135;
    door[0][1] = 400;

    door[1][0] = 135;
    door[1][1] = 300;

    door[2][0] = 195;
    door[2][1] = 300;

    door[3][0] = 195;
    door[3][1] = 400;

    door[4][0] = 135;
    door[4][1] = 400;

    // Window vertices
    window[0][0] = 230;
    window[0][1] = 275;

    window[1][0] = 230;
    window[1][1] = 250;

    window[2][0] = 275;
    window[2][1] = 250;

    window[3][0] = 275;
    window[3][1] = 275;

    window[4][0] = 230;
    window[4][1] = 275;

    houseCenter.x = 200;
    houseCenter.y = 250;

    drawHouse();
}

void drawHouse() {
    scanline(house, SQUARE, 6);
    scanline(roof, TRIANGLE, 54);
    scanline(door, SQUARE, 54);
    scanline(window, SQUARE, 39);
}

void eraseHouse() {
    scanline(house, SQUARE, WHITE);
    scanline(roof, TRIANGLE, WHITE);
    scanline(door, SQUARE, WHITE);
    scanline(window, SQUARE, WHITE);
}

void houseTranslation(int direction) {
    int i;

    if(direction == MOVE_UP){
        factorX = 0;
        factorY = -10;
    }

    if(direction == MOVE_DOWN){
        factorX = 0;
        factorY = 10;
    }

    if(direction == MOVE_RIGHT){
        factorX = 10;
        factorY = 0;
    }

    if(direction == MOVE_LEFT){
        factorX = -10;
        factorY = 0;
    }

    for(i = 0; i < TRIANGLE; i++){
        tempPoint.x = roof[i][0];
        tempPoint.y = roof[i][1];
        tempPoint.z = 1;

        tempPoint = translation(factorX, factorY, tempPoint);

        roof[i][0] = tempPoint.x;
        roof[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = house[i][0];
        tempPoint.y = house[i][1];
        tempPoint.z = 1;

        tempPoint = translation(factorX, factorY, tempPoint);

        house[i][0] = tempPoint.x;
        house[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = door[i][0];
        tempPoint.y = door[i][1];
        tempPoint.z = 1;

        tempPoint = translation(factorX, factorY, tempPoint);

        door[i][0] = tempPoint.x;
        door[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = window[i][0];
        tempPoint.y = window[i][1];
        tempPoint.z = 1;

        tempPoint = translation(factorX, factorY, tempPoint);

        window[i][0] = tempPoint.x;
        window[i][1] = tempPoint.y;
    }

    houseCenter = translation(factorX, factorY, houseCenter);
}

void houseRotation(){
    int i;

    for(i = 0; i < TRIANGLE; i++){
        tempPoint.x = roof[i][0];
        tempPoint.y = roof[i][1];
        tempPoint.z = 1;

        tempPoint = rotation(tempPoint, houseCenter, 30);

        roof[i][0] = tempPoint.x;
        roof[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = house[i][0];
        tempPoint.y = house[i][1];
        tempPoint.z = 1;

        tempPoint = rotation(tempPoint, houseCenter, 30);

        house[i][0] = tempPoint.x;
        house[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = door[i][0];
        tempPoint.y = door[i][1];
        tempPoint.z = 1;

        tempPoint = rotation(tempPoint, houseCenter, 30);

        door[i][0] = tempPoint.x;
        door[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = window[i][0];
        tempPoint.y = window[i][1];
        tempPoint.z = 1;

        tempPoint = rotation(tempPoint, houseCenter, 30);

        window[i][0] = tempPoint.x;
        window[i][1] = tempPoint.y;
    }
}

void houseScale(int inOrOut){
    int i;

    for(i = 0; i < TRIANGLE; i++){
        tempPoint.x = roof[i][0];
        tempPoint.y = roof[i][1];
        tempPoint.z = 1;

        if (inOrOut == IN) {
            tempPoint = scale(tempPoint, houseCenter, 0.9, 0.9);
        } else {
            tempPoint = scale(tempPoint, houseCenter, 1.1, 1.1);
        }

        roof[i][0] = tempPoint.x;
        roof[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = house[i][0];
        tempPoint.y = house[i][1];
        tempPoint.z = 1;

        if (inOrOut == IN) {
            tempPoint = scale(tempPoint, houseCenter, 0.9, 0.9);
        } else {
            tempPoint = scale(tempPoint, houseCenter, 1.1, 1.1);
        }

        house[i][0] = tempPoint.x;
        house[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = door[i][0];
        tempPoint.y = door[i][1];
        tempPoint.z = 1;

        if (inOrOut == IN) {
            tempPoint = scale(tempPoint, houseCenter, 0.9, 0.9);
        } else {
            tempPoint = scale(tempPoint, houseCenter, 1.1, 1.1);
        }

        door[i][0] = tempPoint.x;
        door[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = window[i][0];
        tempPoint.y = window[i][1];
        tempPoint.z = 1;

        if (inOrOut == IN) {
            tempPoint = scale(tempPoint, houseCenter, 0.9, 0.9);
        } else {
            tempPoint = scale(tempPoint, houseCenter, 1.1, 1.1);
        }

        window[i][0] = tempPoint.x;
        window[i][1] = tempPoint.y;
    }
}

void houseShear(int direction){
    int i;

    if(direction == MOVE_UP){
        factorX = 0;
        factorY = 0.1;
    }

    if(direction == MOVE_DOWN){
        factorX = 0;
        factorY = -0.1;
    }

    if(direction == MOVE_RIGHT){
        factorX = 0.1;
        factorY = 0;
    }

    if(direction == MOVE_LEFT){
        factorX = -0.1;
        factorY = 0;
    }

    for(i = 0; i < TRIANGLE; i++){
        tempPoint.x = roof[i][0];
        tempPoint.y = roof[i][1];
        tempPoint.z = 1;

        tempPoint = shear(factorX, factorY, tempPoint, houseCenter);

        roof[i][0] = tempPoint.x;
        roof[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = house[i][0];
        tempPoint.y = house[i][1];
        tempPoint.z = 1;

        tempPoint = shear(factorX, factorY, tempPoint, houseCenter);

        house[i][0] = tempPoint.x;
        house[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = door[i][0];
        tempPoint.y = door[i][1];
        tempPoint.z = 1;

        tempPoint = shear(factorX, factorY, tempPoint, houseCenter);

        door[i][0] = tempPoint.x;
        door[i][1] = tempPoint.y;
    }

    for(i = 0; i < SQUARE; i++){
        tempPoint.x = window[i][0];
        tempPoint.y = window[i][1];
        tempPoint.z = 1;

        tempPoint = shear(factorX, factorY, tempPoint, houseCenter);

        window[i][0] = tempPoint.x;
        window[i][1] = tempPoint.y;
    }

    houseCenter = shear(factorX, factorY, houseCenter, houseCenter);
}