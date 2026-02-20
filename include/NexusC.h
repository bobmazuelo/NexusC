#pagma once
#ifndef NEXUSC_H
#define NEXUSC_H

#include <stdio.h>
#include <unistd.h>

#include "reader_csv.h"

#define errf(fmt, args...)                                                     \
  do {                                                                         \
    fprintf(stderr, "[ERROR]: @ %s(): ", __func__);                            \
    fprintf(stderr, fmt, ##args);                                              \
  } while (0)
#define ERROR_EXIT(...)                                                        \
  fprintf(stderr, __VA_ARGS__);                                                \
  exit(1)
#define ERROR_RETURN(R, ...)                                                   \
  fprintf(stderr, __VA_ARGS__);                                                \
  return R

#endif
