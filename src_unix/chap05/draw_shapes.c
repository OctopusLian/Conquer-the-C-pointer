#include <stdio.h>
#include <assert.h>
#include "shape.h"

void draw_polyline(Shape *shape);
void draw_rectangle(Shape *shape);
void draw_ellipse(Shape *shape);

/*
 * 前提是通过全局变量shape_list_head和shape_list_tail
 * 保存Shape的链表的初始元素和末尾元素
 */
Shape *shape_list_head;
Shape *shape_list_tail;

void draw_shape(Shape *shape)
{
    Shape *pos;

    if (shape->type == PRIMITIVE_SHAPE) {
	switch (shape->u.primitive.type) {
	case POLYLINE_PRIMITIVE:
	    draw_polyline(shape);
	    break;
	case RECTANGLE_PRIMITIVE:
	    draw_rectangle(shape);
	    break;
	case ELLIPSE_PRIMITIVE:
	    draw_ellipse(shape);
	    break;
	default:
	    assert(0);
	}
    } else {
	assert(shape->type == GROUP_SHAPE);
	for (pos = shape->u.group.head; pos != NULL; pos = pos->next) {
	    draw_shape(pos);
	}
    }
}

void draw_all_shapes(void)
{
    Shape *pos;

    for (pos = shape_list_head; pos != NULL; pos = pos->next) {
	draw_shape(pos);
    }
}
