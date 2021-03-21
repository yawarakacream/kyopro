#include "./source.cpp"

void sample() {
    Matrixll<2> A({
        {1, 0},
        {0, 2}
    });
    Matrixll<2> B({
        {1, 1},
        {1, 1}
    });
    debug(A);
    debug(B);
    debug(A + B);
    debug(A * B);
    debug(B * A);
    A(0, 1) = 3;
    A += B;
    debug(A);
}

// m x n matrix ===================
template<typename T, int m, int n = m>
struct Matrix {

    vector<T> _values;
    // true: identity matrix, false: zero matrix
    Matrix(bool identity = false) : Matrix(vector<T>(m * n)) {
        if (identity) {
            assert(m == n);
            rep (i, m) _values[i * m + i] = 1;
        }
    }
    Matrix(vector<vector<T>> values) : Matrix(vector<T>(m * n)) {
        assert(values.size() == m);
        assert(values[0].size() == n);
        rep (r, m) rep (c, n) (*this)(r, c) = values[r][c];
    }
    Matrix(vector<T> values) : _values(values) {
        assert(_values.size() == m * n);
    }

    T& operator()(int r, int c) {
        return _values[r * m + c];
    }

    Matrix<T, m, n>& operator+=(Matrix<T, m, n> B) {
        rep (r, m) rep (c, n) (*this)(r, c) += B(r, c);
        return *this;
    }
    Matrix<T, m, n>& operator-=(Matrix<T, m, n> &B) {
        rep (r, m) rep (c, n) (*this)(r, c) -= B(r, c);
        return *this;
    }

    Matrix<T, m, n> operator*=(Matrix<T, n> &B) {
        *this = *this * B;
        return *this;
    }

    Matrix<T, m, n> operator*=(int &k) {
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
template<int m, int n, typename T = ll>
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
