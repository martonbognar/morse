#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "display.h"

Sign characterToSign(char c) {
  if (c == '.') return DOT;
  if (c == '-') return DASH;
  return WORD_SPACE;
}

int letterToSigns(char letter, Sign * signs) {
  Letter * target = NULL;

  for (int i = 0; i < 26; ++i) {
    if (letters[i].ascii == letter) {
      target = &letters[i];
    }
  }

  if (target == NULL) return 0;

  int length = strlen(target->morse);

  for (int i = 0; i < length; ++i) {
    signs[i] = characterToSign(target->morse[i]);
  }

  return length;
}

void displaySign(Sign sign) {
  switch(sign) {
    case DOT: displayDot(); break;
    case DASH: displayDash(); break;
    case SMALL_SPACE: displaySmallSpace(); break;
    case LETTER_SPACE: displayLetterSpace(); break;
    case WORD_SPACE: displayWordSpace(); break;
  }
}

void codeString(const char * text) {
  int length = strlen(text);
  for (int i = 0; i < length; ++i) {
    char c = toupper(text[i]);
    if (c == ' ') {
      displaySign(WORD_SPACE);
    } else {
      Sign signs[4];
      int signLength = letterToSigns(c, signs);
      for (int j = 0; j < signLength; ++j) {
        displaySign(signs[j]);
        if (j != signLength - 1) {
          displaySign(SMALL_SPACE);
        }
      }
      if (i != length - 1 && text[i + 1] != ' ') {
        displaySign(LETTER_SPACE);
      }
    }
  }
}

int main(void) {
  char text[256];
  scanf("%255[^\n]", text);
  codeString(text);
  printf("\n");
  return 0;
}
