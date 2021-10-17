#include "template.cpp"

/**
 * 2 次元 vector を時計回り 90 度回転させる
 */
template<typename T>
vector<vector<T>> rotate90(vector<vector<T>>& v) {
    vector<vector<T>> r(v[0].size(), vector<T>(v.size()));
    rep (i, v.size()) rep (j, v[0].size()) r[j][v.size() - (i + 1)] = v[i][j];
    return r;
}
