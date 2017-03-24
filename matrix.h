// Siempre retornamos la nueva coordenada
coordinate multiply(double x, double y, double transMatrix[3][3]);
coordinate translation(double x, double y, coordinate ref);
coordinate rotation(coordinate rotateCoord, coordinate rotateRef, int angle);
coordinate scale(coordinate ref, coordinate rotateRef, double scale_x, double scale_y);

coordinate multiply(double x, double y, double transMatrix[3][3])
{
  int i, j, k;
  coordinate newPoint;
  double factMatrix[3][1];
  double mult[3][1];
  factMatrix[0][0] = x;
  factMatrix[1][0] = y; 
  factMatrix[2][0] = 1;

  for(i = 0; i < 3; ++i) {
    for(j = 0; j < 1; ++j) {
      mult[i][j] = 0;
    }
  }

  // Multiplying matrix transMatrix and factMatrix and storing in array mult.
  for(i = 0; i < 3; ++i) {
    for(j = 0; j < 1; ++j) {
      for(k=0; k < 3; ++k) {
        mult[i][j] += transMatrix[i][k] * factMatrix[k][j];
      }
    }
  }

  newPoint.x = mult[0][0];
  newPoint.y = mult[1][0];
  newPoint.z = mult[2][0];
  return newPoint;
}

coordinate translation(double x, double y, coordinate ref) {
  double matrix[3][3];
  
  matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = x;
  matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = y;
  matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;

  return multiply(ref.x, ref.y, matrix);
}

coordinate rotation(coordinate rotateCoord, coordinate rotateRef, int angle) {
  double matrix[3][3];
  double val;
  double radians = angle*PI	 / 180.0;
  
  matrix[0][0] =  cos(radians);       matrix[0][1] = -sin(radians);   matrix[0][2] = -rotateRef.x*cos(radians) + rotateRef.y*sin(radians) + rotateRef.x;
  matrix[1][0] = sin(radians);        matrix[1][1] = cos(radians);    matrix[1][2] = -rotateRef.x*sin(radians) -rotateRef.y*cos(radians) + rotateRef.y;
  matrix[2][0] = 0;                   matrix[2][1] = 0;               matrix[2][2] = 1;

  return multiply(rotateCoord.x, rotateCoord.y, matrix);
}

coordinate scale(coordinate ref, coordinate rotateRef, double scale_x, double scale_y) {
  double matrix[3][3];

  matrix[0][0] = scale_x;       matrix[0][1] = 0;         matrix[0][2] = -rotateRef.x * scale_x + rotateRef.x;
  matrix[1][0] = 0;             matrix[1][1] = scale_y;   matrix[1][2] = -rotateRef.y * scale_y + rotateRef.y;
  matrix[2][0] = 0;             matrix[2][1] = 0;         matrix[2][2] = 1;

  return multiply(ref.x, ref.y, matrix);
}

coordinate shear(double shear_x, double shear_y, coordinate ref, coordinate pivot) {
  double matrix[3][3];

  matrix[0][0] = 1;         matrix[0][1] = shear_x;   matrix[0][2] = -pivot.x*shear_x;
  matrix[1][0] = shear_y;   matrix[1][1] = 1;         matrix[1][2] = -pivot.y*shear_y;
  matrix[2][0] = 0;         matrix[2][1] = 0;         matrix[2][2] = 1;

  return multiply(ref.x, ref.y, matrix);
}