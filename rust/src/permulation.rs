// permulation ====================
struct Permulation { i: usize, p: Vec<usize> }
impl Permulation {
    #[allow(unused)]
    fn new(n: usize) -> Permulation {
        assert!(0 < n);
        Permulation { i: 0, p: (0..n).collect() }
    }
}
impl Iterator for Permulation {
    type Item = (usize, Vec<usize>);
    fn next(&mut self) -> Option<Self::Item> {
        if self.i == INF_U {
            None
        } else {
            let ret = (self.i, self.p.clone());
            self.i = if self.p.next_permutation() { self.i + 1 } else { INF_U };
            Some(ret)
        }
    }
}
// ================================
