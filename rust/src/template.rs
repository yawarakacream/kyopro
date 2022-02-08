#![allow(unused_imports)]
#![allow(unused_macros)]
use std::{cmp::{min, max}, mem::swap, collections::*};
use num::integer::*;
use proconio::marker::{Bytes, Chars};
use permutohedron::LexicalPermutation;
macro_rules! input {
    ($t:tt, $x:ident) => (proconio::input! { mut $x: $t });
    ($t:tt, $x:ident, $($y:ident),+) => { input!($t, $x); input!($t, $($y),+); };
}
macro_rules! invec {
    ($t:tt, $v:ident, $n:expr) => {
        let mut $v = Vec::<$t>::with_capacity($n as usize);
        for _ in 0..$n { input!($t, _a); $v.push(_a); }
    };
    ($t:tt, $va:ident, $vb:ident, $n:expr) => {
        let mut $va = Vec::<$t>::with_capacity($n as usize);
        let mut $vb = Vec::<$t>::with_capacity($n as usize);
        for _ in 0..$n { input!($t, _a, _b); $va.push(_a); $vb.push(_b); }
    };
    ($t:tt, $va:ident, $vb:ident, $vc:ident, $n:expr) => {
        let mut $va = Vec::<$t>::with_capacity($n as usize);
        let mut $vb = Vec::<$t>::with_capacity($n as usize);
        let mut $vc = Vec::<$t>::with_capacity($n as usize);
        for _ in 0..$n { input!($t, _a, _b, _c); $va.push(_a); $vb.push(_b); $vc.push(_c); }
    };
}
macro_rules! invec2 {
    ($t:tt, $v:ident, $h:expr, $w:expr) => {
        let mut $v = Vec::<Vec<$t>>::with_capacity($h as usize);
        for _ in 0..$h { invec!($t, u, $w); $v.push(u); }
    };
    (char, $v:ident, $h:expr) => {
        let mut $v = Vec::<Vec<char>>::with_capacity($h as usize);
        for _ in 0..$h { input!(Chars, _a); $v.push(_a); }
    };
}
trait PrintFormat { fn format(&self) -> String; }
macro_rules! print_as_to_string {
    ($t:ty) => { impl PrintFormat for $t { fn format(&self) -> String { self.to_string() } } };
    ($t:ty, $($rest:ty),*) => { print_as_to_string!($t); print_as_to_string!($($rest),*); };
}
print_as_to_string!(i64, isize, u64, usize, str);
impl PrintFormat for f64 { fn format(&self) -> String { format!("{:.15}", self) } }
impl<T: ToString> PrintFormat for Vec<T> {
    fn format(&self) -> String { self.iter().map(ToString::to_string).collect::<Vec<_>>().join(" ") }
}
macro_rules! print {
    () => (println!());
    ($x:expr) => (println!("{}", $x.format()));
    ($x:expr, $y:expr) => (println!("{} {}", $x.format(), $y.format()));
    ($x:expr, $y:expr, $z:expr) => (println!("{} {} {}", $x.format(), $y.format(), $z.format()));
    (YesNo $x:expr) => (print!(if $x { "Yes" } else { "No" }));
}
#[cfg(debug_assertions)]
macro_rules! debug {
    ($($x:expr),* $(,)*) => (eprintln!(concat!("\x1B[44m", $(stringify!($x), ": {:?}\t"),*, "\x1B[0m"), $(&$x),*))
}
#[cfg(not(debug_assertions))] macro_rules! debug { ($($x:expr),*) => {}; }
macro_rules! chmax { ($a:expr, $b:expr) => { if $a < $b { $a = $b; true } else { false } }; }
macro_rules! chmin { ($a:expr, $b:expr) => { if $a > $b { $a = $b; true } else { false } }; }
macro_rules! vec2 { ($init:expr; $h:expr, $w:expr) => (vec![vec![$init; $w]; $h]); }
macro_rules! inf { () => (1001002003004005006); }

fn main() {
}
