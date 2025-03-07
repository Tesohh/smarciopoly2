#include "ui.h"

void DrawBorderRect(Rectangle rect, Color border_color, Color rect_color, int border_width) {
    if (border_width == 0) {
        border_width = RECTANGLE_DEFAULT_BORDER;
    }

    Rectangle inner = {.x = rect.x + border_width,
                       .y = rect.y + border_width,
                       .width = rect.width - border_width * 2,
                       .height = rect.height - border_width * 2};

    DrawRectangleRec(rect, border_color);
    DrawRectangleRec(inner, rect_color);
}
