// Copyright (c) 2021 Jan Delgado <jdelgado[at]gmx.net>
// https://github.com/jandelgado/carl
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//
#pragma once
#include <Arduino.h>

// uncomment to use large folder DFPlayer API with up to 3000 mp3s in a folder.
// files are named "##/####*.mp3" then. Does not work with all DFPlayers,
// otherwise files are named "##/###*.mp3", with only up to 255 file per folder.
// #define USE_LARGE_FOLDERS

// uncomment to disable logging
//#define NO_LOGGING

// uncomment to enable the config mode option
// #define ENABLE_CONFIG_MODEf

// Select  DFPlayerMini driver lib to use.
// Don't forget to install the needed lib!
//
// Leave untouched to use default (Powerbroker driver) or if you set
// the library in your platform.ini file. Otherwise uncomment driver to use.
// See also mp3_driver_factory.h
#define USE_MAKUNA_MP3_DRIVER //library name: DFPlayerMini_Fast
//#define USE_DFROBOT_MP3_DRIVER //library name: DFRobotDFPlayerMini
//#define USE_POWERBROKER_MP3_DRIVER //library name: DFPlayer Mini Mp3 by Makuna

// Hardware configuration - where stuff is connected / Konfiguration der
// genutzen GPIO am Arduino Pro Mini.
constexpr uint8_t PIN_BUTTONS = A3;
constexpr uint8_t PIN_VOLUME = A2;
constexpr uint8_t PIN_VOLUME_POWER = 3;
constexpr uint8_t PIN_RX = 10;
constexpr uint8_t PIN_TX = 11;
constexpr uint8_t PIN_LED = 12;
constexpr uint8_t PP_LED = 8;
constexpr uint8_t NEXT_LED = 6;
constexpr uint8_t PREV_LED = 7;
constexpr uint8_t PIN_DFPLAYER_BUSY = 5;
