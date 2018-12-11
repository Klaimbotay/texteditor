/**
 * mpweb.c -- для перемещения курсора в конец предыдущего слова, если это
 * возможно
 *
 * Copyright (c) 2018, Klim Basargin <basargin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void mpweb_line(int index, char *contents, int cursor, void *data);

void mpweb(text txt) { process_forward(txt, mpweb_line, txt); }

static void mpweb_line(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  if (cursor > 1) {
    for (int i = 1; i < cursor ; i++) {
      if (isspace(contents[cursor - i]) && !isspace(contents[cursor - i - 1]) &&
          contents[cursor - i - 1] != '\0') {
        mwcrsr((text)data, index + 1, cursor - i);
        break;
      }
    }
  }
}