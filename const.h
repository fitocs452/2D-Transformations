// Constant PI
// cos π = cos(−π) = −1
#define PI acos(-1)

// House and tree movements (Shear too)
#define MOVE_UP 1
#define MOVE_DOWN 2
#define MOVE_LEFT 3
#define MOVE_RIGHT 4

// Scale
#define IN 1
#define OUT 2

// Vertices
#define SQUARE 5
#define TRIANGLE 4
#define WHITE 246

// Operations
#define TRANSLATION 1
#define ROTATION 2
#define SCALE 3
#define SHEAR 4

// Structure of the coordinate
typedef struct point {
  double x;
  double y;
  double z; // es 1 siempre
} coordinate;