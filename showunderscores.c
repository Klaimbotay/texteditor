/**
 * showunderscores.c -- функция замены пробелов на символ _ подчеркивания
 *
 * Copyright (c) 2018, Klim Basargin <basargin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Заменяет пробелы на символ '_' подчеркивания
 */
static void show_underscores(int index, char *contents, int cursor, void *data);

void showunderscores(text txt) {
  /*Обработка строк*/
  process_forward(txt, show_underscores, NULL);
}

static void show_underscores(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(cursor);
  UNUSED(data);

  int i = 0;
  while (contents[i]) {
    if (contents[i] == ' ')
      printf("_");
    else
      printf("%c", contents[i]);
    i++;
  }
  if (contents[strlen(contents) - 1] != '\n')
    printf("\n");
}