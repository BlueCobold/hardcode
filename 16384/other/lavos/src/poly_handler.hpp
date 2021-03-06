#ifndef POLY_HANDLER_HPP
#define POLY_HANDLER_HPP

#include "delay.hpp"
#include "parameters.h"
#include "voice.hpp"

/** Maximum number of voices to handle.
 *
 * Don't know if this should be dynamic, leaving like this for now.
 */
#define NUM_VOICES 16

/** \brief Polyphony handler class.
 *
 * Handles which notes get routed to which voices.
 *
 * Idea and parts of code lifted from Niall Moody's Polyphonic Synth Tutorial at
 * http://www.niallmoody.com/ndcplugs/programming.htm
 * 
 * See MIDI2Freq.h for the required copyright notice.
 */
class PolyHandler
{
  public:
    /** \brief Fake constructor.
     *
     * @param params Parameters.
     * @param num_params Parameter count.
     */
    void init(int params[], int num_params);

    ///	Called when the plugin receives a MIDI note on message.
    /*!
      We look for the first voice not currently active, and call it's
      noteOn() method, assigning it this note.
      */
    void noteOn(int note, float velocity);
    ///	Called when the plugin receives a MIDI note off message.
    /*!
      Find the voice associated with this note, and call it's noteOff()
      method.  Remember that, according to the length of the voice's
      envelope's release section, it won't stop outputting sound
      immediately.  We need to check each active voice in getSample() to
      determine whether or not it's still active.
      */
    void noteOff(int note);
    void allNotesOff();
    bool getIsActive();

    ///	Called when the plugin's setParameter() method is called.
    /*!
      All calls just get passed on to the voices in this case.
      */
    void setParameter(int parameter, float value);

    /*obsolete,remove
      void setPitchBend(float val);
    ///	Called whenever the plugin checks the samplerate, usually in resume().
    void setSamplerate(float samplerate);
    void setADSR(float attack, float decay, float sustain, float release);
    void setEnvLength(float envlength);
    void setOsc1(int waveform, float detune, float volume);
    void setOsc2(int waveform, float detune, float volume);
    */

    ///	Called for every sample in the plugin's process/processReplacing loop.
    /*!
      Returns the current sample.
      This isn't the most efficient way of doing things, but it's simpler
      imo, and easier to understand.
      */
    void getSample(float &leftsample, float &rightsample);

  private:

    ///	Array of voices.
    Voice m_voices[NUM_VOICES];

    int m_num_active_voices;

    ///	Holds the currently-assigned note values for each voice.
    int m_notes[NUM_VOICES];
    // total synth volume
    float m_volume;
    float m_pan;
    Delay m_delay;
};

#endif
