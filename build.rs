// build.rs

fn main() {
    cxx_build::bridge("src/lib.rs")
        .file("src/utils.cpp")
        .include("include")
        .std("c++11")
        .compile("divisor-rs");
}
