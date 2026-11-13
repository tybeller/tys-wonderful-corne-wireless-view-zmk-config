#include <zephyr/kernel.h>
#include "animation.h"

// Static character art replaces the original crystal animation.
LV_IMG_DECLARE(character);

// Distance from the top of the (portrait) screen to the top of the art.
// The status area uses roughly the top 36px, so 52 centers the 92px-tall
// art in the remaining space.
#define ART_TOP 52
#define ART_HEIGHT 92
#define SCREEN_LONG_SIDE 160

void draw_animation(lv_obj_t *canvas) {
    lv_obj_t *art = lv_img_create(canvas);
    lv_img_set_src(art, &character);

    // The panel is landscape; portrait "top" is the right-hand edge.
    lv_obj_align(art, LV_ALIGN_TOP_LEFT, SCREEN_LONG_SIDE - ART_TOP - ART_HEIGHT, 0);
}
