#ifndef GRAPHICS_DATA_H
#define GRAPHICS_DATA_H

#define LIGHT_COLOR 0x5b
#define DARK_COLOR 0xeb

#define KING_COLOR {\
  0b00000000,0b00000000,\
  0b00000001,0b10000000,\
  0b00000011,0b11000000,\
  0b00000011,0b11000000,\
  0b00000001,0b10000000,\
  0b00011110,0b01111000,\
  0b00111110,0b01111100,\
  0b01111110,0b01111110,\
  0b01111110,0b01111110,\
  0b01111110,0b01111110,\
  0b01111110,0b01111110,\
  0b00111110,0b01111100,\
  0b00000000,0b00000000,\
  0b00011111,0b11111000,\
  0b00011111,0b11111000,\
  0b00001111,0b11110000\
}
#define KING_MASK {\
  0b00000001,0b10000000,\
  0b00000011,0b11000000,\
  0b00000111,0b11100000,\
  0b00000111,0b11100000,\
  0b00011111,0b11111000,\
  0b00111111,0b11111100,\
  0b01111111,0b11111110,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b01111111,0b11111110,\
  0b00111111,0b11111100,\
  0b00111111,0b11111100,\
  0b00111111,0b11111100,\
  0b00011111,0b11111000\
}

#define QUEEN_COLOR {\
  0b00000001,0b10000000,\
  0b00000001,0b10000000,\
  0b00001101,0b10110000,\
  0b01101101,0b10110110,\
  0b01110101,0b10101110,\
  0b00110110,0b01101100,\
  0b00111010,0b01011100,\
  0b00011011,0b11011000,\
  0b00011101,0b10111000,\
  0b00001101,0b10110000,\
  0b01111111,0b11111110,\
  0b01111111,0b11111110,\
  0b01000000,0b00000010,\
  0b01111111,0b11111110,\
  0b01111111,0b11111110,\
  0b00000000,0b00000000\
}
#define QUEEN_MASK {\
  0b00000001,0b10000000,\
  0b00001111,0b11110000,\
  0b01111111,0b11111110,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b01111111,0b11111110,\
  0b01111111,0b11111110,\
  0b00111111,0b11111100,\
  0b00111111,0b11111100,\
  0b01111111,0b11111110,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b01111111,0b11111110\
}

#define ROOK_COLOR {\
  0b00000000,0b00000000,\
  0b01110011,0b11001110,\
  0b01110011,0b11001110,\
  0b01111111,0b11111110,\
  0b01111111,0b11111110,\
  0b00011000,0b00011000,\
  0b00001111,0b11110000,\
  0b00001111,0b11110000,\
  0b00001111,0b11110000,\
  0b00001111,0b11110000,\
  0b00001111,0b11110000,\
  0b00001111,0b11110000,\
  0b00011000,0b00011000,\
  0b01111111,0b11111110,\
  0b01111111,0b11111110,\
  0b00000000,0b00000000\
}
#define ROOK_MASK {\
  0b11110011,0b11001111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b01111111,0b11111110,\
  0b00011111,0b11111000,\
  0b00011111,0b11111000,\
  0b00011111,0b11111000,\
  0b00011111,0b11111000,\
  0b00011111,0b11111000,\
  0b00111111,0b11111100,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111\
}

#define BISHOP_COLOR {\
  0b00000000,0b00000000,\
  0b00000001,0b10000000,\
  0b00000011,0b11000000,\
  0b00000011,0b11000000,\
  0b00000111,0b11100000,\
  0b00001110,0b01110000,\
  0b00001100,0b00110000,\
  0b00001100,0b00110000,\
  0b00001110,0b01110000,\
  0b00000111,0b11100000,\
  0b00000011,0b11000000,\
  0b00000011,0b11000000,\
  0b00000111,0b11100000,\
  0b00011100,0b00111000,\
  0b01111111,0b11111110,\
  0b00000000,0b00000000\
}
#define BISHOP_MASK {\
  0b00000001,0b10000000,\
  0b00000011,0b11000000,\
  0b00000111,0b11100000,\
  0b00000111,0b11100000,\
  0b00001111,0b11110000,\
  0b00011111,0b11111000,\
  0b00011111,0b11111000,\
  0b00011111,0b11111000,\
  0b00011111,0b11111000,\
  0b00001111,0b11110000,\
  0b00000111,0b11100000,\
  0b00000111,0b11100000,\
  0b00011111,0b11111000,\
  0b01111111,0b11111110,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111\
}

#define KNIGHT_COLOR {\
  0b00000000,0b00000000,\
  0b01110011,0b10000000,\
  0b01111111,0b10000000,\
  0b00111111,0b11000000,\
  0b00100111,0b11100000,\
  0b01100111,0b11110000,\
  0b01111111,0b11111000,\
  0b01111110,0b11111000,\
  0b01101101,0b11111000,\
  0b01011011,0b11111100,\
  0b00100111,0b11111100,\
  0b00011111,0b11111100,\
  0b01111111,0b11111110,\
  0b01111111,0b11111110,\
  0b01111111,0b11111110,\
  0b00000000,0b00000000\
}
#define KNIGHT_MASK {\
  0b01110011,0b10000000,\
  0b11111111,0b11000000,\
  0b11111111,0b11000000,\
  0b01111111,0b11100000,\
  0b01111111,0b11110000,\
  0b11111111,0b11111000,\
  0b11111111,0b11111100,\
  0b11111111,0b11111100,\
  0b11111111,0b11111100,\
  0b11111111,0b11111110,\
  0b11111111,0b11111110,\
  0b01111111,0b11111110,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b01111111,0b11111111\
}

#define PAWN_COLOR {\
  0b00000000,0b00000000,\
  0b00000011,0b11000000,\
  0b00000111,0b11100000,\
  0b00001111,0b11110000,\
  0b00001111,0b11110000,\
  0b00001111,0b11110000,\
  0b00000111,0b11100000,\
  0b00000011,0b11000000,\
  0b00000000,0b00000000,\
  0b00000111,0b11100000,\
  0b00001111,0b11110000,\
  0b00011111,0b11111000,\
  0b00111111,0b11111100,\
  0b01111111,0b11111110,\
  0b01111111,0b11111110,\
  0b00000000,0b00000000\
}
#define PAWN_MASK {\
  0b00000011,0b11000000,\
  0b00000111,0b11100000,\
  0b00001111,0b11110000,\
  0b00011111,0b11111000,\
  0b00011111,0b11111000,\
  0b00011111,0b11111000,\
  0b00001111,0b11110000,\
  0b00000111,0b11100000,\
  0b00000111,0b11100000,\
  0b00001111,0b11110000,\
  0b00011111,0b11111000,\
  0b00111111,0b11111100,\
  0b01111111,0b11111110,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111,\
  0b11111111,0b11111111\
}

#endif