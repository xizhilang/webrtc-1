/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

/*
 * This file includes feature calculating functionality used in vad_core.c.
 */

#ifndef WEBRTC_COMMON_AUDIO_VAD_VAD_FILTERBANK_H_
#define WEBRTC_COMMON_AUDIO_VAD_VAD_FILTERBANK_H_

#include "typedefs.h"
#include "vad_core.h"

// Takes |data_length| samples of |data_in| and calculates the logarithm of the
// power of each of the |NUM_CHANNELS| = 6 frequency bands used by the VAD:
//        80 Hz - 250 Hz
//        250 Hz - 500 Hz
//        500 Hz - 1000 Hz
//        1000 Hz - 2000 Hz
//        2000 Hz - 3000 Hz
//        3000 Hz - 4000 Hz
//
// The values are given in Q4 and written to |data_out|. Further, an approximate
// overall power is returned. The return value is used in
// WebRtcVad_GmmProbability() as a signal indicator, hence it is arbitrary above
// the threshold MIN_ENERGY.
//
// - self         [i/o] : State information of the VAD.
// - data_in      [i]   : Input audio data, for feature extraction.
// - data_length  [i]   : Audio data size, in number of samples.
// - data_out     [o]   : 10 * log10(power in each frequency band), Q4.
// - returns            : Total power of the signal (NOTE! This value is not
//                        exact. It is only used in a comparison.)
int16_t WebRtcVad_CalculateFeatures(VadInstT* self, const int16_t* data_in,
                                    int data_length, int16_t* data_out);

#endif  // WEBRTC_COMMON_AUDIO_VAD_VAD_FILTERBANK_H_