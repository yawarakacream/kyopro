#include "./template.cpp"
#include "./matrix.cpp"

// Geometry 2D ==========
using G2DNumber = ll;

template<typename T> using AffineMap = Matrix<T, 3>;
using AffineMapG = AffineMap<G2DNumber>;
AffineMapG scale(G2DNumber kx, G2DNumber ky) {
    return AffineMapG({ kx, 0, 0, 0, ky, 0, 0, 0, 1 });
}
AffineMapG translate(G2DNumber vx, G2DNumber vy) {
    return AffineMapG({ 1, 0, vx, 0, 1, vy, 0, 0, 1 });
}
AffineMapG rotate90() {
    return AffineMapG({ 0, -1, 0, 1, 0, 0, 0, 0, 1 });
}
AffineMapG rotate270() {
    return AffineMapG({ 0, 1, 0, -1, 0, 0, 0, 0, 1 });
}
AffineMap<ld> rotate(ld theta) {
    ld c = cosl(theta), s = sinl(theta);
    return AffineMap<ld>({ c, -s, 0, s, c, 0, 0, 0, 1 });
}

struct Point {

    Matrix<G2DNumber, 3, 1> _m;
    G2DNumber &x, &y;

    Point() : Point(0, 0) {}
    Point(Matrix<G2DNumber, 3, 1> m) : _m(m), x(_m(0, 0)), y(_m(0, 1)) {}
    Point(G2DNumber x, G2DNumber y) : Point(Matrix<G2DNumber, 3, 1>({ x, y, 1 })) {}
    
    Point& operator+=(Point &q) { x += q.x, y += q.y; return *this; }
    Point& operator-=(Point &q) { x -= q.x, y -= q.y; return *this; }

    Point operator+(Point &q) { Point ret(*this); return ret += q; }
    Point operator-(Point &q) { Point ret(*this); return ret -= q; }

    G2DNumber dot(Point &q) { return x * q.x + y * q.y; }

    Point map(AffineMapG map) { return Point(map * _m); }

};
istream& operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
ostream& operator<<(ostream &os, Point &p) {
    if (&os == &cout) os << p.x << ' ' << p.y;
    if (&os == &cerr) os << '(' << p.x << ", " << p.y << ')';
    return os;
}
// ================================
