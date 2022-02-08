// mint ===========================
#[derive(Clone, Copy)]
struct Mint { value: i64 }
impl Mint {
    const MOD: i64 = 1000000007; // must be prime

    fn pow(&self, mut y: i64) -> Mint {
        let mut t = self.clone();
        let mut ret = 1.into();
        while 0 < y { if y & 1 == 1 { ret *= t; } t *= t; y >>= 1; }
        ret
    }

    fn inverse(&self) -> Mint { self.pow(Mint::MOD - 2) }
}
impl From<i32> for Mint { fn from(item: i32) -> Mint { Mint { value: (item as i64) % Mint::MOD } } }
impl From<i64> for Mint { fn from(item: i64) -> Mint { Mint { value: item % Mint::MOD } } }
impl From<isize> for Mint { fn from(item: isize) -> Mint { Mint { value: (item as i64) % Mint::MOD } } }
impl PrintFormat for Mint { fn format(&self) -> String { self.value.format() } }
impl std::fmt::Debug for Mint { fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result { write!(f, "Mint({})", &self.value) } }

macro_rules! mint_define_calc_operator {
    ($trait:ident, $fn:ident, $assignTrait:ident, $assignFn:ident; $process:expr) => {
        impl std::ops::$assignTrait<Mint> for Mint {
            fn $assignFn(&mut self, rhs: Mint) { $process(self, &rhs) }
        }
        impl std::ops::$trait<Mint> for Mint {
            type Output = Mint;
            fn $fn(self, rhs: Mint) -> Self::Output {
                let mut ret = self.clone();
                std::ops::$assignTrait::<Mint>::$assignFn(&mut ret, rhs);
                ret
            }
        }
    };
}
mint_define_calc_operator!(Add, add, AddAssign, add_assign; |this: &mut Mint, rhs: &Mint| {
    this.value += rhs.value; if Mint::MOD <= this.value { this.value -= Mint::MOD; }
});
mint_define_calc_operator!(Sub, sub, SubAssign, sub_assign; |this: &mut Mint, rhs: &Mint| {
    this.value += Mint::MOD - rhs.value; if Mint::MOD <= this.value { this.value -= Mint::MOD; }
});
mint_define_calc_operator!(Mul, mul, MulAssign, mul_assign; |this: &mut Mint, rhs: &Mint| {
    this.value *= rhs.value; if Mint::MOD <= this.value { this.value %= Mint::MOD; }
});
mint_define_calc_operator!(Div, div, DivAssign, div_assign; |this: &mut Mint, rhs: &Mint| {
    *this *= rhs.inverse();
});
// ================================

// mint (old) =====================
#[derive(Clone, Copy)]
struct Mint { value: i64 }
impl Mint {
    const MOD: i64 = 1000000007; // must be prime

    fn pow(&self, mut y: i64) -> Mint {
        let mut t = self.clone();
        let mut ret = 1.into();
        while 0 < y {
            if y & 1 == 1 { ret *= t; }
            t *= t;
            y >>= 1;
        }
        ret
    }

    fn inverse(&self) -> Mint { self.pow(Mint::MOD - 2) }
}
impl From<i32> for Mint { fn from(item: i32) -> Mint { Mint { value: (item as i64) % Mint::MOD } } }
impl From<i64> for Mint { fn from(item: i64) -> Mint { Mint { value: item % Mint::MOD } } }
impl From<isize> for Mint { fn from(item: isize) -> Mint { Mint { value: (item as i64) % Mint::MOD } } }
impl PrintFormat for Mint { fn format(&self) -> String { self.value.format() } }
impl std::fmt::Debug for Mint { fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result { write!(f, "Mint({})", &self.value) } }

impl std::ops::AddAssign for Mint {
    fn add_assign(&mut self, rhs: Mint) {
        self.value += rhs.value;
        if Mint::MOD <= self.value {
            self.value -= Mint::MOD;
        }
    }
}
impl std::ops::SubAssign for Mint {
    fn sub_assign(&mut self, rhs: Mint) {
        self.value += Mint::MOD - rhs.value;
        if Mint::MOD <= self.value {
            self.value -= Mint::MOD;
        }
    }
}
impl std::ops::MulAssign for Mint {
    fn mul_assign(&mut self, rhs: Mint) {
        self.value *= rhs.value;
        if Mint::MOD <= self.value {
            self.value %= Mint::MOD;
        }
    }
}
impl std::ops::DivAssign for Mint {
    fn div_assign(&mut self, rhs: Mint) {
        *self *= rhs.inverse();
    }
}
// ================================
