/* mruby/c VM */
#include <mrubyc.h>

#include "hardware/adc.h"

void joystick_report_hid(uint32_t, uint8_t);

void c_Joystick_reset_axes(mrb_vm *vm, mrb_value *v, int argc);
void c_Joystick_init_axis_offset(mrb_vm *vm, mrb_value *v, int argc);
void c_Joystick_drift_suppression_eq(mrb_vm *vm, mrb_value *v, int argc);
void c_Joystick_init_sensitivity(mrb_vm *vm, mrb_value *v, int argc);

#define JOYSTICK_INIT() do { \
  adc_init(); \
  mrbc_class *mrbc_class_Joystick = mrbc_define_class(0, "Joystick", mrbc_class_object); \
  mrbc_define_method(0, mrbc_class_Joystick, "reset_axes",          c_Joystick_reset_axes); \
  mrbc_define_method(0, mrbc_class_Joystick, "init_axis_offset",    c_Joystick_init_axis_offset); \
  mrbc_define_method(0, mrbc_class_Joystick, "drift_suppression=",  c_Joystick_drift_suppression_eq); \
  mrbc_define_method(0, mrbc_class_Joystick, "init_sensitivity",    c_Joystick_init_sensitivity); \
} while (0)

