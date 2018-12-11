/**
 * rn.c -- удаляет строку после текущей
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

static void rn_line(int index, char *contents, int cursor, void *data);

/**
 * Удаляет строку после текущей
 */
void rn(text txt) { process_forward(txt, rn_line, txt); }

static void rn_line(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(cursor);

  if (index+2 > 0 && cursor >= 0) {
    delete_line((text)data, index+2);
  }
}