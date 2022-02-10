// SegmentTree ====================
struct SegmentTree<T: Copy, C: Fn(T, T) -> T, A: Fn(&mut T, T)> {
    n: usize,
    dat: Vec<T>,
    identity: T,
    calc: C,
    assign: A,
}
#[allow(dead_code)]
impl<T: Copy, C: Fn(T, T) -> T, A: Fn(&mut T, T)> SegmentTree<T, C, A> {
    fn new(n: usize, identity: T, calc: C, assign: A) -> SegmentTree<T, C, A> {
        let mut m = 1;
        while m < n { m <<= 1; }
        SegmentTree { n: m, dat: vec![identity; m * 2 - 1], identity, calc, assign }
    }

    // i 番目の要素を x を用いて更新
    fn update(&mut self, i: usize, x: T) {
        let mut i = i + self.n - 1;
        (self.assign)(&mut self.dat[i], x);
        while 0 < i {
            i = (i - 1) / 2;
            self.dat[i] = (self.calc)(self.dat[i * 2 + 1], self.dat[i * 2 + 2]);
        }
    }

    // 区間の self.calc の値を返す
    fn query_one(&mut self, i: usize) -> T { self.query(i, i + 1) }
    fn query(&mut self, a: usize, b: usize) -> T { self._query(a, b, 0, 0, self.n) }
    fn _query(&mut self, a: usize, b: usize, k: usize, l: usize, r: usize) -> T {
        if r <= a || b <= l {
            self.identity
        }
        else if a <= l && r <= b {
            self.dat[k]
        }
        else {
            let p = self._query(a, b, k * 2 + 1, l, (l + r) / 2);
            let q = self._query(a, b, k * 2 + 2, (l + r) / 2, r);
            (self.calc)(p, q)
        }
    }
}
// ================================
