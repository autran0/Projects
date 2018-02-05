/// \file sound.h
/// \brief Interface for the sound manager class CSoundManager.

/// Created by Ian Parberry to accompany his book
/// "Introduction to Game Physics with Box2D", published by CRC Press in 2013.
/// Copyright Ian Parberry, Laboratory for Recreational Computing,
/// Department of Computer Science & Engineering, University of North
/// Texas, Denton, TX, USA. URL: http://larc.unt.edu/ian.
///
/// This file is made available under the GNU All-Permissive License.
/// Copying and distribution of this file, with or without
/// modification, are permitted in any medium without royalty
/// provided the copyright notice and this notice are preserved.
/// This file is offered as-is, without any warranty.

#pragma once

#include <Audio.h>

#include "Defines.h"
#include "Abort.h"

using namespace std;

/// \brief The sound manager. 
///
/// The sound manager allows you to play multiple 
/// overlapping copies of sounds simultaneously.  It reads settings from the
/// XML settings file, including a list of file names to be loaded. It can load
/// WAV format sounds. 

class CSoundManager{
  private:
    AudioEngine* m_pAudioEngine; ///< XAudio 2.8 Engine wrapped up in DirectXTK.
    vector<SoundEffect*> m_pSoundEffects; ///< A list of sound effect.
    SoundEffectInstance*** m_pInstance; ///< A list of arrays of sound effect instances.

    int* m_nInstanceCount; ///< Number of copies of each sound.

    int m_nCount; ///< Number of sounds loaded.
    int m_nMaxSounds; ///< Maximum number of sounds allowed.
    int m_nLastPlayedSound; ///< Last sound played.
    int m_nLastPlayedInstance; ///< Instance of the last sound played.

    BOOL g_bMuted; ///< Whether mute is on.

    void createInstances(int index, int n, SOUND_EFFECT_INSTANCE_FLAGS flags); ///< Create sound instances.
    int Load(wchar_t *filename); ///< Load sound from file.
    int getNextInstance(int index); ///< Get the next instance that is not playing.

  public:
    CSoundManager(); ///< Constructor.
    ~CSoundManager(); ///< Destructor.
    void Load(); ///< Load sounds from list in XML document.

    int play(int index); ///< Play a sound.
    int loop(int index); ///< Play a sound looped.

    void move(Vector3 ePos, int instance=-1, int index=-1); ///< Move sound relative to plane.
    void pitch(float p, int instance=-1, int index=-1); ///< Set sound pitch.
    void volume(float v, int instance=-1, int index=-1); ///< Set sound volume.

    void mute(); ///< Mute/unmute the sounds.
}; //CSoundManager