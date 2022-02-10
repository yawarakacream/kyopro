// UnionFind ======================
struct UnionFind {
    n: usize,
    root: Vec<isize>,
}

#[allow(unused)]
impl UnionFind {
    fn new(n: usize) -> UnionFind {
        UnionFind { n, root: vec![-1; n] }
    }
    
    fn find(&mut self, x: usize) -> usize {
        if self.root[x] < 0 {
            x
        }
        else {
            let ret = self.find(self.root[x] as usize);
            self.root[x] = ret as isize;
            ret
        }
    }

    fn unite(&mut self, x: usize, y: usize) {
        let mut x = self.find(x);
        let mut y = self.find(y);
        if x == y {
            return
        }
        if -self.root[x] > -self.root[y] {
            swap(&mut x, &mut y);
        }
        self.root[y] += self.root[x];
        self.root[x] = y as isize;
    }

    fn same(&mut self, x: usize, y: usize) -> bool {
        self.find(x) == self.find(y)
    }

    fn groups(&mut self) -> HashMap<usize, Vec<usize>> {
        let mut ret: HashMap<usize, Vec<usize>> = HashMap::new();
        for i in 0..self.n {
            let r = self.find(i);
            ret.entry(r).or_default().push(i);
        }
        ret
    }
}
// ================================
