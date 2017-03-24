#define sgn(x) ((x < 0) ? -1 : ( (x > 0) ? 1 : 0))

void drawLine(int x1, int y1, int x2, int y2, char color);
void drawRectangle(int x1, int y1, int x2, int y2, char color);
void drawFilledRectangle(int x1, int y1, int x2, int y2, char color);
void scanline(int a[20][2], int n, char color);
void showPalette();

void drawLine(int x1, int y1, int x2, int y2, char color){
	int i, dx, dy, sdx, sdy, x, y, px, py;
	dx = x2 - x1;
	dy = y2 - y1;

	sdx = sgn(dx);
	sdy = sgn(dy);

	if (dx < 0){
		dx = dx * -1;
	}

	if (dy < 0){
		dy = dy * -1;
	}

	x = dy>>1;
	y = dx>>1;	

	px = x1;
	py = y1;

	if(dx >= dy){
		for(i=0; i<dx; i++){
			y += dy;
			if(y >= dx){
				y -= dx;
				py += sdy;
			}
			px+=sdx;
			putPixel(px, py, color);
		}
	}else{
		for(i=0; i<dy; i++){
			x += dx;
			if (x >= dy){
				x -= dy;
				px += sdx;
			}
			py+=sdy;
			putPixel(px, py, color);
		}
	}
}

void drawRectangle(int x1, int y1, int x2, int y2, char color){
	drawLine(x1, y1, x2, y1, color);
	drawLine(x1, y1, x1, y2, color);
	drawLine(x2, y1, x2, y2, color);
	drawLine(x1, y2, x2, y2, color);
}

void drawFilledRectangle(int x1, int y1, int x2, int y2, char color){
	int y, temp;

	//Arregla los valores de y1 y y2 para que sean congruentes.
	if(y1 > y2){
		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	//Se dibuja el relleno del rectangulo.
	for(y = y1; y <= y2; y++){
		drawLine(x1, y, x2, y, color);
	}

	//Se dibuja el contorno.
	drawRectangle(x1, y1, x2, y2, color);
}

void scanline(int a[20][2], int n, char color){
	int i,j,k,gd,gm,dy,dx;
	int x,y,temp;
	int xi[20];
	float slope[20];

	for(i=0;i<n-1;i++)
	{
		dy=a[i+1][1]-a[i][1];
		dx=a[i+1][0]-a[i][0];

		if(dy==0) 
			slope[i]=1.0;

		if(dx==0) 
			slope[i]=0.0;

		if((dy!=0)&&(dx!=0))
			slope[i]=(float) dx/dy;
	}

	for(y=0;y<600;y++)
	{
		k=0;
		for(i=0;i<n-1;i++)
			if( ((a[i][1]<=y)&&(a[i+1][1]>y)) || ((a[i][1]>y)&&(a[i+1][1]<=y)))
			{
				xi[k]=(int)(a[i][0]+slope[i]*(y-a[i][1]));
				k++;
			}

		for(j=0;j<k-1;j++)
			for(i=0;i<k-1;i++)
				if(xi[i]>xi[i+1])
				{
					temp=xi[i];
					xi[i]=xi[i+1];
					xi[i+1]=temp;
				}

		for(i=0;i<k;i+=2)
			drawLine(xi[i], y, xi[i+1]+1, y, color);
	}

	for(i=0; i<n-1; i++) 
		drawLine(a[i][0], a[i][1], a[i+1][0], a[i+1][1], color);
}

void showPalette() {
    int i, j, k, l, color = 0;
    int x0 = 0;
    int y0 = 0;
    int size = 16;
    int columns = 12;

    for (i = x0; color < 256; i = i + size, color++) {
        if (color % columns == 0) {
            i = x0;
        }
        j = y0 + ((color - 0)/columns)*size;

        for (k = 0; k < size; j++, k++) {
            for (l = 0; l < size; l++) {
                putPixel(i + l, j, color);
            }
        }
    }
}