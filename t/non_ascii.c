#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libcue.h"
#include "minunit.h"

/* TODO
bad character '�'
bad character '�'
bad character '�'
*/
int tests_run;
static char cue[] =
// ↓ copy-pasted from gdb (2)
"﻿REM GENRE Game\r\nREM DATE 1991/07/21\r\nREM DISCID EF0A9212\r\nREM COMMENT ExactAudioCopy v0.99pb4\r\nPERFORMER \"Falcom Sound Team J.D.K.\"\r\nTITLE \"パーフェクト·コレクション·ソーサリアン DISC1\"\r\nFILE \"CDImage.flac\" WAVE\r\n  TRACK 01 AUDIO\r\n    TITLE \"オープニング\"\r\n    INDEX 01 00:00:00\r\n  TRACK 02 AUDIO\r\n    TITLE \"城「ここで逢えるね」\"\r\n    INDEX 01 01:12:70\r\n  TRACK 03 AUDIO\r\n    TITLE \"町「ペンタウアⅠ」\"\r\n    INDEX 01 03:39:47\r\n  TRACK 04 AUDIO\r\n    TITLE \"町「ペンタウアⅡ」\"\r\n    INDEX 01 05:56:17\r\n  TRACK 05 AUDIO\r\n    TITLE \"消えた王様の杖 - ダンジョン\"\r\n    INDEX 01 07:51:22\r\n  TRACK 06 AUDIO\r\n    TITLE \"消えた王様の杖 - ヒドラ\"\r\n    INDEX 01 09:53:12\r\n  TRACK 07 AUDIO\r\n    TITLE \"消えた王様の杖 - 生還\"\r\n    INDEX 01 12:11:10\r\n  TRACK 08 AUDIO\r\n    TITLE \"消えた王様の杖 - トラベラーズ·イン\"\r\n    INDEX 01 14:23:50\r\n  TRACK 09 AUDIO\r\n    TITLE \"失われたタリスマン - 森\"\r\n    INDEX 01 16:49:17\r\n  TRACK 10 AUDIO\r\n    TITLE \"失われたタリスマン - 地下ダンジョン\"\r\n    INDEX 01 19:00:50\r\n  TRACK 11 AUDIO\r\n    TITLE \"失われたタリスマン - 神官デルヒテ\"\r\n    INDEX 01 21:16:25\r\n  TRACK 12 AUDIO\r\n    TITLE \"失われたタリスマン - サンド·マリボー\"\r\n    INDEX 01 23:53:17\r\n  TRACK 13 AUDIO\r\n    TITLE \"ルシフェルの水門 - 地下ダンジョン\"\r\n    INDEX 01 26:11:17\r\n  TRACK 14 AUDIO\r\n    TITLE \"ルシフェルの水門 - クラーケン\"\r\n    INDEX 01 30:39:07\r\n  TRACK 15 AUDIO\r\n    TITLE \"ルシフェルの水門 - ブラディー·リバー\"\r\n    INDEX 01 32:08:22\r\n  TRACK 16 AUDIO\r\n    TITLE \"呪われたオアシス - 砂漠\"\r\n    INDEX 01 36:06:30\r\n  TRACK 17 AUDIO\r\n    TITLE \"呪われたオアシス - 砂の城\"\r\n    INDEX 01 39:23:25\r\n  TRACK 18 AUDIO\r\n    TITLE \"呪われたオアシス - ルワンとゴールド·ドラゴン\"\r\n    INDEX 01 42:56:72";
    // "REM GENRE Game\n"
    // "REM DATE 1991/07/21\n"
    // "REM DISCID EF0A9212\n"
    // "REM COMMENT ExactAudioCopy v0.99pb4\n"
    // "PERFORMER \"Falcom Sound Team J.D.K.\"\n"
    // "TITLE \"パーフェクト·コレクション·ソーサリアン DISC1\"\n"
    // "FILE \"CDImage.flac\" WAVE\n"
    // "  TRACK 01 AUDIO\n"
    // "    TITLE \"オープニング\"\n"
    // "    INDEX 01 00:00:00\n"
    // "  TRACK 02 AUDIO\n"
    // "    TITLE \"城「ここで逢えるね」\"\n"
    // "    INDEX 01 01:12:70\n"
    // "  TRACK 03 AUDIO\n"
    // "    TITLE \"町「ペンタウアⅠ」\"\n"
    // "    INDEX 01 03:39:47\n"
    // "  TRACK 04 AUDIO\n"
    // "    TITLE \"町「ペンタウアⅡ」\"\n"
    // "    INDEX 01 05:56:17\n"
    // "  TRACK 05 AUDIO\n"
    // "    TITLE \"消えた王様の杖 - ダンジョン\"\n"
    // "    INDEX 01 07:51:22\n"
    // "  TRACK 06 AUDIO\n"
    // "    TITLE \"消えた王様の杖 - ヒドラ\"\n"
    // "    INDEX 01 09:53:12\n"
    // "  TRACK 07 AUDIO\n"
    // "    TITLE \"消えた王様の杖 - 生還\"\n"
    // "    INDEX 01 12:11:10\n"
    // "  TRACK 08 AUDIO\n"
    // "    TITLE \"消えた王様の杖 - トラベラーズ·イン\"\n"
    // "    INDEX 01 14:23:50\n"
    // "  TRACK 09 AUDIO\n"
    // "    TITLE \"失われたタリスマン - 森\"\n"
    // "    INDEX 01 16:49:17\n"
    // "  TRACK 10 AUDIO\n"
    // "    TITLE \"失われたタリスマン - 地下ダンジョン\"\n"
    // "    INDEX 01 19:00:50\n"
    // "  TRACK 11 AUDIO\n"
    // "    TITLE \"失われたタリスマン - 神官デルヒテ\"\n"
    // "    INDEX 01 21:16:25\n"
    // "  TRACK 12 AUDIO\n"
    // "    TITLE \"失われたタリスマン - サンド·マリボー\"\n"
    // "    INDEX 01 23:53:17\n"
    // "  TRACK 13 AUDIO\n"
    // "    TITLE \"ルシフェルの水門 - 地下ダンジョン\"\n"
    // "    INDEX 01 26:11:17\n"
    // "  TRACK 14 AUDIO\n"
    // "    TITLE \"ルシフェルの水門 - クラーケン\"\n"
    // "    INDEX 01 30:39:07\n"
    // "  TRACK 15 AUDIO\n"
    // "    TITLE \"ルシフェルの水門 - ブラディー·リバー\"\n"
    // "    INDEX 01 32:08:22\n"
    // "  TRACK 16 AUDIO\n"
    // "    TITLE \"呪われたオアシス - 砂漠\"\n"
    // "    INDEX 01 36:06:30\n"
    // "  TRACK 17 AUDIO\n"
    // "    TITLE \"呪われたオアシス - 砂の城\"\n"
    // "    INDEX 01 39:23:25\n"
    // "  TRACK 18 AUDIO\n"
    // "    TITLE \"呪われたオアシス - ルワンとゴールド·ドラゴン\"\n"
    // "    INDEX 01 42:56:72\n";

static char *cue_test() {
  // FILE *cue = fopen("non_ascii.cue", "r");
  // mu_assert("error reading cue file", cue);
  // Cd *cd = cue_parse_file(cue);
  Cd *cd = cue_parse_string(cue);
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
