#include <stdio.h>
#include <limits.h>
#include "automate.h"

#define TIMEOUT_DELTA(timeout) ((timeout) * 1000) //увеличение размера "шага" при симуляции в simintech
#define DELAY_DELTA(delay) ((delay) * 1000)

void pneumo_engine_init(struct PneumoEngine *engine) {
    if (engine != 0) {
        engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;

        engine->state = PneumoState_Init;
        engine->delay = 0;
        engine->timeout = 0;

        engine->timeouts[PneumoState_Init] = INT_MAX; //огромное значение из библиотеки limits.h
        engine->delays[PneumoState_Init] = INT_MAX;

        engine->timeouts[PneumoState_0] = TIMEOUT_DELTA(45);
        engine->delays[PneumoState_0] = DELAY_DELTA(70);

        engine->timeouts[PneumoState_1] = TIMEOUT_DELTA(60);
        engine->delays[PneumoState_1] = DELAY_DELTA(33);

        engine->timeouts[PneumoState_2] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_2] = DELAY_DELTA(33);

        engine->timeouts[PneumoState_3] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_3] = DELAY_DELTA(70);

        engine->timeouts[PneumoState_4] = TIMEOUT_DELTA(45);
        engine->delays[PneumoState_4] = DELAY_DELTA(70);

        engine->timeouts[PneumoState_5] = TIMEOUT_DELTA(30);
        engine->delays[PneumoState_5] = DELAY_DELTA(60);

        engine->timeouts[PneumoState_6] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_6] = DELAY_DELTA(45);

        engine->timeouts[PneumoState_7] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_7] = DELAY_DELTA(70);

        engine->timeouts[PneumoState_8] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_8] = DELAY_DELTA(78);

        engine->timeouts[PneumoState_9] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_9] = DELAY_DELTA(45);

        engine->timeouts[PneumoState_10] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_10] = DELAY_DELTA(45);

        engine->timeouts[PneumoState_11] = TIMEOUT_DELTA(45);
        engine->delays[PneumoState_11] = DELAY_DELTA(70);

        engine->timeouts[PneumoState_12] = TIMEOUT_DELTA(45);
        engine->delays[PneumoState_12] = DELAY_DELTA(33);

        engine->timeouts[PneumoState_13] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_13] = DELAY_DELTA(78);

        engine->timeouts[PneumoState_14] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_14] = DELAY_DELTA(78);

        engine->timeouts[PneumoState_15] = TIMEOUT_DELTA(30);
        engine->delays[PneumoState_15] = DELAY_DELTA(45);

        engine->timeouts[PneumoState_16] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_16] = DELAY_DELTA(33);

        engine->timeouts[PneumoState_17] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_17] = DELAY_DELTA(33);
    }
}
/*
void pneumo_engine_destroy(struct PneumoEngine *engine) {
    if (0 != engine) {
        //освобождение ресурсов
        return 0;
    }
}
*/

#define TIMEOUT_GE(engine) ( (engine)->timeout > (engine)->timeouts[(engine)->state] )
#define DELAY_GE(engine) ( (engine)->delay > (engine)->delays[(engine)->state] )

bool pneumo_engine_tick(struct PneumoEngine *engine) {
    static int n = 0;
    bool ret = true;
    if (0 == engine)
        return false;
    switch (engine->state) { // проверка состояния
        case PneumoState_Init: {
            engine->state = PneumoState_0;
            engine->delay = 0;
            engine->timeout = 0;
            break;
        }
        case PnState_0: {
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0; 
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) { 
                engine->state = PnState_2;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_1: {
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
        if (engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) { 
                engine->state = PnState_2;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = PnState_16;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_2: {
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 1;
        if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] ) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_3;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = PnState_16;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_3: {
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 1; 
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 1;
        if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_4;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_4: {
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0; 
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_5;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_5: {
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
        engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_6;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_6: {
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_7;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_7: {
        engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 1;
        if (engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_8;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_8: {
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0; 
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_9;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_9: {
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 1;
        if (engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
        engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
        engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
        engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_10;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_10: {
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
        engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_11;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_11: { 
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) { 
                engine->state = PnState_12;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_12: {
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_13;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_13: {
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
        engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_14;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_14: {
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 1;
        if (engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_15;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_15: {
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
        if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_16;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_16: {
        engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
            engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
            engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_17;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    case PnState_17: {
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
        if (engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
        engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
            engine->timeout = 0;
            engine->delay++;
            if (DELAY_GE(engine)) {
                engine->state = PnState_0;
                engine->delay = 0;
                engine->timeout = 0;
            }
        }
        else if (TIMEOUT_GE(engine)) {
            engine->state = Exception;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            engine->delay = 0;
            engine->timeout = 0;
        }
        break;
    }
    }
    engine->timeout++;
    engine->delay++;
    return ret;
}
