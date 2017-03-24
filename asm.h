#define v800x600x256     0x103
#define v1024x768x256    0x105
#define v1280x1024x256   0x107

int setVideoMode(int mode, long width, long height);
void unsetVideoMode();
void setBank(char bank);
char getPixel(int x, int y);
void putPixel(int x, int y, char color);

char currentBank;
long resolutionWidth, resolutionHeight, nBanks;
long resY, resX, limitX, limitY, numberOfBanks;
char currentBank;

int setVideoMode(int mode, long width, long height)
{
    resolutionWidth = width;
    resolutionHeight = height;
    nBanks = ((resolutionWidth*resolutionHeight)/65536L); 

    asm{
        MOV AX, 4F02H
        MOV BX, [mode]
        INT 10H                     
        CMP AX, 004FH
    JNE Error
    }

    return(1);
    
    Error:;
    return(0);
}

void unsetVideoMode()
{
    asm{
        MOV AX, 0003H
        XOR BX, BX
        INT 10H
    }
}

void setBank(char banco)
{
    asm{
        MOV AL, [banco]
        CMP[currentBank], AL
        JE noSwitch
        MOV [currentBank], AL
        MOV AX, 4F05H
        XOR BX, BX 
        XOR DX, DX
        MOV DL, [banco]
        INT 10H
    }
    noSwitch:;
}

void putPixel(int x,int y, char color)
{
    long address;
    int off;  
    char bank;

    if(x>resolutionWidth || x<0 || y>resolutionHeight || y<0)
        return;

    address = (resolutionWidth*y)+x;

    // Offset = address - (bank * 0ffffh) = address - (bank * 2^16)
    // Left Shift (<<) = A<<B = A * 2^B
    off = address-(bank<<16);

    // Bank = address / 0ffffh = address / 2^16
    // Right Shift (>>) = A>>B = A / 2^B
    bank = address>>16;

    if(bank != currentBank)
    {
        setBank(bank);
        currentBank = bank;
    }

    asm{
        MOV AX, 0A000H
        MOV ES, AX
        MOV DI, [off]
        MOV AL, [color]
        MOV ES:[DI], AL
    }
}

char getPixel(int x, int y)
{
  long address;
  int off;  
  char bank, color;

  if(x>resolutionWidth || x<0 || y>resolutionHeight || y<0)
    return;

  address = (resolutionWidth*y)+x;
  // Offset = address - (bank * 0ffffh) = address - (bank * 2^16)
  // Left Shift (<<) = A<<B = A * 2^B
  off = address-(bank<<16);
  // Bank = address / 0ffffh = address / 2^16
  // Right Shift (>>) = A>>B = A / 2^B
  bank = address>>16;

  if(bank != currentBank){
    setBank(bank);
    currentBank = bank;
  }

    asm{
    MOV AX, 0A000H
      MOV ES, AX
      MOV DI, [off]
      MOV AL, ES: [DI]
      MOV [color], AL 
    }
  return color;
}
