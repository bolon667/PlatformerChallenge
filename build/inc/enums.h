#pragma once

#include <genesis.h>

typedef enum {
  TRIGGER_TYPE_changeLevel,
  TRIGGER_TYPE_changeLevelv2,
  TRIGGER_TYPE_deleteEntityMerged,
  TRIGGER_TYPE_executeScript,
  TRIGGER_TYPE_forceDownPlayer,
  TRIGGER_TYPE_forceLeftPlayer,
  TRIGGER_TYPE_forceRightPlayer,
  TRIGGER_TYPE_forceUpPlayer,
  TRIGGER_TYPE_gotSomething,
  TRIGGER_TYPE_hurt,
  TRIGGER_TYPE_printMessageNoStopV1,
  TRIGGER_TYPE_restartLevel,
  TRIGGER_TYPE_showMessage,
  TRIGGER_TYPE_solidObject,
  TRIGGER_TYPE_solidObjectOneWayUpTransferSpeed,
  TRIGGER_TYPE_solidObjectTransferSpeed,
} triggetType;

typedef enum {
  CUSTOM_SCRIPT_updatePlayer,
  CUSTOM_SCRIPT_updateCamera,
  CUSTOM_SCRIPT_freeCam1,
  CUSTOM_SCRIPT_moveBack1,
  CUSTOM_SCRIPT_showFPSWindow,
  CUSTOM_SCRIPT_testMainMenu,
  CUSTOM_SCRIPT_turnOnWindowMode1,
  CUSTOM_SCRIPT_uselessScript,
} customScriptEnum;

