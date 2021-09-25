#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

typedef enum {
    FALSE = 0,
    TRUE = 1
} Boolean;

typedef struct {
    int red;
    int green;
    int blue;
} Color;

typedef enum {
    FILL_NONE,                  /* 不填充 */
    FILL_SOLID                  /* 实心填充 */
} FillPattern;

typedef enum {
    POLYLINE_PRIMITIVE,
    RECTANGLE_PRIMITIVE,
    ELLIPSE_PRIMITIVE
} PrimitiveType;

typedef struct {
    double      x;
    double      y;
} Point;

typedef struct {
    int         npoints;
    Point       *point;
} Polyline;

typedef struct {
    Point       min_point;       /* 左下角的坐标 */
    Point       max_point;       /* 右上角的坐标 */
} Rectangle;

typedef struct {
    Point       center;         /* 圆心 */
    double 	h_radius; /* 横向半径 */
    double 	v_radius; /* 纵向半径 */
} Ellipse;

typedef struct {
    /* 图形的种类 */
    PrimitiveType   type;
	/* 画笔（轮廓）的颜色 */
    Color       line_color;
    /* 填充式样。FILL_NONE表示不填充 */
    FillPattern fill_pattern;
    /* 有填充时的颜色 */
    Color       fill_color;
    union {
        Polyline        polyline;
        Rectangle       rectangle;
        Ellipse         ellipse;
    } u;
} Primitive;

typedef struct Shape_tag Shape;

typedef struct {
    Shape   *head;
    Shape   *tail;
} Group;

typedef enum {
    PRIMITIVE_SHAPE,
    GROUP_SHAPE
} ShapeType;

struct Shape_tag {
    ShapeType           type;
    Boolean		selected;
    union {
        Primitive       primitive;
        Group           group;
    } u;
    struct Shape_tag *prev;
    struct Shape_tag *next;
};

#endif /* SHAPE_H_INCLUDED */
