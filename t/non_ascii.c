#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libcue.h"
#include "minunit.h"

int tests_run;

static char *cue_test() {
  FILE *cue = fopen("non_ascii.cue", "r");
  mu_assert("error reading cue file", cue);
  Cd *cd = cue_parse_file(cue);
  mu_assert("error parsing cue file", cd);

  Track *track = NULL;
  const char *val = NULL;
  Cdtext *cdtext = cd_get_cdtext(cd);
  mu_assert("error getting CDTEXT", cdtext != NULL);

  val = cdtext_get(PTI_PERFORMER, cdtext);
  mu_assert("error getting CD performer", val != NULL);
  mu_assert("error validating CD performer",
            strcmp(val, "Falcom Sound Team J.D.K.") == 0);

  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting CD title", val != NULL);
  mu_assert("error validating CD title",
            strcmp(val, "パーフェクト·コレクション·ソーサリアン DISC1") == 0);

  val = cdtext_get(PTI_TITLE, cdtext);
  int ntrack = cd_get_ntrack(cd);
  assert(ntrack == 18);

  /* Track 1 */
  track = cd_get_track(cd, 1);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title", strcmp(val, "オープニング") == 0);

  /* Track 2 */
  track = cd_get_track(cd, 2);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "城「ここで逢えるね」") == 0);

  /* Track 3 */
  track = cd_get_track(cd, 3);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "町「ペンタウアⅠ」") == 0);

  /* Track 4 */
  track = cd_get_track(cd, 4);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "町「ペンタウアⅡ」") == 0);

  /* Track 5 */
  track = cd_get_track(cd, 5);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "消えた王様の杖 - ダンジョン") == 0);

  /* Track 6 */
  track = cd_get_track(cd, 6);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "消えた王様の杖 - ヒドラ") == 0);

  /* Track 7 */
  track = cd_get_track(cd, 7);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "消えた王様の杖 - 生還") == 0);

  /* Track 8 */
  track = cd_get_track(cd, 8);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "消えた王様の杖 - トラベラーズ·イン") == 0);

  /* Track 9 */
  track = cd_get_track(cd, 9);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "失われたタリスマン - 森") == 0);

  /* Track 10 */
  track = cd_get_track(cd, 10);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "失われたタリスマン - 地下ダンジョン") == 0);

  /* Track 11 */
  track = cd_get_track(cd, 11);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "失われたタリスマン - 神官デルヒテ") == 0);

  /* Track 12 */
  track = cd_get_track(cd, 12);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "失われたタリスマン - サンド·マリボー") == 0);

  /* Track 13 (this is the actual conflicting track name) */
  track = cd_get_track(cd, 13);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "ルシフェルの水門 - 地下ダンジョン") == 0);

  /* Track 14 */
  track = cd_get_track(cd, 14);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "ルシフェルの水門 - クラーケン") == 0);

  /* Track 15 */
  track = cd_get_track(cd, 15);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "ルシフェルの水門 - ブラディー·リバー") == 0);

  /* Track 16 */
  track = cd_get_track(cd, 16);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "呪われたオアシス - 砂漠") == 0);

  /* Track 17 */
  track = cd_get_track(cd, 17);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "呪われたオアシス - 砂の城") == 0);

  /* Track 18 */
  track = cd_get_track(cd, 18);
  mu_assert("error getting track", track != NULL);
  cdtext = track_get_cdtext(track);
  mu_assert("error getting track CDTEXT", cdtext != NULL);
  val = cdtext_get(PTI_TITLE, cdtext);
  mu_assert("error getting track title", val != NULL);
  mu_assert("error validating track title",
            strcmp(val, "呪われたオアシス - ルワンとゴールド·ドラゴン") == 0);

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
