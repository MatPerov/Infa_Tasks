#include <stdio.h>
#include <math.h>
struct point
{
    double x;
    double y;
};
typedef struct point Point;

struct triangle
{
    Point a;
    Point b;
    Point c;
};
typedef struct triangle Triangle;

// Тут нужно написать все необходимые функции
void print_point(Point a) {
    printf("(%.2lf, %.2lf)", a.x, a.y);
}
void print_triangle(Triangle* t) {
    printf("{");
    print_point(t->a);
    printf(", ");
    print_point(t->b);
    printf(", ");
    print_point(t->c);
    printf("}\n");
}
double distance(Point a, Point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
double get_triangle_perimeter(const Triangle* t){
    double P = distance(t->a, t->b) + distance(t->b, t->c) + distance(t->a, t->c);
    return P;
}
Triangle moved_triangle(const Triangle* t, Point r) {
    Triangle moved_t;
    moved_t.a.x = t->a.x + r.x;
    moved_t.a.y = t->a.y + r.y;
    moved_t.b.x = t->b.x + r.x;
    moved_t.b.y = t->b.y + r.y;
    moved_t.c.x = t->c.x + r.x;
    moved_t.c.y = t->c.y + r.y;
    return moved_t;
}

void move_triangle(Triangle* t, Point r) {
    t->a.x = t->a.x + r.x;
    t->a.y = t->a.y + r.y;
    t->b.x = t->b.x + r.x;
    t->b.y = t->b.y + r.y;
    t->c.x = t->c.x + r.x;
    t->c.y = t->c.y + r.y;
}
int main()
{
    Triangle t = { {1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50} };
    printf("Perimeter = %.2f\n", get_triangle_perimeter(&t));

    Point d = { 1.0, 1.0 };
    Triangle T=moved_triangle(&t, d);
    print_triangle(&T);
    print_triangle(&t);
    move_triangle(&t, d);
    print_triangle(&t);
    print_point(d);
}
