#include "cPlayer.h"


void cPlayer::killPlayer(){
  isDead = true;
}

char ** cPlayer::shape() {
  return a;
}

cPosition cPlayer::getPos() {
  return pos;
}

int cPlayer::getHeight() {
  return width;
}

int cPlayer::getWidth() {
  return height;
}
