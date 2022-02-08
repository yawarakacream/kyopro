// permutation ====================
struct Permutation { i: usize, p: Vec<usize> }
impl Permutation {
    #[allow(unused)]
    fn new(n: usize) -> Permutation {
        assert!(0 < n);
        Permutation { i: 0, p: (0..n).collect() }
    }
}
impl Iterator for Permutation {
    type Item = (usize, Vec<usize>);
    fn next(&mut self) -> Option<Self::Item> {
        if self.i == inf!() {
            None
        } else {
            let ret = (self.i, self.p.clone());
            self.i = if self.p.next_permutation() { self.i + 1 } else { inf!() };
            Some(ret)
        }
    }
}
// ================================
