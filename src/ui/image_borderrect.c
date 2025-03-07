#include "ui.h"

void ImageDrawBorderRect(Image* img, Rectangle rect, Color border_color, Color rect_color, int border_width) {
    if (border_width == 0) {
        border_width = RECTANGLE_DEFAULT_BORDER;
    }

    Rectangle inner = {.x = rect.x + border_width,
                       .y = rect.y + border_width,
                       .width = rect.width - border_width * 2,
                       .height = rect.height - border_width * 2};

    ImageDrawRectangleRec(img, rect, border_color);
    ImageDrawRectangleRec(img, inner, rect_color);
}
