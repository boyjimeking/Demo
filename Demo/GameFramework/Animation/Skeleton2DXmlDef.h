#pragma once
#include "SkeletonDef.h"

namespace Skel2D
{

static const char* VERSION = "1.4";

static const double ANGLE_TO_RADIAN = M_PI / 180.0;

static const char* SKELETON = "skeleton";

static const char* ARMATURES = "armatures";
static const char* ARMATURE = "armature";
static const char* BONE = "b";
static const char* DISPLAY = "d";

static const char* ANIMATIONS = "animations";
static const char* ANIMATION = "animation";
static const char* MOVEMENT = "mov";
static const char* FRAME = "f";

static const char* TEXTURE_ATLAS = "TextureAtlas";
static const char* SUB_TEXTURE = "SubTexture";

static const char* AT = "@";
static const char* A_VERSION = "version";
static const char* A_FRAME_RATE = "frameRate";
static const char* A_NAME = "name";
static const char* A_START = "st";
static const char* A_DURATION = "dr";
static const char* A_DURATION_TO = "to";
static const char* A_DURATION_TWEEN = "drTW";
static const char* A_LOOP = "lp";
static const char* A_MOVEMENT_SCALE = "sc";
static const char* A_MOVEMENT_DELAY = "dl";

static const char* A_PARENT = "parent";
static const char* A_SKEW_X = "kX";
static const char* A_SKEW_Y = "kY";
static const char* A_SCALE_X = "cX";
static const char* A_SCALE_Y = "cY";
static const char* A_Z = "z";
static const char* A_DISPLAY_INDEX = "dI";
static const char* A_EVENT = "evt";
static const char* A_SOUND = "sd";
static const char* A_SOUND_EFFECT = "sdE";
static const char* A_TWEEN_EASING ="twE";
static const char* A_TWEEN_ROTATE ="twR";
static const char* A_IS_ARMATURE = "isArmature";
static const char* A_MOVEMENT = "mov";

static const char* A_X = "x";
static const char* A_Y = "y";
static const char* A_WIDTH = "width";
static const char* A_HEIGHT = "height";
static const char* A_PIVOT_X = "pX";
static const char* A_PIVOT_Y = "pY";

static const char* V_SOUND_LEFT = "l";
static const char* V_SOUND_RIGHT = "r";
static const char* V_SOUND_LEFT_TO_RIGHT = "lr";
static const char* V_SOUND_RIGHT_TO_LEFT = "rl";
static const char* V_SOUND_FADE_IN = "in";
static const char* V_SOUND_FADE_OUT = "out";

}