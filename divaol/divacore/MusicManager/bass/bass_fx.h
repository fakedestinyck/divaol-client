/****************************************************************************
 BASS_FX 2.4 - Copyright (c) 2002-2012 (: JOBnik! :) [Arthur Aminov, ISRAEL]
                                                     [http://www.jobnik.org]

      bugs/suggestions/questions:
        forum  : http://www.un4seen.com/forum/?board=1
                 http://www.jobnik.org/smforum
        e-mail : bass_fx@jobnik.org
     --------------------------------------------------

 NOTE: This header will work only with BASS_FX version 2.4.8
       Check www.un4seen.com or www.jobnik.org for any later versions.

 * Requires BASS 2.4 (available @ www.un4seen.com)
****************************************************************************/

#ifndef BASS_FX_H
#define BASS_FX_H

#ifdef __cplusplus
  extern "C" {
#endif

#ifndef BASS_FXDEF
  #define BASS_FXDEF(f) WINAPI f
#endif

// Error codes returned by BASS_ErrorGetCode()
#define BASS_ERROR_FX_NODECODE		4000	// Not a decoding channel
#define BASS_ERROR_FX_BPMINUSE		4001	// BPM/Beat detection is in use

// Tempo / Reverse / BPM / Beat flag
#define BASS_FX_FREESOURCE			0x10000	// Free the source handle as well?

// BASS_FX Version
DWORD BASS_FXDEF(BASS_FX_GetVersion)();

/*=============================================================================================
	D S P (Digital Signal Processing)
==============================================================================================*/

/*
	Multi-channel order of each channel is as follows:
	 3 channels       left-front, right-front, center.
	 4 channels       left-front, right-front, left-rear/side, right-rear/side.
	 6 channels (5.1) left-front, right-front, center, LFE, left-rear/side, right-rear/side.
	 8 channels (7.1) left-front, right-front, center, LFE, left-rear/side, right-rear/side, left-rear center, right-rear center.
*/

// DSP channels flags
#define BASS_BFX_CHANALL	-1				// all channels at once (as by default)
#define BASS_BFX_CHANNONE	0				// disable an effect for all channels
#define BASS_BFX_CHAN1		1				// left-front channel
#define BASS_BFX_CHAN2		2				// right-front channel
#define BASS_BFX_CHAN3		4				// see above info
#define BASS_BFX_CHAN4		8				// see above info
#define BASS_BFX_CHAN5		16				// see above info
#define BASS_BFX_CHAN6		32				// see above info
#define BASS_BFX_CHAN7		64				// see above info
#define BASS_BFX_CHAN8		128				// see above info

// if you have more than 8 channels, use this macro
#define BASS_BFX_CHANNEL_N(n) (1<<((n)-1))

// DSP effects
enum {
	BASS_FX_BFX_ROTATE = 0x10000,			// A channels volume ping-pong	/ stereo
	BASS_FX_BFX_ECHO,						// Echo							/ 2 channels max
	BASS_FX_BFX_FLANGER,					// Flanger						/ multi channel
	BASS_FX_BFX_VOLUME,						// Volume						/ multi channel
	BASS_FX_BFX_PEAKEQ,						// Peaking Equalizer			/ multi channel
	BASS_FX_BFX_REVERB,						// Reverb						/ 2 channels max
	BASS_FX_BFX_LPF,						// Low Pass Filter 24dB			/ multi channel
	BASS_FX_BFX_MIX,						// Swap, remap and mix channels	/ multi channel
	BASS_FX_BFX_DAMP,						// Dynamic Amplification		/ multi channel
	BASS_FX_BFX_AUTOWAH,					// Auto WAH						/ multi channel
	BASS_FX_BFX_ECHO2,						// Echo 2						/ multi channel
	BASS_FX_BFX_PHASER,						// Phaser						/ multi channel
	BASS_FX_BFX_ECHO3,						// Echo 3						/ multi channel
	BASS_FX_BFX_CHORUS,						// Chorus						/ multi channel
	BASS_FX_BFX_APF,						// All Pass Filter				/ multi channel
	BASS_FX_BFX_COMPRESSOR,					// Compressor					/ multi channel
	BASS_FX_BFX_DISTORTION,					// Distortion					/ multi channel
	BASS_FX_BFX_COMPRESSOR2,				// Compressor 2					/ multi channel
	BASS_FX_BFX_VOLUME_ENV,					// Volume envelope				/ multi channel
	BASS_FX_BFX_BQF							// BiQuad filters				/ multi channel
};

// BiQuad filters
enum {
	BASS_BFX_BQF_LOWPASS,
	BASS_BFX_BQF_HIGHPASS,
	BASS_BFX_BQF_BANDPASS,					// constant 0 dB peak gain
	BASS_BFX_BQF_BANDPASS_Q,				// constant skirt gain, peak gain = Q
	BASS_BFX_BQF_NOTCH,
	BASS_BFX_BQF_ALLPASS,
	BASS_BFX_BQF_PEAKINGEQ,
	BASS_BFX_BQF_LOWSHELF,
	BASS_BFX_BQF_HIGHSHELF
};

// Echo
typedef struct {
	float fLevel;							// [0....1....n] linear
	int   lDelay;							// [1200..30000]
} BASS_BFX_ECHO;

// Flanger
typedef struct {
	float fWetDry;							// [0....1....n] linear
	float fSpeed;							// [0......0.09]
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_FLANGER;

// Volume
typedef struct {
	int   lChannel;							// BASS_BFX_CHANxxx flag/s or 0 for global volume control
	float fVolume;							// [0....1....n] linear
} BASS_BFX_VOLUME;

// Peaking Equalizer
typedef struct {
	int   lBand;							// [0...............n] more bands means more memory & cpu usage
	float fBandwidth;						// [0.1...........<10] in octaves - fQ is not in use (Bandwidth has a priority over fQ)
	float fQ;								// [0...............1] the EE kinda definition (linear) (if Bandwidth is not in use)
	float fCenter;							// [1Hz..<info.freq/2] in Hz
	float fGain;							// [-15dB...0...+15dB] in dB
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_PEAKEQ;

// Reverb
typedef struct {
	float fLevel;							// [0....1....n] linear
	int   lDelay;							// [1200..10000]
} BASS_BFX_REVERB;

// Low Pass Filter
typedef struct {
	float fResonance;						// [0.01...........10]
	float fCutOffFreq;						// [1Hz...info.freq/2] cutoff frequency
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_LPF;

// Swap, remap and mix
typedef struct {
	const int *lChannel;					// an array of channels to mix using BASS_BFX_CHANxxx flag/s (lChannel[0] is left channel...)
} BASS_BFX_MIX;

// Dynamic Amplification
typedef struct {
	float fTarget;							// target volume level						[0<......1] linear
	float fQuiet; 							// quiet  volume level						[0.......1] linear
	float fRate;							// amp adjustment rate						[0.......1] linear
	float fGain;							// amplification level						[0...1...n] linear
	float fDelay;							// delay in seconds before increasing level	[0.......n] linear
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_DAMP;

// Auto WAH
typedef struct {
	float fDryMix;							// dry (unaffected) signal mix				[-2......2]
	float fWetMix;							// wet (affected) signal mix				[-2......2]
	float fFeedback;						// feedback									[-1......1]
	float fRate;							// rate of sweep in cycles per second		[0<....<10]
	float fRange;							// sweep range in octaves					[0<....<10]
	float fFreq;							// base frequency of sweep Hz				[0<...1000]
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_AUTOWAH;

// Echo 2
typedef struct {
	float fDryMix;							// dry (unaffected) signal mix				[-2......2]
	float fWetMix;							// wet (affected) signal mix				[-2......2]
	float fFeedback;						// feedback									[-1......1]
	float fDelay;							// delay sec								[0<......n]
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_ECHO2;

// Phaser
typedef struct {
	float fDryMix;							// dry (unaffected) signal mix				[-2......2]
	float fWetMix;							// wet (affected) signal mix				[-2......2]
	float fFeedback;						// feedback									[-1......1]
	float fRate;							// rate of sweep in cycles per second		[0<....<10]
	float fRange;							// sweep range in octaves					[0<....<10]
	float fFreq;							// base frequency of sweep					[0<...1000]
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_PHASER;

// Echo 3
typedef struct {
	float fDryMix;							// dry (unaffected) signal mix				[-2......2]
	float fWetMix;							// wet (affected) signal mix				[-2......2]
	float fDelay;							// delay sec								[0<......n]
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_ECHO3;

// Chorus
typedef struct {
	float fDryMix;							// dry (unaffected) signal mix				[-2......2]
	float fWetMix;							// wet (affected) signal mix				[-2......2]
	float fFeedback;						// feedback									[-1......1]
	float fMinSweep;						// minimal delay ms							[0<...6000]
	float fMaxSweep;						// maximum delay ms							[0<...6000]
	float fRate;							// rate ms/s								[0<...1000]
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_CHORUS;

// All Pass Filter
typedef struct {
	float fGain;							// reverberation time						[-1=<..<=1]
	float fDelay;							// delay sec								[0<....<=n]
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_APF;

// Compressor
typedef struct {
	float fThreshold;						// compressor threshold						[0<=...<=1]
	float fAttacktime;						// attack time ms							[0<.<=1000]
	float fReleasetime;						// release time ms							[0<.<=5000]
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_COMPRESSOR;

// Distortion
typedef struct {
	float fDrive;							// distortion drive							[0<=...<=5]
	float fDryMix;							// dry (unaffected) signal mix				[-5<=..<=5]
	float fWetMix;							// wet (affected) signal mix				[-5<=..<=5]
	float fFeedback;						// feedback									[-1<=..<=1]
	float fVolume;							// distortion volume						[0=<...<=2]
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_DISTORTION;

// Compressor 2
typedef struct {
	float fGain;							// output gain of signal after compression	[-60....60] in dB
	float fThreshold;						// point at which compression begins		[-60.....0] in dB
	float fRatio;							// compression ratio						[1.......n]
	float fAttack;							// attack time in ms						[0.01.1000]
	float fRelease;							// release time in ms						[0.01.5000]
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_COMPRESSOR2; 

// Volume envelope
typedef struct {
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
	int   lNodeCount;						// number of nodes
	const struct BASS_BFX_ENV_NODE *pNodes;	// the nodes
	BOOL  bFollow;							// follow source position
} BASS_BFX_VOLUME_ENV;

#pragma pack(push,4)
typedef struct BASS_BFX_ENV_NODE {
	double pos;								// node position in seconds (1st envelope node must be at position 0)
	float  val;								// node value
} BASS_BFX_ENV_NODE;
#pragma pack(pop)

// BiQuad Filters
typedef struct {
	int   lFilter;							// BASS_BFX_BQF_xxx filter types
	float fCenter;							// [1Hz..<info.freq/2] Cutoff (central) frequency in Hz
	float fGain;							// [-15dB...0...+15dB] Used only for PEAKINGEQ and Shelving filters in dB
	float fBandwidth;						// [0.1...........<10] Bandwidth in octaves (fQ is not in use (fBandwidth has a priority over fQ))
											// 						(between -3 dB frequencies for BANDPASS and NOTCH or between midpoint
											// 						(fGgain/2) gain frequencies for PEAKINGEQ)
	float fQ;								// [0.1.............1] The EE kinda definition (linear) (if fBandwidth is not in use)
	float fS;								// [0.1.............1] A "shelf slope" parameter (linear) (used only with Shelving filters)
											// 						when fS = 1, the shelf slope is as steep as you can get it and remain monotonically
											// 						increasing or decreasing gain with frequency.
	int   lChannel;							// BASS_BFX_CHANxxx flag/s
} BASS_BFX_BQF;

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	set dsp fx - BASS_ChannelSetFX
 =============================================================================================
	remove dsp fx - BASS_ChannelRemoveFX
 =============================================================================================
	set parameters - BASS_FXSetParameters
 =============================================================================================
	retrieve parameters - BASS_FXGetParameters
 =============================================================================================
	reset the state - BASS_FXReset
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

/*=============================================================================================
	TEMPO / PITCH SCALING / SAMPLERATE
==============================================================================================*/

// NOTES: 1. Supported only - mono / stereo - channels
//        2. Enable Tempo supported flags in BASS_FX_TempoCreate and the others to source handle.

// tempo attributes (BASS_ChannelSet/GetAttribute)
enum {
	BASS_ATTRIB_TEMPO = 0x10000,
	BASS_ATTRIB_TEMPO_PITCH,
	BASS_ATTRIB_TEMPO_FREQ
};

// tempo attributes options
//		[option]											[value]
enum {
	BASS_ATTRIB_TEMPO_OPTION_USE_AA_FILTER = 0x10010,	// TRUE (default) / FALSE
	BASS_ATTRIB_TEMPO_OPTION_AA_FILTER_LENGTH,			// 32 default (8 .. 128 taps)
	BASS_ATTRIB_TEMPO_OPTION_USE_QUICKALGO,				// TRUE / FALSE (default)
	BASS_ATTRIB_TEMPO_OPTION_SEQUENCE_MS,				// 82 default, 0 = automatic
	BASS_ATTRIB_TEMPO_OPTION_SEEKWINDOW_MS,				// 28 default, 0 = automatic
	BASS_ATTRIB_TEMPO_OPTION_OVERLAP_MS,				// 8  default
	BASS_ATTRIB_TEMPO_OPTION_PREVENT_CLICK				// TRUE / FALSE (default)
};

HSTREAM BASS_FXDEF(BASS_FX_TempoCreate)(DWORD chan, DWORD flags);
DWORD BASS_FXDEF(BASS_FX_TempoGetSource)(HSTREAM chan);
float BASS_FXDEF(BASS_FX_TempoGetRateRatio)(HSTREAM chan);

/*=============================================================================================
	R E V E R S E
==============================================================================================*/

// NOTES: 1. MODs won't load without BASS_MUSIC_PRESCAN flag.
//		  2. Enable Reverse supported flags in BASS_FX_ReverseCreate and the others to source handle.

// reverse attribute (BASS_ChannelSet/GetAttribute)
#define BASS_ATTRIB_REVERSE_DIR 0x11000

// playback directions
#define BASS_FX_RVS_REVERSE -1
#define BASS_FX_RVS_FORWARD 1

HSTREAM BASS_FXDEF(BASS_FX_ReverseCreate)(DWORD chan, float dec_block, DWORD flags);
DWORD BASS_FXDEF(BASS_FX_ReverseGetSource)(HSTREAM chan);

/*=============================================================================================
	B P M (Beats Per Minute)
==============================================================================================*/

// bpm flags
#define BASS_FX_BPM_BKGRND	1	// if in use, then you can do other processing while detection's in progress. Not available in MacOSX yet. (BPM/Beat)
#define BASS_FX_BPM_MULT2	2	// if in use, then will auto multiply bpm by 2 (if BPM < minBPM*2)

// translation options
enum {
	BASS_FX_BPM_TRAN_X2,		// multiply the original BPM value by 2 (may be called only once & will change the original BPM as well!)
	BASS_FX_BPM_TRAN_2FREQ,		// BPM value to Frequency
	BASS_FX_BPM_TRAN_FREQ2,		// Frequency to BPM value
	BASS_FX_BPM_TRAN_2PERCENT,	// BPM value to Percents
	BASS_FX_BPM_TRAN_PERCENT2	// Percents to BPM value
};

typedef void (CALLBACK BPMPROCESSPROC)(DWORD chan, float percent, void *user);
typedef void (CALLBACK BPMPROC)(DWORD chan, float bpm, void *user);

float BASS_FXDEF(BASS_FX_BPM_DecodeGet)(DWORD chan, double startSec, double endSec, DWORD minMaxBPM, DWORD flags, BPMPROCESSPROC *proc, void *user);
BOOL BASS_FXDEF(BASS_FX_BPM_CallbackSet)(DWORD handle, BPMPROC *proc, double period, DWORD minMaxBPM, DWORD flags, void *user);
BOOL BASS_FXDEF(BASS_FX_BPM_CallbackReset)(DWORD handle);
float BASS_FXDEF(BASS_FX_BPM_Translate)(DWORD handle, float val2tran, DWORD trans);
BOOL BASS_FXDEF(BASS_FX_BPM_Free)(DWORD handle);

/*=============================================================================================
	B E A T
==============================================================================================*/

typedef void (CALLBACK BPMBEATPROC)(DWORD chan, double beatpos, void *user);

BOOL BASS_FXDEF(BASS_FX_BPM_BeatCallbackSet)(DWORD handle, BPMBEATPROC *proc, void *user);
BOOL BASS_FXDEF(BASS_FX_BPM_BeatCallbackReset)(DWORD handle);
BOOL BASS_FXDEF(BASS_FX_BPM_BeatDecodeGet)(DWORD chan, double startSec, double endSec, DWORD flags, BPMBEATPROC *proc, void *user);
BOOL BASS_FXDEF(BASS_FX_BPM_BeatSetParameters)(DWORD handle, float bandwidth, float centerfreq, float beat_rtime);
BOOL BASS_FXDEF(BASS_FX_BPM_BeatGetParameters)(DWORD handle, float *bandwidth, float *centerfreq, float *beat_rtime);
BOOL BASS_FXDEF(BASS_FX_BPM_BeatFree)(DWORD handle);

#ifdef __cplusplus
}
#endif

#endif