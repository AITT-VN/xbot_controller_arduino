#include "Tone32.h"
#include "setting.h"

void tone(unsigned int frequency, unsigned long duration)
{
    if (ledcRead(BUZZER_CHANNEL)) {
        log_e("Tone channel %d is already in use", ledcRead(BUZZER_CHANNEL));
        return;
    }
    ledcAttachPin(BUZZER, BUZZER_CHANNEL);
    ledcWriteTone(BUZZER_CHANNEL, frequency);
    if (duration) {
        delay(duration);
        noTone();
    }    
}

void noTone()
{
    ledcDetachPin(BUZZER);
    ledcWrite(BUZZER_CHANNEL, 0);
}
