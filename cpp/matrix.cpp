#include "./template.cpp"

// m x n matrix ===================
template<typename T, int m, int n = m>
struct Matrix {

    array<T, m * n> _values;
    // true: identity matrix, false: zero matrix
    Matrix(bool identity = false) : _values(array<T, m * n>()) {
        if (identity) {
            assert(m == n);
            rep (i, n) _values[i * n + i] = 1;
        }
    }
    Matrix(array<T, m * n> values) : _values(values) {}

    T& operator()(int r, int c) {
        return _values[r * n + c];
    }

    Matrix<T, m, n>& operator+=(Matrix<T, m, n> &B) {
        rep (r, m) rep (c, n) (*this)(r, c) += B(r, c);
        return *this;
    }
    Matrix<T, m, n>& operator-=(Matrix<T, m, n> &B) {
        rep (r, m) rep (c, n) (*this)(r, c) -= B(r, c);
        return *this;
    }

    Matrix<T, m, n>& operator*=(int &k) {
        rep (r, m) rep (c, n) (*this)(r, c) *= k;
        return *this;
    }

    Matrix<T, m, n> operator+(Matrix<T, m, n> &B) {
        return Matrix<T, m, n>(*this) += B;
    }

    Matrix<T, m, n> operator-(Matrix<T, m, n> &B) {
        return Matrix<T, m, n>(*this) -= B;
    }
    template<int l>
    Matrix<T, m, l> operator*(Matrix<T, n, l> &B) {
        Matrix<T, m, l> ret;
        rep (r, m) rep (c, l) rep (i, n) ret(r, c) += (*this)(r, i) * B(i, c);
        return ret;
    }
    Matrix<T, m, n> operator*(int &k) {
        return Matrix<T, m, n>(*this) *= k;
    }

    Matrix<T, m, n> operator-() {
        Matrix<T, m, n> ret(*this);
        rep (r, m) rep (c, n) ret(r, c) *= -1;
        return ret; 
    }

    bool operator==(Matrix<T, m, n> &B) {
        rep (r, m) rep (c, n) {
            if (this(r, c) != B(r, c)) return false;
        }
        return true;
    }
    bool operator!=(Matrix<T, m, n> &B) {
        rep (r, m) rep (c, n) {
            if (this(r, c) == B(r, c)) return false;
        }
        return true;
    }

};
template<int m, int n = m> using Matrixll = Matrix<ll, m, n>;
template<int m, int n = m> using Matrixld = Matrix<ld, m, n>;
template<int m, int n, typename T>
ostream& operator<<(ostream &os, Matrix<T, m, n> x) {
    if (&os == &cout) {
        rep (r, m) {
            rep (c, n) os << x(r, c) << ' ';
            if (r < m - 1) os << '\n';
        }
    }
    if (&os == &cerr) {
        rep (r, m) {
            os << (r == 0 ? '[' : ' ') << '[';
            rep (c, n) os << x(r, c) << (c == n - 1 ? ']' : ' ');
            os << (r < m - 1 ? '\n' : ']');
        }
    }
    return os;
}
// ================================
