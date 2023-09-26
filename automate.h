#ifndef KR_AUTOMATE_H
#define KR_AUTOMATE_H
#include <stdbool.h>

enum PneumoState {
    PneumoState_Init = 0,
    PneumoState_0, PneumoState_1, PneumoState_2,
    PneumoState_3, PneumoState_4, PneumoState_5,
    PneumoState_6, PneumoState_7, PneumoState_8,
    PneumoState_9, PneumoState_10, PneumoState_11,
    PneumoState_12, PneumoState_13, PneumoState_14,
    PneumoState_15, PneumoState_16, PneumoState_17,
    PneumoState_FatalException
};

#define PNEUMO_CYLINDER_SIGNAL_UP   0 
#define PNEUMO_CYLINDER_SIGNAL_DOWN 1

struct PneumoCylinder {
    int input_signal[2]; 
    int output_signal; 
};

#define PNEUMO_CYLINDER_Y1 0 
#define PNEUMO_CYLINDER_Y2 1
#define PNEUMO_CYLINDER_Y3 2
#define PNEUMO_CYLINDER_Y4 3
#define PNEUMO_CYLINDER_Y5 4
#define PNEUMO_CYLINDER_Y6 5
#define PNEUMO_CYLINDER_Y7 6
#define PNEUMO_CYLINDER_Y8 7
struct PneumoEngine {
    enum PneumoState state; //текущее состояние автомата. одно из самых главных полей!
    int timeout; //время процесса перехода из одного стабильного состояния в другое
    int delay; //задержка, время удержания стабильного состояния
    int timeouts[PneumoState_FatalException]; //массив таймаутов
    int delays[PneumoState_FatalException]; //массив задержек
    struct PneumoCylinder cylinders[8]; //количество пневмоцилиндров 8
};
//функции автомата
void pneumo_engine_init(struct PneumoEngine *engine); //инициализация автомата, выделение памяти

bool pneumo_engine_tick(struct PneumoEngine *engine); //кадр автомата для динамического моделирования процесса

void pneumo_engine_destroy(struct PneumoEngine *engine); //удаление автомата, освобождение памяти

#if defined(__cplusplus)
}
#endif

#endif //KR_AUTOMATE_H
