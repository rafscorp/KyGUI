#ifndef KYGUI_H
#define KYGUI_H

// ======================================================
// 🧠 TIPOS BASE (INPUT GENÉRICO)
// ======================================================

typedef enum {
    KY_TYPE_INT,
    KY_TYPE_FLOAT,
    KY_TYPE_TEXT
} ky_type;

// valor genérico
typedef struct {
    ky_type type;   // tipo do dado
    void *data;     // ponteiro para o valor
    int max;        // limite lógico (principalmente texto)
} ky_value;


// ======================================================
// 🧠 BUFFER DE TEXTO (DINÂMICO)
// ======================================================

typedef struct {
    char *data;   // buffer
    int len;      // tamanho atual
    int cap;      // capacidade física
    int max;      // limite lógico
    int cursor;   // posição do cursor
} ky_text_buffer;


// ======================================================
// 🪟 WINDOW / CORE
// ======================================================

int  ky_win_init(int w, int h, const char *title);
void ky_win_close();
int  ky_win_running();
void ky_win_poll();

int  ky_win_width();
int  ky_win_height();
void ky_win_set_title(const char *title);


// ======================================================
// ⏱️ FRAME / TEMPO
// ======================================================

void  ky_frame_begin();
void  ky_frame_end();
void  ky_frame_clear(unsigned int color);

void  ky_time_update();
float ky_time_delta();
double ky_time_now();


// ======================================================
// 🎮 INPUT (BAIXO NÍVEL)
// ======================================================

int ky_key_down(int key);
int ky_key_pressed(int key);
int ky_key_released(int key);

int ky_mouse_down(int btn);
int ky_mouse_pressed(int btn);
int ky_mouse_released(int btn);

void ky_mouse_pos(int *x, int *y);
int  ky_mouse_x();
int  ky_mouse_y();

int ky_mouse_wheel();


// ======================================================
// 🎨 DRAW (PRIMITIVAS)
// ======================================================

void ky_draw_pixel(int x, int y, unsigned int color);

void ky_draw_line(int x1, int y1, int x2, int y2, unsigned int color);

void ky_draw_rect(int x, int y, int w, int h, unsigned int color);
void ky_draw_rect_fill(int x, int y, int w, int h, unsigned int color);

void ky_draw_circle(int cx, int cy, int r, unsigned int color);
void ky_draw_circle_fill(int cx, int cy, int r, unsigned int color);


// ======================================================
// 🧾 TEXTO
// ======================================================

void ky_draw_text(int x, int y, const char *str, unsigned int color);

int  ky_text_width(const char *str);
int  ky_text_height();


// ======================================================
// 🧠 BUFFER (FRAMEBUFFER)
// ======================================================

void ky_buffer_clear(unsigned int color);
void ky_buffer_present();

unsigned int* ky_buffer_pixels();

int ky_buffer_width();
int ky_buffer_height();


// ======================================================
// 🧩 UI (IMMEDIATE MODE)
// ======================================================

void ky_ui_begin();
void ky_ui_end();


// ======================================================
// 🎯 FOCO
// ======================================================

void ky_ui_set_focus(int id);
int  ky_ui_get_focus();
int  ky_ui_has_focus(int id);
void ky_ui_clear_focus();


// ======================================================
// 🆔 SISTEMA DE IDs
// ======================================================

int  ky_id_next();
int  ky_id_current();
void ky_id_reset();


// ======================================================
// 🧩 ELEMENTOS UI
// ======================================================

int   ky_ui_button(int x, int y, int w, int h, const char *label);
void  ky_ui_label(int x, int y, const char *text);

int   ky_ui_checkbox(int x, int y, int *value);
float ky_ui_slider(int x, int y, int w, float value, float min, float max);


// ======================================================
// 🔥 INPUT GENÉRICO (STRUCT + VOID*)
// ======================================================

// campo de input universal
// edita:
// - int
// - float
// - texto (via buffer)
void ky_ui_input(int x, int y, int w, int h, ky_value *value);


// ======================================================
// 🧠 TEXT BUFFER (FUNÇÕES AUXILIARES)
// ======================================================

// inicializa buffer
void ky_tb_init(ky_text_buffer *tb, int initial_cap, int max);

// libera memória
void ky_tb_free(ky_text_buffer *tb);

// limpa conteúdo
void ky_tb_clear(ky_text_buffer *tb);

// insere caractere na posição do cursor
void ky_tb_insert_char(ky_text_buffer *tb, char c);

// remove caractere antes do cursor
void ky_tb_backspace(ky_text_buffer *tb);

// move cursor
void ky_tb_move_left(ky_text_buffer *tb);
void ky_tb_move_right(ky_text_buffer *tb);

// garante capacidade
void ky_tb_reserve(ky_text_buffer *tb, int new_cap);


// ======================================================
// 🧱 UTIL
// ======================================================

int ky_util_inside(int x, int y, int rx, int ry, int rw, int rh);

int   ky_util_clamp_int(int v, int min, int max);
float ky_util_clamp_float(float v, float min, float max);


// ======================================================
// 🎨 STYLE (OPCIONAL)
// ======================================================

void ky_style_set_color(unsigned int color);
unsigned int ky_style_get_color();

void ky_style_push();
void ky_style_pop();


#endif