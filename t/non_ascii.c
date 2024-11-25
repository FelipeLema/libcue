#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libcue.h"
#include "minunit.h"

int tests_run;

static char *cue_test() {
  FILE *cue = fopen("non_ascii.cue", "r");
  assert(cue);
  Cd *cd = cue_parse_file(cue);
  assert(cd);
  assert(NULL); // todo write something
  cd_delete(cd);

  return NULL;
}

static char *run_tests() {
  mu_run_test(cue_test);
  mu_run_test(cue_test);
  return NULL;
}

int main(int argc, char **argv) {
  char *result = run_tests();
  if (result != NULL)
    printf("%s\n", result);
  else
    printf("All tests passed!\n");

  printf("Tests run: %d\n", tests_run);

  return result != NULL;
}
