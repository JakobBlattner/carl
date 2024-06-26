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
#include <AnalogMultiButton.h>
#include "key_events.h"
#include "key_event_source.h"

class Keypad : public KeyEventSource {
 public:
    explicit Keypad(int pin);
    void update() override;

    // return logical key event of last key press or KeyEvent::kNone if no
    // key was pressed
    KeyEvent::Type getKeyEvent() override;

 private:
    // ** ADD YOUR OWN VALUES HERE / HIER EIGENE WERTE EINTRAGEN **
    //
    // The 12 buttons are connected through one analog input using a resistor
    // network. The actual values depend on the resistor used in the circuit.
    // The values therefore need to be determined by a simple script:
    //    loop(){Serial.println(analogRead(PIN_BUTTONS);}
    //
    // We use a slightly modified circuit, so that current will flow only when a
    // button is pressed (i.e. VCC and GND reversed).  We have to use two tricks
    // to use the AnalogButtons library with our button circuit to work without
    // modifications 1) insert dummy button (100) to catch 0V case  when no
    // button is pressed 2) set analog resoultion to 1100 to detect the 5V
    // (1023) case for button #12.
    //
    static constexpr int button_values_[] = {
        0, /* dummy button 0, will be ignored */
        486, 511, 538, 568, 601, 639, 682, 730, 787, 853, 931, 1023};
        //{bnext, b9, b6, b3, b2, b5, b8, bpp, b7, b4, bprev, b1}

    constexpr static uint16_t kAnalogResolution = 1100;
    constexpr static uint16_t kDebounceDurationMs = 20;

    // time [ms] for long/short keypresses.
    constexpr static uint16_t kDurationLongPressMs = 2000;
    constexpr static uint16_t kDurationShortPressMs = 500;

    AnalogMultiButton buttons_;
};
